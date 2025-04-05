// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from liftoff_utils:srv/TargetNavigation.idl
// generated code does not contain a copyright notice

#ifndef LIFTOFF_UTILS__SRV__DETAIL__TARGET_NAVIGATION__STRUCT_H_
#define LIFTOFF_UTILS__SRV__DETAIL__TARGET_NAVIGATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/TargetNavigation in the package liftoff_utils.
typedef struct liftoff_utils__srv__TargetNavigation_Request
{
  /// True to start navigation, False to stop
  bool start;
} liftoff_utils__srv__TargetNavigation_Request;

// Struct for a sequence of liftoff_utils__srv__TargetNavigation_Request.
typedef struct liftoff_utils__srv__TargetNavigation_Request__Sequence
{
  liftoff_utils__srv__TargetNavigation_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} liftoff_utils__srv__TargetNavigation_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'status'
// Member 'error'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/TargetNavigation in the package liftoff_utils.
typedef struct liftoff_utils__srv__TargetNavigation_Response
{
  /// Current status (e.g., "Executing", "Error", "Stopped")
  rosidl_runtime_c__String status;
  /// Error message (empty if no error)
  rosidl_runtime_c__String error;
} liftoff_utils__srv__TargetNavigation_Response;

// Struct for a sequence of liftoff_utils__srv__TargetNavigation_Response.
typedef struct liftoff_utils__srv__TargetNavigation_Response__Sequence
{
  liftoff_utils__srv__TargetNavigation_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} liftoff_utils__srv__TargetNavigation_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LIFTOFF_UTILS__SRV__DETAIL__TARGET_NAVIGATION__STRUCT_H_
