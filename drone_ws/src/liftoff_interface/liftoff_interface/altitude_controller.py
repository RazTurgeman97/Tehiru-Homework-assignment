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
        
        # Add this line to declare the debug parameter with a default value
        self.declare_parameter('debug', False)
        
        # Add these lines near your other declare_parameter calls
        self.declare_parameter('kp_altitude', 0.25)
        self.declare_parameter('ki_altitude', 0.03)
        self.declare_parameter('kd_altitude', 0.5)
        
        # Add these lines to declare drift parameters
        self.declare_parameter('drift_adaptation_rate', 0.002)
        self.declare_parameter('initial_drift_compensation', -0.05)
        
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
        self.kp_altitude = self.get_parameter('kp_altitude').value
        self.ki_altitude = self.get_parameter('ki_altitude').value
        self.kd_altitude = self.get_parameter('kd_altitude').value
        self.rate_limit = 0.2     # Maximum change in throttle per second
        
        # Smoother control
        self.previous_throttle_commands = []  # Store recent commands for smoothing
        self.max_history = 3  # Number of previous commands to average
        
        # Initialize drift compensation system
        self.drift_compensation = self.get_parameter('initial_drift_compensation').value
        self.drift_adaptation_rate = self.get_parameter('drift_adaptation_rate').value
        self.stable_time = 0.0
        self.last_throttle_output = 0.0
        self.natural_ascent_tracked = False
        self.natural_ascent_rate = 0.0
        
        # Create a timer for altitude control
        self.timer = self.create_timer(0.05, self.altitude_control_loop)
        
        # Add debug toggle
        self.declare_parameter('debug', False)
        
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
        """Process controller input with diagnostic triggers"""
        if len(msg.axes) >= 2:
            # Special diagnostic: Force neutral throttle on button press
            if len(msg.buttons) > 0 and msg.buttons[0] == 1:
                self.force_neutral_throttle()
                return
            
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
        """Enhanced adaptive control loop leveraging drone's natural ascent tendency"""
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
        
        # Calculate error (positive means we need to go up)
        altitude_error = self.target_altitude - current_height
        
        # Get vertical velocity (positive means going up)
        vertical_velocity = self.velocity[1] if len(self.velocity) >= 3 else 0.0
        
        # Update stable time tracking
        is_stable = abs(altitude_error) < 0.3 and abs(vertical_velocity) < 0.15
        if is_stable:
            if self.stable_time == 0:
                self.stable_time = current_time
        else:
            self.stable_time = 0
        
        # Track natural ascent rate when throttle is minimal
        if not self.natural_ascent_tracked and abs(self.last_throttle_output) < 0.05 and vertical_velocity > 0:
            self.natural_ascent_rate = vertical_velocity
            self.natural_ascent_tracked = True
            self.get_logger().info(f"Detected natural ascent rate: {self.natural_ascent_rate:.3f} m/s")
        
        # Learn drift properties when stable
        if self.stable_time > 0 and current_time - self.stable_time > 3.0:
            # If we're drifting up despite being at target, increase downward compensation
            if vertical_velocity > 0.05:
                self.drift_compensation -= self.drift_adaptation_rate
                if int(current_time) % 10 == 0:
                    self.get_logger().info(f"Adapting drift compensation: {self.drift_compensation:.4f} (upward drift)")
            # If we're drifting down, reduce the downward compensation
            elif vertical_velocity < -0.05:
                self.drift_compensation += self.drift_adaptation_rate
                if int(current_time) % 10 == 0:
                    self.get_logger().info(f"Adapting drift compensation: {self.drift_compensation:.4f} (downward drift)")
        
        # PASSIVE ASCENT MODE: If we need to go up, rely on natural ascent
        # Only apply minimal throttle to maintain upward movement
        if altitude_error > 0.5 and vertical_velocity >= 0:
            # We're below target and already moving up or stable - let natural ascent work
            base_throttle = 0.0  # Neutral throttle
            damping = 0.0        # No damping
            
            # Apply slight boost only if not moving up fast enough
            if vertical_velocity < 0.1:
                base_throttle = 0.05  # Very minimal throttle
                
            self.get_logger().debug("PASSIVE ASCENT MODE - letting drone rise naturally")
        
        # ACTIVE DESCENT MODE: If we need to go down, apply more active control
        elif altitude_error < -0.5:
            # We're above target - need to descend
            # Apply stronger proportional control
            base_throttle = 0.25 * altitude_error  # This will be negative
            damping = -0.3 * vertical_velocity    # Counteract velocity
            
            # When far above target, apply stronger descent
            if altitude_error < -2.0:
                base_throttle = -0.3  # Strong downward thrust
                
            self.get_logger().debug("ACTIVE DESCENT MODE - applying downward thrust")
        
        # PRECISION MODE: When close to target
        else:
            # Fine tuning when close to target
            # Use gentler proportional control
            base_throttle = 0.15 * math.tanh(1.5 * altitude_error)
            
            # Apply velocity damping to prevent oscillation
            damping = -0.25 * vertical_velocity
            
            self.get_logger().debug("PRECISION MODE - fine tuning altitude")
        
        # Apply drift compensation (learned offset)
        offset = self.drift_compensation
        
        # Anti-overshoot mechanism
        anti_overshoot = 0.0
        if abs(vertical_velocity) > 0.2:
            # Predict position in 1 second
            predicted_position = current_height + vertical_velocity * 1.0
            predicted_error = self.target_altitude - predicted_position
            
            # If we predict overshooting
            if math.copysign(1.0, predicted_error) != math.copysign(1.0, altitude_error):
                anti_overshoot = -0.2 * vertical_velocity
                self.get_logger().debug(f"Anti-overshoot active: {anti_overshoot:.3f}")
        
        # Calculate final throttle value
        raw_throttle = base_throttle + damping + offset + anti_overshoot
        
        # Special cases for common scenarios
        
        # 1. When at target but rising - apply stronger downward correction
        if abs(altitude_error) < 0.3 and vertical_velocity > 0.1:
            raw_throttle -= 0.1  # Additional downward bias
            self.get_logger().debug("Applying extra downward bias to counter rise")
        
        # 2. Near target & stable - use minimal control
        if abs(altitude_error) < 0.2 and abs(vertical_velocity) < 0.1:
            # Just maintain drift compensation with minimal adjustments
            raw_throttle = offset + 0.1 * base_throttle + 0.5 * damping
            self.get_logger().debug("Minimal control mode - stable at target")
        
        # Rate limiting - use more gentle rate limits
        if hasattr(self, 'last_throttle_output'):
            # Gentler rate limits
            if (altitude_error < 0 and vertical_velocity > 0) or (altitude_error > 0 and vertical_velocity < 0):
                max_change = 0.3 * dt  # Still responsive when needed
            else:
                max_change = 0.15 * dt  # Very gentle changes
                
            throttle_delta = raw_throttle - self.last_throttle_output
            if abs(throttle_delta) > max_change:
                raw_throttle = self.last_throttle_output + max_change * math.copysign(1.0, throttle_delta)
        
        # Store for next iteration
        self.last_throttle_output = raw_throttle
        
        # Apply final limits - narrower range for gentler control
        final_throttle = max(-0.6, min(0.5, raw_throttle))
        
        # Create and publish joy message
        joy_msg = Joy()
        joy_msg.axes = [0.0] * 8
        joy_msg.axes[1] = final_throttle  # Set throttle axis
        joy_msg.buttons = [0] * 11
        self.joy_publisher.publish(joy_msg)
        
        # Create a diagnostic message to verify command flow
        diagnostic_msg = Joy()
        diagnostic_msg.axes = [0.0] * 8
        diagnostic_msg.axes[1] = final_throttle  # Set throttle axis
        diagnostic_msg.buttons = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]  # Special marker in button 0
        self.joy_publisher.publish(diagnostic_msg)

        # Log with a distinctive marker
        self.get_logger().info(f"🔄 SENT-CMD: throttle={final_throttle:.2f}")
        
        # Log altitude control info
        if int(current_time * 10) % 20 == 0:  # Log every ~2 seconds
            state = "STABLE" if is_stable else "ADJUSTING"
            mode = "ASCEND" if altitude_error > 0.5 else "DESCEND" if altitude_error < -0.5 else "PRECISION"
            compensation = "ACTIVE" if self.stable_time > 0 else "LEARNING"
            
            self.get_logger().info(
                f'Alt [{mode}|{compensation}]: target={self.target_altitude:.1f}m, '
                f'current={current_height:.1f}m, '
                f'error={altitude_error:.2f}, '
                f'vel={vertical_velocity:.2f}, '
                f'drift_comp={self.drift_compensation:.3f}, '
                f'throttle={final_throttle:.2f}'
            )
            
            # Debug component breakdown
            try:
                debug_mode = self.get_parameter('debug').get_parameter_value().bool_value
            except:
                debug_mode = False
                
            if debug_mode:
                self.get_logger().info(
                    f"COMPONENTS: base={base_throttle:.3f}, damp={damping:.3f}, "
                    f"offset={offset:.3f}, antiovr={anti_overshoot:.3f}"
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

    def force_neutral_throttle(self):
        """Force neutral throttle for 5 seconds to test response"""
        self.get_logger().info("🔴 FORCING NEUTRAL THROTTLE FOR 5 SECONDS 🔴")
        
        # Send neutral throttle 50 times (5 seconds)
        for i in range(50):
            joy_msg = Joy()
            joy_msg.axes = [0.0] * 8
            joy_msg.axes[1] = 0.0  # Neutral throttle
            joy_msg.buttons = [0] * 11
            self.joy_publisher.publish(joy_msg)
            time.sleep(0.1)
        
        self.get_logger().info("✅ NEUTRAL THROTTLE TEST COMPLETE ✅")

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