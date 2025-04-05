#ifndef VIRTUAL_PS_CONTROLLER_CONTROLLER_HPP
#define VIRTUAL_PS_CONTROLLER_CONTROLLER_HPP

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include "virtual_ps_controller/msg/button_state.hpp"
#include "virtual_ps_controller/msg/controller_state.hpp"

class Controller
{
public:
    Controller(rclcpp::Node::SharedPtr node);
    void initialize();
    void readButtonStates();
    void publishControllerState();

private:
    rclcpp::Node::SharedPtr node_;
    rclcpp::Publisher<virtual_ps_controller::msg::ControllerState>::SharedPtr controller_state_publisher_;
    virtual_ps_controller::msg::ControllerState controller_state_;
};

#endif // VIRTUAL_PS_CONTROLLER_CONTROLLER_HPP