/*
 * stripcontrol.c
 *
 *  Created on: 04.01.2015
 *      Author: zaphod
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#include "stripcontrol.h"

#include "uart.h"
#include "util.h"

uint8_t lastRed, lastGreen, lastBlue = 0;
uint8_t enabled = 1;

void strip_init() {
	// set PWM pins to output
	STRIP_DDR |= (_BV(STRIP_RED) | _BV(STRIP_GRN) | _BV(STRIP_BLU));

	// timer 0 is used for red/green pwm.
	// fast pwm, inverted output on both pins
	TCCR0A |=
			_BV(
					COM0A0) | _BV(COM0A1) | _BV(COM0B0) | _BV(COM0B1) | _BV(WGM00) | _BV(WGM01);
	// prescaler set to clk/8 -> 8 khz pwm frequency
	TCCR0B |= _BV(CS01);

	// timer 2 is used for blue pwm.
	// fast pwm, inverted output on both pins
	TCCR2A |= _BV(COM2B0) | _BV(COM2B1) | _BV(WGM20) | _BV(WGM21);
	// prescaler set to clk/8 -> 8 khz pwm frequency
	TCCR2B |= _BV(CS21);

	// turn off the strip
	strip_set_rgb_numeric(0);
}

void strip_switch_off(void) {
	enabled = 0;

	STRIP_REG_RED = 255;
	STRIP_REG_GRN = 255;
	STRIP_REG_BLU = 255;
}

void strip_switch_on(void) {
	STRIP_REG_RED = lastRed;
	STRIP_REG_GRN = lastGreen;
	STRIP_REG_BLU = lastBlue;

	enabled = 1;
}

uint8_t strip_is_on() {
	return enabled;
}

void strip_set_rgb_components(uint8_t red, uint8_t green, uint8_t blue) {
	lastRed = 255 - red;
	lastGreen = 255 - green;
	lastBlue = 255 - blue;

	if (enabled) {
		STRIP_REG_RED = lastRed;
		STRIP_REG_GRN = lastGreen;
		STRIP_REG_BLU = lastBlue;
	}
}

void strip_set_rgb_numeric(uint32_t colVal) {
	uint8_t r, g, b;
	get_components_from_numeric(colVal, &r, &g, &b);
	strip_set_rgb_components(r, g, b);
}

void strip_set_rgb_hex(char* color) {
	strip_set_rgb_numeric(get_long_from_hex(color));
}
