#include "virtual_ps_controller/ps_controller.hpp"
#include <linux/input.h>
#include <linux/uinput.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include "virtual_ps_controller/msg/controller_state.hpp"
#include "virtual_ps_controller/msg/button_state.hpp"

namespace virtual_ps_controller
{

PS4Controller::PS4Controller()
: Node("ps_controller"), fd_(-1)
{
  RCLCPP_INFO(get_logger(), "Initializing PS4 virtual controller");
  
  // Subscribe to joy topic
  subscription_ = this->create_subscription<sensor_msgs::msg::Joy>(
    "joy", 10, std::bind(&PS4Controller::joy_callback, this, std::placeholders::_1));

  // Add a publisher for controller state
  controller_state_pub_ = this->create_publisher<virtual_ps_controller::msg::ControllerState>(
    "controller_state", 10);
  
  // Set up the virtual device
  setup_uinput_device();
  
  RCLCPP_INFO(get_logger(), "PS4 virtual controller initialized");
}

PS4Controller::~PS4Controller()
{
  close_device();
}

void PS4Controller::setup_uinput_device()
{
  struct uinput_setup usetup;
  struct uinput_abs_setup abs_setup;
  
  // Open uinput device
  fd_ = open("/dev/uinput", O_WRONLY | O_NONBLOCK);
  if (fd_ < 0) {
    RCLCPP_ERROR(get_logger(), "Failed to open /dev/uinput");
    return;
  }

  // Enable the types of events we want to send
  ioctl(fd_, UI_SET_EVBIT, EV_KEY);
  ioctl(fd_, UI_SET_EVBIT, EV_ABS);
  ioctl(fd_, UI_SET_EVBIT, EV_SYN);

  // Enable key events for buttons
  ioctl(fd_, UI_SET_KEYBIT, BTN_SOUTH);  // Cross
  ioctl(fd_, UI_SET_KEYBIT, BTN_EAST);   // Circle
  ioctl(fd_, UI_SET_KEYBIT, BTN_NORTH);  // Triangle
  ioctl(fd_, UI_SET_KEYBIT, BTN_WEST);   // Square
  ioctl(fd_, UI_SET_KEYBIT, BTN_TL);     // L1
  ioctl(fd_, UI_SET_KEYBIT, BTN_TR);     // R1
  ioctl(fd_, UI_SET_KEYBIT, BTN_TL2);    // L2
  ioctl(fd_, UI_SET_KEYBIT, BTN_TR2);    // R2
  ioctl(fd_, UI_SET_KEYBIT, BTN_SELECT); // Share
  ioctl(fd_, UI_SET_KEYBIT, BTN_START);  // Options
  ioctl(fd_, UI_SET_KEYBIT, BTN_THUMBL); // L3
  ioctl(fd_, UI_SET_KEYBIT, BTN_THUMBR); // R3
  ioctl(fd_, UI_SET_KEYBIT, BTN_MODE);   // PS button
  ioctl(fd_, UI_SET_KEYBIT, BTN_A);      // Touchpad

  // Enable absolute axis events
  ioctl(fd_, UI_SET_ABSBIT, ABS_X);     // Left stick X
  ioctl(fd_, UI_SET_ABSBIT, ABS_Y);     // Left stick Y
  ioctl(fd_, UI_SET_ABSBIT, ABS_RX);    // Right stick X
  ioctl(fd_, UI_SET_ABSBIT, ABS_RY);    // Right stick Y
  ioctl(fd_, UI_SET_ABSBIT, ABS_Z);     // L2 trigger
  ioctl(fd_, UI_SET_ABSBIT, ABS_RZ);    // R2 trigger
  ioctl(fd_, UI_SET_ABSBIT, ABS_HAT0X); // D-pad X
  ioctl(fd_, UI_SET_ABSBIT, ABS_HAT0Y); // D-pad Y

  // Set up absolute axes
  memset(&abs_setup, 0, sizeof(abs_setup));
  
  // Left stick X
  abs_setup.code = ABS_X;
  abs_setup.absinfo.minimum = -32768;
  abs_setup.absinfo.maximum = 32767;
  abs_setup.absinfo.value = 0;
  ioctl(fd_, UI_ABS_SETUP, &abs_setup);
  
  // Left stick Y
  abs_setup.code = ABS_Y;
  abs_setup.absinfo.minimum = -32768;
  abs_setup.absinfo.maximum = 32767;
  abs_setup.absinfo.value = 0;
  ioctl(fd_, UI_ABS_SETUP, &abs_setup);
  
  // Right stick X
  abs_setup.code = ABS_RX;
  abs_setup.absinfo.minimum = -32768;
  abs_setup.absinfo.maximum = 32767;
  abs_setup.absinfo.value = 0;
  ioctl(fd_, UI_ABS_SETUP, &abs_setup);
  
  // Right stick Y
  abs_setup.code = ABS_RY;
  abs_setup.absinfo.minimum = -32768;
  abs_setup.absinfo.maximum = 32767;
  abs_setup.absinfo.value = 0;
  ioctl(fd_, UI_ABS_SETUP, &abs_setup);
  
  // L2 trigger
  abs_setup.code = ABS_Z;
  abs_setup.absinfo.minimum = 0;
  abs_setup.absinfo.maximum = 255;
  abs_setup.absinfo.value = 0;
  ioctl(fd_, UI_ABS_SETUP, &abs_setup);
  
  // R2 trigger
  abs_setup.code = ABS_RZ;
  abs_setup.absinfo.minimum = 0;
  abs_setup.absinfo.maximum = 255;
  abs_setup.absinfo.value = 0;
  ioctl(fd_, UI_ABS_SETUP, &abs_setup);
  
  // D-pad X
  abs_setup.code = ABS_HAT0X;
  abs_setup.absinfo.minimum = -1;
  abs_setup.absinfo.maximum = 1;
  abs_setup.absinfo.value = 0;
  ioctl(fd_, UI_ABS_SETUP, &abs_setup);
  
  // D-pad Y
  abs_setup.code = ABS_HAT0Y;
  abs_setup.absinfo.minimum = -1;
  abs_setup.absinfo.maximum = 1;
  abs_setup.absinfo.value = 0;
  ioctl(fd_, UI_ABS_SETUP, &abs_setup);

  // Set up device
  memset(&usetup, 0, sizeof(usetup));
  usetup.id.bustype = BUS_USB;
  usetup.id.vendor = 0x054c;  // Sony
  usetup.id.product = 0x05c4; // DualShock 4
  usetup.id.version = 0x0111;
  strcpy(usetup.name, "Sony DualShock 4 Virtual Controller");

  ioctl(fd_, UI_DEV_SETUP, &usetup);
  ioctl(fd_, UI_DEV_CREATE);
  
  RCLCPP_INFO(get_logger(), "Virtual PS4 controller device created");
}

void PS4Controller::joy_callback(const sensor_msgs::msg::Joy::SharedPtr msg)
{
  if (fd_ < 0) {
    RCLCPP_ERROR(get_logger(), "Device not initialized");
    return;
  }
  
  // Process joystick axes
  if (msg->axes.size() >= 8) {
    // Left stick X and Y (invert Y axis)
    send_abs_event(ABS_X, static_cast<int>(msg->axes[LEFT_STICK_X] * 32767.0f));
    send_abs_event(ABS_Y, static_cast<int>(-msg->axes[LEFT_STICK_Y] * 32767.0f));
    
    // Right stick X and Y (invert Y axis)
    send_abs_event(ABS_RX, static_cast<int>(msg->axes[RIGHT_STICK_X] * 32767.0f));
    send_abs_event(ABS_RY, static_cast<int>(-msg->axes[RIGHT_STICK_Y] * 32767.0f));
    
    // L2 and R2 triggers (convert -1 to 1 range to 0-255)
    send_abs_event(ABS_Z, static_cast<int>((msg->axes[L2_AXIS] + 1.0f) * 127.5f));
    send_abs_event(ABS_RZ, static_cast<int>((msg->axes[R2_AXIS] + 1.0f) * 127.5f));
    
    // D-pad
    send_abs_event(ABS_HAT0X, static_cast<int>(msg->axes[DPAD_X]));
    send_abs_event(ABS_HAT0Y, static_cast<int>(-msg->axes[DPAD_Y])); // Invert Y
  }
  
  // Process buttons
  if (msg->buttons.size() >= 13) {
    send_key_event(BTN_SOUTH, msg->buttons[CROSS]);
    send_key_event(BTN_EAST, msg->buttons[CIRCLE]);
    send_key_event(BTN_NORTH, msg->buttons[TRIANGLE]);
    send_key_event(BTN_WEST, msg->buttons[SQUARE]);
    send_key_event(BTN_TL, msg->buttons[L1]);
    send_key_event(BTN_TR, msg->buttons[R1]);
    send_key_event(BTN_TL2, msg->buttons[L2_BTN]);
    send_key_event(BTN_TR2, msg->buttons[R2_BTN]);
    send_key_event(BTN_SELECT, msg->buttons[SHARE]);
    send_key_event(BTN_START, msg->buttons[OPTIONS]);
    send_key_event(BTN_THUMBL, msg->buttons[L3]);
    send_key_event(BTN_THUMBR, msg->buttons[R3]);
    send_key_event(BTN_MODE, msg->buttons[PS]);
    
    // Touchpad button if available
    if (msg->buttons.size() > TOUCHPAD) {
      send_key_event(BTN_A, msg->buttons[TOUCHPAD]);
    }
  }
  
  // Sync events
  sync_events();
  
  // NEW: Publish controller state
  auto controller_state = virtual_ps_controller::msg::ControllerState();
  controller_state.header = msg->header;
  controller_state.axes = msg->axes;
  
  // Convert joy buttons to ButtonState messages
  for (size_t i = 0; i < msg->buttons.size(); i++) {
    auto button_state = virtual_ps_controller::msg::ButtonState();
    button_state.button_id = i;
    button_state.pressed = (msg->buttons[i] == 1);
    controller_state.buttons.push_back(button_state);
  }
  
  controller_state_pub_->publish(controller_state);
}

void PS4Controller::send_abs_event(int code, int value)
{
  struct input_event ev;
  memset(&ev, 0, sizeof(ev));
  
  ev.type = EV_ABS;
  ev.code = code;
  ev.value = value;
  
  if (write(fd_, &ev, sizeof(ev)) < 0) {
    RCLCPP_ERROR(get_logger(), "Failed to send ABS event");
  }
}

void PS4Controller::send_key_event(int code, int value)
{
  struct input_event ev;
  memset(&ev, 0, sizeof(ev));
  
  ev.type = EV_KEY;
  ev.code = code;
  ev.value = value;
  
  if (write(fd_, &ev, sizeof(ev)) < 0) {
    RCLCPP_ERROR(get_logger(), "Failed to send KEY event");
  }
}

void PS4Controller::sync_events()
{
  struct input_event ev;
  memset(&ev, 0, sizeof(ev));
  
  ev.type = EV_SYN;
  ev.code = SYN_REPORT;
  ev.value = 0;
  
  if (write(fd_, &ev, sizeof(ev)) < 0) {
    RCLCPP_ERROR(get_logger(), "Failed to send SYN event");
  }
}

void PS4Controller::close_device()
{
  if (fd_ >= 0) {
    ioctl(fd_, UI_DEV_DESTROY);
    close(fd_);
    fd_ = -1;
    RCLCPP_INFO(get_logger(), "Virtual PS4 controller device closed");
  }
}

}  // namespace virtual_ps_controller