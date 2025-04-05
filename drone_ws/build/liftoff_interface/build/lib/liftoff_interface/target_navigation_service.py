import rclpy
from rclpy.node import Node
from liftoff_utils.srv import TargetNavigation

class TargetNavigationService(Node):
    def __init__(self):
        super().__init__('target_navigation_service')
        self.srv = self.create_service(TargetNavigation, 'target_navigation', self.handle_request)
        self.get_logger().info("Target Navigation Service is ready.")

    def handle_request(self, request, response):
        if request.start:
            self.get_logger().info("Navigation started.")
            response.status = "Executing"
            response.error = ""
        else:
            self.get_logger().info("Navigation stopped.")
            response.status = "Stopped"
            response.error = ""
        return response

def main(args=None):
    rclpy.init(args=args)
    node = TargetNavigationService()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()