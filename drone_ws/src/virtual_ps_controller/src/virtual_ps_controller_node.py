#include <rclcpp/rclcpp.hpp>
#include <virtual_ps_controller/controller.hpp>

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("virtual_ps_controller_node");
    auto controller = std::make_shared<Controller>(node);

    controller->initialize();
    
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}