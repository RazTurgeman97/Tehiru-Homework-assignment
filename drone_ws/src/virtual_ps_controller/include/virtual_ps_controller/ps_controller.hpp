#ifndef VIRTUAL_PS_CONTROLLER__PS_CONTROLLER_HPP_
#define VIRTUAL_PS_CONTROLLER__PS_CONTROLLER_HPP_

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joy.hpp>
#include <linux/uinput.h>
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <memory>
#include "virtual_ps_controller/msg/controller_state.hpp"

namespace virtual_ps_controller
{

class PS4Controller : public rclcpp::Node
{
public:
  PS4Controller();
  virtual ~PS4Controller();

private:
  // Subscriber callback
  void joy_callback(const sensor_msgs::msg::Joy::SharedPtr msg);

  // Set up input device
  void setup_uinput_device();
  
  // Send input events
  void send_abs_event(int code, int value);
  void send_key_event(int code, int value);
  void sync_events();
  
  // Close the device
  void close_device();

  // PS4 button mappings
  static constexpr int CROSS = 0;
  static constexpr int CIRCLE = 1;
  static constexpr int TRIANGLE = 2;
  static constexpr int SQUARE = 3;
  static constexpr int L1 = 4;
  static constexpr int R1 = 5;
  static constexpr int L2_BTN = 6;
  static constexpr int R2_BTN = 7;
  static constexpr int SHARE = 8;
  static constexpr int OPTIONS = 9;
  static constexpr int L3 = 10;
  static constexpr int R3 = 11;
  static constexpr int PS = 12;
  static constexpr int TOUCHPAD = 13;

  // PS4 axes mappings
  static constexpr int LEFT_STICK_X = 0;
  static constexpr int LEFT_STICK_Y = 1;
  static constexpr int L2_AXIS = 2;
  static constexpr int RIGHT_STICK_X = 3;
  static constexpr int RIGHT_STICK_Y = 4;
  static constexpr int R2_AXIS = 5;
  static constexpr int DPAD_X = 6;
  static constexpr int DPAD_Y = 7;

  // Member variables
  rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr subscription_;
  int fd_;  // File descriptor for uinput device

  // Controller state publisher
  rclcpp::Publisher<virtual_ps_controller::msg::ControllerState>::SharedPtr controller_state_pub_;
};

}  // namespace virtual_ps_controller

#endif  // VIRTUAL_PS_CONTROLLER__PS_CONTROLLER_HPP_