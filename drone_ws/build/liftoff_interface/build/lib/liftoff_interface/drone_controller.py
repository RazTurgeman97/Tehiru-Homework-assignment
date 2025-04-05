import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist, Point

class DroneController(Node):
    def __init__(self):
        super().__init__('drone_controller')
        self.publisher_ = self.create_publisher(Twist, 'cmd_vel', 10)
        self.timer = self.create_timer(0.1, self.timer_callback)

        # Subscriptions
        self.target_subscription = self.create_subscription(
            Point,
            'target_coordinates',
            self.target_callback,
            10
        )
        self.position_subscription = self.create_subscription(
            Point,
            'telemetry/position',
            self.position_callback,
            10
        )
        self.obstacle_subscription = self.create_subscription(
            Point,
            'obstacle_distance',
            self.obstacle_callback,
            10
        )

        # Initialize variables
        self.current_position = Point()
        self.target_position = Point()
        self.obstacle_distance = Point()
        self.target_received = False
        self.navigation_active = False

        # PID gains
        self.Kp = 0.5
        self.Ki = 0.1
        self.Kd = 0.2

        # Error tracking
        self.prev_error = Point()
        self.integral_error = Point()

    def position_callback(self, msg):
        self.current_position = msg
        # self.get_logger().info(f"Current position: ({msg.x}, {msg.y}, {msg.z})")

    def target_callback(self, msg):
        self.target_position = msg
        self.target_received = True
        # self.get_logger().info(f"Received target: ({msg.x}, {msg.y}, {msg.z})")

    def obstacle_callback(self, msg):
        self.obstacle_distance = msg
        # self.get_logger().info(f"Obstacle distances: ({msg.x}, {msg.y}, {msg.z})")

    def timer_callback(self):
        if not self.target_received or not self.navigation_active:
            return  # No target to navigate to or navigation not active

        # Calculate errors
        error_x = self.target_position.x - self.current_position.x
        error_y = self.target_position.y - self.current_position.y
        error_z = self.target_position.z - self.current_position.z

        # Calculate integral errors
        self.integral_error.x += error_x
        self.integral_error.y += error_y
        self.integral_error.z += error_z

        # Calculate derivative errors
        derivative_error_x = error_x - self.prev_error.x
        derivative_error_y = error_y - self.prev_error.y
        derivative_error_z = error_z - self.prev_error.z

        # PID control
        msg = Twist()
        msg.linear.x = (self.Kp * error_x +
                        self.Ki * self.integral_error.x +
                        self.Kd * derivative_error_x)
        msg.linear.y = (self.Kp * error_y +
                        self.Ki * self.integral_error.y +
                        self.Kd * derivative_error_y)
        msg.linear.z = (self.Kp * error_z +
                        self.Ki * self.integral_error.z +
                        self.Kd * derivative_error_z)

        # Update previous error
        self.prev_error.x = error_x
        self.prev_error.y = error_y
        self.prev_error.z = error_z

        # Obstacle avoidance
        obstacle_threshold = 1.0
        if self.obstacle_distance.x < obstacle_threshold:
            msg.linear.x = 0.0
        if self.obstacle_distance.y < obstacle_threshold:
            msg.linear.y = 0.0
        if self.obstacle_distance.z < obstacle_threshold:
            msg.linear.z = 0.0

        # Stop if within threshold
        threshold = 0.1
        if abs(error_x) < threshold and abs(error_y) < threshold and abs(error_z) < threshold:
            self.get_logger().info("Target reached!")
            msg.linear.x = 0.0
            msg.linear.y = 0.0
            msg.linear.z = 0.0
            self.target_received = False  # Stop navigating

        # Publish velocity command
        self.publisher_.publish(msg)
        self.get_logger().info(f"Published cmd_vel: {msg}")

    def handle_request(self, request, response):
        if request.start:
            if not self.navigation_active:
                self.navigation_active = True
                response.status = "Executing"
                response.error = ""
                self.get_logger().info("Navigation started.")
            else:
                response.status = "Already Executing"
                response.error = ""
        else:
            if self.navigation_active:
                self.navigation_active = False
                response.status = "Stopped"
                response.error = ""
                self.get_logger().info("Navigation stopped.")
            else:
                response.status = "Already Stopped"
                response.error = ""

        return response

def main(args=None):
    rclpy.init(args=args)
    node = DroneController()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()