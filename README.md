# Zephyr RTOS Projects

![License](https://img.shields.io/badge/License-MIT-blue.svg)
![Zephyr](https://img.shields.io/badge/Zephyr-RTOS-6DB33F)
![Language](https://img.shields.io/badge/Language-C-blue)
![Board](https://img.shields.io/badge/Board-STM32_Nucleo_F411RE-orange)

A curated collection of embedded firmware examples demonstrating the core capabilities of the **Zephyr Real-Time Operating System** on the **STM32 Nucleo-F411RE** development board.

The repository is organized by subsystem and API to provide focused, self-contained examples that emphasize clean implementation, maintainability, and practical use of Zephyr kernel services.

---

## Objectives

This repository is maintained to:

* Explore Zephyr RTOS architecture through practical implementations.
* Develop a strong understanding of Zephyr Kernel APIs and execution model.
* Demonstrate embedded firmware development using modern RTOS design practices.
* Build reusable reference implementations for common embedded software components.

---

## Repository Organization

```text
zephyr-rtos-projects/
│
├── getting_started/
│   ├── hello_world/
│   ├── gpio_led/
│   └── devicetree_basics/
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
└── README.md
```

Each example is developed as an independent Zephyr application with its own source, configuration, board overlay, and documentation.

---

## Technical Scope

### Kernel

* Thread Management
* Scheduling
* Cooperative Execution
* Preemptive Execution
* Thread Priorities
* Delays and Sleep APIs

### Synchronization

* Semaphores
* Mutexes
* Message Queues
* FIFOs
* LIFOs
* Work Queues

### Hardware Abstraction

* GPIO
* DeviceTree
* Interrupt Handling
* Timers

### Driver Development

* UART
* I²C
* SPI
* PWM
* ADC
* Sensor Drivers

---

## Development Platform

| Item         | Description                   |
| ------------ | ----------------------------- |
| Board        | STM32 Nucleo-F411RE           |
| MCU          | STM32F411RET6 (ARM Cortex-M4) |
| Language     | C                             |
| Build System | West + CMake                  |
| RTOS         | Zephyr                        |
| Toolchain    | Zephyr SDK                    |

---

## Build

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

## Design Principles

* Modular project structure
* One concept per example
* Standard Zephyr application layout
* DeviceTree-based hardware configuration
* Portable and reusable code
* Clear project documentation
* Incremental learning from kernel fundamentals to driver development

---

## Repository Roadmap

| Area                  |    Status   |
| --------------------- | :---------: |
| Getting Started       |      ✓      |
| Kernel APIs           |      ✓      |
| Scheduling            |      ✓      |
| Synchronization       | In Progress |
| Interrupts            |   Planned   |
| Device Drivers        |   Planned   |
| Peripheral Interfaces |   Planned   |
| Sensor Integration    |   Planned   |

---

## References

* Zephyr Project Documentation
* Zephyr API Reference
* Zephyr Samples
* Zephyr DeviceTree Documentation

---

## Author

**Priya Dharshini S**

Electronics and Communication Engineering

Embedded Systems • Firmware Development • Zephyr RTOS

GitHub: https://github.com/PriyaSelvakumar123

---

## License

This project is licensed under the MIT License.
