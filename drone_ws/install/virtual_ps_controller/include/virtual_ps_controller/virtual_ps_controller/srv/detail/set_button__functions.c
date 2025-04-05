// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from virtual_ps_controller:srv/SetButton.idl
// generated code does not contain a copyright notice
#include "virtual_ps_controller/srv/detail/set_button__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
virtual_ps_controller__srv__SetButton_Request__init(virtual_ps_controller__srv__SetButton_Request * msg)
{
  if (!msg) {
    return false;
  }
  // button_id
  // pressed
  return true;
}

void
virtual_ps_controller__srv__SetButton_Request__fini(virtual_ps_controller__srv__SetButton_Request * msg)
{
  if (!msg) {
    return;
  }
  // button_id
  // pressed
}

bool
virtual_ps_controller__srv__SetButton_Request__are_equal(const virtual_ps_controller__srv__SetButton_Request * lhs, const virtual_ps_controller__srv__SetButton_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // button_id
  if (lhs->button_id != rhs->button_id) {
    return false;
  }
  // pressed
  if (lhs->pressed != rhs->pressed) {
    return false;
  }
  return true;
}

bool
virtual_ps_controller__srv__SetButton_Request__copy(
  const virtual_ps_controller__srv__SetButton_Request * input,
  virtual_ps_controller__srv__SetButton_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // button_id
  output->button_id = input->button_id;
  // pressed
  output->pressed = input->pressed;
  return true;
}

virtual_ps_controller__srv__SetButton_Request *
virtual_ps_controller__srv__SetButton_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  virtual_ps_controller__srv__SetButton_Request * msg = (virtual_ps_controller__srv__SetButton_Request *)allocator.allocate(sizeof(virtual_ps_controller__srv__SetButton_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(virtual_ps_controller__srv__SetButton_Request));
  bool success = virtual_ps_controller__srv__SetButton_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
virtual_ps_controller__srv__SetButton_Request__destroy(virtual_ps_controller__srv__SetButton_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    virtual_ps_controller__srv__SetButton_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
virtual_ps_controller__srv__SetButton_Request__Sequence__init(virtual_ps_controller__srv__SetButton_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  virtual_ps_controller__srv__SetButton_Request * data = NULL;

  if (size) {
    data = (virtual_ps_controller__srv__SetButton_Request *)allocator.zero_allocate(size, sizeof(virtual_ps_controller__srv__SetButton_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = virtual_ps_controller__srv__SetButton_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        virtual_ps_controller__srv__SetButton_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
virtual_ps_controller__srv__SetButton_Request__Sequence__fini(virtual_ps_controller__srv__SetButton_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      virtual_ps_controller__srv__SetButton_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

virtual_ps_controller__srv__SetButton_Request__Sequence *
virtual_ps_controller__srv__SetButton_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  virtual_ps_controller__srv__SetButton_Request__Sequence * array = (virtual_ps_controller__srv__SetButton_Request__Sequence *)allocator.allocate(sizeof(virtual_ps_controller__srv__SetButton_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = virtual_ps_controller__srv__SetButton_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
virtual_ps_controller__srv__SetButton_Request__Sequence__destroy(virtual_ps_controller__srv__SetButton_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    virtual_ps_controller__srv__SetButton_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
virtual_ps_controller__srv__SetButton_Request__Sequence__are_equal(const virtual_ps_controller__srv__SetButton_Request__Sequence * lhs, const virtual_ps_controller__srv__SetButton_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!virtual_ps_controller__srv__SetButton_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
virtual_ps_controller__srv__SetButton_Request__Sequence__copy(
  const virtual_ps_controller__srv__SetButton_Request__Sequence * input,
  virtual_ps_controller__srv__SetButton_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(virtual_ps_controller__srv__SetButton_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    virtual_ps_controller__srv__SetButton_Request * data =
      (virtual_ps_controller__srv__SetButton_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!virtual_ps_controller__srv__SetButton_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          virtual_ps_controller__srv__SetButton_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!virtual_ps_controller__srv__SetButton_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
virtual_ps_controller__srv__SetButton_Response__init(virtual_ps_controller__srv__SetButton_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    virtual_ps_controller__srv__SetButton_Response__fini(msg);
    return false;
  }
  return true;
}

void
virtual_ps_controller__srv__SetButton_Response__fini(virtual_ps_controller__srv__SetButton_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
virtual_ps_controller__srv__SetButton_Response__are_equal(const virtual_ps_controller__srv__SetButton_Response * lhs, const virtual_ps_controller__srv__SetButton_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
virtual_ps_controller__srv__SetButton_Response__copy(
  const virtual_ps_controller__srv__SetButton_Response * input,
  virtual_ps_controller__srv__SetButton_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

virtual_ps_controller__srv__SetButton_Response *
virtual_ps_controller__srv__SetButton_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  virtual_ps_controller__srv__SetButton_Response * msg = (virtual_ps_controller__srv__SetButton_Response *)allocator.allocate(sizeof(virtual_ps_controller__srv__SetButton_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(virtual_ps_controller__srv__SetButton_Response));
  bool success = virtual_ps_controller__srv__SetButton_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
virtual_ps_controller__srv__SetButton_Response__destroy(virtual_ps_controller__srv__SetButton_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    virtual_ps_controller__srv__SetButton_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
virtual_ps_controller__srv__SetButton_Response__Sequence__init(virtual_ps_controller__srv__SetButton_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  virtual_ps_controller__srv__SetButton_Response * data = NULL;

  if (size) {
    data = (virtual_ps_controller__srv__SetButton_Response *)allocator.zero_allocate(size, sizeof(virtual_ps_controller__srv__SetButton_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = virtual_ps_controller__srv__SetButton_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        virtual_ps_controller__srv__SetButton_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
virtual_ps_controller__srv__SetButton_Response__Sequence__fini(virtual_ps_controller__srv__SetButton_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      virtual_ps_controller__srv__SetButton_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

virtual_ps_controller__srv__SetButton_Response__Sequence *
virtual_ps_controller__srv__SetButton_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  virtual_ps_controller__srv__SetButton_Response__Sequence * array = (virtual_ps_controller__srv__SetButton_Response__Sequence *)allocator.allocate(sizeof(virtual_ps_controller__srv__SetButton_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = virtual_ps_controller__srv__SetButton_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
virtual_ps_controller__srv__SetButton_Response__Sequence__destroy(virtual_ps_controller__srv__SetButton_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    virtual_ps_controller__srv__SetButton_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
virtual_ps_controller__srv__SetButton_Response__Sequence__are_equal(const virtual_ps_controller__srv__SetButton_Response__Sequence * lhs, const virtual_ps_controller__srv__SetButton_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!virtual_ps_controller__srv__SetButton_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
virtual_ps_controller__srv__SetButton_Response__Sequence__copy(
  const virtual_ps_controller__srv__SetButton_Response__Sequence * input,
  virtual_ps_controller__srv__SetButton_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(virtual_ps_controller__srv__SetButton_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    virtual_ps_controller__srv__SetButton_Response * data =
      (virtual_ps_controller__srv__SetButton_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!virtual_ps_controller__srv__SetButton_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          virtual_ps_controller__srv__SetButton_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!virtual_ps_controller__srv__SetButton_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
