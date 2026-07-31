# 02 Thread Scheduling

## Overview

This module demonstrates **Thread Scheduling** in **Zephyr RTOS** using the Kernel API. It explains how the Zephyr scheduler manages thread execution using two scheduling types:

| Project | Scheduling Type | Description |
|---------|-----------------|-------------|
| **preemptive_demo** | Preemptive | The scheduler automatically switches the CPU to a higher-priority ready thread. |
| **cooperative_thread** | Cooperative | The running thread voluntarily releases the CPU using `k_yield()` or `k_msleep()`. |

## Scheduling Comparison

| Feature | Preemptive | Cooperative |
|---------|------------|-------------|
| Priority | `0` and above | Negative (`-1`, `-2`, ...) |
| CPU Switch | Automatic | Voluntary |
| Controlled By | Scheduler | Running Thread |
| Best For | Real-time tasks | Cooperative execution |

Each project contains a dedicated `README.md` with implementation details, execution flow, and sample output.
