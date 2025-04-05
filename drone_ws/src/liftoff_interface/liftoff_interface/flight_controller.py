#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from std_msgs.msg import Float32MultiArray, Bool
from geometry_msgs.msg import Point, Twist
import time

class FlightController(Node):
    def __init__(self):
        super().__init__('flight_controller')
        
        # Publishers
        self.joy_publisher = self.create_publisher(Joy, 'joy', 10)
        self.cmd_vel_publisher = self.create_publisher(Twist, 'cmd_vel', 10)
        
        # Subscribers
        self.controller_sub = self.create_subscription(
            Joy,
            'controller_state',
            self.controller_callback,
            10)
        
        self.attitude_sub = self.create_subscription(
            Point,
            'telemetry/attitude',  # Subscribe to the original topic
            self.attitude_callback,
            10)
            
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
            
        self.drone_armed_sub = self.create_subscription(
            Bool,
            'drone/armed',
            self.armed_callback,
            10)
        
        # Initialize state variables
        self.drone_armed = False
        self.position = None
        self.velocity = None
        self.attitude = None
        self.home_position = None
        
        # Controller inputs
        self.throttle = 0.0  # Left stick up/down
        self.yaw = 0.0       # Left stick left/right
        self.pitch = 0.0     # Right stick up/down
        self.roll = 0.0      # Right stick left/right
        
        # Other state
        self.altitude_control_active = False
        
        # Timer for telemetry reporting
        self.timer = self.create_timer(1.0, self.report_telemetry)
        
        self.get_logger().info('Flight controller started')
    
    def armed_callback(self, msg):
        """Process drone armed status updates"""
        was_armed = self.drone_armed
        self.drone_armed = msg.data
        
        if self.drone_armed and not was_armed:
            self.get_logger().info('Drone is now armed')
        elif not self.drone_armed and was_armed:
            self.get_logger().info('Drone is now disarmed')
    
    def attitude_callback(self, msg):
        """Process attitude updates"""
        self.attitude = msg
    
    def position_callback(self, msg):
        """Process position updates"""
        self.position = msg
        
        # Set home position if not already set and drone is armed
        if self.drone_armed and self.home_position is None:
            self.home_position = Point()
            self.home_position.x = msg.x
            self.home_position.y = msg.y
            self.home_position.z = msg.z
            self.get_logger().info(f'Home position set: x={msg.x:.2f}, y={msg.y:.2f}, z={msg.z:.2f}')
    
    def velocity_callback(self, msg):
        """Process velocity updates"""
        self.velocity = msg.data
    
    def controller_callback(self, msg):
        """Process controller inputs"""
        if not self.drone_armed or len(msg.axes) < 4:
            return
            
        # Store controller values for non-throttle axes
        # Altitude is handled by the altitude_controller node
        self.yaw = msg.axes[0]       # Left stick X
        # Skip throttle processing - handled by altitude controller
        self.roll = msg.axes[2]      # Right stick X
        self.pitch = msg.axes[3]     # Right stick Y
        
        # Altitude control is handled separately
        # We only need to pass the other controls
        
        # Create a Joy message with stick positions other than throttle
        joy_msg = Joy()
        joy_msg.axes = list(msg.axes)  # Copy all axes values
        
        # Set throttle to 0 as it's handled by altitude controller
        # The altitude controller will mix its commands with ours
        joy_msg.axes[1] = 0.0
        
        joy_msg.buttons = list(msg.buttons)  # Copy all button values
        
        # Publish to joy topic
        self.joy_publisher.publish(joy_msg)
        
        # Also publish to cmd_vel for diagnostic purposes
        cmd = Twist()
        cmd.angular.z = self.yaw
        cmd.linear.x = self.pitch
        cmd.linear.y = self.roll
        self.cmd_vel_publisher.publish(cmd)
    
    def report_telemetry(self):
        """Periodically report telemetry information"""
        if not self.drone_armed:
            return
            
        # Report position if available
        if self.position and self.home_position:
            rel_x = self.position.x - self.home_position.x
            rel_y = self.position.y - self.home_position.y
            rel_z = self.position.z - self.home_position.z
            self.get_logger().info(
                f'Position: rel=({rel_x:.1f}, {rel_y:.1f}, {rel_z:.1f}), '
                f'height={rel_y:.1f}m'
            )
        
        # Report attitude if available
        if self.attitude:
            self.get_logger().info(
                f'Attitude: roll={self.attitude.x:.1f}°, '
                f'pitch={self.attitude.y:.1f}°, '
                f'yaw={self.attitude.z:.1f}°'
            )
        
        # Report velocity if available
        if self.velocity and len(self.velocity) >= 3:
            self.get_logger().info(
                f'Velocity: vx={self.velocity[0]:.1f}, '
                f'vy={self.velocity[1]:.1f}, '
                f'vz={self.velocity[2]:.1f}'
            )

def main(args=None):
    rclpy.init(args=args)
    node = FlightController()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Node stopped cleanly')
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()