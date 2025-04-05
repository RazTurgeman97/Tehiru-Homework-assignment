#include "virtual_ps_controller/ps_controller.hpp"
#include <rclcpp/rclcpp.hpp>
#include <memory>

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  
  auto node = std::make_shared<virtual_ps_controller::PS4Controller>();
  
  rclcpp::spin(node);
  
  rclcpp::shutdown();
  return 0;
}