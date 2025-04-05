#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from std_msgs.msg import Float32MultiArray, Bool
from geometry_msgs.msg import Point
import time
import math

class AltitudeController(Node):
    def __init__(self):
        super().__init__('altitude_controller')
        
        # Publishers
        self.joy_publisher = self.create_publisher(Joy, 'joy', 10)
        
        # Subscribers
        self.position_sub = self.create_subscription(
            Point,
            'telemetry/position',
            self.position_callback,
            10)
            
        self.velocity_sub = self.create_subscription(
            Float32MultiArray,
            'telemetry/velocity',
            self.velocity_callback,
            10)
            
        self.controller_sub = self.create_subscription(
            Joy,
            'controller_state',
            self.controller_callback,
            10)
            
        self.drone_armed_sub = self.create_subscription(
            Bool,
            'drone/armed',
            self.armed_callback,
            10)
        
        # Initialize state variables
        self.position = None
        self.velocity = None
        self.home_position = None
        self.relative_position = None
        self.target_altitude = 20.0  # Default target altitude
        self.control_active = False
        self.user_control_active = False
        self.throttle = 0.0
        self.drone_armed = False
        
        # PID controller parameters
        self.altitude_error_prev = 0.0
        self.altitude_error_sum = 0.0
        self.last_throttle_adjustment = 0.0
        self.last_altitude_control_time = time.time()
        self.kp_altitude = 0.25   # Proportional gain
        self.ki_altitude = 0.03   # Integral gain
        self.kd_altitude = 0.5    # Derivative gain
        self.rate_limit = 0.2     # Maximum change in throttle per second
        
        # Smoother control
        self.previous_throttle_commands = []  # Store recent commands for smoothing
        self.max_history = 3  # Number of previous commands to average
        
        # Create a timer for altitude control
        self.timer = self.create_timer(0.05, self.altitude_control_loop)
        
        self.get_logger().info('Altitude controller started')
        
    def armed_callback(self, msg):
        """Process drone armed status updates"""
        self.drone_armed = msg.data
        if self.drone_armed:
            self.get_logger().info('Drone armed, altitude controller ready')
        else:
            self.get_logger().info('Drone disarmed, altitude control disabled')
            self.control_active = False
        
    def position_callback(self, msg):
        """Process position updates from telemetry"""
        self.position = msg
        
        # Set home position if not already set and drone is armed
        if self.drone_armed and self.home_position is None:
            self.set_home_position(msg)
            return
        
        # Calculate position relative to home
        if self.home_position is not None:
            if self.relative_position is None:
                self.relative_position = Point()
            
            self.relative_position.x = msg.x - self.home_position.x
            self.relative_position.y = msg.y - self.home_position.y
            self.relative_position.z = msg.z - self.home_position.z
            
            # Periodic position logging
            curr_time = time.time()
            if int(curr_time * 2) % 10 == 0:  # Log every 5 seconds
                self.get_logger().info(
                    f'Position relative to home: x={self.relative_position.x:.2f}, '
                    f'y={self.relative_position.y:.2f}, z={self.relative_position.z:.2f}, '
                    f'height={self.relative_position.y:.2f}m'
                )
        
    def velocity_callback(self, msg):
        """Process velocity updates from telemetry"""
        self.velocity = msg.data
        
    def controller_callback(self, msg):
        """Process controller input"""
        if len(msg.axes) >= 2:
            # Check if user is controlling throttle
            new_throttle = msg.axes[1]  # Left stick Y axis
            
            if abs(new_throttle) > 0.1:
                if not self.user_control_active:
                    self.user_control_active = True
                    self.control_active = False
                    self.get_logger().info('User throttle control detected, altitude hold deactivated')
            elif self.user_control_active:
                # User released throttle, update target and reactivate control
                self.user_control_active = False
                if self.position and self.home_position:
                    current_height = self.position.y - self.home_position.y
                    self.target_altitude = current_height
                    self.control_active = True
                    # Reset PID controller
                    self.altitude_error_prev = 0.0
                    self.altitude_error_sum = 0.0
                    self.previous_throttle_commands = []
                    self.get_logger().info(f'Altitude hold activated at {self.target_altitude:.1f}m')
                    
            # Store throttle value
            self.throttle = new_throttle
        
    def set_home_position(self, position):
        """Set the home position for relative altitude calculation"""
        self.home_position = Point()
        self.home_position.x = position.x
        self.home_position.y = position.y
        self.home_position.z = position.z
        self.get_logger().info(f'Home position set: x={position.x:.2f}, y={position.y:.2f}, z={position.z:.2f}')
        
    def altitude_control_loop(self):
        """Main control loop for altitude regulation"""
        if not self.drone_armed or self.user_control_active or not self.control_active:
            return
            
        if not self.position or not self.home_position or not self.velocity:
            return
            
        # Current height above home
        current_height = self.position.y - self.home_position.y
            
        # Current time for dt calculation
        current_time = time.time()
        dt = current_time - self.last_altitude_control_time
        self.last_altitude_control_time = current_time
        
        # Calculate error
        altitude_error = self.target_altitude - current_height
        
        # Get vertical velocity
        vertical_velocity = self.velocity[1] if len(self.velocity) >= 3 else 0.0
        
        # Calculate derivative term with improved noise filtering
        if hasattr(self, 'altitude_error_prev'):
            # Use both error derivative and velocity feedback for better performance
            altitude_error_derivative = (altitude_error - self.altitude_error_prev) / max(dt, 0.01)
            # Add a low-pass filter to the derivative term to reduce noise
            altitude_error_derivative = 0.7 * altitude_error_derivative + 0.3 * (-vertical_velocity)
        else:
            altitude_error_derivative = 0.0
        
        # Update integral term with anti-windup and conditional integration
        if abs(altitude_error) < 1.5:  # Only integrate when close to target
            self.altitude_error_sum += altitude_error * dt * 0.03
            # Tighter bounds on integral term
            self.altitude_error_sum = max(-0.3, min(0.3, self.altitude_error_sum))
        else:
            # Reset integral term when far from target to prevent windup
            self.altitude_error_sum = 0.0
        
        # Base PID adjustment
        pid_adjustment = (
            self.kp_altitude * altitude_error + 
            self.ki_altitude * self.altitude_error_sum + 
            self.kd_altitude * altitude_error_derivative
        )
        
        # Apply velocity feedforward for improved stability
        # This counters the drone's momentum when approaching the target
        velocity_correction = -vertical_velocity * 0.3
        
        # Combine PID and velocity terms
        throttle_adjustment = pid_adjustment + velocity_correction
        
        # Apply non-linear response curve for better control feel
        if abs(altitude_error) < 0.15:  # Very close to target
            # Hover compensation - this crucial value prevents drift
            hover_value = 0.18  # Experimentally determined hover throttle
            
            # Adjust hover value based on small vertical movement
            if vertical_velocity > 0.05:
                # We're still rising, reduce throttle slightly
                hover_value -= 0.02
            elif vertical_velocity < -0.05:
                # We're still falling, increase throttle slightly
                hover_value += 0.02
                
            throttle_adjustment = hover_value
        elif abs(altitude_error) < 0.5:
            # Gentle adjustment when close
            throttle_adjustment *= 0.4
        elif abs(altitude_error) < 1.0:
            # Moderate adjustment
            throttle_adjustment *= 0.6
        
        # Rate limiting for smoother control
        if hasattr(self, 'last_throttle_adjustment'):
            max_change = self.rate_limit * dt
            throttle_delta = throttle_adjustment - self.last_throttle_adjustment
            if abs(throttle_delta) > max_change:
                throttle_adjustment = self.last_throttle_adjustment + max_change * (1 if throttle_delta > 0 else -1)
        
        # Add to command history for smoothing
        self.previous_throttle_commands.append(throttle_adjustment)
        if len(self.previous_throttle_commands) > self.max_history:
            self.previous_throttle_commands.pop(0)
        
        # Apply smoothing by averaging recent commands
        smoothed_throttle = sum(self.previous_throttle_commands) / len(self.previous_throttle_commands)
            
        # Save for next iteration
        self.last_throttle_adjustment = throttle_adjustment
        self.altitude_error_prev = altitude_error
        
        # Apply final limits
        final_throttle = max(-0.7, min(0.7, smoothed_throttle))
        
        # Create and publish joy message
        joy_msg = Joy()
        joy_msg.axes = [0.0] * 8
        joy_msg.axes[1] = final_throttle  # Set throttle axis
        joy_msg.buttons = [0] * 11
        self.joy_publisher.publish(joy_msg)
        
        # Log altitude control info (less frequently to reduce noise)
        if int(current_time * 10) % 20 == 0:  # Log every ~2 seconds
            self.get_logger().info(
                f'Alt control: target={self.target_altitude:.1f}m, '
                f'current={current_height:.1f}m, '
                f'error={altitude_error:.2f}, '
                f'vel={vertical_velocity:.2f}, '
                f'throttle={final_throttle:.2f}'
            )

    def activate_control(self):
        """Activate altitude control"""
        if not self.drone_armed:
            self.get_logger().warning("Cannot activate altitude control: Drone not armed")
            return
            
        self.control_active = True
        if self.position and self.home_position:
            self.target_altitude = self.position.y - self.home_position.y
            self.get_logger().info(f'Altitude control activated at {self.target_altitude:.1f}m')
        
    def deactivate_control(self):
        """Deactivate altitude control"""
        self.control_active = False
        self.get_logger().info('Altitude control deactivated')
        
    def set_target_altitude(self, altitude):
        """Set a new target altitude"""
        self.target_altitude = altitude
        self.get_logger().info(f'New target altitude set: {altitude:.1f}m')

def main(args=None):
    rclpy.init(args=args)
    node = AltitudeController()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Node stopped cleanly')
    except Exception as e:
        node.get_logger().error(f'Error: {str(e)}')
    finally:
        # Safer shutdown sequence
        try:
            node.destroy_node()
            # Only shutdown if not already shutting down
            if rclpy.ok():
                rclpy.shutdown()
        except Exception as e:
            pass

if __name__ == '__main__':
    main()