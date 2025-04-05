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
            'drone_activator = liftoff_interface.drone_activator:main',
            'altitude_controller = liftoff_interface.altitude_controller:main',
            'flight_controller = liftoff_interface.flight_controller:main',
        ],
    },
)
