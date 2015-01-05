/*
 * stripcontrol.c
 *
 *  Created on: 04.01.2015
 *      Author: zaphod
 */

#include <avr/io.h>
#include <string.h>
#include <stdlib.h>
#include "stripcontrol.h"

#include "uart.h"

void strip_init() {
	// set PWM pins to output
	STRIP_DDR |= (_BV(STRIP_RED) | _BV(STRIP_GRN) | _BV(STRIP_BLU));

	// timer 0 is used for red/green pwm.
	// fast pwm, inverted output on both pins
	TCCR0A |= _BV(COM0A0) | _BV(COM0A1) | _BV(COM0B0) | _BV(COM0B1) | _BV(WGM00) | _BV(WGM01);
	// prescaler set to clk/8 -> 8 khz pwm frequency
	TCCR0B |= _BV(CS01);

	// timer 2 is used for blue pwm.
	// fast pwm, inverted output on both pins
	TCCR2A |= _BV(COM2B0) | _BV(COM2B1) | _BV(WGM20) | _BV(WGM21);
	// prescaler set to clk/8 -> 8 khz pwm frequency
	TCCR2B |= _BV(CS21);

	// turn off the strip
	strip_set_color(0,0,0);
}

void strip_set_color(uint8_t red, uint8_t green, uint8_t blue) {
	STRIP_REG_RED = 255 - red;
	STRIP_REG_GRN = 255 - green;
	STRIP_REG_BLU = 255 - blue;
}

void strip_set_color_hex(char* color) {
	uint8_t r,g,b;
	uint32_t colVal;

	if(strlen(color) != 6) {
		return;
	}

	colVal = strtoul(color, NULL, 16);
	b = (uint8_t)(colVal & 0x000000FF);
	g = (uint8_t)((colVal & 0x0000FF00) >> 8);
	r = (uint8_t)((colVal & 0x00FF0000) >> 16);

	strip_set_color(r, g, b);
}
