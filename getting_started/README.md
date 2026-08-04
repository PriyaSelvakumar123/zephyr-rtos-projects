# Getting Started

## Overview

This module covers the fundamentals required to begin developing applications with **Zephyr RTOS**. It includes environment setup, understanding the Zephyr application structure, DeviceTree basics, and running official Zephyr sample applications.

---

## Prerequisites

- Ubuntu (WSL/Linux)
- Zephyr SDK
- West
- CMake
- Ninja
- Python 3
- Git

---

## Installation

- Install the Zephyr SDK.
- Install the required development tools.
- Initialize the Zephyr workspace.
- Install project dependencies.
- Verify the installation by building and running a sample application.

---

## Build Workflow

1. Build the application using `west`.
2. Flash the application to the target board.
3. Open the serial terminal.
4. Verify the application output.

---

## Zephyr Application Structure

A typical Zephyr application contains:

| File/Folder | Purpose |
|-------------|---------|
| `src/` | Application source code |
| `CMakeLists.txt` | Build configuration |
| `prj.conf` | Kconfig options |
| `app.overlay` | DeviceTree overlay for hardware configuration |
| `boards/` | Board-specific configuration (optional) |

---

## DeviceTree Basics

DeviceTree describes the hardware available on the board and allows applications to access peripherals without modifying the application source code.

### Key Concepts

- Nodes represent hardware devices.
- Properties describe device configuration.
- Aliases provide convenient names for devices.
- Overlays extend or modify the board's default DeviceTree.

### In this module

- Learned the DeviceTree structure.
- Added an accelerometer node.
- Configured the sensor on **I²C2**.
- Used DeviceTree to enable the sensor for the application.

---

## Official Samples

| Sample | Description |
|---------|-------------|
| Blinky | Basic GPIO LED control |
| Accelerometer Polling | Read accelerometer data using the Zephyr Sensor API |

---

## Skills Gained

- Zephyr environment setup
- Building and flashing applications
- Running official samples
- Understanding Zephyr application structure
- DeviceTree fundamentals
- Basic Kconfig configuration
- I²C peripheral configuration
- Sensor API usage

---

## Repository Structure

```
getting_started/
├── README.md
├── blinky/
└── accel_polling/
```

---

## Next Module

After completing this module, continue with **Kernel API** to learn:

- Threads
- Thread Scheduling
- Semaphores
- Mutexes
- Message Queues
- Timers
- Other Zephyr kernel services
