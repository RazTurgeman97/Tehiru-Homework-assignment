// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from virtual_ps_controller:msg/ButtonState.idl
// generated code does not contain a copyright notice

#ifndef VIRTUAL_PS_CONTROLLER__MSG__DETAIL__BUTTON_STATE__TRAITS_HPP_
#define VIRTUAL_PS_CONTROLLER__MSG__DETAIL__BUTTON_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "virtual_ps_controller/msg/detail/button_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace virtual_ps_controller
{

namespace msg
{

inline void to_flow_style_yaml(
  const ButtonState & msg,
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
  const ButtonState & msg,
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

inline std::string to_yaml(const ButtonState & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace virtual_ps_controller

namespace rosidl_generator_traits
{

[[deprecated("use virtual_ps_controller::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const virtual_ps_controller::msg::ButtonState & msg,
  std::ostream & out, size_t indentation = 0)
{
  virtual_ps_controller::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use virtual_ps_controller::msg::to_yaml() instead")]]
inline std::string to_yaml(const virtual_ps_controller::msg::ButtonState & msg)
{
  return virtual_ps_controller::msg::to_yaml(msg);
}

template<>
inline const char * data_type<virtual_ps_controller::msg::ButtonState>()
{
  return "virtual_ps_controller::msg::ButtonState";
}

template<>
inline const char * name<virtual_ps_controller::msg::ButtonState>()
{
  return "virtual_ps_controller/msg/ButtonState";
}

template<>
struct has_fixed_size<virtual_ps_controller::msg::ButtonState>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<virtual_ps_controller::msg::ButtonState>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<virtual_ps_controller::msg::ButtonState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VIRTUAL_PS_CONTROLLER__MSG__DETAIL__BUTTON_STATE__TRAITS_HPP_
