# Zephyr RTOS Projects

A curated collection of hands-on Zephyr RTOS examples developed while learning embedded systems and real-time operating system concepts. This repository documents my journey from Zephyr fundamentals to kernel APIs, peripheral interfaces, and driver development using the **STM32 Nucleo-F411RE** development board.

---

## Objectives

* Learn Zephyr RTOS architecture and development workflow.
* Explore Zephyr Kernel APIs through practical examples.
* Understand DeviceTree and Kconfig configuration.
* Develop peripheral and sensor drivers.
* Build complete embedded applications using Zephyr.
* Progress towards contributing to the Zephyr open-source ecosystem.

---

## Hardware

* STM32 Nucleo-F411RE

---

## Software Environment

* Zephyr RTOS
* West
* CMake
* Ninja
* GCC ARM Toolchain
* Visual Studio Code

---

# Repository Structure

```text
zephyr-rtos-projects
│
├── getting_started
│   ├── hello_world
│   ├── blinky
│   └── gpio_basic
│
├── kernel_api
│   ├── threads
│   ├── thread_scheduling
│   │   ├── cooperative
│   │   └── preemptive
│   ├── gpio_interrupt
│   ├── semaphore
│   ├── mutex
│   ├── timer
│   ├── workqueue
│   └── message_queue
│
├── drivers
│   ├── gpio
│   ├── uart
│   ├── i2c
│   ├── spi
│   ├── adc
│   ├── pwm
│   └── sensor
│
├── projects
│
└── docs
```

---

# Learning Progress

| Topic                  | Status |
| ---------------------- | :----: |
| Zephyr Setup           |    ✅   |
| Hello World            |    ✅   |
| GPIO                   |    ✅   |
| Threads                |    ✅   |
| Cooperative Scheduling |    ✅   |
| Preemptive Scheduling  |    ✅   |
| GPIO Interrupts        |   🚧   |
| Semaphore              |   🚧   |
| Mutex                  |   🚧   |
| Timer                  |   🚧   |
| Work Queue             |   🚧   |
| UART                   |   🚧   |
| I2C                    |   🚧   |
| SPI                    |   🚧   |
| ADC                    |   🚧   |
| PWM                    |   🚧   |
| Sensor Driver          |   🚧   |
| Embedded Project       |   🚧   |

---

# Topics Covered

### Getting Started

* Zephyr installation
* Build system
* Flashing applications
* GPIO basics

### Kernel APIs

* Thread creation
* Cooperative scheduling
* Preemptive scheduling
* Synchronization primitives
* Timers
* Work Queues
* GPIO Interrupts

### Peripheral Interfaces

* GPIO
* UART
* I2C
* SPI
* ADC
* PWM

### Driver Development

* DeviceTree
* Kconfig
* Sensor Driver Development

### Embedded Applications

* Multi-threaded applications
* Sensor-based projects
* Real-time embedded systems

---

# Skills Developed

* Embedded C
* Zephyr RTOS
* Thread Scheduling
* DeviceTree
* Kconfig
* GPIO Programming
* Interrupt Handling
* Peripheral Driver Development
* Embedded Debugging
* Build Systems (West & CMake)

---

# Build

```bash
west build -b nucleo_f411re
```

# Flash

```bash
west flash
```

---

# Documentation

Each example includes:

* Objective
* Theory
* Hardware Used
* Project Structure
* DeviceTree Configuration
* Build Instructions
* Flash Instructions
* Expected Output
* APIs Used
* Learning Outcomes

---

# Future Work

* Complete Zephyr Kernel API examples
* Develop custom sensor drivers
* Explore Bluetooth and networking
* Study power management
* Build complete embedded applications
* Contribute to the Zephyr Project

---

# Learning Resources

* Zephyr Project Documentation
* Zephyr Project GitHub Repository
* STM32 Nucleo-F411RE User Manual
* STM32 Reference Manual

---

## License

This repository is intended for learning, experimentation, and educational purposes.

---

## About Me

I am an Electronics and Communication Engineering student with a strong interest in Embedded Systems, RTOS, Embedded Linux, and Firmware Development.

This repository documents my continuous learning journey with Zephyr RTOS through practical implementations, experimentation, and progressively more advanced embedded software development.
