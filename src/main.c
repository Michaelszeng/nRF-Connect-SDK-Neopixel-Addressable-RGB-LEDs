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
		// Basic Showing Colors
		printk("1");
		neopixel_show_color(255, 0, 0, 255, 0, 0, 500);
		printk("2");
		neopixel_show_color(0, 255, 0, 0, 255, 0, 500);
		printk("3");
		neopixel_show_color(0, 0, 255, 0, 0, 255, 500);
		printk("4");
		neopixel_show_color(255, 255, 255, 255, 255, 255, 500);
		neopixel_show_color(0, 0, 0, 0, 0, 0, 2000);

		// Fading
		neopixel_fade_in_out(255, 0, 0, 255, 0, 0, 3000);
		neopixel_fade_in_out(0, 255, 0, 0, 255, 0, 3000);
		neopixel_fade_in_out(0, 0, 255, 0, 0, 255, 3000);
		neopixel_fade_in_out(255, 255, 0, 255, 255, 0, 3000);
		neopixel_fade_in_out(255, 0, 255, 255, 0, 255, 3000);
		neopixel_fade_in_out(0, 255, 255, 0, 255, 255, 3000);
		neopixel_fade_in_out(255, 255, 255, 255, 255, 255, 3000);
		neopixel_show_color(0, 0, 0, 0, 0, 0, 2000);
	}

	return 0;
}