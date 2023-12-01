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
		neopixel_show_color(255, 0, 0, 255, 0, 0, 1000);
		neopixel_show_color(0, 0, 0, 0, 0, 0, 1000);
		neopixel_show_color(0, 255, 0, 0, 255, 0, 1000);
		neopixel_show_color(0, 0, 0, 0, 0, 0, 1000);
		neopixel_show_color(0, 0, 255, 0, 0, 255, 1000);
		neopixel_show_color(0, 0, 0, 0, 0, 0, 1000);
		neopixel_show_color(255, 255, 255, 255, 255, 255, 3000);
		neopixel_show_color(0, 0, 0, 0, 0, 0, 1000);
	}

	return 0;
}