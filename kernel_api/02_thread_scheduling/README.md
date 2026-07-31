# 02 Thread Scheduling

## Overview

This module demonstrates **Thread Scheduling** in **Zephyr RTOS** using the Kernel API. It explains how the Zephyr scheduler manages thread execution using two scheduling types:

| Project | Scheduling Type | Description |
|---------|-----------------|-------------|
| **preemptive_demo** | Preemptive | The scheduler automatically switches the CPU to a higher-priority ready thread. |
| **cooperative_thread** | Cooperative | The running thread voluntarily releases the CPU using `k_yield()` or `k_msleep()`. |

## Scheduling Comparison
<img width="1536" height="1024" alt="image" src="https://github.com/user-attachments/assets/653d1bd5-abe6-45ce-9fe2-6b449c80740a" />
