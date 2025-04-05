// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from virtual_ps_controller:srv/SetButton.idl
// generated code does not contain a copyright notice

#ifndef VIRTUAL_PS_CONTROLLER__SRV__DETAIL__SET_BUTTON__FUNCTIONS_H_
#define VIRTUAL_PS_CONTROLLER__SRV__DETAIL__SET_BUTTON__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "virtual_ps_controller/msg/rosidl_generator_c__visibility_control.h"

#include "virtual_ps_controller/srv/detail/set_button__struct.h"

/// Initialize srv/SetButton message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * virtual_ps_controller__srv__SetButton_Request
 * )) before or use
 * virtual_ps_controller__srv__SetButton_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
bool
virtual_ps_controller__srv__SetButton_Request__init(virtual_ps_controller__srv__SetButton_Request * msg);

/// Finalize srv/SetButton message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
void
virtual_ps_controller__srv__SetButton_Request__fini(virtual_ps_controller__srv__SetButton_Request * msg);

/// Create srv/SetButton message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * virtual_ps_controller__srv__SetButton_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
virtual_ps_controller__srv__SetButton_Request *
virtual_ps_controller__srv__SetButton_Request__create();

/// Destroy srv/SetButton message.
/**
 * It calls
 * virtual_ps_controller__srv__SetButton_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
void
virtual_ps_controller__srv__SetButton_Request__destroy(virtual_ps_controller__srv__SetButton_Request * msg);

/// Check for srv/SetButton message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
bool
virtual_ps_controller__srv__SetButton_Request__are_equal(const virtual_ps_controller__srv__SetButton_Request * lhs, const virtual_ps_controller__srv__SetButton_Request * rhs);

/// Copy a srv/SetButton message.
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
virtual_ps_controller__srv__SetButton_Request__copy(
  const virtual_ps_controller__srv__SetButton_Request * input,
  virtual_ps_controller__srv__SetButton_Request * output);

/// Initialize array of srv/SetButton messages.
/**
 * It allocates the memory for the number of elements and calls
 * virtual_ps_controller__srv__SetButton_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
bool
virtual_ps_controller__srv__SetButton_Request__Sequence__init(virtual_ps_controller__srv__SetButton_Request__Sequence * array, size_t size);

/// Finalize array of srv/SetButton messages.
/**
 * It calls
 * virtual_ps_controller__srv__SetButton_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
void
virtual_ps_controller__srv__SetButton_Request__Sequence__fini(virtual_ps_controller__srv__SetButton_Request__Sequence * array);

/// Create array of srv/SetButton messages.
/**
 * It allocates the memory for the array and calls
 * virtual_ps_controller__srv__SetButton_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
virtual_ps_controller__srv__SetButton_Request__Sequence *
virtual_ps_controller__srv__SetButton_Request__Sequence__create(size_t size);

/// Destroy array of srv/SetButton messages.
/**
 * It calls
 * virtual_ps_controller__srv__SetButton_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
void
virtual_ps_controller__srv__SetButton_Request__Sequence__destroy(virtual_ps_controller__srv__SetButton_Request__Sequence * array);

/// Check for srv/SetButton message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
bool
virtual_ps_controller__srv__SetButton_Request__Sequence__are_equal(const virtual_ps_controller__srv__SetButton_Request__Sequence * lhs, const virtual_ps_controller__srv__SetButton_Request__Sequence * rhs);

/// Copy an array of srv/SetButton messages.
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
virtual_ps_controller__srv__SetButton_Request__Sequence__copy(
  const virtual_ps_controller__srv__SetButton_Request__Sequence * input,
  virtual_ps_controller__srv__SetButton_Request__Sequence * output);

/// Initialize srv/SetButton message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * virtual_ps_controller__srv__SetButton_Response
 * )) before or use
 * virtual_ps_controller__srv__SetButton_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
bool
virtual_ps_controller__srv__SetButton_Response__init(virtual_ps_controller__srv__SetButton_Response * msg);

/// Finalize srv/SetButton message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
void
virtual_ps_controller__srv__SetButton_Response__fini(virtual_ps_controller__srv__SetButton_Response * msg);

/// Create srv/SetButton message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * virtual_ps_controller__srv__SetButton_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
virtual_ps_controller__srv__SetButton_Response *
virtual_ps_controller__srv__SetButton_Response__create();

/// Destroy srv/SetButton message.
/**
 * It calls
 * virtual_ps_controller__srv__SetButton_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
void
virtual_ps_controller__srv__SetButton_Response__destroy(virtual_ps_controller__srv__SetButton_Response * msg);

/// Check for srv/SetButton message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
bool
virtual_ps_controller__srv__SetButton_Response__are_equal(const virtual_ps_controller__srv__SetButton_Response * lhs, const virtual_ps_controller__srv__SetButton_Response * rhs);

/// Copy a srv/SetButton message.
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
virtual_ps_controller__srv__SetButton_Response__copy(
  const virtual_ps_controller__srv__SetButton_Response * input,
  virtual_ps_controller__srv__SetButton_Response * output);

/// Initialize array of srv/SetButton messages.
/**
 * It allocates the memory for the number of elements and calls
 * virtual_ps_controller__srv__SetButton_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
bool
virtual_ps_controller__srv__SetButton_Response__Sequence__init(virtual_ps_controller__srv__SetButton_Response__Sequence * array, size_t size);

/// Finalize array of srv/SetButton messages.
/**
 * It calls
 * virtual_ps_controller__srv__SetButton_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
void
virtual_ps_controller__srv__SetButton_Response__Sequence__fini(virtual_ps_controller__srv__SetButton_Response__Sequence * array);

/// Create array of srv/SetButton messages.
/**
 * It allocates the memory for the array and calls
 * virtual_ps_controller__srv__SetButton_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
virtual_ps_controller__srv__SetButton_Response__Sequence *
virtual_ps_controller__srv__SetButton_Response__Sequence__create(size_t size);

/// Destroy array of srv/SetButton messages.
/**
 * It calls
 * virtual_ps_controller__srv__SetButton_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
void
virtual_ps_controller__srv__SetButton_Response__Sequence__destroy(virtual_ps_controller__srv__SetButton_Response__Sequence * array);

/// Check for srv/SetButton message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_virtual_ps_controller
bool
virtual_ps_controller__srv__SetButton_Response__Sequence__are_equal(const virtual_ps_controller__srv__SetButton_Response__Sequence * lhs, const virtual_ps_controller__srv__SetButton_Response__Sequence * rhs);

/// Copy an array of srv/SetButton messages.
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
virtual_ps_controller__srv__SetButton_Response__Sequence__copy(
  const virtual_ps_controller__srv__SetButton_Response__Sequence * input,
  virtual_ps_controller__srv__SetButton_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // VIRTUAL_PS_CONTROLLER__SRV__DETAIL__SET_BUTTON__FUNCTIONS_H_
