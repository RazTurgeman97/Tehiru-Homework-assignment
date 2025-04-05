// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from virtual_ps_controller:srv/SetButton.idl
// generated code does not contain a copyright notice

#ifndef VIRTUAL_PS_CONTROLLER__SRV__DETAIL__SET_BUTTON__STRUCT_HPP_
#define VIRTUAL_PS_CONTROLLER__SRV__DETAIL__SET_BUTTON__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__virtual_ps_controller__srv__SetButton_Request __attribute__((deprecated))
#else
# define DEPRECATED__virtual_ps_controller__srv__SetButton_Request __declspec(deprecated)
#endif

namespace virtual_ps_controller
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetButton_Request_
{
  using Type = SetButton_Request_<ContainerAllocator>;

  explicit SetButton_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->button_id = 0;
      this->pressed = false;
    }
  }

  explicit SetButton_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    virtual_ps_controller::srv::SetButton_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const virtual_ps_controller::srv::SetButton_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<virtual_ps_controller::srv::SetButton_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<virtual_ps_controller::srv::SetButton_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      virtual_ps_controller::srv::SetButton_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<virtual_ps_controller::srv::SetButton_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      virtual_ps_controller::srv::SetButton_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<virtual_ps_controller::srv::SetButton_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<virtual_ps_controller::srv::SetButton_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<virtual_ps_controller::srv::SetButton_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__virtual_ps_controller__srv__SetButton_Request
    std::shared_ptr<virtual_ps_controller::srv::SetButton_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__virtual_ps_controller__srv__SetButton_Request
    std::shared_ptr<virtual_ps_controller::srv::SetButton_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetButton_Request_ & other) const
  {
    if (this->button_id != other.button_id) {
      return false;
    }
    if (this->pressed != other.pressed) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetButton_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetButton_Request_

// alias to use template instance with default allocator
using SetButton_Request =
  virtual_ps_controller::srv::SetButton_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace virtual_ps_controller


#ifndef _WIN32
# define DEPRECATED__virtual_ps_controller__srv__SetButton_Response __attribute__((deprecated))
#else
# define DEPRECATED__virtual_ps_controller__srv__SetButton_Response __declspec(deprecated)
#endif

namespace virtual_ps_controller
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetButton_Response_
{
  using Type = SetButton_Response_<ContainerAllocator>;

  explicit SetButton_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit SetButton_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    virtual_ps_controller::srv::SetButton_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const virtual_ps_controller::srv::SetButton_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<virtual_ps_controller::srv::SetButton_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<virtual_ps_controller::srv::SetButton_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      virtual_ps_controller::srv::SetButton_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<virtual_ps_controller::srv::SetButton_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      virtual_ps_controller::srv::SetButton_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<virtual_ps_controller::srv::SetButton_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<virtual_ps_controller::srv::SetButton_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<virtual_ps_controller::srv::SetButton_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__virtual_ps_controller__srv__SetButton_Response
    std::shared_ptr<virtual_ps_controller::srv::SetButton_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__virtual_ps_controller__srv__SetButton_Response
    std::shared_ptr<virtual_ps_controller::srv::SetButton_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetButton_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetButton_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetButton_Response_

// alias to use template instance with default allocator
using SetButton_Response =
  virtual_ps_controller::srv::SetButton_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace virtual_ps_controller

namespace virtual_ps_controller
{

namespace srv
{

struct SetButton
{
  using Request = virtual_ps_controller::srv::SetButton_Request;
  using Response = virtual_ps_controller::srv::SetButton_Response;
};

}  // namespace srv

}  // namespace virtual_ps_controller

#endif  // VIRTUAL_PS_CONTROLLER__SRV__DETAIL__SET_BUTTON__STRUCT_HPP_
