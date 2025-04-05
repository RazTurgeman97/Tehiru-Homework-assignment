// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from virtual_ps_controller:srv/SetButton.idl
// generated code does not contain a copyright notice

#ifndef VIRTUAL_PS_CONTROLLER__SRV__DETAIL__SET_BUTTON__STRUCT_H_
#define VIRTUAL_PS_CONTROLLER__SRV__DETAIL__SET_BUTTON__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetButton in the package virtual_ps_controller.
typedef struct virtual_ps_controller__srv__SetButton_Request
{
  uint8_t button_id;
  bool pressed;
} virtual_ps_controller__srv__SetButton_Request;

// Struct for a sequence of virtual_ps_controller__srv__SetButton_Request.
typedef struct virtual_ps_controller__srv__SetButton_Request__Sequence
{
  virtual_ps_controller__srv__SetButton_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} virtual_ps_controller__srv__SetButton_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetButton in the package virtual_ps_controller.
typedef struct virtual_ps_controller__srv__SetButton_Response
{
  bool success;
  rosidl_runtime_c__String message;
} virtual_ps_controller__srv__SetButton_Response;

// Struct for a sequence of virtual_ps_controller__srv__SetButton_Response.
typedef struct virtual_ps_controller__srv__SetButton_Response__Sequence
{
  virtual_ps_controller__srv__SetButton_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} virtual_ps_controller__srv__SetButton_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VIRTUAL_PS_CONTROLLER__SRV__DETAIL__SET_BUTTON__STRUCT_H_
