// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from liftoff_utils:srv/TargetNavigation.idl
// generated code does not contain a copyright notice

#ifndef LIFTOFF_UTILS__SRV__DETAIL__TARGET_NAVIGATION__BUILDER_HPP_
#define LIFTOFF_UTILS__SRV__DETAIL__TARGET_NAVIGATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "liftoff_utils/srv/detail/target_navigation__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace liftoff_utils
{

namespace srv
{

namespace builder
{

class Init_TargetNavigation_Request_start
{
public:
  Init_TargetNavigation_Request_start()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::liftoff_utils::srv::TargetNavigation_Request start(::liftoff_utils::srv::TargetNavigation_Request::_start_type arg)
  {
    msg_.start = std::move(arg);
    return std::move(msg_);
  }

private:
  ::liftoff_utils::srv::TargetNavigation_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::liftoff_utils::srv::TargetNavigation_Request>()
{
  return liftoff_utils::srv::builder::Init_TargetNavigation_Request_start();
}

}  // namespace liftoff_utils


namespace liftoff_utils
{

namespace srv
{

namespace builder
{

class Init_TargetNavigation_Response_error
{
public:
  explicit Init_TargetNavigation_Response_error(::liftoff_utils::srv::TargetNavigation_Response & msg)
  : msg_(msg)
  {}
  ::liftoff_utils::srv::TargetNavigation_Response error(::liftoff_utils::srv::TargetNavigation_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::liftoff_utils::srv::TargetNavigation_Response msg_;
};

class Init_TargetNavigation_Response_status
{
public:
  Init_TargetNavigation_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TargetNavigation_Response_error status(::liftoff_utils::srv::TargetNavigation_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_TargetNavigation_Response_error(msg_);
  }

private:
  ::liftoff_utils::srv::TargetNavigation_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::liftoff_utils::srv::TargetNavigation_Response>()
{
  return liftoff_utils::srv::builder::Init_TargetNavigation_Response_status();
}

}  // namespace liftoff_utils

#endif  // LIFTOFF_UTILS__SRV__DETAIL__TARGET_NAVIGATION__BUILDER_HPP_
