# Zephyr RTOS Projects

![License](https://img.shields.io/badge/License-MIT-blue.svg)
![RTOS](https://img.shields.io/badge/RTOS-Zephyr%203.x-734f96)
![Language](https://img.shields.io/badge/Language-C-blue.svg)
![Board](https://img.shields.io/badge/Board-STM32_Nucleo_F411RE-orange.svg)
![Microcontroller](https://img.shields.io/badge/MCU-ARM_Cortex--M4-red.svg)

A structured collection of **Zephyr RTOS** examples demonstrating kernel services, device drivers, peripherals, and embedded firmware development on the **STM32 Nucleo-F411RE** development board. 

This repository is designed as a learning resource, progressing from basic hardware abstraction (GPIO, Sensors) to raw Kernel Scheduler behavior (Threads, Cooperative/Preemptive scheduling, IPC). Each subdirectory isolates a single concept with a modular, scalable, and production-ready implementation.

---

## Table of Contents

- [Repository Directory Structure](#repository-directory-structure)
- [Module Deep Dive](#module-deep-dive)
  - [1. Getting Started](#1-getting-started)
  - [2. Kernel API - Threads](#2-kernel-api---threads)
  - [3. Kernel API - Thread Scheduling](#3-kernel-api---thread-scheduling)
- [Zephyr Scheduling Mechanics](#zephyr-scheduling-mechanics)
  - [Cooperative Scheduling Flow](#cooperative-scheduling-flow)
  - [Preemptive Scheduling Flow](#preemptive-scheduling-flow)
- [Hardware & Pin Mapping](#hardware--pin-mapping)
- [Development Environment Setup](#development-environment-setup)
- [Build and Flash Guide](#build-and-flash-guide)
- [Learning Roadmap & Status](#learning-roadmap--status)
- [References](#references)
- [Author & License](#author--license)

---

## Repository Directory Structure

```text
zephyr-rtos-projects/
│
├── getting_started/
│   ├── README.md                      # Module setup & Devicetree overview
│   ├── blinky/                        # Introductory LED control example
│   └── accel_polling/                 # Read 3-axis accelerometer data (Sensor API)
│
├── kernel_api/
│   ├── 01_threads/                    # Static thread creation & priority assignment
│   │   ├── app.overlay                # Devicetree overlay for dual LED aliases
│   │   ├── prj.conf                   # Thread and GPIO Kconfig options
│   │   └── src/main.c                 # Multi-threaded toggle logic
│   │
│   └── 02_thread_scheduling/          # In-depth scheduling demonstrations
│       ├── README.md                  # Scheduling concepts comparison
│       ├── cooperative_thread/        # Negative priorities & yielding mechanics
│       └── preemptive_demo/           # Positive priorities & preemption mechanics
│
└── README.md                          # Main project guide (this file)
```

Each subdirectory behaves as a standalone Zephyr application containing its own build configurations (`CMakeLists.txt`), configuration overlays (`prj.conf`), source codes (`src/main.c`), and optional DeviceTree overlays (`app.overlay`).

---

## Module Deep Dive

### 1. Getting Started

Designed to familiarise developers with the Zephyr project layout and hardware abstraction layer (HAL) configuration using the DeviceTree.

#### A. Blinky
- **Description**: The classic "Hello World" of embedded systems.
- **Hardware Integration**: Directly binds to the onboard user LED via the standard DeviceTree alias (`led0`).
- **Core APIs**: `gpio_pin_configure_dt()`, `gpio_pin_toggle_dt()`, `k_msleep()`.

#### B. Accelerometer Polling
- **Description**: Uses Zephyr's **Sensor API** to poll standard 3-axis accelerometer values.
- **Hardware Integration**: Dynamically matches up to 10 accelerometer nodes bound via DeviceTree aliases (`accel0` through `accel9`). Supports polling and streaming mode configurations.
- **Core APIs**: `sensor_sample_fetch()`, `sensor_channel_get()`, `sensor_value_to_double()`.

---

### 2. Kernel API - Threads

Demonstrates how to declare and control threads statically in Zephyr RTOS at compile-time and configure multi-threaded synchronization.

#### Threads Demo (`01_threads`)
- **Description**: Spawns two independent execution threads (`thread0` and `thread1`) that drive the onboard LED (`led0`) and an external LED connected to pin **PA9** (`led1`).
- **DeviceTree Overlays**: Utilizes `app.overlay` to link `PA9` to `led1` under the `gpio-leds` driver context.
- **Priority Specs**:
  - `thread0`: Priority `3` (higher priority), toggling `led0` every 500 ms.
  - `thread1`: Priority `5` (lower priority), toggling `led1` every 2000 ms.

```c
/* Static thread registration at compile-time */
K_THREAD_DEFINE(thread0_id, STACK_SIZE, thread0, NULL, NULL, NULL, 3, 0, 0);
K_THREAD_DEFINE(thread1_id, STACK_SIZE, thread1, NULL, NULL, NULL, 5, 0, 0);
```

---

### 3. Kernel API - Thread Scheduling

Presents how the Zephyr RTOS Scheduler acts depending on whether the active thread is cooperative or preemptive.

#### A. Cooperative Scheduling (`cooperative_thread`)
- **Description**: Demonstrates cooperative threads using negative priority values (`-1` and `-2`).
- **Concept**: A running cooperative thread cannot be forced off the CPU by another thread, regardless of its priority. It must voluntarily yield control by calling blocking calls (`k_sleep()`, `k_msleep()`) or by calling `k_yield()`.
- **Implementation**: The low-priority cooperative thread (`-1`) runs an intense loop of 10 increments without yielding. The high-priority cooperative thread (`-2`) is READY but blocked from running until the low-priority thread explicitly executes `k_yield()`.

#### B. Preemptive Scheduling (`preemptive_demo`)
- **Description**: Demonstrates preemptive threads using positive priority values (`2` and `5`).
- **Concept**: A running preemptive thread will instantly be suspended by the scheduler the moment a higher-priority preemptive thread becomes execution-ready.
- **Implementation**: A low-priority thread (`5`) CPU busy-waits via `k_busy_wait()`. When the high-priority thread (`2`) finishes its 1-second sleep time, the Scheduler immediately preempts the low-priority thread to execute the high-priority tasks.

---

## Zephyr Scheduling Mechanics

The following diagrams illustrate the scheduling behavior modeled in the `02_thread_scheduling` directory, matching the official Zephyr RTOS layout:

### Cooperative Time Slicing
![Cooperative Time Slicing](https://docs.zephyrproject.org/latest/_images/cooperative.svg)

### Preemptive Time Slicing
![Preemptive Time Slicing](https://docs.zephyrproject.org/latest/_images/preemptive.svg)

---

## Zephyr Data Passing Objects

The following table summarizes the high-level features of kernel objects that can be used to pass data between threads and ISRs, referenced directly from the [Zephyr Kernel Services Documentation](https://docs.zephyrproject.org/latest/kernel/services/index.html):

| Object | Bidirectional? | Data Structure | Data Item Size | Data Alignment | ISRs Receive? | ISRs Send? | Overrun Handling |
| :--- | :---: | :--- | :--- | :--- | :---: | :---: | :--- |
| **FIFO** | No | Queue | Arbitrary | 4 B | Yes* | Yes | N/A |
| **LIFO** | No | Queue | Arbitrary | 4 B | Yes* | Yes | N/A |
| **Stack** | No | Array | Word | Word | Yes* | Yes | Undefined behavior |
| **Message Queue** | No | Ring Buffer | Arbitrary | Power of two | Yes* | Yes | Pend thread or return `-errno` |
| **Mailbox** | Yes | Queue | Arbitrary | Arbitrary | No | No | N/A |
| **Pipe** | No | Ring Buffer | Arbitrary | Arbitrary | Yes* | Yes* | Pend thread or return `-errno` |

*\*Only when passing `K_NO_WAIT` as the timeout argument.*


---

## Hardware & Pin Mapping

Configurations are tested on the **STM32 Nucleo-F411RE**.

| Component / Function | GPIO pin (Nucleo) | DeviceTree Node / Alias |
|----------------------|-------------------|--------------------------|
| **Green user LED**   | PA5               | `led0` (Onboard alias)   |
| **External Green LED**| PA9              | `led1` (Defined in overlay) |
| **I2C2 Clock (SCL)** | PB10              | `i2c2` (Accel polling)   |
| **I2C2 Data (SDA)**  | PB3               | `i2c2` (Accel polling)   |
| **Serial Tx (UART2)**| PA2               | Console logs (ST-LINK Virtual COM)|
| **Serial Rx (UART2)**| PA3               | Console logs (ST-LINK Virtual COM)|

---

## Development Environment Setup

To compile and load these projects, you need to set up the Zephyr environment on your host machine (WSL2/Linux or Windows Setup):

1. **Initialize West Workspace**:
   ```bash
   # Create a fresh Zephyr workspace directory
   west init ~/zephyrproject
   cd ~/zephyrproject
   west update
   ```

2. **Install Python & System Dependencies**:
   ```bash
   # Export Zephyr dependencies
   west zephyr-export
   pip install -r ~/zephyrproject/zephyr/scripts/requirements.txt
   ```

3. **Install Zephyr SDK**:
   Download and install the appropriate Zephyr SDK translation toolchain for ARM:
   ```bash
   # E.g. on Ubuntu:
   cd ~
   wget https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.16.8/zephyr-sdk-0.16.8_linux-x86_64.tar.xz
   tar xf zephyr-sdk-0.16.8_linux-x86_64.tar.xz
   cd zephyr-sdk-0.16.8
   ./setup.sh
   ```

---

## Build and Flash Guide

Substitute the path with the project you want to compile. The `-p always` flag forces a clean build directory refresh.

### 1. Compile Code
```bash
# Navigate to the repository root directory
cd zephyr-rtos-projects

# Example: Build 01_threads on Nucleo F411RE
west build -p always -b nucleo_f411re kernel_api/01_threads
```

### 2. Upload/Flash to Microcontroller
Ensure the Nucleo-F411RE board is connected via USB:
```bash
west flash
```

### 3. Open Serial Console
To read `printk()` and log statements, open an active terminal utility at **115200 baud**:

- **Using Minicom**:
  ```bash
  minicom -D /dev/ttyACM0 -b 115200
  ```
- **Using Picocom**:
  ```bash
  picocom -b 115200 /dev/ttyACM0
  ```
- **Using PySerial Toolkit**:
  ```bash
  python -m serial.tools.miniterm /dev/ttyACM0 115200
  ```

---

## Learning Roadmap & Status

| Module | Submodule / API Topic | Status | Target Hardware |
| :--- | :--- | :---: | :--- |
| **Getting Started** | GPIO Led Toggling (Blinky) | ✅ | STM32 Nucleo-F411RE |
| | Sensor Pollings (I2C) | ✅ | STM32 + 3-Axis Accel |
| **Kernel API** | Compile-Time Threads (`K_THREAD_DEFINE`) | ✅ | STM32 + Dual LEDs |
| | Cooperative Scheduling (`k_yield`) | ✅ | Virtual Console |
| | Preemptive Scheduling (`k_busy_wait`) | ✅ | Virtual Console |
| | Semaphores & Mutex API | 🚧 | Under Development |
| | Message Queues & Timers | ⏳ | Planned |
| **Peripherals** | PWM Generator, ADC converters | ⏳ | Planned |
| **Device Drivers** | Custom Peripheral Drivers (UART/SPI/I2C)| ⏳ | Planned |

---

## References

- [Zephyr Project Official Documentation](https://docs.zephyrproject.org/latest/introduction/index.html)
- [Zephyr API Reference Index](https://docs.zephyrproject.org/latest/doxygen/html/index.html)
- [STM32 Nucleo-F411RE Board Guide](https://docs.zephyrproject.org/latest/boards/arm/nucleo_f411re/doc/index.html)
- [Zephyr Kernel Services Guide](https://docs.zephyrproject.org/latest/kernel/services/index.html)

---

## Author & License

### Author
**Priya Dharshini S**
- *Department of Electronics and Communication Engineering*
- Dedicated to: **Embedded Systems | Firmware Development | Zephyr RTOS | STM32 Microcontrollers | C Programming**
- GitHub: [PriyaSelvakumar123](https://github.com/PriyaSelvakumar123)

### License
This project is licensed under the **MIT License**. Check out the [LICENSE](LICENSE) file for more information. Dynamic redistribution and code reuse for academic or development settings is highly encouraged!
