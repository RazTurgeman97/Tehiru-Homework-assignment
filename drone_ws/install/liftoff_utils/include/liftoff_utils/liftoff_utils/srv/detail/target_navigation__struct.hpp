// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from liftoff_utils:srv/TargetNavigation.idl
// generated code does not contain a copyright notice

#ifndef LIFTOFF_UTILS__SRV__DETAIL__TARGET_NAVIGATION__STRUCT_HPP_
#define LIFTOFF_UTILS__SRV__DETAIL__TARGET_NAVIGATION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__liftoff_utils__srv__TargetNavigation_Request __attribute__((deprecated))
#else
# define DEPRECATED__liftoff_utils__srv__TargetNavigation_Request __declspec(deprecated)
#endif

namespace liftoff_utils
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TargetNavigation_Request_
{
  using Type = TargetNavigation_Request_<ContainerAllocator>;

  explicit TargetNavigation_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->start = false;
    }
  }

  explicit TargetNavigation_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->start = false;
    }
  }

  // field types and members
  using _start_type =
    bool;
  _start_type start;

  // setters for named parameter idiom
  Type & set__start(
    const bool & _arg)
  {
    this->start = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    liftoff_utils::srv::TargetNavigation_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const liftoff_utils::srv::TargetNavigation_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<liftoff_utils::srv::TargetNavigation_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<liftoff_utils::srv::TargetNavigation_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      liftoff_utils::srv::TargetNavigation_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<liftoff_utils::srv::TargetNavigation_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      liftoff_utils::srv::TargetNavigation_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<liftoff_utils::srv::TargetNavigation_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<liftoff_utils::srv::TargetNavigation_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<liftoff_utils::srv::TargetNavigation_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__liftoff_utils__srv__TargetNavigation_Request
    std::shared_ptr<liftoff_utils::srv::TargetNavigation_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__liftoff_utils__srv__TargetNavigation_Request
    std::shared_ptr<liftoff_utils::srv::TargetNavigation_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TargetNavigation_Request_ & other) const
  {
    if (this->start != other.start) {
      return false;
    }
    return true;
  }
  bool operator!=(const TargetNavigation_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TargetNavigation_Request_

// alias to use template instance with default allocator
using TargetNavigation_Request =
  liftoff_utils::srv::TargetNavigation_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace liftoff_utils


#ifndef _WIN32
# define DEPRECATED__liftoff_utils__srv__TargetNavigation_Response __attribute__((deprecated))
#else
# define DEPRECATED__liftoff_utils__srv__TargetNavigation_Response __declspec(deprecated)
#endif

namespace liftoff_utils
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TargetNavigation_Response_
{
  using Type = TargetNavigation_Response_<ContainerAllocator>;

  explicit TargetNavigation_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = "";
      this->error = "";
    }
  }

  explicit TargetNavigation_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : status(_alloc),
    error(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = "";
      this->error = "";
    }
  }

  // field types and members
  using _status_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_type status;
  using _error_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _error_type error;

  // setters for named parameter idiom
  Type & set__status(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__error(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->error = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    liftoff_utils::srv::TargetNavigation_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const liftoff_utils::srv::TargetNavigation_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<liftoff_utils::srv::TargetNavigation_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<liftoff_utils::srv::TargetNavigation_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      liftoff_utils::srv::TargetNavigation_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<liftoff_utils::srv::TargetNavigation_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      liftoff_utils::srv::TargetNavigation_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<liftoff_utils::srv::TargetNavigation_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<liftoff_utils::srv::TargetNavigation_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<liftoff_utils::srv::TargetNavigation_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__liftoff_utils__srv__TargetNavigation_Response
    std::shared_ptr<liftoff_utils::srv::TargetNavigation_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__liftoff_utils__srv__TargetNavigation_Response
    std::shared_ptr<liftoff_utils::srv::TargetNavigation_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TargetNavigation_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->error != other.error) {
      return false;
    }
    return true;
  }
  bool operator!=(const TargetNavigation_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TargetNavigation_Response_

// alias to use template instance with default allocator
using TargetNavigation_Response =
  liftoff_utils::srv::TargetNavigation_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace liftoff_utils

namespace liftoff_utils
{

namespace srv
{

struct TargetNavigation
{
  using Request = liftoff_utils::srv::TargetNavigation_Request;
  using Response = liftoff_utils::srv::TargetNavigation_Response;
};

}  // namespace srv

}  // namespace liftoff_utils

#endif  // LIFTOFF_UTILS__SRV__DETAIL__TARGET_NAVIGATION__STRUCT_HPP_
