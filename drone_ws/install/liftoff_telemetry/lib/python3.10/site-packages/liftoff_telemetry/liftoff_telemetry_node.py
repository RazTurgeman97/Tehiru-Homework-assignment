import rclpy
from rclpy.node import Node
import socket
import struct
from std_msgs.msg import Float32, Float32MultiArray
from geometry_msgs.msg import Point  # Import Point message type

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
        
        # Use Point message for position
        self.position_pub = self.create_publisher(Point, 'telemetry/position', 10)
        
        # Use Point message for attitude
        self.attitude_pub = self.create_publisher(Point, 'telemetry/attitude', 10)
        
        self.velocity_pub = self.create_publisher(Float32MultiArray, 'telemetry/velocity', 10)
        self.gyro_pub = self.create_publisher(Float32MultiArray, 'telemetry/gyro', 10)
        self.input_pub = self.create_publisher(Float32MultiArray, 'telemetry/input', 10)
        self.battery_voltage_pub = self.create_publisher(Float32, 'telemetry/battery_voltage', 10)
        self.battery_percentage_pub = self.create_publisher(Float32, 'telemetry/battery_percentage', 10)
        self.motor_rpm_pub = self.create_publisher(Float32MultiArray, 'telemetry/motor_rpm', 10)

        # Timer to process incoming data
        self.timer = self.create_timer(0.01, self.receive_data)

    def receive_data(self):
        try:
            data, _ = self.sock.recvfrom(1024)  # Buffer size is 1024 bytes
            self.get_logger().debug(f"Raw data received: {data}")
            self.get_logger().debug(f"Raw data (hex): {data.hex()}")
            self.get_logger().debug(f"Received data size: {len(data)} bytes")

            # Validate data size
            expected_size = 97  # Adjusted to match the actual data size
            if len(data) != expected_size:
                self.get_logger().error(f"Unexpected data size: {len(data)} (expected {expected_size})")
                self.get_logger().debug(f"Raw data (hex): {data.hex()}")
                return

            # Parse the data
            unpacked_data = struct.unpack('=f3f4f3f3f4f2fB4f', data)  # Added '=' to disable padding
            self.get_logger().debug(f"Unpacked data: {unpacked_data}")

            # Publish timestamp
            timestamp_msg = Float32()
            timestamp_msg.data = unpacked_data[0]
            self.timestamp_pub.publish(timestamp_msg)
            self.get_logger().debug(f"Published timestamp: {timestamp_msg.data}")

            # Publish position as Point
            position_msg = Point()
            position_msg.x = unpacked_data[1]
            position_msg.y = unpacked_data[2]
            position_msg.z = unpacked_data[3]
            self.position_pub.publish(position_msg)
            self.get_logger().debug(f"Published position: x={position_msg.x}, y={position_msg.y}, z={position_msg.z}")

            # Publish attitude as Point
            attitude_msg = Point()
            attitude_msg.x = unpacked_data[4]  # Roll
            attitude_msg.y = unpacked_data[5]  # Pitch
            attitude_msg.z = unpacked_data[6]  # Yaw
            self.attitude_pub.publish(attitude_msg)
            self.get_logger().debug(f"Published attitude: roll={attitude_msg.x}, pitch={attitude_msg.y}, yaw={attitude_msg.z}")

            # Publish velocity
            velocity_msg = Float32MultiArray()
            velocity_msg.data = unpacked_data[8:11]
            self.velocity_pub.publish(velocity_msg)
            self.get_logger().debug(f"Published velocity: {velocity_msg.data}")

            # Publish gyro
            gyro_msg = Float32MultiArray()
            gyro_msg.data = unpacked_data[11:14]
            self.gyro_pub.publish(gyro_msg)
            self.get_logger().debug(f"Published gyro: {gyro_msg.data}")

            # Publish input
            input_msg = Float32MultiArray()
            input_msg.data = unpacked_data[14:18]
            self.input_pub.publish(input_msg)
            self.get_logger().debug(f"Published input: {input_msg.data}")

            # Publish battery voltage
            battery_voltage_msg = Float32()
            battery_voltage_msg.data = unpacked_data[18]
            self.battery_voltage_pub.publish(battery_voltage_msg)
            self.get_logger().debug(f"Published battery voltage: {battery_voltage_msg.data}")

            # Publish battery percentage
            battery_percentage_msg = Float32()
            battery_percentage_msg.data = unpacked_data[19]
            self.battery_percentage_pub.publish(battery_percentage_msg)
            self.get_logger().debug(f"Published battery percentage: {battery_percentage_msg.data}")

            # Publish motor RPM
            motor_count = unpacked_data[20]
            motor_rpm_msg = Float32MultiArray()
            motor_rpm_msg.data = unpacked_data[21:21 + motor_count]
            self.motor_rpm_pub.publish(motor_rpm_msg)
            self.get_logger().debug(f"Published motor RPM: {motor_rpm_msg.data}")

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