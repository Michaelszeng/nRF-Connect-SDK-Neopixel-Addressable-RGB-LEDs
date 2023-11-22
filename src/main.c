#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/logging/log.h>

#include "neopixel.h"

LOG_MODULE_REGISTER(nrfx_sample, LOG_LEVEL_INF);

// [source]: https://devzone.nordicsemi.com/f/nordic-q-a/70735/gpio-pin-configuration
// [source]: https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrfx/drivers/gpio/hal.html#c.nrf_gpio_pin_write


/**
 * REMEMBER TO MODIFY CMAKELISTS TO INCLUDE NEOPIXEL.C!
 */



int main(void)
{
	LOG_INF("Testing nrfx GPIO HAL on %s", CONFIG_BOARD);

	init_neopixels();

	while(1) {
		// nrf_gpio_pin_set(NEOPIXEL_PIN);
		// k_msleep(10);
		// nrf_gpio_pin_clear(NEOPIXEL_PIN);
		// k_msleep(10);

		// NEOPIXEL_SEND_ONE
		// NEOPIXEL_SEND_ZERO
		
		// LOG_INF("x ");

		test();
	}

	return 0;
}