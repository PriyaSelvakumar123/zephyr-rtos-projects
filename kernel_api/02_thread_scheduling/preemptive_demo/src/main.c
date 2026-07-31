#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#define STACK_SIZE 1024

/* Thread Priorities
 * Smaller number = Higher priority
 */
#define HIGH_PRIORITY 2
#define LOW_PRIORITY 5

K_THREAD_STACK_DEFINE(high_stack, STACK_SIZE);
K_THREAD_STACK_DEFINE(low_stack, STACK_SIZE);

struct k_thread high_thread_data;
struct k_thread low_thread_data;

void high_thread(void *arg1, void *arg2, void *arg3)
{
    while (1)
    {
        printk("\n===============================\n");
        printk("HIGH THREAD READY\n");
        printk("===============================\n");

        for (int i = 1; i <= 5; i++)
        {
            printk("HIGH : %d\n", i);
            k_msleep(200);
        }

        printk("HIGH THREAD SLEEPING...\n\n");

        /* Sleep for 1 second */
        k_msleep(1000);
    }
}

/* Low Priority Thread */
void low_thread(void *arg1, void *arg2, void *arg3)
{
    int count = 1;

    while (1)
{
    printk("LOW : %d\n", count++);
    k_busy_wait(50000);   // 50 ms
}
}

int main(void)
{
    printk("\n===== Preemptive Scheduling Demo =====\n");

    k_thread_create(&high_thread_data,
                    high_stack,
                    STACK_SIZE,
                    high_thread,
                    NULL, NULL, NULL,
                    HIGH_PRIORITY,
                    0,
                    K_NO_WAIT);

    k_thread_create(&low_thread_data,
                    low_stack,
                    STACK_SIZE,
                    low_thread,
                    NULL, NULL, NULL,
                    LOW_PRIORITY,
                    0,
                    K_NO_WAIT);

    while (1)
    {
        k_sleep(K_SECONDS(5));
    }
}
