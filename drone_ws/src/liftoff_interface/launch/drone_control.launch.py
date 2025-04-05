from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    """
    Launch file for the LiftOff drone control system
    
    This launch file starts:
    1. The telemetry node to receive data from the simulator
    2. The PS4 controller node to provide controller input
    3. The drone activator to detect the sim and activate the drone
    4. The altitude controller for smooth altitude management
    5. The flight controller for all other flight controls
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
    
    # Drone activator to detect simulation and activate the drone
    drone_activator = Node(
        package='liftoff_interface',
        executable='drone_activator',
        name='drone_activator'
    )
    
    # Altitude controller for smooth height control
    altitude_controller = Node(
        package='liftoff_interface',
        executable='altitude_controller',
        name='altitude_controller'
    )
    
    # Flight controller for processing input and managing drone behavior
    flight_controller = Node(
        package='liftoff_interface',
        executable='flight_controller',
        name='flight_controller'
    )
    
    return LaunchDescription([
        telemetry_node,
        ps_controller_node,
        drone_activator,
        altitude_controller,
        flight_controller
    ])