# 01 Threads

## Overview

This project demonstrates **thread creation and priority-based scheduling** in Zephyr RTOS using the Kernel API. Two threads are created to independently control two GPIO outputs configured through a custom DeviceTree overlay.

## Hardware

* STM32 Nucleo-F411RE
* Two LEDs

## DeviceTree Overlay

A custom **`.overlay`** file is used to configure the GPIO pins:

| GPIO Pin | Function |
| -------- | -------- |
| PA5      | LED 0    |
| PA9      | LED 1    |

## Thread Configuration

| Thread   | GPIO | Priority |
| -------- | ---- | :------: |
| Thread 1 | PA5  |     3    |
| Thread 2 | PA9  |     5    |

> **Note:** In Zephyr RTOS, a lower priority value indicates a higher scheduling priority. Therefore, **Thread 1 (Priority 3)** executes before **Thread 2 (Priority 5)** whenever both threads are ready.

## Implementation

* Created a custom DeviceTree overlay to configure **PA5** and **PA9** as GPIO outputs.
* Implemented two threads using `K_THREAD_DEFINE()`.
* Each thread toggles its assigned GPIO pin and periodically yields the CPU using `k_msleep()`.
* The Zephyr scheduler manages execution based on thread priority and sleep state.

## Zephyr APIs Used

* `K_THREAD_DEFINE()`
* `gpio_pin_configure_dt()`
* `gpio_pin_toggle_dt()`
* `k_msleep()`

## Build and Flash

```bash
west build -b nucleo_f411re
west flash
```

## Learning Outcomes

* Thread creation in Zephyr RTOS
* Priority-based preemptive scheduling
* GPIO control using a DeviceTree overlay
* Concurrent task execution using multiple threads
