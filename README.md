# Power Management Module for Embedded Devices

## Overview

This project demonstrates a state-based power management system for embedded devices, designed to control transitions between Active, Sleep, and Idle states. By simulating real-world conditions, the module showcases energy efficiency, fault recovery, and event-driven state changes.

## Features

- **State-based Power Management:**  
  The system manages three primary states:  
  - **Active:** Normal operation mode.  
  - **Idle:** Reduced activity, waiting for events.  
  - **Sleep:** Minimal power consumption until a wake event occurs.
  
- **Energy Usage Metrics:**  
  The module tracks how long the system spends in each state, providing insights into power consumption over time.

- **Event-driven Transitions:**  
  External events such as wake triggers or idle conditions dynamically shift the system’s power state, emulating real-world embedded scenarios.

- **Fault Handling and Recovery:**  
  Basic fault detection ensures the system can recover from unexpected conditions.

- **Platform-independent Design:**  
  The code uses an abstracted hardware interface, allowing portability across different embedded platforms.

## Getting Started

### Prerequisites

- A C++17-compatible compiler
- CMake for building the project
- Python (optional) for testing or simulating external events

### Building the Project

1. Clone the repository:
   ```bash
   git clone https://github.com/YourUsername/embedded-power-module.git
   cd embedded-power-module
   ```

2. Create a build directory:
   ```bash
   mkdir build && cd build
   ```

3. Run CMake to configure the project:
   ```bash
   cmake ..
   ```

4. Build the project:
   ```bash
   make
   ```

5. Run the compiled binary:
   ```bash
   ./power_management
   ```

## File Structure

```
power_management_project/
├── src/                  # Source code files
│   ├── main.cpp          # Entry point
│   ├── PowerManager.cpp  # Implementation of power manager logic
│   ├── PowerManager.h    # Header file defining PowerManager class
├── include/              # Header files (for modular design)
│   ├── PowerManager.h
├── tests/                # Test code
│   ├── test_power_manager.cpp
├── build/                # Build artifacts (after running CMake)
├── CMakeLists.txt        # CMake configuration file
└── README.md             # Project documentation (this file)
```
