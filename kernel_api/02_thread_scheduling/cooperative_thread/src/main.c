#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#define STACK_SIZE 1024

K_THREAD_STACK_DEFINE(high_stack, STACK_SIZE);
struct k_thread high_thread_data;

/* High-priority cooperative thread */
void high_thread(void *p1, void *p2, void *p3)
{
    while (1) {
        printk(">>> High Priority Thread Running\n");
        k_sleep(K_SECONDS(1));
    }
}

/* Low-priority cooperative thread */
void low_thread(void *p1, void *p2, void *p3)
{
    printk("Low Priority Thread Started\n");

    /* Create the high-priority cooperative thread */
    k_thread_create(&high_thread_data,
                    high_stack,
                    STACK_SIZE,
                    high_thread,
                    NULL, NULL, NULL,
                    -2,          /* Higher cooperative priority */
                    0,
                    K_NO_WAIT);

    printk("High Priority Thread Created (READY)\n");

    /* Run 10 iterations without yielding */
    for (int i = 1; i <= 10; i++) {
        printk("Low Thread Count = %d\n", i);
    }

    printk("\nNow calling k_yield()...\n\n");

    /* Give CPU voluntarily */
    k_yield();

    while (1) {
        printk("Low Thread Running After Yield\n");
        k_sleep(K_SECONDS(1));
    }
}

K_THREAD_DEFINE(low_tid,
                STACK_SIZE,
                low_thread,
                NULL, NULL, NULL,
                -1,      /* Lower cooperative priority */
                0,
                0);

int main(void)
{
    printk("=== Cooperative Scheduling Demo ===\n");
    return 0;
}
