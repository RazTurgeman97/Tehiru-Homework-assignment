// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from virtual_ps_controller:msg/ButtonState.idl
// generated code does not contain a copyright notice

#ifndef VIRTUAL_PS_CONTROLLER__MSG__DETAIL__BUTTON_STATE__STRUCT_HPP_
#define VIRTUAL_PS_CONTROLLER__MSG__DETAIL__BUTTON_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__virtual_ps_controller__msg__ButtonState __attribute__((deprecated))
#else
# define DEPRECATED__virtual_ps_controller__msg__ButtonState __declspec(deprecated)
#endif

namespace virtual_ps_controller
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ButtonState_
{
  using Type = ButtonState_<ContainerAllocator>;

  explicit ButtonState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->button_id = 0;
      this->pressed = false;
    }
  }

  explicit ButtonState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->button_id = 0;
      this->pressed = false;
    }
  }

  // field types and members
  using _button_id_type =
    uint8_t;
  _button_id_type button_id;
  using _pressed_type =
    bool;
  _pressed_type pressed;

  // setters for named parameter idiom
  Type & set__button_id(
    const uint8_t & _arg)
  {
    this->button_id = _arg;
    return *this;
  }
  Type & set__pressed(
    const bool & _arg)
  {
    this->pressed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    virtual_ps_controller::msg::ButtonState_<ContainerAllocator> *;
  using ConstRawPtr =
    const virtual_ps_controller::msg::ButtonState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<virtual_ps_controller::msg::ButtonState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<virtual_ps_controller::msg::ButtonState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      virtual_ps_controller::msg::ButtonState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<virtual_ps_controller::msg::ButtonState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      virtual_ps_controller::msg::ButtonState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<virtual_ps_controller::msg::ButtonState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<virtual_ps_controller::msg::ButtonState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<virtual_ps_controller::msg::ButtonState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__virtual_ps_controller__msg__ButtonState
    std::shared_ptr<virtual_ps_controller::msg::ButtonState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__virtual_ps_controller__msg__ButtonState
    std::shared_ptr<virtual_ps_controller::msg::ButtonState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ButtonState_ & other) const
  {
    if (this->button_id != other.button_id) {
      return false;
    }
    if (this->pressed != other.pressed) {
      return false;
    }
    return true;
  }
  bool operator!=(const ButtonState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ButtonState_

// alias to use template instance with default allocator
using ButtonState =
  virtual_ps_controller::msg::ButtonState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace virtual_ps_controller

#endif  // VIRTUAL_PS_CONTROLLER__MSG__DETAIL__BUTTON_STATE__STRUCT_HPP_
