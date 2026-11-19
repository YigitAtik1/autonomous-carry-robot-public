# Autonomous Carry Robot

**Autonomous Mobile Robotics | Localization | Path Planning | Embedded Control**

A university senior design project developed at MEF University in 2021, focused on autonomous navigation, obstacle detection, localization, and motion control.

This repository preserves the original academic work and serves as a foundation for future robotics software development.

## Project Overview

The Autonomous Carry Robot project investigated and implemented core components of an autonomous mobile robotic system.

The project combined:

- Arduino-based motor control
- Ultrasonic obstacle detection
- Adaptive Wavefront path planning
- Camera-based localization using ArUco markers and OpenCV
- MATLAB simulations for path planning and LiDAR SLAM

The physical prototype and the MATLAB simulations represent different stages of the original research.

## System Architecture

The original project included three main components:

**Perception and Localization**

An external camera and ArUco markers were used to estimate the robot's position relative to reference markers. Ultrasonic sensing supported obstacle detection.

**Navigation and Path Planning**

An Adaptive Wavefront algorithm operated on a grid-based representation of the environment, supporting path selection and obstacle updates.

**Motion Control**

An Arduino Uno controlled the robot's movement using a motor driver and DC motors.

## Technologies

| Area | Technologies |
|---|---|
| Embedded Systems | Arduino Uno, C/C++ |
| Computer Vision | Python, OpenCV, ArUco |
| Path Planning | Adaptive Wavefront, PRM |
| Simulation | MATLAB |
| Mapping Research | LiDAR SLAM |
| Hardware | HC-SR04, L298 motor driver, DC motors |

## Repository Structure

```text
autonomous-carry-robot/
├── docs/
│   └── thesis/
│       └── Autonomous_Carry_Robot_Thesis_2021.pdf
├── legacy/
│   ├── arduino/
│   │   └── autonomous_carry_robot.ino
│   ├── python/
│   │   └── aruco_localization.py
│   └── matlab/
│       ├── path_planning/
│       │   └── path_planning_known_map.m
│       └── simulations/
│           └── lidar_slam_simulation.m
├── src/
│   └── carry_robot/
├── tests/
├── pyproject.toml
└── README.md
```

## Original Research and Implementation

The 2021 project included a physical mobile robot prototype, Arduino-based motion control, ultrasonic obstacle sensing, camera-based ArUco localization, and Adaptive Wavefront navigation.

MATLAB was used separately to investigate path planning and LiDAR SLAM techniques in simulation.

The original thesis is available under `docs/thesis/`.

### Legacy Source Code

The source files under `legacy/` were reconstructed from code listings included in the 2021 thesis.

They are preserved for historical reference and have not been fully validated, compiled, or tested in the current development environment.

They should not be treated as production-ready implementations.

## Modernization Roadmap

Future development is planned to include:

- Reimplementing navigation algorithms in modern Python
- Adding automated unit and integration tests
- Building reproducible robotics simulations
- Exploring ROS 2 integration
- Improving software architecture and documentation

These improvements are planned work and are not presented as completed features.

## Contributors

**Original Senior Design Project — MEF University, 2021**

- Yiğit Atik
- Ziya Oğuzhan Çevik

**Academic Advisor:** Dr. Yusuf Aydın

## Project Status

**Original academic project:** Completed in 2021.

**Legacy source archival:** Completed, pending further validation.

**Modern Python / ROS 2 development:** Planned.