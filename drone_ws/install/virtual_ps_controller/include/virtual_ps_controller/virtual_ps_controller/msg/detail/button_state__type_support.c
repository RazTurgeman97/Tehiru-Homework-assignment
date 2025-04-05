// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from virtual_ps_controller:msg/ButtonState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "virtual_ps_controller/msg/detail/button_state__rosidl_typesupport_introspection_c.h"
#include "virtual_ps_controller/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "virtual_ps_controller/msg/detail/button_state__functions.h"
#include "virtual_ps_controller/msg/detail/button_state__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void virtual_ps_controller__msg__ButtonState__rosidl_typesupport_introspection_c__ButtonState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  virtual_ps_controller__msg__ButtonState__init(message_memory);
}

void virtual_ps_controller__msg__ButtonState__rosidl_typesupport_introspection_c__ButtonState_fini_function(void * message_memory)
{
  virtual_ps_controller__msg__ButtonState__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember virtual_ps_controller__msg__ButtonState__rosidl_typesupport_introspection_c__ButtonState_message_member_array[2] = {
  {
    "button_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(virtual_ps_controller__msg__ButtonState, button_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pressed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(virtual_ps_controller__msg__ButtonState, pressed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers virtual_ps_controller__msg__ButtonState__rosidl_typesupport_introspection_c__ButtonState_message_members = {
  "virtual_ps_controller__msg",  // message namespace
  "ButtonState",  // message name
  2,  // number of fields
  sizeof(virtual_ps_controller__msg__ButtonState),
  virtual_ps_controller__msg__ButtonState__rosidl_typesupport_introspection_c__ButtonState_message_member_array,  // message members
  virtual_ps_controller__msg__ButtonState__rosidl_typesupport_introspection_c__ButtonState_init_function,  // function to initialize message memory (memory has to be allocated)
  virtual_ps_controller__msg__ButtonState__rosidl_typesupport_introspection_c__ButtonState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t virtual_ps_controller__msg__ButtonState__rosidl_typesupport_introspection_c__ButtonState_message_type_support_handle = {
  0,
  &virtual_ps_controller__msg__ButtonState__rosidl_typesupport_introspection_c__ButtonState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_virtual_ps_controller
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, virtual_ps_controller, msg, ButtonState)() {
  if (!virtual_ps_controller__msg__ButtonState__rosidl_typesupport_introspection_c__ButtonState_message_type_support_handle.typesupport_identifier) {
    virtual_ps_controller__msg__ButtonState__rosidl_typesupport_introspection_c__ButtonState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &virtual_ps_controller__msg__ButtonState__rosidl_typesupport_introspection_c__ButtonState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
