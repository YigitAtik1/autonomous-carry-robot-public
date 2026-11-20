# System Architecture — 2021 Prototype

The original project combined **camera-based localization**, **grid-based navigation**, and **embedded motor control** in a physical mobile robot. It also investigated known-map planning and LiDAR SLAM in **separate MATLAB simulations**.

## Subsystem boundaries

| Subsystem | Platform | Evidence | Status |
|---|---|---|---|
| Known-map planning, PRM, Pure Pursuit | MATLAB | `legacy/matlab/path_planning/path_planning_known_map.m` | Historical simulation; not revalidated |
| LiDAR SLAM and mapping | MATLAB | `legacy/matlab/simulations/lidar_slam_simulation.m` | Separate simulation; not onboard physical LiDAR |
| Camera calibration and ArUco tracking | Python/OpenCV | `legacy/python/aruco_localization.py` | Thesis-documented; transcription not executable as-is |
| Relative marker pose | Python/OpenCV | `relativePosition()` and `stepFunction()` | Historical code; no modern regression tests |
| Adaptive grid navigation | Arduino/C++ | `legacy/arduino/autonomous_carry_robot.ino` | Historical embedded implementation; not recompiled |
| Motor control | Arduino/C++ | `motorControlFunction()` and drive/turn routines | Historical timed commands; no current hardware validation |
| Circuit and physical prototype | Electronics | Thesis Appendix 3, photographs | Schematic and prototype documented |

**Integration boundary:** the thesis conclusion identifies unresolved work on transferring a map to Arduino at sufficient resolution and tighter MATLAB–Arduino integration. Do not interpret the separate MATLAB SLAM simulation as an end-to-end deployed SLAM robot.

## Source provenance

Original project: MEF University senior design, 2021. Legacy files were transcribed from thesis appendices and may contain formatting defects. The full thesis is at [`docs/thesis/Autonomous_Carry_Robot_Thesis_2021.pdf`](../thesis/Autonomous_Carry_Robot_Thesis_2021.pdf).
