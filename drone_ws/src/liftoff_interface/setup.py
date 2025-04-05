from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'liftoff_interface'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        # Include all launch files in the 'launch' directory
        (os.path.join('share', package_name, 'launch'), glob('launch/*.launch.py')),

    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='raz',
    maintainer_email='Raz.Turgeman97@gmail.com',
    description='ROS2 package to interface with the LiftOff drone simulator',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'drone_controller = liftoff_interface.drone_controller:main',
            'sensor_listener = liftoff_interface.sensor_listener:main',
            'liftoff_bridge = liftoff_interface.liftoff_bridge:main',
            'target_selector = liftoff_interface.target_selector:main',
            'mock_obstacle_publisher = liftoff_interface.mock_obstacle_publisher:main',
            'target_navigation_service = liftoff_interface.target_navigation_service:main',
            'drone_activator = liftoff_interface.drone_activator:main',
            'attitude_adapter = liftoff_interface.attitude_adapter:main',
            # 'telemetry_listener = liftoff_interface.telemetry_listener:main',
            # 'telemetry_publisher = liftoff_interface.telemetry_publisher:main',
            # 'telemetry_publisher_node = liftoff_interface.telemetry_publisher_node:main',
        ],
    },
)
