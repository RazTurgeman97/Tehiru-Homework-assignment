#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32, String, Bool
from sensor_msgs.msg import Joy
from std_msgs.msg import Float32MultiArray
from geometry_msgs.msg import Point, Twist
import time

class DroneActivator(Node):
    def __init__(self):
        super().__init__('drone_activator')
        
        # Publishers
        self.joy_publisher = self.create_publisher(Joy, 'joy', 10)
        self.cmd_vel_publisher = self.create_publisher(Twist, 'cmd_vel', 10)
        self.drone_status_pub = self.create_publisher(Bool, 'drone/armed', 10)
        
        # Subscribers
        self.battery_sub = self.create_subscription(
            Float32, 
            'telemetry/battery_percentage', 
            self.battery_callback, 
            10)
        
        self.motor_rpm_sub = self.create_subscription(
            Float32MultiArray, 
            'telemetry/motor_rpm', 
            self.motor_rpm_callback, 
            10)
            
        self.position_sub = self.create_subscription(
            Point,
            'telemetry/position',
            self.position_callback,
            10)
            
        self.attitude_sub = self.create_subscription(
            Point,
            'drone/attitude',  # Changed from 'telemetry/attitude'
            self.attitude_callback,
            10)
            
        # Subscribe to real controller inputs
        self.controller_sub = self.create_subscription(
            Joy,
            'controller_state',
            self.controller_callback,
            10)
        
        # Add a velocity subscriber
        self.velocity_sub = self.create_subscription(
            Float32MultiArray,
            'telemetry/velocity',
            self.velocity_callback,
            10)
        
        # Initialize state variables
        self.simulation_active = False
        self.drone_activated = False
        self.simulation_paused = False
        self.first_battery_reading_time = None
        self.battery_readings_count = 0
        self.motor_rpm_values = None
        self.position = None
        self.attitude = None
        self.velocity = None  # Will store the latest velocity data
        self.activation_stage = 0  # 0: Not started, 1: Sending initial command, 2: Activated
        self.last_activation_time = 0
        self.last_telemetry_time = None  # Initially None, will be set when simulation is detected
        self.target_altitude = 20.0  # Target altitude to maintain (20 meters)
        self.height_control_active = False
        self.height_control_timer = None
        self.activation_time = 0
        
        # Controller inputs
        self.throttle = 0.0  # Left stick up/down
        self.yaw = 0.0       # Left stick left/right
        self.pitch = 0.0     # Right stick up/down
        self.roll = 0.0      # Right stick left/right
        
        # PID controllers with more conservative gains to reduce oscillation
        self.altitude_error_prev = 0.0
        self.altitude_error_sum = 0.0
        self.kp_altitude = 0.4   # Reduced for less aggressive control
        self.ki_altitude = 0.05  # Reduced to minimize overshoot
        self.kd_altitude = 0.8   # Increased for stronger damping
        
        # Create a timer for checking status
        self.timer = self.create_timer(0.1, self.check_status)
        
        # Create a timer for checking if simulation is paused
        self.telemetry_timer = self.create_timer(1.0, self.check_telemetry)
        
        self.get_logger().info('Drone Activator started. Waiting for simulation...')
        
        # Add home position tracking
        self.home_position = None
        self.relative_position = None
        self.target_altitude = 20.0  # Target altitude above home in meters

    def battery_callback(self, msg):
        """Called when a new battery percentage reading is received"""
        # Only start tracking telemetry time after simulation is detected
        if self.simulation_active:
            self.last_telemetry_time = time.time()
            self.simulation_paused = False
        
        if self.first_battery_reading_time is None:
            self.first_battery_reading_time = time.time()
            self.get_logger().info('First battery reading received')
            
        self.battery_readings_count += 1
        
        # If we've been receiving battery readings for at least 3 seconds
        if (not self.simulation_active and 
            self.first_battery_reading_time is not None and
            time.time() - self.first_battery_reading_time >= 3.0 and 
            self.battery_readings_count > 5):
            
            self.simulation_active = True
            self.last_telemetry_time = time.time()  # Initialize when simulation is detected
            self.get_logger().info('Simulation detected! Beginning activation sequence...')
            # Don't start activation yet - wait to set home position first
            # We'll set the activation stage when we have the home position
            
            # Just record that we've detected the simulation
            # The check_status method will handle setting the home position and starting activation

    def motor_rpm_callback(self, msg):
        """Called when new motor RPM data is received"""
        # Only update telemetry time after simulation is confirmed active
        if self.simulation_active:
            self.last_telemetry_time = time.time()
            self.simulation_paused = False
            
        self.motor_rpm_values = msg.data
        
        # Check if all motor RPMs are zero - drone is disarmed
        if self.drone_activated and all(rpm == 0.0 for rpm in self.motor_rpm_values):
            self.get_logger().info('Drone has been disarmed or simulation restarted.')
            self.drone_activated = False
            self.height_control_active = False
            self.activation_stage = 1 if self.simulation_active else 0
            self.last_activation_time = time.time()
            
            # Cancel any existing height control timer
            if self.height_control_timer is not None:
                self.height_control_timer.cancel()
                self.height_control_timer = None
                
            # Publish disarmed status
            armed_msg = Bool()
            armed_msg.data = False
            self.drone_status_pub.publish(armed_msg)
            
            return
        
        # Check if motors are spinning (values above zero) - drone is armed
        if not self.drone_activated and self.motor_rpm_values and all(rpm > 0 for rpm in self.motor_rpm_values):
            self.drone_activated = True
            self.activation_stage = 2
            self.activation_time = time.time()
            self.get_logger().info('Drone activation confirmed! Motors are spinning.')
            self.get_logger().info(f'Motor RPMs: {self.motor_rpm_values}')
            
            # Release throttle after activation
            self.send_center_stick()
            
            # Send a test throttle command ONCE to verify control
            self.test_throttle_timer = self.create_timer(1.0, self.send_test_throttle_once)
            
            # Start height control after 3 seconds using a standard timer
            self.height_control_timer = self.create_timer(3.0, self.start_height_control_and_cancel_timer)
            
            # Publish armed status
            armed_msg = Bool()
            armed_msg.data = True
            self.drone_status_pub.publish(armed_msg)

    def send_test_throttle_once(self):
        """Send a test throttle command once and cancel the timer"""
        # Cancel the timer to make it run only once
        if hasattr(self, 'test_throttle_timer') and self.test_throttle_timer is not None:
            self.test_throttle_timer.cancel()
            self.test_throttle_timer = None
        
        # Now call the actual test throttle method
        self.send_test_throttle()

    def send_test_throttle(self):
        """Send a test throttle command to verify control is working"""
        # Create Joy message for test throttle
        joy_msg = Joy()
        joy_msg.axes = [0.0] * 8
        joy_msg.axes[1] = 0.3  # Small positive throttle
        joy_msg.buttons = [0] * 11
        
        # Publish test throttle command
        self.joy_publisher.publish(joy_msg)
        
        # Also publish to cmd_vel for completeness
        cmd = Twist()
        cmd.linear.z = 0.3
        self.cmd_vel_publisher.publish(cmd)
        
        self.get_logger().info('Sending test throttle command: 0.3')
        
        # Create a timer to stop the test after 0.5 seconds
        self.test_timer = self.create_timer(0.5, self.stop_test_throttle_and_cancel_timer)

    def stop_test_throttle_and_cancel_timer(self):
        """Stop the test throttle command and cancel the timer"""
        # Cancel the timer to make it one-shot
        if hasattr(self, 'test_timer') and self.test_timer is not None:
            self.test_timer.cancel()
            self.test_timer = None
        
        # Stop the throttle using Joy message
        joy_msg = Joy()
        joy_msg.axes = [0.0] * 8
        joy_msg.axes[1] = 0.0  # Center throttle
        joy_msg.buttons = [0] * 11
        self.joy_publisher.publish(joy_msg)
        
        # Also publish to cmd_vel for completeness
        cmd = Twist()
        cmd.linear.z = 0.0
        self.cmd_vel_publisher.publish(cmd)
        
        self.get_logger().info('Test throttle command complete')

    def start_height_control_and_cancel_timer(self):
        """Start height control and cancel the oneshot timer"""
        # Cancel the timer (making it effectively oneshot)
        if self.height_control_timer is not None:
            self.height_control_timer.cancel()
            self.height_control_timer = None
            
        # Start the height control
        self.start_height_control()

    def position_callback(self, msg):
        """Called when position data is received"""
        # Only update telemetry time after simulation is confirmed active
        if self.simulation_active:
            self.last_telemetry_time = time.time()
            self.simulation_paused = False
            
        # Store the raw position data
        self.position = msg
        
        # If the simulation is active but we haven't set the home position yet
        if self.simulation_active and self.home_position is None and self.activation_stage == 0:
            # Set the current position as home
            self.set_home_position()
        
        # Calculate the relative position if we have a home position
        if self.home_position is not None:
            # Create a new Point for the relative position
            if self.relative_position is None:
                self.relative_position = Point()
                
            # Calculate positions relative to home
            self.relative_position.x = msg.x - self.home_position.x
            self.relative_position.y = msg.y - self.home_position.y
            self.relative_position.z = msg.z - self.home_position.z
            
            # Debug relative position periodically
            curr_time = time.time()
            if int(curr_time) % 5 == 0:
                self.get_logger().info(
                    f'Position relative to home: '
                    f'x={self.relative_position.x:.2f}, '
                    f'y={self.relative_position.y:.2f}, '
                    f'z={self.relative_position.z:.2f}, '
                    f'height={self.relative_position.y:.2f}m'
                )
        
        # Debug raw position received periodically
        curr_time = time.time()
        if int(curr_time) % 5 == 0:
            self.get_logger().info(f'Raw position: x={msg.x:.2f}, y={msg.y:.2f}, z={msg.z:.2f}')
        
        # If height control is active, regulate the altitude
        if self.height_control_active and self.drone_activated:
            self.regulate_altitude()

    def set_home_position(self):
        """Set the current position as the home/reference position"""
        if self.position is None:
            self.get_logger().warning("Cannot set home position: position data not available")
            return
            
        # Create a new Point to store the home position
        self.home_position = Point()
        self.home_position.x = self.position.x
        self.home_position.y = self.position.y
        self.home_position.z = self.position.z
        
        self.get_logger().info(
            f'Home position set: '
            f'x={self.home_position.x:.2f}, '
            f'y={self.home_position.y:.2f}, '
            f'z={self.home_position.z:.2f}'
        )
        
        # Now we can start the activation sequence
        self.last_activation_time = time.time()
        self.activation_stage = 1
        self.get_logger().info('Home position set, beginning drone activation...')

    def regulate_altitude(self):
        """PID controller with velocity feedback for altitude regulation"""
        if not self.position or not self.home_position:
            self.get_logger().warning("Cannot regulate altitude: position data or home position not available")
            return
            
        # Calculate current height (y-coordinate) relative to home
        current_height = self.position.y - self.home_position.y
            
        # Calculate error (target - current)
        altitude_error = self.target_altitude - current_height
        
        # Get vertical velocity if available (usually y component in our frame)
        vertical_velocity = 0.0
        if self.velocity and len(self.velocity) >= 3:
            vertical_velocity = self.velocity[1]  # Y-axis velocity
        
        # Calculate derivative term (change in error)
        altitude_error_derivative = altitude_error - self.altitude_error_prev
        
        # Use velocity feedback to enhance control
        # This is key to overcoming the drone's physical response delay
        # If we're going up too fast when trying to go down, we need stronger down control
        velocity_correction = 0.0
        if abs(vertical_velocity) > 0.5:  # If moving significantly
            # If going up while we need to go down (or vice versa), apply stronger correction
            if (vertical_velocity > 0 and altitude_error < 0) or (vertical_velocity < 0 and altitude_error > 0):
                velocity_correction = -vertical_velocity * 0.5  # Counter the current momentum
                self.get_logger().debug(f'Velocity correction: {velocity_correction:.2f} (countering momentum)')
        
        # Update integral term with tighter limits to prevent windup
        # Only accumulate integral when close to target to prevent overshooting
        if abs(altitude_error) < 3.0:
            self.altitude_error_sum += altitude_error * 0.05  # Accumulate very slowly
        else:
            # Reset integral when far from target to prevent large buildups
            self.altitude_error_sum = 0.0
            
        self.altitude_error_sum = max(-0.5, min(0.5, self.altitude_error_sum))  # Even tighter limits
        
        # PID formula with velocity feedback
        throttle_adjustment = (
            self.kp_altitude * altitude_error + 
            self.ki_altitude * self.altitude_error_sum + 
            self.kd_altitude * altitude_error_derivative + 
            velocity_correction  # Add velocity feedback
        )
        
        # Apply predictive control - if we're moving quickly toward target, start slowing down early
        if (altitude_error > 0 and vertical_velocity > 1.0) or (altitude_error < 0 and vertical_velocity < -1.0):
            # We're moving toward target at good speed - prepare to slow down
            # Estimate stopping distance based on velocity and apply pre-emptive correction
            stopping_correction = vertical_velocity * 0.3  # Adjust based on how quickly drone stops
            throttle_adjustment -= stopping_correction
            self.get_logger().debug(f'Applying stopping correction: {stopping_correction:.2f}')
        
        # Apply non-linear mapping to create smoother response
        # For small errors, make very gentle adjustments
        if abs(altitude_error) < 0.5:
            # Very close to target - minimal adjustment
            throttle_adjustment *= 0.3
        elif abs(altitude_error) < 2.0:
            # Somewhat close to target - moderate adjustment
            throttle_adjustment *= 0.5
        elif abs(altitude_error) < 5.0:
            # Medium distance from target - standard adjustment
            throttle_adjustment *= 0.7
        else:
            # Far from target - stronger adjustment but still smoothed
            if throttle_adjustment > 0:
                throttle_adjustment = min(0.8, throttle_adjustment * 0.8)
            else:
                throttle_adjustment = max(-0.8, throttle_adjustment * 0.8)
        
        # Apply dead zone to prevent tiny adjustments that cause jitter
        if abs(throttle_adjustment) < 0.05:
            throttle_adjustment = 0.0
        
        # Limit maximum throttle adjustment
        throttle_adjustment = max(-0.8, min(0.8, throttle_adjustment))
        
        # Save current error for next iteration
        self.altitude_error_prev = altitude_error
        
        # Create joy message
        joy_msg = Joy()
        joy_msg.axes = [0.0] * 8
        
        # Set throttle (left stick Y) based on PID adjustment
        joy_msg.axes[1] = throttle_adjustment
        
        # Create standard buttons array
        joy_msg.buttons = [0] * 11
        
        # Publish the joy message directly
        self.joy_publisher.publish(joy_msg)
        
        # Log altitude control info
        curr_time = time.time()
        if int(curr_time * 2) % 2 == 0:  # Log every ~0.5 seconds
            velocity_info = f', velocity={vertical_velocity:.2f}' if self.velocity else ''
            self.get_logger().info(
                f'Altitude control: target={self.target_altitude}m, '
                f'current={current_height:.2f}m, '
                f'error={altitude_error:.2f}{velocity_info}, '
                f'joy_throttle={throttle_adjustment:.2f}'
            )

    def start_height_control(self):
        """Start altitude control mode"""
        if self.drone_activated and self.home_position is not None:
            self.height_control_active = True
            
            # Calculate current height relative to home
            current_height = self.position.y - self.home_position.y
            
            # Log the starting altitude control with both desired and current height
            self.get_logger().info(
                f'Starting height control. Current height: {current_height:.2f}m, '
                f'Target altitude: {self.target_altitude}m'
            )
            
            # Reset PID variables
            self.altitude_error_prev = 0.0
            self.altitude_error_sum = 0.0
        else:
            self.get_logger().warning(
                "Cannot start height control: Either drone is not activated or home position is not set"
            )

    def attitude_callback(self, msg):
        """Called when attitude data is received"""
        # Only update telemetry time after simulation is confirmed active
        if self.simulation_active:
            self.last_telemetry_time = time.time()
            self.simulation_paused = False
            
        self.attitude = msg
        if self.drone_activated:
            self.get_logger().debug(f'Attitude: (roll: {msg.x:.2f}, pitch: {msg.y:.2f}, yaw: {msg.z:.2f})')

    def velocity_callback(self, msg):
        """Called when velocity data is received"""
        # Only update telemetry time after simulation is confirmed active
        if self.simulation_active:
            self.last_telemetry_time = time.time()
            self.simulation_paused = False
            
        self.velocity = msg.data
        
        # Debug velocity periodically
        curr_time = time.time()
        if int(curr_time) % 5 == 0 and self.velocity:
            self.get_logger().info(f'Velocity: x={self.velocity[0]:.2f}, y={self.velocity[1]:.2f}, z={self.velocity[2]:.2f}')

    def controller_callback(self, msg):
        """Process controller inputs to control the drone"""
        if not self.drone_activated:
            return  # Don't process inputs until drone is activated
            
        if len(msg.axes) >= 4:  # Make sure we have enough axes
            # Store controller values
            self.throttle = msg.axes[1]  # Left stick Y
            self.yaw = msg.axes[0]       # Left stick X
            self.pitch = msg.axes[3]     # Right stick Y
            self.roll = msg.axes[2]      # Right stick X
            
            # Important: We will pass the Joy message directly to the joy topic
            # so the simulator receives it in the format it expects
            
            # Create a new Joy message to forward to the simulator
            joy_msg = Joy()
            joy_msg.axes = list(msg.axes)  # Copy all axes values
            joy_msg.buttons = list(msg.buttons)  # Copy all button values
            
            # Turn off height control if user is controlling throttle
            if abs(self.throttle) > 0.1:
                if self.height_control_active:
                    self.height_control_active = False
                    self.get_logger().info('Height control deactivated - manual throttle detected')
                    
                # When manual control is active, forward the joy message directly
                self.joy_publisher.publish(joy_msg)
            # When throttle is released, activate height control
            elif not self.height_control_active and self.drone_activated:
                self.height_control_active = True
                
                # Update target altitude to current height relative to home
                if self.position and self.home_position:
                    current_height = self.position.y - self.home_position.y
                    self.target_altitude = current_height
                    self.get_logger().info(f'Height control reactivated - maintaining {self.target_altitude:.2f}m')
            
            # For debug purposes, also publish to cmd_vel
            cmd = Twist()
            cmd.linear.z = self.throttle
            cmd.angular.z = self.yaw
            cmd.linear.x = self.pitch
            cmd.linear.y = self.roll
            self.cmd_vel_publisher.publish(cmd)
            
            self.get_logger().debug(
                f'Controller inputs - throttle: {self.throttle:.2f}, yaw: {self.yaw:.2f}, ' +
                f'pitch: {self.pitch:.2f}, roll: {self.roll:.2f}'
            )

    def check_status(self):
        """Periodic check to activate the drone if needed"""
        if self.simulation_active and self.activation_stage == 1 and not self.simulation_paused:
            # If we've been trying to activate for more than 5 seconds, try again
            if time.time() - self.last_activation_time > 5.0:
                self.last_activation_time = time.time()
                
            self.send_throttle_down()
            self.get_logger().info('Sending throttle down command to activate drone...')

    def check_telemetry(self):
        """Check if telemetry has stopped (simulation paused)"""
        # Only check for paused simulation if:
        # 1. Simulation has been detected (simulation_active is True)
        # 2. We have received telemetry data (last_telemetry_time is not None)
        if self.simulation_active and self.last_telemetry_time is not None:
            if time.time() - self.last_telemetry_time > 2.0:
                if not self.simulation_paused:
                    self.simulation_paused = True
                    self.get_logger().info('Telemetry stopped - simulation may be paused')
            elif self.simulation_paused:
                self.simulation_paused = False
                self.get_logger().info('Telemetry resumed - simulation is running')

    def send_throttle_down(self):
        """Send a throttle down command via the joy topic"""
        joy_msg = Joy()
        
        # Create standard axes array (8 values)
        joy_msg.axes = [0.0] * 8
        # Set throttle down (left stick down, typically axes[1] = -1.0)
        joy_msg.axes[1] = -1.0  
        
        # Create standard buttons array (usually 11 values for a PS4)
        joy_msg.buttons = [0] * 11
        
        # Publish the message
        self.joy_publisher.publish(joy_msg)

    def send_center_stick(self):
        """Release all controls to center positions"""
        joy_msg = Joy()
        
        # Create standard axes array (8 values)
        joy_msg.axes = [0.0] * 8
        
        # Create standard buttons array 
        joy_msg.buttons = [0] * 11
        
        # Publish the message
        self.joy_publisher.publish(joy_msg)

def main(args=None):
    rclpy.init(args=args)
    node = DroneActivator()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        # Handle keyboard interrupt gracefully
        node.get_logger().info('Node stopped cleanly')
    except Exception as e:
        node.get_logger().error(f'Error in node: {str(e)}')
    finally:
        # Clean shutdown to avoid the context error
        try:
            node.destroy_node()
            rclpy.shutdown()
        except Exception:
            # If shutdown already called, ignore the error
            pass

if __name__ == '__main__':
    main()