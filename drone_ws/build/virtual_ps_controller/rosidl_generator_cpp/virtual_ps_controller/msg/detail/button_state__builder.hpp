// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from virtual_ps_controller:msg/ButtonState.idl
// generated code does not contain a copyright notice

#ifndef VIRTUAL_PS_CONTROLLER__MSG__DETAIL__BUTTON_STATE__BUILDER_HPP_
#define VIRTUAL_PS_CONTROLLER__MSG__DETAIL__BUTTON_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "virtual_ps_controller/msg/detail/button_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace virtual_ps_controller
{

namespace msg
{

namespace builder
{

class Init_ButtonState_pressed
{
public:
  explicit Init_ButtonState_pressed(::virtual_ps_controller::msg::ButtonState & msg)
  : msg_(msg)
  {}
  ::virtual_ps_controller::msg::ButtonState pressed(::virtual_ps_controller::msg::ButtonState::_pressed_type arg)
  {
    msg_.pressed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::virtual_ps_controller::msg::ButtonState msg_;
};

class Init_ButtonState_button_id
{
public:
  Init_ButtonState_button_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ButtonState_pressed button_id(::virtual_ps_controller::msg::ButtonState::_button_id_type arg)
  {
    msg_.button_id = std::move(arg);
    return Init_ButtonState_pressed(msg_);
  }

private:
  ::virtual_ps_controller::msg::ButtonState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::virtual_ps_controller::msg::ButtonState>()
{
  return virtual_ps_controller::msg::builder::Init_ButtonState_button_id();
}

}  // namespace virtual_ps_controller

#endif  // VIRTUAL_PS_CONTROLLER__MSG__DETAIL__BUTTON_STATE__BUILDER_HPP_
