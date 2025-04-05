import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
import random

class MockObstaclePublisher(Node):
    def __init__(self):
        super().__init__('mock_obstacle_publisher')
        self.publisher_ = self.create_publisher(Point, 'obstacle_distance', 10)
        self.timer = self.create_timer(0.5, self.timer_callback)  # Publish every 0.5 seconds

    def timer_callback(self):
        # Simulate obstacle distances
        msg = Point()
        msg.x = random.uniform(0.5, 2.0)  # Random distance in meters for x-axis
        msg.y = random.uniform(0.5, 2.0)  # Random distance in meters for y-axis
        msg.z = random.uniform(0.5, 2.0)  # Random distance in meters for z-axis

        self.publisher_.publish(msg)
        # self.get_logger().info(f"Published obstacle distances: ({msg.x:.2f}, {msg.y:.2f}, {msg.z:.2f})")

def main(args=None):
    rclpy.init(args=args)
    node = MockObstaclePublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()