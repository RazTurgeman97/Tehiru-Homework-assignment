// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from virtual_ps_controller:msg/ButtonState.idl
// generated code does not contain a copyright notice

#ifndef VIRTUAL_PS_CONTROLLER__MSG__DETAIL__BUTTON_STATE__STRUCT_H_
#define VIRTUAL_PS_CONTROLLER__MSG__DETAIL__BUTTON_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ButtonState in the package virtual_ps_controller.
/**
  * Message for button state
 */
typedef struct virtual_ps_controller__msg__ButtonState
{
  uint8_t button_id;
  bool pressed;
} virtual_ps_controller__msg__ButtonState;

// Struct for a sequence of virtual_ps_controller__msg__ButtonState.
typedef struct virtual_ps_controller__msg__ButtonState__Sequence
{
  virtual_ps_controller__msg__ButtonState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} virtual_ps_controller__msg__ButtonState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VIRTUAL_PS_CONTROLLER__MSG__DETAIL__BUTTON_STATE__STRUCT_H_
