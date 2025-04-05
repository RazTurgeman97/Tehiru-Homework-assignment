// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from virtual_ps_controller:msg/ControllerState.idl
// generated code does not contain a copyright notice

#ifndef VIRTUAL_PS_CONTROLLER__MSG__DETAIL__CONTROLLER_STATE__STRUCT_H_
#define VIRTUAL_PS_CONTROLLER__MSG__DETAIL__CONTROLLER_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'buttons'
#include "virtual_ps_controller/msg/detail/button_state__struct.h"
// Member 'axes'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/ControllerState in the package virtual_ps_controller.
/**
  * PS4 controller state message
 */
typedef struct virtual_ps_controller__msg__ControllerState
{
  std_msgs__msg__Header header;
  virtual_ps_controller__msg__ButtonState__Sequence buttons;
  rosidl_runtime_c__float__Sequence axes;
} virtual_ps_controller__msg__ControllerState;

// Struct for a sequence of virtual_ps_controller__msg__ControllerState.
typedef struct virtual_ps_controller__msg__ControllerState__Sequence
{
  virtual_ps_controller__msg__ControllerState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} virtual_ps_controller__msg__ControllerState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VIRTUAL_PS_CONTROLLER__MSG__DETAIL__CONTROLLER_STATE__STRUCT_H_
