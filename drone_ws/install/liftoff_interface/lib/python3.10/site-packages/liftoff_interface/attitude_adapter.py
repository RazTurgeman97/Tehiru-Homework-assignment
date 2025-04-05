#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point

class AttitudeAdapter(Node):
    def __init__(self):
        super().__init__('attitude_adapter')
        
        # Create a standardized publisher for attitude data
        self.attitude_pub = self.create_publisher(
            Point, 
            'drone/attitude', 
            10)
        
        # Subscribe to the telemetry/attitude topic with the correct type
        self.attitude_sub = self.create_subscription(
            Point,
            'telemetry/attitude',
            self.attitude_callback,
            10)
            
        self.get_logger().info('Attitude adapter running. Converting telemetry/attitude to drone/attitude')

    def attitude_callback(self, msg):
        """Simply republish the attitude data"""
        self.attitude_pub.publish(msg)
        self.get_logger().debug(f'Attitude: roll={msg.x:.2f}, pitch={msg.y:.2f}, yaw={msg.z:.2f}')

def main(args=None):
    rclpy.init(args=args)
    node = AttitudeAdapter()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Node stopped cleanly')
    except Exception as e:
        node.get_logger().error(f'Error in node: {str(e)}')
    finally:
        try:
            node.destroy_node()
            rclpy.shutdown()
        except Exception:
            pass

if __name__ == '__main__':
    main()