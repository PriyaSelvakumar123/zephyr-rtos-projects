# 02 Preemptive Thread Scheduling

## Overview

This project demonstrates **preemptive thread scheduling** in Zephyr RTOS using two threads with different priorities. The scheduler always executes the **highest-priority ready thread**, automatically preempting the lower-priority thread when it becomes ready. Thread execution is observed through serial console output using `printk()`.

---

## Hardware

* STM32 Nucleo-F411RE

---

## Thread Configuration

| Thread               | Priority | Function                                                      |
| -------------------- | :------: | ------------------------------------------------------------- |
| High Priority Thread |     2    | Executes periodically and then sleeps.                        |
| Low Priority Thread  |     5    | Runs continuously while the high-priority thread is sleeping. |

> **Note:** In Zephyr RTOS, a **lower priority value indicates a higher scheduling priority**.

---

## Implementation

* Created two threads using `k_thread_create()`.
* Assigned different priorities to demonstrate preemptive scheduling.
* The High Priority Thread performs its task and sleeps using `k_msleep()`.
* The Low Priority Thread executes while the High Priority Thread is sleeping.
* When the High Priority Thread wakes up, it immediately preempts the Low Priority Thread.

---

## Zephyr APIs Used

* `k_thread_create()`
* `K_THREAD_STACK_DEFINE()`
* `k_msleep()`
* `k_busy_wait()`
* `printk()`

---

## Build and Flash

```bash
west build -b nucleo_f411re
west flash
```

---

## Sample Output

<img width="1600" height="846" alt="image" src="https://github.com/user-attachments/assets/279cd9c4-b94e-4168-a22c-cbf8aac9773e" />

## Learning Outcomes

* Thread creation using the Zephyr Kernel API
* Priority-based preemptive scheduling
* Thread sleep and wake-up behavior
* Context switching between threads
* Serial debugging using `printk()`
