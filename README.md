# Zephyr RTOS Projects

A collection of hands-on **Zephyr RTOS** projects developed while learning the Zephyr ecosystem. This repository focuses on understanding the Zephyr kernel, DeviceTree, GPIO drivers, thread scheduling, synchronization, and embedded application development using STM32 development boards.

The objective of this repository is to build a strong foundation in Zephyr RTOS through practical examples rather than isolated code snippets.

---

## Hardware

* STM32 Nucleo-F411RE
* On-board LED
* External LEDs
* USB Serial Console

---

## Development Environment

| Tool         | Version     |
| ------------ | ----------- |
| Zephyr RTOS  | 4.x         |
| West         | Latest      |
| Zephyr SDK   | 0.17.x      |
| CMake        | 3.20+       |
| Ninja        | Latest      |
| VS Code      | Latest      |
| Ubuntu (WSL) | Recommended |

---

# Repository Structure

```text
zephyr-rtos-projects/
│
├── getting_started/
├── kernel_api/
├── drivers/
├── networking/
├── boards/
├── docs/
└── README.md
```


---

# Topics Covered

* Zephyr Workspace Setup
* West Build System
* DeviceTree Basics
* GPIO Driver API
* Kernel Threads
* Thread Priorities
* Preemptive Scheduling
* Cooperative Scheduling
* Kernel Timing
* Serial Console Output
* STM32 Board Support

---

# Current Projects

| Folder                            | Description                                          |
| --------------------------------- | ---------------------------------------------------- |
| `getting_started`                 | Basic Zephyr applications and workspace setup        |
| `kernel_api/01_threads`           | Thread creation using Zephyr Kernel APIs             |
| `kernel_api/02_thread_scheduling` | Cooperative and Preemptive scheduling demonstrations |

More projects will be added as I continue exploring the Zephyr ecosystem.

---

# Learning Goals

This repository is being developed to gain practical experience with:

* Zephyr Kernel
* Device Drivers
* DeviceTree
* Interrupt Handling
* Synchronization Mechanisms
* Timers and Work Queues
* Sensors
* Communication Protocols (UART, I2C, SPI)
* Custom Driver Development

---

# Build

```bash
west build -b nucleo_f411re
```

Flash

```bash
west flash
```

Serial Console

```bash
minicom -D /dev/ttyACM0 -b 115200
```

---

# Repository Highlights

* Well-organized folder structure
* Individual README for each project
* Practical examples with STM32
* DeviceTree overlays included where required
* Focus on understanding Zephyr internals

---

# Future Work

* GPIO Interrupts
* Timers
* Work Queues
* Mutexes
* Semaphores
* Message Queues
* FIFOs
* UART Driver
* I2C Driver
* SPI Driver
* Sensor Drivers
* Custom Zephyr Driver Development

---

## References

* Zephyr Official Documentation
* Zephyr Kernel API
* STM32 Nucleo-F411RE Board Documentation

---

## Author

**Priya Dharshini**

Embedded Systems | Electronics & Communication Engineering

Learning Zephyr RTOS through practical embedded projects.
