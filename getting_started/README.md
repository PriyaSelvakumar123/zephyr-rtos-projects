# Module 1: Getting Started

![RTOS](https://img.shields.io/badge/RTOS-Zephyr-734f96)
![Language](https://img.shields.io/badge/Language-C-blue.svg)
![Board](https://img.shields.io/badge/Board-STM32_Nucleo_F411RE-orange.svg)
![Objective](https://img.shields.io/badge/Objective-Hardware_Abstraction-brightgreen)

Welcome to the **Getting Started** module. This folder contains introductory projects designed to get you comfortable with the Zephyr development toolchain, DeviceTree hardware descriptors, Kconfig systems, and basic input/output polling.

---

## 🎯 Learning Objectives

By working through these examples, you will learn to:
1. Set up the development pipeline with the `west` meta-tool.
2. Understand Zephyr's modular project folder structure.
3. Configure physical pins and I2C buses using DeviceTree overlays (`.overlay`).
4. Read and process hardware sensor values using the built-in **Sensor API**.

---

## 📂 Folder Contents

```text
getting_started/
├── blinky/         # Hardware check: periodic toggling of the user LED
└── accel_polling/  # Reads data from an accelerometer using polling
```

---

## 🏗️ Zephyr Application Structure

Every project in this module conforms to the standard Zephyr system layout. Here is a breakdown of the key files:

| File / Folder | Purpose | Description |
| :--- | :--- | :--- |
| **`CMakeLists.txt`** | Build configuration | Directs CMake to find the Zephyr package and compile your source files. |
| **`prj.conf`** | Kconfig configuration | Enables kernel APIs and system features (e.g. `CONFIG_GPIO=y`, `CONFIG_SENSOR=y`). |
| **`app.overlay`** | DeviceTree Overlay | Modifies or adds pins, interfaces, and sensors to the default board configurations. |
| **`src/main.c`** | Application logic | The C entry point. Code begins executing inside `main()`. |

---

## 🔌 Hardware Abstraction: DeviceTree & Kconfig

Zephyr separates application logic from the underlying microcontroller hardware using two mechanisms:

### A. DeviceTree (Hardware Configuration)
DeviceTree describes the physical board components (LEDs, buttons, buses, timers) in a tree layout.
*   **Nodes**: Represent hardware blocks.
*   **Aliases**: Assign readable names (e.g., matching `led0` to physical pin `PA5`).
*   **Overlays (`.overlay`)**: Allow you to map external sensors (like accelerometers on I2C) in your workspace without modifying the core system files.

### B. Kconfig (Driver/API Configuration)
Kconfigs act as software gates to enable or disable drivers and compiler layers. For instance, to enable I2C and sensors in `accel_polling`, the `prj.conf` file specifies:
```ini
CONFIG_GPIO=y
CONFIG_SENSOR=y
CONFIG_I2C=y
```

---

## 💻 Demos Walkthrough

### 1. Blinky (`getting_started/blinky`)
*   **Goal**: Ensure the flashing tool chain works and toggle the board's green LED.
*   **Execution**: Obtains a DeviceTree specification struct via the `DT_ALIAS(led0)` macro and toggles it inside an infinite loop using `gpio_pin_toggle_dt()`.

### 2. Accelerometer Polling (`getting_started/accel_polling`)
*   **Goal**: Interface with an external three-axis I2C accelerometer.
*   **Execution**:
    *   Finds matching sensor instances using the aliases `accel0` through `accel9`.
    *   Triggers periodic acquisitions using `sensor_sample_fetch()`.
    *   Decodes acceleration datasets (X, Y, Z axes) into user-ready floating point values using `sensor_channel_get()`.

---

## ⚡ Build & Run Guide

All commands should be executed from the **repository root directory**.

### 1. Build the Applications
Verify CMake compiles your chosen project cleanly:

```bash
# Build Blinky
west build -p always -b nucleo_f411re getting_started/blinky

# Build Accelerometer Polling
west build -p always -b nucleo_f411re getting_started/accel_polling
```

> [!TIP]
> The `-p always` flag forces a clean build directory refresh, preventing target compilation caching conflicts.

### 2. Flash to the Hardware
Connect your Nucleo-F411RE board to your development machine's USB port and run:
```bash
west flash
```

### 3. Open Serial Console
To view printer statement outputs, connect a serial monitor configured for **115200 Baud**:
```bash
# Example using screen (Unix)
screen /dev/ttyACM0 115200

# Example using Picocom (Linux)
picocom -b 115200 /dev/ttyACM0
```

---

## 🚀 Next Module

Once you understand the basic workflow, you are ready to study multitasking. Head over to the [Kernel API Module](../kernel_api/README.md) to explore:
*   Static Thread Definition (`01_threads`)
*   Cooperative vs Preemptive Execution (`02_thread_scheduling`)
