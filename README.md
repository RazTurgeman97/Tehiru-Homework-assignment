# Tehiru Homework Assignment

The goal of this assignment is to develop a ROS2-based solution for autonomous navigation using a drone within the LiftOff simulator.

## Table of Contents
- [Introduction](#introduction)
- [Demonstration](#demonstration)
- [Overview](#overview)
- [Key Features](#key_features)
- [Architecture](#architecture)
- [Installation](#installation)
- [Usage](#usage)
- [Packages](#packages)
- [Project Structure](#project-structure)


## Introduction

This project provides a ROS2-based control system for the LiftOff drone simulator, allowing for stable flight control and altitude regulation with automatic drift compensation.


## Demonstration

https://github.com/user-attachments/assets/13df9b57-de68-4d32-8f16-21a1eed22206


## Overview

The system consists of several interconnected packages:

- **virtual_ps_controller**: Creates a virtual PS4 controller for simulation input
- **liftoff_telemetry**: Receives and processes telemetry data from the simulator
- **liftoff_interface**: Provides high-level control for drone activation and flight
- **liftoff_utils**: Utility services and messages for drone navigation
  

## Key Features

- ✅ Automatic drone detection and activation  
- 🚡 Adaptive altitude control with drift compensation  
- 🎮 Virtual PS4 controller integration  
- 📊 Telemetry processing and visualization  
- 🧩 Modular architecture for easy extension
  

## Architecture

The system follows a modular architecture with these main components:

1. **Telemetry Module**: Receives and processes simulator data (position, attitude, velocity)
2. **Controller Module**: Translates user inputs to drone commands
3. **Flight Control**: Altitude regulation and flight stabilization
4. **Activator**: Handles simulator detection and drone arming


## Installation

1. **Clone the repository:**
    ```sh
    git clone https://github.com/RazTurgeman97/Tehiru-Homework-assignment.git
    cd Tehiru-Homework-assignment
    ```

2. **Install dependencies:**
    Ensure you have ROS2 and other necessary dependencies installed. Follow the official ROS2 installation guide for your platform.

3. **Build the project:**
    ```sh
    cd drone_ws/
    rm -rf log/ build/ install/
    colcon build
    ```

4. **Source the setup files:**
    ```sh
    source install/setup.bash
    ```

## Usage

Start the system using the provided launch file:

```bash
ros2 launch liftoff_interface drone_control.launch.py
```

### Launch Arguments

- `altitude_controller_debug`: Enable debug output for altitude controller (default: false)
- `auto_start_simulator`: Automatically start the LiftOff simulator (default: true)
- `target_altitude`: Default target altitude in meters (default: 20.0)
- `drift_adaptation_rate`: Rate at which drift compensation adapts (default: 0.002)


## Packages

### virtual_ps_controller

Provides a virtual PS4 controller interface with both Python and C++ implementations:
- ps_controller_py.py: Python implementation 
- `ps_controller.cpp/hpp`: C++ implementation
- controller.hpp: Generic controller interface

### liftoff_interface

Contains nodes for drone control:
- drone_activator.py: Detects simulator and activates the drone
- altitude_controller.py: PID-based altitude regulation
- flight_controller.py: Overall flight control logic

### liftoff_telemetry

Processes simulator data:
- liftoff_telemetry_node.py: Receives and distributes telemetry data
- 

## Development

To extend the system:

1. Use the existing message interfaces for compatibility
2. Subscribe to `telemetry/*` topics for drone state information
3. Publish to `joy` topic to control the drone
4. Check drone activation state with `drone/armed` topic


## Project Structure
```bash
Directory structure:
└── razturgeman97-tehiru-homework-assignment/
    └── drone_ws/
        └── src/
            ├── liftoff_interface/
            │   ├── package.xml
            │   ├── setup.cfg
            │   ├── setup.py
            │   ├── launch/
            │   │   └── drone_control.launch.py
            │   └── liftoff_interface/
            │       ├── __init__.py
            │       ├── altitude_controller.py
            │       ├── drone_activator.py
            │       ├── drone_controller.py
            │       └── flight_controller.py
            ├── liftoff_telemetry/
            │   ├── package.xml
            │   ├── setup.cfg
            │   ├── setup.py
            │   └── liftoff_telemetry/
            │       ├── __init__.py
            │       ├── liftoff_telemetry_node.py
            │       └── __pycache__/
            ├── liftoff_utils/
            │   ├── CMakeLists.txt
            │   ├── package.xml
            │   └── srv/
            │       └── TargetNavigation.srv
            └── virtual_ps_controller/
                ├── CMakeLists.txt
                ├── package.xml
                ├── include/
                │   └── virtual_ps_controller/
                │       ├── controller.hpp
                │       └── ps_controller.hpp
                ├── msg/
                │   ├── ButtonState.msg
                │   └── ControllerState.msg
                ├── src/
                │   ├── ps_controller.cpp
                │   └── ps_controller_node.cpp
                ├── srv/
                │   └── SetButton.srv
                └── virtual_ps_controller/
                    ├── __init__.py
                    ├── ps4_constants.py
                    └── ps_controller_py.py
```

