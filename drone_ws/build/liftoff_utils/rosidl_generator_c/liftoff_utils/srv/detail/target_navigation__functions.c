// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from liftoff_utils:srv/TargetNavigation.idl
// generated code does not contain a copyright notice
#include "liftoff_utils/srv/detail/target_navigation__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
liftoff_utils__srv__TargetNavigation_Request__init(liftoff_utils__srv__TargetNavigation_Request * msg)
{
  if (!msg) {
    return false;
  }
  // start
  return true;
}

void
liftoff_utils__srv__TargetNavigation_Request__fini(liftoff_utils__srv__TargetNavigation_Request * msg)
{
  if (!msg) {
    return;
  }
  // start
}

bool
liftoff_utils__srv__TargetNavigation_Request__are_equal(const liftoff_utils__srv__TargetNavigation_Request * lhs, const liftoff_utils__srv__TargetNavigation_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // start
  if (lhs->start != rhs->start) {
    return false;
  }
  return true;
}

bool
liftoff_utils__srv__TargetNavigation_Request__copy(
  const liftoff_utils__srv__TargetNavigation_Request * input,
  liftoff_utils__srv__TargetNavigation_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // start
  output->start = input->start;
  return true;
}

liftoff_utils__srv__TargetNavigation_Request *
liftoff_utils__srv__TargetNavigation_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  liftoff_utils__srv__TargetNavigation_Request * msg = (liftoff_utils__srv__TargetNavigation_Request *)allocator.allocate(sizeof(liftoff_utils__srv__TargetNavigation_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(liftoff_utils__srv__TargetNavigation_Request));
  bool success = liftoff_utils__srv__TargetNavigation_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
liftoff_utils__srv__TargetNavigation_Request__destroy(liftoff_utils__srv__TargetNavigation_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    liftoff_utils__srv__TargetNavigation_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
liftoff_utils__srv__TargetNavigation_Request__Sequence__init(liftoff_utils__srv__TargetNavigation_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  liftoff_utils__srv__TargetNavigation_Request * data = NULL;

  if (size) {
    data = (liftoff_utils__srv__TargetNavigation_Request *)allocator.zero_allocate(size, sizeof(liftoff_utils__srv__TargetNavigation_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = liftoff_utils__srv__TargetNavigation_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        liftoff_utils__srv__TargetNavigation_Request__fini(&data[i - 1]);
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
liftoff_utils__srv__TargetNavigation_Request__Sequence__fini(liftoff_utils__srv__TargetNavigation_Request__Sequence * array)
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
      liftoff_utils__srv__TargetNavigation_Request__fini(&array->data[i]);
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

liftoff_utils__srv__TargetNavigation_Request__Sequence *
liftoff_utils__srv__TargetNavigation_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  liftoff_utils__srv__TargetNavigation_Request__Sequence * array = (liftoff_utils__srv__TargetNavigation_Request__Sequence *)allocator.allocate(sizeof(liftoff_utils__srv__TargetNavigation_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = liftoff_utils__srv__TargetNavigation_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
liftoff_utils__srv__TargetNavigation_Request__Sequence__destroy(liftoff_utils__srv__TargetNavigation_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    liftoff_utils__srv__TargetNavigation_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
liftoff_utils__srv__TargetNavigation_Request__Sequence__are_equal(const liftoff_utils__srv__TargetNavigation_Request__Sequence * lhs, const liftoff_utils__srv__TargetNavigation_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!liftoff_utils__srv__TargetNavigation_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
liftoff_utils__srv__TargetNavigation_Request__Sequence__copy(
  const liftoff_utils__srv__TargetNavigation_Request__Sequence * input,
  liftoff_utils__srv__TargetNavigation_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(liftoff_utils__srv__TargetNavigation_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    liftoff_utils__srv__TargetNavigation_Request * data =
      (liftoff_utils__srv__TargetNavigation_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!liftoff_utils__srv__TargetNavigation_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          liftoff_utils__srv__TargetNavigation_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!liftoff_utils__srv__TargetNavigation_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `status`
// Member `error`
#include "rosidl_runtime_c/string_functions.h"

bool
liftoff_utils__srv__TargetNavigation_Response__init(liftoff_utils__srv__TargetNavigation_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__init(&msg->status)) {
    liftoff_utils__srv__TargetNavigation_Response__fini(msg);
    return false;
  }
  // error
  if (!rosidl_runtime_c__String__init(&msg->error)) {
    liftoff_utils__srv__TargetNavigation_Response__fini(msg);
    return false;
  }
  return true;
}

void
liftoff_utils__srv__TargetNavigation_Response__fini(liftoff_utils__srv__TargetNavigation_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  rosidl_runtime_c__String__fini(&msg->status);
  // error
  rosidl_runtime_c__String__fini(&msg->error);
}

bool
liftoff_utils__srv__TargetNavigation_Response__are_equal(const liftoff_utils__srv__TargetNavigation_Response * lhs, const liftoff_utils__srv__TargetNavigation_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->status), &(rhs->status)))
  {
    return false;
  }
  // error
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->error), &(rhs->error)))
  {
    return false;
  }
  return true;
}

bool
liftoff_utils__srv__TargetNavigation_Response__copy(
  const liftoff_utils__srv__TargetNavigation_Response * input,
  liftoff_utils__srv__TargetNavigation_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__copy(
      &(input->status), &(output->status)))
  {
    return false;
  }
  // error
  if (!rosidl_runtime_c__String__copy(
      &(input->error), &(output->error)))
  {
    return false;
  }
  return true;
}

liftoff_utils__srv__TargetNavigation_Response *
liftoff_utils__srv__TargetNavigation_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  liftoff_utils__srv__TargetNavigation_Response * msg = (liftoff_utils__srv__TargetNavigation_Response *)allocator.allocate(sizeof(liftoff_utils__srv__TargetNavigation_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(liftoff_utils__srv__TargetNavigation_Response));
  bool success = liftoff_utils__srv__TargetNavigation_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
liftoff_utils__srv__TargetNavigation_Response__destroy(liftoff_utils__srv__TargetNavigation_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    liftoff_utils__srv__TargetNavigation_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
liftoff_utils__srv__TargetNavigation_Response__Sequence__init(liftoff_utils__srv__TargetNavigation_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  liftoff_utils__srv__TargetNavigation_Response * data = NULL;

  if (size) {
    data = (liftoff_utils__srv__TargetNavigation_Response *)allocator.zero_allocate(size, sizeof(liftoff_utils__srv__TargetNavigation_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = liftoff_utils__srv__TargetNavigation_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        liftoff_utils__srv__TargetNavigation_Response__fini(&data[i - 1]);
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
liftoff_utils__srv__TargetNavigation_Response__Sequence__fini(liftoff_utils__srv__TargetNavigation_Response__Sequence * array)
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
      liftoff_utils__srv__TargetNavigation_Response__fini(&array->data[i]);
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

liftoff_utils__srv__TargetNavigation_Response__Sequence *
liftoff_utils__srv__TargetNavigation_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  liftoff_utils__srv__TargetNavigation_Response__Sequence * array = (liftoff_utils__srv__TargetNavigation_Response__Sequence *)allocator.allocate(sizeof(liftoff_utils__srv__TargetNavigation_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = liftoff_utils__srv__TargetNavigation_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
liftoff_utils__srv__TargetNavigation_Response__Sequence__destroy(liftoff_utils__srv__TargetNavigation_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    liftoff_utils__srv__TargetNavigation_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
liftoff_utils__srv__TargetNavigation_Response__Sequence__are_equal(const liftoff_utils__srv__TargetNavigation_Response__Sequence * lhs, const liftoff_utils__srv__TargetNavigation_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!liftoff_utils__srv__TargetNavigation_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
liftoff_utils__srv__TargetNavigation_Response__Sequence__copy(
  const liftoff_utils__srv__TargetNavigation_Response__Sequence * input,
  liftoff_utils__srv__TargetNavigation_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(liftoff_utils__srv__TargetNavigation_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    liftoff_utils__srv__TargetNavigation_Response * data =
      (liftoff_utils__srv__TargetNavigation_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!liftoff_utils__srv__TargetNavigation_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          liftoff_utils__srv__TargetNavigation_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!liftoff_utils__srv__TargetNavigation_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
