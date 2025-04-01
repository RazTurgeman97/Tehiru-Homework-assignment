import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu

class SensorListener(Node):
    def __init__(self):
        super().__init__('sensor_listener')
        self.subscription = self.create_subscription(
            Imu,
            'imu/data',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):
        self.get_logger().info(f'IMU data: {msg.orientation}')

def main(args=None):
    rclpy.init(args=args)
    node = SensorListener()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()