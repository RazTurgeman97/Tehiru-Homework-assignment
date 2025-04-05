// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from virtual_ps_controller:msg/ButtonState.idl
// generated code does not contain a copyright notice

#ifndef VIRTUAL_PS_CONTROLLER__MSG__DETAIL__BUTTON_STATE__FUNCTIONS_H_
#define VIRTUAL_PS_CONTROLLER__MSG__DETAIL__BUTTON_STATE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "virtual_ps_controller/msg/rosidl_generator_c__visibility_control.h"

#include "virtual_ps_controller/msg/detail/button_state__struct.h"

/// Initialize msg/ButtonState message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * virtual_ps_controller__msg__ButtonState
 * )) before or use
 * virtual_ps_controller__msg__ButtonState__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
bool
virtual_ps_controller__msg__ButtonState__init(virtual_ps_controller__msg__ButtonState * msg);

/// Finalize msg/ButtonState message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
void
virtual_ps_controller__msg__ButtonState__fini(virtual_ps_controller__msg__ButtonState * msg);

/// Create msg/ButtonState message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * virtual_ps_controller__msg__ButtonState__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
virtual_ps_controller__msg__ButtonState *
virtual_ps_controller__msg__ButtonState__create();

/// Destroy msg/ButtonState message.
/**
 * It calls
 * virtual_ps_controller__msg__ButtonState__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
void
virtual_ps_controller__msg__ButtonState__destroy(virtual_ps_controller__msg__ButtonState * msg);

/// Check for msg/ButtonState message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
bool
virtual_ps_controller__msg__ButtonState__are_equal(const virtual_ps_controller__msg__ButtonState * lhs, const virtual_ps_controller__msg__ButtonState * rhs);

/// Copy a msg/ButtonState message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
bool
virtual_ps_controller__msg__ButtonState__copy(
  const virtual_ps_controller__msg__ButtonState * input,
  virtual_ps_controller__msg__ButtonState * output);

/// Initialize array of msg/ButtonState messages.
/**
 * It allocates the memory for the number of elements and calls
 * virtual_ps_controller__msg__ButtonState__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
bool
virtual_ps_controller__msg__ButtonState__Sequence__init(virtual_ps_controller__msg__ButtonState__Sequence * array, size_t size);

/// Finalize array of msg/ButtonState messages.
/**
 * It calls
 * virtual_ps_controller__msg__ButtonState__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
void
virtual_ps_controller__msg__ButtonState__Sequence__fini(virtual_ps_controller__msg__ButtonState__Sequence * array);

/// Create array of msg/ButtonState messages.
/**
 * It allocates the memory for the array and calls
 * virtual_ps_controller__msg__ButtonState__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
virtual_ps_controller__msg__ButtonState__Sequence *
virtual_ps_controller__msg__ButtonState__Sequence__create(size_t size);

/// Destroy array of msg/ButtonState messages.
/**
 * It calls
 * virtual_ps_controller__msg__ButtonState__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
void
virtual_ps_controller__msg__ButtonState__Sequence__destroy(virtual_ps_controller__msg__ButtonState__Sequence * array);

/// Check for msg/ButtonState message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
bool
virtual_ps_controller__msg__ButtonState__Sequence__are_equal(const virtual_ps_controller__msg__ButtonState__Sequence * lhs, const virtual_ps_controller__msg__ButtonState__Sequence * rhs);

/// Copy an array of msg/ButtonState messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
bool
virtual_ps_controller__msg__ButtonState__Sequence__copy(
  const virtual_ps_controller__msg__ButtonState__Sequence * input,
  virtual_ps_controller__msg__ButtonState__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // VIRTUAL_PS_CONTROLLER__MSG__DETAIL__BUTTON_STATE__FUNCTIONS_H_
