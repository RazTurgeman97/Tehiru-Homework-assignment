// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from virtual_ps_controller:srv/SetButton.idl
// generated code does not contain a copyright notice

#ifndef VIRTUAL_PS_CONTROLLER__SRV__DETAIL__SET_BUTTON__BUILDER_HPP_
#define VIRTUAL_PS_CONTROLLER__SRV__DETAIL__SET_BUTTON__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "virtual_ps_controller/srv/detail/set_button__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace virtual_ps_controller
{

namespace srv
{

namespace builder
{

class Init_SetButton_Request_pressed
{
public:
  explicit Init_SetButton_Request_pressed(::virtual_ps_controller::srv::SetButton_Request & msg)
  : msg_(msg)
  {}
  ::virtual_ps_controller::srv::SetButton_Request pressed(::virtual_ps_controller::srv::SetButton_Request::_pressed_type arg)
  {
    msg_.pressed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::virtual_ps_controller::srv::SetButton_Request msg_;
};

class Init_SetButton_Request_button_id
{
public:
  Init_SetButton_Request_button_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetButton_Request_pressed button_id(::virtual_ps_controller::srv::SetButton_Request::_button_id_type arg)
  {
    msg_.button_id = std::move(arg);
    return Init_SetButton_Request_pressed(msg_);
  }

private:
  ::virtual_ps_controller::srv::SetButton_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::virtual_ps_controller::srv::SetButton_Request>()
{
  return virtual_ps_controller::srv::builder::Init_SetButton_Request_button_id();
}

}  // namespace virtual_ps_controller


namespace virtual_ps_controller
{

namespace srv
{

namespace builder
{

class Init_SetButton_Response_message
{
public:
  explicit Init_SetButton_Response_message(::virtual_ps_controller::srv::SetButton_Response & msg)
  : msg_(msg)
  {}
  ::virtual_ps_controller::srv::SetButton_Response message(::virtual_ps_controller::srv::SetButton_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::virtual_ps_controller::srv::SetButton_Response msg_;
};

class Init_SetButton_Response_success
{
public:
  Init_SetButton_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetButton_Response_message success(::virtual_ps_controller::srv::SetButton_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SetButton_Response_message(msg_);
  }

private:
  ::virtual_ps_controller::srv::SetButton_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::virtual_ps_controller::srv::SetButton_Response>()
{
  return virtual_ps_controller::srv::builder::Init_SetButton_Response_success();
}

}  // namespace virtual_ps_controller

#endif  // VIRTUAL_PS_CONTROLLER__SRV__DETAIL__SET_BUTTON__BUILDER_HPP_
