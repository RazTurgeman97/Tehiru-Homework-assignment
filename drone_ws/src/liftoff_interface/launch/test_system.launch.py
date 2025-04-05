from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    virtual_controller = Node(
        package='virtual_controller',  # Fixed package name
        executable='virtual_controller_node',
        name='virtual_controller_node'
    )
    
    telemetry_node = Node(
        package='liftoff_telemetry',
        executable='liftoff_telemetry_node',
        name='liftoff_telemetry_node'
    )
    
    target_selector = Node(
        package='liftoff_interface',
        executable='target_selector',
        name='target_selector'
    )
    
    mock_obstacle_publisher = Node(
        package='liftoff_interface',
        executable='mock_obstacle_publisher',
        name='mock_obstacle_publisher'
    )
    
    drone_controller = Node(
        package='liftoff_interface',
        executable='drone_controller',
        name='drone_controller'
    )
    
    liftoff_bridge = Node(
        package='liftoff_interface',
        executable='liftoff_bridge',
        name='liftoff_bridge'
    )
    
    target_navigation_service = Node(
        package='liftoff_interface',
        executable='target_navigation_service',
        name='target_navigation_service'
    )
    
    return LaunchDescription([
        virtual_controller,
        telemetry_node,
        target_selector,
        mock_obstacle_publisher,
        drone_controller,
        # liftoff_bridge,
        target_navigation_service
    ])