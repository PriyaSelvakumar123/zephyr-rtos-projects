# 01 Threads

## Overview

This project demonstrates **thread creation and priority-based scheduling** in Zephyr RTOS using the Kernel API. Two threads are created to independently control two GPIO outputs configured through a custom DeviceTree overlay.

## Hardware

- STM32 Nucleo-F411RE
- Two LEDs

## DeviceTree Overlay

A custom **`.overlay`** file is used to configure the GPIO pins:

| GPIO Pin | Function |
|----------|----------|
| PA5 | LED 0 |
| PA9 | LED 1 |

## Thread Configuration

| Thread | GPIO | Priority |
|--------|------|:--------:|
| Thread 1 | PA5 | 3 |
| Thread 2 | PA9 | 5 |

> **Note:** In Zephyr RTOS, a lower priority value indicates a higher scheduling priority. Therefore, **Thread 1 (Priority 3)** executes before **Thread 2 (Priority 5)** whenever both threads are ready.

## Thread Creation Methods

Zephyr supports two common methods for creating threads:

| API | Description |
|-----|-------------|
| `K_THREAD_DEFINE()` | Creates a thread statically at compile time. The thread is automatically started during system initialization. |
| `k_thread_create()` | Creates a thread dynamically at runtime after the kernel has started. |

## Implementation

- Configured **PA5** and **PA9** as GPIO outputs using a custom DeviceTree overlay.
- Created two application threads using **`K_THREAD_DEFINE()`**.
- Each thread toggles its assigned GPIO pin independently.
- Used `k_msleep()` to periodically block each thread, allowing the scheduler to switch between ready threads.
- Demonstrated Zephyr's priority-based scheduler, where the higher-priority thread executes first whenever it is ready.

## Zephyr APIs Used

- `K_THREAD_DEFINE()`
- `k_thread_create()` *(runtime thread creation API)*
- `gpio_pin_configure_dt()`
- `gpio_pin_toggle_dt()`
- `k_msleep()`

## Build and Flash

```bash
west build -b nucleo_f411re
west flash
