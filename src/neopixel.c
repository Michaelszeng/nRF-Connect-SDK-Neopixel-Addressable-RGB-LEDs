#include <zephyr/kernel.h>
#include <hal/nrf_gpio.h> 

#include "neopixel.h"

// #define NEOPIXEL_PIN 5  // P0.05
// #define NEOPIXEL_PIN 38  // P1.06
#define NEOPIXEL_PIN 13  // P0.13

// 64 MHz CLOCK = 15.625ns Clock Period

// Target: 900ns H + 300ns L 
#define NEOPIXEL_SEND_ONE \
nrf_gpio_pin_set(NEOPIXEL_PIN); \
__ASM ( \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
); \
nrf_gpio_pin_clear(NEOPIXEL_PIN); \
__ASM ( \
" NOP\n\t" \
); // Logic "1" 57x1 + 19x0 * 15.625ns = 890.625ns H + 296.875ns L


// Target: 300ns H + 900ns L 
#define NEOPIXEL_SEND_ZERO \
nrf_gpio_pin_set(NEOPIXEL_PIN); \
__ASM ( \
" NOP\n\t" \
); \
nrf_gpio_pin_clear(NEOPIXEL_PIN); \
__ASM ( \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
" NOP\n\t NOP\n\t NOP\n\t NOP\n\t NOP\n\t" \
); // Logic "1" 19x1 + 57x0 * 15.625ns = 296.875ns H + 890.625ns L


void init_neopixels() {
    nrf_gpio_cfg_output(NEOPIXEL_PIN);
    nrf_gpio_pin_clear(NEOPIXEL_PIN);
}

void test() {
    NEOPIXEL_SEND_ONE
    NEOPIXEL_SEND_ZERO
}

void neopixel_show_color(uint8_t r1, uint8_t g1, uint8_t b1, uint8_t r2, uint8_t g2, uint8_t b2, int msecs) {
    /**
     * Send this command to change the color of the LEDs.
     * 
     * Set to all 0's to turn the LEDs off.
     * 
     * IMPLEMENTATION NOTE: LED expects 24 bit signal in GRB order (8 bits each color)
     * 
     * THIS IS THE PRIMARY FUNCTION WE SHOULD BE USING.
     */

    // Estimated time per loop (rough) is 0.2ms. The timing is horribly inaccurate.
    int num_loops = (int) (msecs / 0.2);

    for (int _=0; _<num_loops; _++) {
        // LED 1 Green
        if ((g1 & 128) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((g1 & 64) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((g1 & 32) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((g1 & 16) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((g1 & 8) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((g1 & 4) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((g1 & 2) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((g1 & 1) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}

        // LED 1 Red
        if ((r1 & 128) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((r1 & 64) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((r1 & 32) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((r1 & 16) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((r1 & 8) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((r1 & 4) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((r1 & 2) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((r1 & 1) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}

        // LED 1 Blue
        if ((b1 & 128) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((b1 & 64) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((b1 & 32) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((b1 & 16) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((b1 & 8) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((b1 & 4) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((b1 & 2) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((b1 & 1) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}




        // LED 2 Green
        if ((g2 & 128) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((g2 & 64) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((g2 & 32) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((g2 & 16) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((g2 & 8) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((g2 & 4) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((g2 & 2) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((g2 & 1) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}

        // LED 2 Red
        if ((r2 & 128) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((r2 & 64) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((r2 & 32) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((r2 & 16) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((r2 & 8) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((r2 & 4) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((r2 & 2) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((r2 & 1) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}

        // LED 2 Blue
        if ((b2 & 128) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((b2 & 64) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((b2 & 32) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((b2 & 16) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((b2 & 8) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((b2 & 4) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((b2 & 2) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        if ((b2 & 1) > 0)	{NEOPIXEL_SEND_ONE}
        else	{NEOPIXEL_SEND_ZERO}
        
        NEOPIXEL_SEND_ZERO;
        k_sleep(K_USEC(80));  // Reset sequence between commands of two LEDs
    }
    
}