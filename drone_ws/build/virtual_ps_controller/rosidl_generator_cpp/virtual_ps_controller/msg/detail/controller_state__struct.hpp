// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from virtual_ps_controller:msg/ControllerState.idl
// generated code does not contain a copyright notice

#ifndef VIRTUAL_PS_CONTROLLER__MSG__DETAIL__CONTROLLER_STATE__STRUCT_HPP_
#define VIRTUAL_PS_CONTROLLER__MSG__DETAIL__CONTROLLER_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'buttons'
#include "virtual_ps_controller/msg/detail/button_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__virtual_ps_controller__msg__ControllerState __attribute__((deprecated))
#else
# define DEPRECATED__virtual_ps_controller__msg__ControllerState __declspec(deprecated)
#endif

namespace virtual_ps_controller
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ControllerState_
{
  using Type = ControllerState_<ContainerAllocator>;

  explicit ControllerState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit ControllerState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _buttons_type =
    std::vector<virtual_ps_controller::msg::ButtonState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<virtual_ps_controller::msg::ButtonState_<ContainerAllocator>>>;
  _buttons_type buttons;
  using _axes_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _axes_type axes;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__buttons(
    const std::vector<virtual_ps_controller::msg::ButtonState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<virtual_ps_controller::msg::ButtonState_<ContainerAllocator>>> & _arg)
  {
    this->buttons = _arg;
    return *this;
  }
  Type & set__axes(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->axes = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    virtual_ps_controller::msg::ControllerState_<ContainerAllocator> *;
  using ConstRawPtr =
    const virtual_ps_controller::msg::ControllerState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<virtual_ps_controller::msg::ControllerState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<virtual_ps_controller::msg::ControllerState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      virtual_ps_controller::msg::ControllerState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<virtual_ps_controller::msg::ControllerState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      virtual_ps_controller::msg::ControllerState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<virtual_ps_controller::msg::ControllerState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<virtual_ps_controller::msg::ControllerState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<virtual_ps_controller::msg::ControllerState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__virtual_ps_controller__msg__ControllerState
    std::shared_ptr<virtual_ps_controller::msg::ControllerState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__virtual_ps_controller__msg__ControllerState
    std::shared_ptr<virtual_ps_controller::msg::ControllerState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ControllerState_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->buttons != other.buttons) {
      return false;
    }
    if (this->axes != other.axes) {
      return false;
    }
    return true;
  }
  bool operator!=(const ControllerState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ControllerState_

// alias to use template instance with default allocator
using ControllerState =
  virtual_ps_controller::msg::ControllerState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace virtual_ps_controller

#endif  // VIRTUAL_PS_CONTROLLER__MSG__DETAIL__CONTROLLER_STATE__STRUCT_HPP_
