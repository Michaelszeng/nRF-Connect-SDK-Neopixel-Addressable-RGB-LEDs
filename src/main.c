#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/sys/util.h>
#include <zephyr/devicetree.h>
#include <zephyr/sys/printk.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/logging/log.h>

#include <hal/nrf_gpio.h> 

LOG_MODULE_REGISTER(nrfx_sample, LOG_LEVEL_INF);

// [source]: https://devzone.nordicsemi.com/f/nordic-q-a/70735/gpio-pin-configuration
// [source]: https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrfx/drivers/gpio/hal.html#c.nrf_gpio_pin_write


// #define OUTPUT_PIN 5  // P0.05
#define OUTPUT_PIN 38  // P1.06

// 64 MHz CLOCK = 15.625ns Clock Period

// Target: 900ns H + 300ns L 
#define NEOPIXEL_SEND_ONE \
nrf_gpio_pin_set(OUTPUT_PIN); \
__ASM ( \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
" NOP\n\t " \
); \
nrf_gpio_pin_clear(OUTPUT_PIN); \
__ASM ( \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
" NOP\n\t NOP\n\t NOP\n\t" \
); //Logic "1" 57x1 + 19x0 * 15.625ns = 890.625ns H + 296.875ns L


// Target: 300ns H + 900ns L 
#define NEOPIXEL_SEND_ZERO \
nrf_gpio_pin_set(OUTPUT_PIN); \
__ASM ( \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
" NOP\n\t NOP\n\t NOP\n\t" \
); \
nrf_gpio_pin_clear(OUTPUT_PIN); \
__ASM ( \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
" NOP\n\t " \
); //Logic "1" 19x1 + 57x0 * 15.625ns = 296.875ns H + 890.625ns L


int main(void)
{
	LOG_INF("Testing nrfx GPIO HAL on %s", CONFIG_BOARD);

	nrf_gpio_cfg_output(OUTPUT_PIN);
    nrf_gpio_pin_clear(OUTPUT_PIN);

	while(1) {
		// nrf_gpio_pin_set(OUTPUT_PIN);
		// k_msleep(10);
		// nrf_gpio_pin_clear(OUTPUT_PIN);
		// k_msleep(10);

		NEOPIXEL_SEND_ONE
		NEOPIXEL_SEND_ZERO
		
		// LOG_INF("x ");
	}

	return 0;
}