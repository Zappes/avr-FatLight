/*
 * stripcontrol.c
 *
 *  Created on: 04.01.2015
 *      Author: zaphod
 */

#include "stripcontrol.h"
#include <avr/io.h>

void strip_init() {
	// set PWM pins to output
	STRIP_DDR |= (_BV(STRIP_RED) | _BV(STRIP_GRN) | _BV(STRIP_BLU));
}

void strip_set_colors(uint8_t red, uint8_t green, uint8_t blue) {
	if(red) {
		STRIP_PORT |= _BV(STRIP_RED);
	}
	else {
		STRIP_PORT &= ~_BV(STRIP_RED);
	}

	if(green) {
		STRIP_PORT |= _BV(STRIP_GRN);
	}
	else {
		STRIP_PORT &= ~_BV(STRIP_GRN);
	}

	if(blue) {
		STRIP_PORT |= _BV(STRIP_BLU);
	}
	else {
		STRIP_PORT &= ~_BV(STRIP_BLU);
	}

}
