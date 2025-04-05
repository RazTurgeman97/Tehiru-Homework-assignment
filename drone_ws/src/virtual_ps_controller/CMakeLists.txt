cmake_minimum_required(VERSION 3.8)
project(virtual_ps_controller)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Find the input library
find_package(PkgConfig REQUIRED)
pkg_check_modules(INPUT REQUIRED libinput)

# Include directories
include_directories(include)

# Define the PS4 controller executable
add_executable(ps_controller_node src/ps_controller_node.cpp src/ps_controller.cpp)
ament_target_dependencies(ps_controller_node rclcpp sensor_msgs)

# Specify libraries to link executable against
target_link_libraries(ps_controller_node
  ${rclcpp_LIBRARIES}
  ${sensor_msgs_LIBRARIES}
  udev
)
# If pkg-config found the input library, use it
if(INPUT_FOUND)
  target_link_libraries(ps_controller_node ${INPUT_LIBRARIES})
endif()

# Define message and service files
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/ButtonState.msg"
  "msg/ControllerState.msg"
  "srv/SetButton.srv"
  DEPENDENCIES std_msgs
)

# This ensures the PS4 controller node can use the generated messages
rosidl_target_interfaces(ps_controller_node 
  ${PROJECT_NAME} "rosidl_typesupport_cpp")

# Install the targets
install(TARGETS
  ps_controller_node
  DESTINATION lib/${PROJECT_NAME}
)

# Install include files
install(
  DIRECTORY include
  DESTINATION include
)

ament_package()
