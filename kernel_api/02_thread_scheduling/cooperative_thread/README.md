# Cooperative Scheduling Using `k_yield()` (Zephyr RTOS)

This example demonstrates **cooperative thread scheduling** in Zephyr RTOS. Two cooperative threads are created with different priorities. A higher-priority thread is created while the lower-priority thread is running, but it does **not** execute immediately. The higher-priority thread starts only after the lower-priority thread voluntarily releases the CPU using `k_yield()`.

---

## Objective

* Understand cooperative scheduling in Zephyr.
* Learn how `k_yield()` affects thread execution.
* Observe how cooperative threads share the CPU.

---

## Thread Configuration

| Thread      | Priority | Type        | Description                                                                                        |
| ----------- | -------- | ----------- | -------------------------------------------------------------------------------------------------- |
| Low Thread  | -1       | Cooperative | Starts first, creates the high-priority thread and continues executing until it calls `k_yield()`. |
| High Thread | -2       | Cooperative | Has higher priority but remains **READY** until the low thread voluntarily yields the CPU.         |

> **Note:** In Zephyr, **lower numeric values indicate higher priority** for cooperative threads.

---

## Execution Flow

```text
System Boot
      │
      ▼
Low Thread Starts
      │
      ▼
Creates High Thread
      │
      ▼
High Thread → READY
Low Thread → RUNNING
      │
      ▼
Prints Count 1...10
      │
      ▼
Calls k_yield()
      │
      ▼
High Thread Starts Running
      │
      ▼
High Thread Sleeps
      │
      ▼
Low Thread Resumes
      │
      ▼
Both Threads Alternate Execution
```

---

## Expected Output

<img width="960" height="1013" alt="image" src="https://github.com/user-attachments/assets/1cfbfd8b-71f1-4481-abb9-2eb617c9f332" />


## Key Observations

* `low_thread` starts execution first.
* `high_thread` is created with a **higher cooperative priority (-2)**.
* Creating the high-priority thread only changes its state to **READY**.
* The running cooperative thread is **not preempted**.
* The high-priority thread begins execution **only after** `k_yield()` is called.
* After both threads call `k_sleep()`, the scheduler always selects the highest-priority READY thread first.

---

## Zephyr APIs Used

| API                       | Purpose                                 |
| ------------------------- | --------------------------------------- |
| `K_THREAD_DEFINE()`       | Create a thread at system startup       |
| `k_thread_create()`       | Dynamically create a thread             |
| `K_THREAD_STACK_DEFINE()` | Allocate thread stack                   |
| `k_yield()`               | Voluntarily release the CPU             |
| `k_sleep()`               | Block a thread for a specified duration |
| `printk()`                | Print messages to the serial console    |

---

## Learning Outcome

After completing this example, you will understand:

* Cooperative thread scheduling in Zephyr.
* The difference between **RUNNING**, **READY**, and **BLOCKED** thread states.
* Why a higher-priority cooperative thread does **not** preempt the currently running cooperative thread.
* How `k_yield()` enables another READY cooperative thread to execute.
* How thread priorities influence scheduling after a thread blocks or sleeps.
