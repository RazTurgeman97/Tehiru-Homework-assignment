// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from virtual_ps_controller:msg/ControllerState.idl
// generated code does not contain a copyright notice
#include "virtual_ps_controller/msg/detail/controller_state__rosidl_typesupport_fastrtps_cpp.hpp"
#include "virtual_ps_controller/msg/detail/controller_state__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs

namespace virtual_ps_controller
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const virtual_ps_controller::msg::ButtonState &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  virtual_ps_controller::msg::ButtonState &);
size_t get_serialized_size(
  const virtual_ps_controller::msg::ButtonState &,
  size_t current_alignment);
size_t
max_serialized_size_ButtonState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace virtual_ps_controller


namespace virtual_ps_controller
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_virtual_ps_controller
cdr_serialize(
  const virtual_ps_controller::msg::ControllerState & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: buttons
  {
    size_t size = ros_message.buttons.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      virtual_ps_controller::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.buttons[i],
        cdr);
    }
  }
  // Member: axes
  {
    cdr << ros_message.axes;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_virtual_ps_controller
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  virtual_ps_controller::msg::ControllerState & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: buttons
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.buttons.resize(size);
    for (size_t i = 0; i < size; i++) {
      virtual_ps_controller::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.buttons[i]);
    }
  }

  // Member: axes
  {
    cdr >> ros_message.axes;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_virtual_ps_controller
get_serialized_size(
  const virtual_ps_controller::msg::ControllerState & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: buttons
  {
    size_t array_size = ros_message.buttons.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        virtual_ps_controller::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.buttons[index], current_alignment);
    }
  }
  // Member: axes
  {
    size_t array_size = ros_message.axes.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.axes[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_virtual_ps_controller
max_serialized_size_ControllerState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: buttons
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        virtual_ps_controller::msg::typesupport_fastrtps_cpp::max_serialized_size_ButtonState(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: axes
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = virtual_ps_controller::msg::ControllerState;
    is_plain =
      (
      offsetof(DataType, axes) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _ControllerState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const virtual_ps_controller::msg::ControllerState *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ControllerState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<virtual_ps_controller::msg::ControllerState *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ControllerState__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const virtual_ps_controller::msg::ControllerState *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ControllerState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ControllerState(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ControllerState__callbacks = {
  "virtual_ps_controller::msg",
  "ControllerState",
  _ControllerState__cdr_serialize,
  _ControllerState__cdr_deserialize,
  _ControllerState__get_serialized_size,
  _ControllerState__max_serialized_size
};

static rosidl_message_type_support_t _ControllerState__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ControllerState__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace virtual_ps_controller

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_virtual_ps_controller
const rosidl_message_type_support_t *
get_message_type_support_handle<virtual_ps_controller::msg::ControllerState>()
{
  return &virtual_ps_controller::msg::typesupport_fastrtps_cpp::_ControllerState__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, virtual_ps_controller, msg, ControllerState)() {
  return &virtual_ps_controller::msg::typesupport_fastrtps_cpp::_ControllerState__handle;
}

#ifdef __cplusplus
}
#endif
