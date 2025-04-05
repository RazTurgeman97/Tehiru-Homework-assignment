import rclpy
from rclpy.node import Node
import socket
import struct
from std_msgs.msg import Float32, Float32MultiArray

class LiftoffTelemetryNode(Node):
    def __init__(self):
        super().__init__('liftoff_telemetry_node')

        # Parameters for UDP communication
        self.declare_parameter('udp_ip', '127.0.0.1')
        self.declare_parameter('udp_port', 9001)

        self.udp_ip = self.get_parameter('udp_ip').value
        self.udp_port = self.get_parameter('udp_port').value

        # Set up the UDP socket
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.bind((self.udp_ip, self.udp_port))
        self.get_logger().info(f"Listening for telemetry data on {self.udp_ip}:{self.udp_port}")

        # Publishers for telemetry data
        self.timestamp_pub = self.create_publisher(Float32, 'telemetry/timestamp', 10)
        self.position_pub = self.create_publisher(Float32MultiArray, 'telemetry/position', 10)
        self.attitude_pub = self.create_publisher(Float32MultiArray, 'telemetry/attitude', 10)

        # Timer to process incoming data
        self.timer = self.create_timer(0.01, self.receive_data)

    def receive_data(self):
        try:
            data, _ = self.sock.recvfrom(1024)  # Buffer size is 1024 bytes

            # Example: Parse the data (assuming the format matches the Liftoff telemetry)
            # Adjust the unpacking format based on your StreamFormat configuration
            unpacked_data = struct.unpack('f3f4f', data)

            # Publish timestamp
            timestamp_msg = Float32()
            timestamp_msg.data = unpacked_data[0]
            self.timestamp_pub.publish(timestamp_msg)

            # Publish position
            position_msg = Float32MultiArray()
            position_msg.data = unpacked_data[1:4]
            self.position_pub.publish(position_msg)

            # Publish attitude
            attitude_msg = Float32MultiArray()
            attitude_msg.data = unpacked_data[4:8]
            self.attitude_pub.publish(attitude_msg)

        except Exception as e:
            self.get_logger().error(f"Error receiving data: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = LiftoffTelemetryNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()