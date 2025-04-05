from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    
    controller_node = Node(
        package='virtual_ps_controller',
        executable='ps_controller',
        name='ps_controller_node',
        output='screen',
        emulate_tty=True,
        parameters=[
            {'joy_topic': 'joy'}
        ],
    )
    
    telemetry_node = Node(
        package='virtual_ps_telemetry',
        executable='virtual_ps_telemetry_node',
        name='virtual_ps_telemetry_node',
        output='screen',
        parameters=[{'config_file': 'config/telemetry_config.yaml'}]
    )
    
    return LaunchDescription([
        controller_node,
        # telemetry_node,
    ])