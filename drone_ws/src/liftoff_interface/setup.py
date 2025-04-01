from setuptools import find_packages, setup

package_name = 'liftoff_interface'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
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
            'controller = liftoff_interface.controller:main',
            'sensor_listener = liftoff_interface.sensor_listener:main',
            'liftoff_bridge = liftoff_interface.liftoff_bridge:main',
        ],
    },
)
