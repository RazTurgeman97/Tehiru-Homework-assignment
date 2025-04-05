// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from virtual_ps_controller:msg/ControllerState.idl
// generated code does not contain a copyright notice

#ifndef VIRTUAL_PS_CONTROLLER__MSG__DETAIL__CONTROLLER_STATE__TRAITS_HPP_
#define VIRTUAL_PS_CONTROLLER__MSG__DETAIL__CONTROLLER_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "virtual_ps_controller/msg/detail/controller_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'buttons'
#include "virtual_ps_controller/msg/detail/button_state__traits.hpp"

namespace virtual_ps_controller
{

namespace msg
{

inline void to_flow_style_yaml(
  const ControllerState & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: buttons
  {
    if (msg.buttons.size() == 0) {
      out << "buttons: []";
    } else {
      out << "buttons: [";
      size_t pending_items = msg.buttons.size();
      for (auto item : msg.buttons) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: axes
  {
    if (msg.axes.size() == 0) {
      out << "axes: []";
    } else {
      out << "axes: [";
      size_t pending_items = msg.axes.size();
      for (auto item : msg.axes) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ControllerState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: buttons
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.buttons.size() == 0) {
      out << "buttons: []\n";
    } else {
      out << "buttons:\n";
      for (auto item : msg.buttons) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: axes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.axes.size() == 0) {
      out << "axes: []\n";
    } else {
      out << "axes:\n";
      for (auto item : msg.axes) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ControllerState & msg, bool use_flow_style = false)
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
  const virtual_ps_controller::msg::ControllerState & msg,
  std::ostream & out, size_t indentation = 0)
{
  virtual_ps_controller::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use virtual_ps_controller::msg::to_yaml() instead")]]
inline std::string to_yaml(const virtual_ps_controller::msg::ControllerState & msg)
{
  return virtual_ps_controller::msg::to_yaml(msg);
}

template<>
inline const char * data_type<virtual_ps_controller::msg::ControllerState>()
{
  return "virtual_ps_controller::msg::ControllerState";
}

template<>
inline const char * name<virtual_ps_controller::msg::ControllerState>()
{
  return "virtual_ps_controller/msg/ControllerState";
}

template<>
struct has_fixed_size<virtual_ps_controller::msg::ControllerState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<virtual_ps_controller::msg::ControllerState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<virtual_ps_controller::msg::ControllerState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VIRTUAL_PS_CONTROLLER__MSG__DETAIL__CONTROLLER_STATE__TRAITS_HPP_
