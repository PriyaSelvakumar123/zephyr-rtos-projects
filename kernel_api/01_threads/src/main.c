#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

/* Onboard LED */
#define LED0_NODE DT_ALIAS(led0)
static const struct gpio_dt_spec led0 =
	GPIO_DT_SPEC_GET(LED0_NODE, gpios);

/* External LED */
#define LED1_NODE DT_ALIAS(led1)
static const struct gpio_dt_spec led1 =
	GPIO_DT_SPEC_GET(LED1_NODE, gpios);

/* Thread 0 : Onboard LED */
void thread0(void *p1, void *p2, void *p3)
{
	ARG_UNUSED(p1);
	ARG_UNUSED(p2);
	ARG_UNUSED(p3);

	while (1) {
		gpio_pin_toggle_dt(&led0);
		k_msleep(500);
	}
}

/* Thread 1 : External LED */
void thread1(void *p1, void *p2, void *p3)
{
	ARG_UNUSED(p1);
	ARG_UNUSED(p2);
	ARG_UNUSED(p3);

	while (1) {
		gpio_pin_toggle_dt(&led1);
		k_msleep(2000);
	}
}

/* Create Threads */
K_THREAD_DEFINE(thread0_id,
		1024,
		thread0,
		NULL, NULL, NULL,
		3,
		0,
		0);

K_THREAD_DEFINE(thread1_id,
		1024,
		thread1,
		NULL, NULL, NULL,
		5,
		0,
		0);

int main(void)
{
	if (!gpio_is_ready_dt(&led0)) {
		return 0;
	}

	if (!gpio_is_ready_dt(&led1)) {
		return 0;
	}

	gpio_pin_configure_dt(&led0, GPIO_OUTPUT_ACTIVE);
	gpio_pin_configure_dt(&led1, GPIO_OUTPUT_ACTIVE);

	while (1) {
		k_sleep(K_SECONDS(1));
	}

	return 0;
}
