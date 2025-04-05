from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, ExecuteProcess
from launch.substitutions import LaunchConfiguration
from launch.conditions import IfCondition
import os

def generate_launch_description():
    """
    Launch file for the LiftOff drone control system
    
    This launch file starts:
    1. The LiftOff simulator through Steam
    2. The telemetry node to receive data from the simulator
    3. The PS4 controller node to provide controller input
    4. The drone activator to detect the sim and activate the drone
    5. The altitude controller for smooth altitude management
    6. The flight controller for all other flight controls
    """
    
    # Declare the launch arguments
    altitude_controller_debug = DeclareLaunchArgument(
        'altitude_controller_debug',
        default_value='false',
        description='Enable debug output for altitude controller'
    )
    
    auto_start_simulator = DeclareLaunchArgument(
        'auto_start_simulator',
        default_value='true',
        description='Automatically start the LiftOff simulator'
    )
    
    # Start LiftOff through Steam using the provided command
    liftoff_app = ExecuteProcess(
        cmd=['snap', 'run', 'steam', 'steam://rungameid/410340'],
        name='liftoff_simulator',
        output='screen',
        condition=IfCondition(LaunchConfiguration('auto_start_simulator'))
    )
    
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
    
    # Drone activator to detect simulation and activate the drone
    drone_activator = Node(
        package='liftoff_interface',
        executable='drone_activator',
        name='drone_activator'
    )
    
    # Altitude controller for smooth height control with debug parameter
    altitude_controller = Node(
        package='liftoff_interface',
        executable='altitude_controller',
        name='altitude_controller',
        parameters=[{'debug': LaunchConfiguration('altitude_controller_debug')}]
    )
    
    # Flight controller for processing input and managing drone behavior
    flight_controller = Node(
        package='liftoff_interface',
        executable='flight_controller',
        name='flight_controller'
    )
    
    return LaunchDescription([
        altitude_controller_debug,
        auto_start_simulator,
        liftoff_app,
        telemetry_node,
        ps_controller_node,
        drone_activator,
        altitude_controller,
        flight_controller
    ])