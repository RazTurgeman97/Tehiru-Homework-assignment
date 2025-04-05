from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    """
    Launch file for basic drone control with the PS4 controller
    
    This launch file starts:
    1. The telemetry node to receive data from the simulator
    2. The PS4 controller node to provide controller input
    3. The attitude adapter to fix mixed message types
    4. The drone activator to automatically activate the drone when the sim is running
    5. The drone controller for handling control logic
    """
    
    # Telemetry node receives data from LiftOff simulator
    telemetry_node = Node(
        package='liftoff_telemetry',
        executable='liftoff_telemetry_node',
        name='liftoff_telemetry_node'
    )
    
    # Virtual PS4 controller node
    ps_controller_node = Node(
        package='virtual_ps_controller',
        executable='ps_controller_node',
        name='ps_controller_node'
    )
    
    # Attitude adapter converts mixed message types to a standardized format
    attitude_adapter = Node(
        package='liftoff_interface',
        executable='attitude_adapter',
        name='attitude_adapter'
    )
    
    # Drone activator automatically detects when sim is running and activates the drone
    drone_activator = Node(
        package='liftoff_interface',
        executable='drone_activator',
        name='drone_activator'
    )
    
    # Drone controller for processing input and managing drone behavior
    drone_controller = Node(
        package='liftoff_interface',
        executable='drone_controller',
        name='drone_controller'
    )
    
    return LaunchDescription([
        telemetry_node,
        ps_controller_node,
        attitude_adapter,
        drone_activator,
        drone_controller
    ])