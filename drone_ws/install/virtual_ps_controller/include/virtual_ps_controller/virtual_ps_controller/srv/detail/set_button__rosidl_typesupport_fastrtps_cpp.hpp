// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from virtual_ps_controller:srv/SetButton.idl
// generated code does not contain a copyright notice

#ifndef VIRTUAL_PS_CONTROLLER__SRV__DETAIL__SET_BUTTON__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define VIRTUAL_PS_CONTROLLER__SRV__DETAIL__SET_BUTTON__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "virtual_ps_controller/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "virtual_ps_controller/srv/detail/set_button__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace virtual_ps_controller
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_virtual_ps_controller
cdr_serialize(
  const virtual_ps_controller::srv::SetButton_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_virtual_ps_controller
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  virtual_ps_controller::srv::SetButton_Request & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_virtual_ps_controller
get_serialized_size(
  const virtual_ps_controller::srv::SetButton_Request & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_virtual_ps_controller
max_serialized_size_SetButton_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace virtual_ps_controller

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_virtual_ps_controller
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, virtual_ps_controller, srv, SetButton_Request)();

#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "virtual_ps_controller/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
// already included above
// #include "virtual_ps_controller/srv/detail/set_button__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// already included above
// #include "fastcdr/Cdr.h"

namespace virtual_ps_controller
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_virtual_ps_controller
cdr_serialize(
  const virtual_ps_controller::srv::SetButton_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_virtual_ps_controller
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  virtual_ps_controller::srv::SetButton_Response & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_virtual_ps_controller
get_serialized_size(
  const virtual_ps_controller::srv::SetButton_Response & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_virtual_ps_controller
max_serialized_size_SetButton_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace virtual_ps_controller

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_virtual_ps_controller
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, virtual_ps_controller, srv, SetButton_Response)();

#ifdef __cplusplus
}
#endif

#include "rmw/types.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "virtual_ps_controller/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_virtual_ps_controller
const rosidl_service_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, virtual_ps_controller, srv, SetButton)();

#ifdef __cplusplus
}
#endif

#endif  // VIRTUAL_PS_CONTROLLER__SRV__DETAIL__SET_BUTTON__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
