// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from virtual_ps_controller:srv/SetButton.idl
// generated code does not contain a copyright notice

#ifndef VIRTUAL_PS_CONTROLLER__SRV__DETAIL__SET_BUTTON__TRAITS_HPP_
#define VIRTUAL_PS_CONTROLLER__SRV__DETAIL__SET_BUTTON__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "virtual_ps_controller/srv/detail/set_button__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace virtual_ps_controller
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetButton_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: button_id
  {
    out << "button_id: ";
    rosidl_generator_traits::value_to_yaml(msg.button_id, out);
    out << ", ";
  }

  // member: pressed
  {
    out << "pressed: ";
    rosidl_generator_traits::value_to_yaml(msg.pressed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetButton_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: button_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "button_id: ";
    rosidl_generator_traits::value_to_yaml(msg.button_id, out);
    out << "\n";
  }

  // member: pressed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pressed: ";
    rosidl_generator_traits::value_to_yaml(msg.pressed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetButton_Request & msg, bool use_flow_style = false)
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

}  // namespace virtual_ps_controller

namespace rosidl_generator_traits
{

[[deprecated("use virtual_ps_controller::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const virtual_ps_controller::srv::SetButton_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  virtual_ps_controller::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use virtual_ps_controller::srv::to_yaml() instead")]]
inline std::string to_yaml(const virtual_ps_controller::srv::SetButton_Request & msg)
{
  return virtual_ps_controller::srv::to_yaml(msg);
}

template<>
inline const char * data_type<virtual_ps_controller::srv::SetButton_Request>()
{
  return "virtual_ps_controller::srv::SetButton_Request";
}

template<>
inline const char * name<virtual_ps_controller::srv::SetButton_Request>()
{
  return "virtual_ps_controller/srv/SetButton_Request";
}

template<>
struct has_fixed_size<virtual_ps_controller::srv::SetButton_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<virtual_ps_controller::srv::SetButton_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<virtual_ps_controller::srv::SetButton_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace virtual_ps_controller
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetButton_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetButton_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetButton_Response & msg, bool use_flow_style = false)
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

}  // namespace virtual_ps_controller

namespace rosidl_generator_traits
{

[[deprecated("use virtual_ps_controller::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const virtual_ps_controller::srv::SetButton_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  virtual_ps_controller::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use virtual_ps_controller::srv::to_yaml() instead")]]
inline std::string to_yaml(const virtual_ps_controller::srv::SetButton_Response & msg)
{
  return virtual_ps_controller::srv::to_yaml(msg);
}

template<>
inline const char * data_type<virtual_ps_controller::srv::SetButton_Response>()
{
  return "virtual_ps_controller::srv::SetButton_Response";
}

template<>
inline const char * name<virtual_ps_controller::srv::SetButton_Response>()
{
  return "virtual_ps_controller/srv/SetButton_Response";
}

template<>
struct has_fixed_size<virtual_ps_controller::srv::SetButton_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<virtual_ps_controller::srv::SetButton_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<virtual_ps_controller::srv::SetButton_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<virtual_ps_controller::srv::SetButton>()
{
  return "virtual_ps_controller::srv::SetButton";
}

template<>
inline const char * name<virtual_ps_controller::srv::SetButton>()
{
  return "virtual_ps_controller/srv/SetButton";
}

template<>
struct has_fixed_size<virtual_ps_controller::srv::SetButton>
  : std::integral_constant<
    bool,
    has_fixed_size<virtual_ps_controller::srv::SetButton_Request>::value &&
    has_fixed_size<virtual_ps_controller::srv::SetButton_Response>::value
  >
{
};

template<>
struct has_bounded_size<virtual_ps_controller::srv::SetButton>
  : std::integral_constant<
    bool,
    has_bounded_size<virtual_ps_controller::srv::SetButton_Request>::value &&
    has_bounded_size<virtual_ps_controller::srv::SetButton_Response>::value
  >
{
};

template<>
struct is_service<virtual_ps_controller::srv::SetButton>
  : std::true_type
{
};

template<>
struct is_service_request<virtual_ps_controller::srv::SetButton_Request>
  : std::true_type
{
};

template<>
struct is_service_response<virtual_ps_controller::srv::SetButton_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // VIRTUAL_PS_CONTROLLER__SRV__DETAIL__SET_BUTTON__TRAITS_HPP_
