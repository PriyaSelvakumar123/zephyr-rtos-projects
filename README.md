# Zephyr RTOS Projects

![License](https://img.shields.io/badge/License-MIT-blue.svg)
![RTOS](https://img.shields.io/badge/RTOS-Zephyr-734f96)
![Language](https://img.shields.io/badge/Language-C-blue.svg)
![Board](https://img.shields.io/badge/Board-STM32_Nucleo_F411RE-orange.svg)

A structured collection of **Zephyr RTOS** examples demonstrating kernel services, device drivers, peripherals, and embedded firmware development on the **STM32 Nucleo-F411RE** development board.

Each project focuses on a single concept and is designed to provide a clear understanding of Zephyr APIs through clean, modular, and well-documented implementations.

---

## Repository Goals

This repository aims to:

- Learn Zephyr RTOS through practical examples.
- Understand Zephyr Kernel architecture and APIs.
- Build reusable embedded firmware components.
- Explore DeviceTree-based hardware configuration.
- Develop industry-standard embedded software practices.

---

# Repository Structure

```text
zephyr-rtos-projects/
│
├── getting_started/
│   ├── blinky/
│   ├── accel_polling/
│   └── README.md
│
├── kernel_api/
│   ├── 01_threads/
│   ├── 02_thread_scheduling/
│   ├── 03_semaphores/
│   ├── 04_mutex/
│   ├── 05_message_queue/
│   ├── 06_fifo_lifo/
│   ├── 07_timers/
│   └── 08_workqueue/
│
├── interrupts/
├── device_drivers/
├── peripherals/
├── sensors/
│
└── README.md
```

Each project is an independent Zephyr application containing:

- Source code
- Build configuration
- DeviceTree overlay (if required)
- Project documentation

---

# Learning Roadmap

| Module | Topics |
|---------|--------|
| Getting Started | Build System, GPIO, Sensor Basics |
| Kernel API | Threads, Scheduling, Synchronization |
| Interrupts | GPIO Interrupts, ISR |
| Device Drivers | UART, I2C, SPI |
| Peripherals | PWM, ADC, Timers |
| Sensors | Sensor Framework |

---

# Features

- Zephyr Kernel APIs
- Thread Creation
- Cooperative Scheduling
- Preemptive Scheduling
- Thread Priorities
- GPIO Programming
- DeviceTree
- Interrupt Handling
- Timers
- UART
- I²C
- SPI
- PWM
- ADC
- Sensor Drivers

---

# Development Environment

| Component | Description |
|----------|-------------|
| RTOS | Zephyr RTOS |
| Language | C |
| Board | STM32 Nucleo-F411RE |
| MCU | STM32F411RET6 |
| Build System | West + CMake + Ninja |
| Toolchain | Zephyr SDK |

---

# Prerequisites

Install:

- Zephyr SDK
- West
- Python 3
- CMake
- Ninja
- ARM Toolchain

Initialize the Zephyr workspace by following the official Zephyr installation guide.

---

# Build

```bash
west build -b nucleo_f411re
```

---

# Flash

```bash
west flash
```

---

# Serial Console

Using Minicom

```bash
minicom -D /dev/ttyACM0 -b 115200
```

Using Picocom

```bash
picocom -b 115200 /dev/ttyACM0
```

---

# Design Principles

- One concept per project
- Modular project organization
- Standard Zephyr application layout
- DeviceTree-driven hardware configuration
- Portable and reusable code
- Well-documented implementations
- Progressive learning approach

---

# Repository Status

| Module | Status |
|---------|:------:|
| Getting Started | ✅ Complete |
| Threads | ✅ Complete |
| Thread Scheduling | ✅ Complete |
| Synchronization | 🚧 In Progress |
| Interrupts | ⏳ Planned |
| Device Drivers | ⏳ Planned |
| Peripherals | ⏳ Planned |
| Sensors | ⏳ Planned |

---

# Future Work

- Semaphores
- Mutexes
- Message Queues
- FIFO & LIFO
- Timers
- Work Queues
- UART Driver
- SPI Driver
- I²C Driver
- PWM
- ADC
- Bluetooth LE
- USB
- Networking
- Power Management

---

# References

- Zephyr Project Documentation
- Zephyr API Reference
- Zephyr Samples
- Zephyr Kernel Documentation
- Zephyr DeviceTree Guide

---

# Author

**Priya Dharshini S**

**Electronics and Communication Engineering**

Embedded Systems | Firmware Development | Zephyr RTOS | STM32 | C Programming

GitHub: **https://github.com/PriyaSelvakumar123**

---

# License

This project is licensed under the **MIT License**.

Feel free to use, modify, and share this repository for learning and development purposes.
