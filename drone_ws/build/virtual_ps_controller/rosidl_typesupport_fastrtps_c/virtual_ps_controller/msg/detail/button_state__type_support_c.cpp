// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from virtual_ps_controller:msg/ButtonState.idl
// generated code does not contain a copyright notice
#include "virtual_ps_controller/msg/detail/button_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "virtual_ps_controller/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "virtual_ps_controller/msg/detail/button_state__struct.h"
#include "virtual_ps_controller/msg/detail/button_state__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _ButtonState__ros_msg_type = virtual_ps_controller__msg__ButtonState;

static bool _ButtonState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ButtonState__ros_msg_type * ros_message = static_cast<const _ButtonState__ros_msg_type *>(untyped_ros_message);
  // Field name: button_id
  {
    cdr << ros_message->button_id;
  }

  // Field name: pressed
  {
    cdr << (ros_message->pressed ? true : false);
  }

  return true;
}

static bool _ButtonState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ButtonState__ros_msg_type * ros_message = static_cast<_ButtonState__ros_msg_type *>(untyped_ros_message);
  // Field name: button_id
  {
    cdr >> ros_message->button_id;
  }

  // Field name: pressed
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->pressed = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_virtual_ps_controller
size_t get_serialized_size_virtual_ps_controller__msg__ButtonState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ButtonState__ros_msg_type * ros_message = static_cast<const _ButtonState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name button_id
  {
    size_t item_size = sizeof(ros_message->button_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pressed
  {
    size_t item_size = sizeof(ros_message->pressed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ButtonState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_virtual_ps_controller__msg__ButtonState(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_virtual_ps_controller
size_t max_serialized_size_virtual_ps_controller__msg__ButtonState(
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

  // member: button_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: pressed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = virtual_ps_controller__msg__ButtonState;
    is_plain =
      (
      offsetof(DataType, pressed) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _ButtonState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_virtual_ps_controller__msg__ButtonState(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ButtonState = {
  "virtual_ps_controller::msg",
  "ButtonState",
  _ButtonState__cdr_serialize,
  _ButtonState__cdr_deserialize,
  _ButtonState__get_serialized_size,
  _ButtonState__max_serialized_size
};

static rosidl_message_type_support_t _ButtonState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ButtonState,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, virtual_ps_controller, msg, ButtonState)() {
  return &_ButtonState__type_support;
}

#if defined(__cplusplus)
}
#endif
