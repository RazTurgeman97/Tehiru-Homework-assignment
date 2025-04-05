// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from virtual_ps_controller:msg/ControllerState.idl
// generated code does not contain a copyright notice

#ifndef VIRTUAL_PS_CONTROLLER__MSG__DETAIL__CONTROLLER_STATE__BUILDER_HPP_
#define VIRTUAL_PS_CONTROLLER__MSG__DETAIL__CONTROLLER_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "virtual_ps_controller/msg/detail/controller_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace virtual_ps_controller
{

namespace msg
{

namespace builder
{

class Init_ControllerState_axes
{
public:
  explicit Init_ControllerState_axes(::virtual_ps_controller::msg::ControllerState & msg)
  : msg_(msg)
  {}
  ::virtual_ps_controller::msg::ControllerState axes(::virtual_ps_controller::msg::ControllerState::_axes_type arg)
  {
    msg_.axes = std::move(arg);
    return std::move(msg_);
  }

private:
  ::virtual_ps_controller::msg::ControllerState msg_;
};

class Init_ControllerState_buttons
{
public:
  explicit Init_ControllerState_buttons(::virtual_ps_controller::msg::ControllerState & msg)
  : msg_(msg)
  {}
  Init_ControllerState_axes buttons(::virtual_ps_controller::msg::ControllerState::_buttons_type arg)
  {
    msg_.buttons = std::move(arg);
    return Init_ControllerState_axes(msg_);
  }

private:
  ::virtual_ps_controller::msg::ControllerState msg_;
};

class Init_ControllerState_header
{
public:
  Init_ControllerState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ControllerState_buttons header(::virtual_ps_controller::msg::ControllerState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ControllerState_buttons(msg_);
  }

private:
  ::virtual_ps_controller::msg::ControllerState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::virtual_ps_controller::msg::ControllerState>()
{
  return virtual_ps_controller::msg::builder::Init_ControllerState_header();
}

}  // namespace virtual_ps_controller

#endif  // VIRTUAL_PS_CONTROLLER__MSG__DETAIL__CONTROLLER_STATE__BUILDER_HPP_
