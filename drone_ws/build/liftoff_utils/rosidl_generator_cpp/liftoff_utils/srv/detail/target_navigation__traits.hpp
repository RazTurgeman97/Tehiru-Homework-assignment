// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from liftoff_utils:srv/TargetNavigation.idl
// generated code does not contain a copyright notice

#ifndef LIFTOFF_UTILS__SRV__DETAIL__TARGET_NAVIGATION__TRAITS_HPP_
#define LIFTOFF_UTILS__SRV__DETAIL__TARGET_NAVIGATION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "liftoff_utils/srv/detail/target_navigation__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace liftoff_utils
{

namespace srv
{

inline void to_flow_style_yaml(
  const TargetNavigation_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: start
  {
    out << "start: ";
    rosidl_generator_traits::value_to_yaml(msg.start, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TargetNavigation_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: start
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start: ";
    rosidl_generator_traits::value_to_yaml(msg.start, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TargetNavigation_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace liftoff_utils

namespace rosidl_generator_traits
{

[[deprecated("use liftoff_utils::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const liftoff_utils::srv::TargetNavigation_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  liftoff_utils::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use liftoff_utils::srv::to_yaml() instead")]]
inline std::string to_yaml(const liftoff_utils::srv::TargetNavigation_Request & msg)
{
  return liftoff_utils::srv::to_yaml(msg);
}

template<>
inline const char * data_type<liftoff_utils::srv::TargetNavigation_Request>()
{
  return "liftoff_utils::srv::TargetNavigation_Request";
}

template<>
inline const char * name<liftoff_utils::srv::TargetNavigation_Request>()
{
  return "liftoff_utils/srv/TargetNavigation_Request";
}

template<>
struct has_fixed_size<liftoff_utils::srv::TargetNavigation_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<liftoff_utils::srv::TargetNavigation_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<liftoff_utils::srv::TargetNavigation_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace liftoff_utils
{

namespace srv
{

inline void to_flow_style_yaml(
  const TargetNavigation_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: error
  {
    out << "error: ";
    rosidl_generator_traits::value_to_yaml(msg.error, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TargetNavigation_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error: ";
    rosidl_generator_traits::value_to_yaml(msg.error, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TargetNavigation_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace liftoff_utils

namespace rosidl_generator_traits
{

[[deprecated("use liftoff_utils::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const liftoff_utils::srv::TargetNavigation_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  liftoff_utils::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use liftoff_utils::srv::to_yaml() instead")]]
inline std::string to_yaml(const liftoff_utils::srv::TargetNavigation_Response & msg)
{
  return liftoff_utils::srv::to_yaml(msg);
}

template<>
inline const char * data_type<liftoff_utils::srv::TargetNavigation_Response>()
{
  return "liftoff_utils::srv::TargetNavigation_Response";
}

template<>
inline const char * name<liftoff_utils::srv::TargetNavigation_Response>()
{
  return "liftoff_utils/srv/TargetNavigation_Response";
}

template<>
struct has_fixed_size<liftoff_utils::srv::TargetNavigation_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<liftoff_utils::srv::TargetNavigation_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<liftoff_utils::srv::TargetNavigation_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<liftoff_utils::srv::TargetNavigation>()
{
  return "liftoff_utils::srv::TargetNavigation";
}

template<>
inline const char * name<liftoff_utils::srv::TargetNavigation>()
{
  return "liftoff_utils/srv/TargetNavigation";
}

template<>
struct has_fixed_size<liftoff_utils::srv::TargetNavigation>
  : std::integral_constant<
    bool,
    has_fixed_size<liftoff_utils::srv::TargetNavigation_Request>::value &&
    has_fixed_size<liftoff_utils::srv::TargetNavigation_Response>::value
  >
{
};

template<>
struct has_bounded_size<liftoff_utils::srv::TargetNavigation>
  : std::integral_constant<
    bool,
    has_bounded_size<liftoff_utils::srv::TargetNavigation_Request>::value &&
    has_bounded_size<liftoff_utils::srv::TargetNavigation_Response>::value
  >
{
};

template<>
struct is_service<liftoff_utils::srv::TargetNavigation>
  : std::true_type
{
};

template<>
struct is_service_request<liftoff_utils::srv::TargetNavigation_Request>
  : std::true_type
{
};

template<>
struct is_service_response<liftoff_utils::srv::TargetNavigation_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // LIFTOFF_UTILS__SRV__DETAIL__TARGET_NAVIGATION__TRAITS_HPP_
