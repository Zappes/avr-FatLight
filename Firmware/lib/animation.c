/*
 * animation.c
 *
 *  Created on: 05.01.2015
 *      Author: zaphod
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#include "util.h"
#include "stripcontrol.h"
#include "animation.h"

uint8_t target_r, target_g, target_b = 0;
volatile uint8_t current_r, current_g, current_b = 0;
uint8_t anim_mode		= ANIM_MODE_SET;
uint8_t anim_delay 	= 0;

void anim_init(void) {
	// Timer 1 is used for the animation loop
	// fast PWM, 16 bits, TOP in OCR1A
	TCCR1A |= (_BV(WGM10) | _BV(WGM11));
	TCCR1B |= (_BV(WGM12) | _BV(WGM13));

	// prescaler set to clk/1024
	TCCR1B |= (_BV(CS12));

	// above settings create one count every 0.000064 seconds.
	// 200 hz means 1 interrupt every 0.005 seconds
	// => an overflow interrupt is required every 78.125 counts
	OCR1A = 79;

	// enable interrupts on overflow
	TIMSK1 |= _BV(TOIE1);
}

void anim_set_delay(uint8_t delay) {
	anim_delay = delay;
}

uint8_t anim_get_delay(void) {
	return anim_delay;
}

void anim_set_mode(uint8_t mode) {
	anim_mode = mode;

	if(mode == ANIM_MODE_DISCO) {
		// initialize the random number generator with the current value of the animation timer
		srand(TCNT1);
	}
}

uint8_t anim_get_mode(void) {
	return anim_mode;
}

void anim_set_rgb_components(uint8_t red, uint8_t green, uint8_t blue) {
	target_r = red;
	target_g = green;
	target_b = blue;

	if(anim_mode == ANIM_MODE_SET) {
		current_r = red;
		current_g = green;
		current_b = blue;

		strip_set_rgb_components(red, green, blue);
	}
}

void anim_set_rgb_numeric(uint32_t colVal) {
	uint8_t r,g,b;
	get_components_from_numeric(colVal, &r, &g, &b);
	anim_set_rgb_components(r, g, b);
}

uint32_t anim_get_current_rgb_numeric(void) {
	return (uint32_t)current_b | ((uint32_t)current_g << 8) | ((uint32_t)current_r << 16);
}

uint32_t anim_get_target_rgb_numeric(void) {
	return (uint32_t)target_b | ((uint32_t)target_g << 8) | ((uint32_t)target_r << 16);
}

uint8_t fade_to_target(volatile uint8_t* variable, const uint8_t target) {
	if(*variable == target)
		return 0;

	if(*variable < target) {
		(*variable)++;
	}
	else {
		(*variable)--;
	}

	return 1;
}

/*
 * This routine is called with a frequency of 50Hz. It controls the animations for the
 * LED strip.
 */
ISR(TIMER1_OVF_vect) {
	static uint8_t anim_counter = 0;

	if(anim_counter == 0) {
		anim_counter = anim_delay;

		uint8_t faded = 0;

		faded += fade_to_target(&current_r, target_r);
		faded += fade_to_target(&current_g, target_g);
		faded += fade_to_target(&current_b, target_b);

		if(faded) {
			strip_set_rgb_components(current_r, current_g, current_b);
		}
		else if(anim_mode == ANIM_MODE_DISCO){
			// no fading occurred, so we have reached the target color and need a new one
			anim_set_rgb_components(rand() & 0xFF, rand() & 0xFF, rand() & 0xFF);
		}
	}
	else {
		anim_counter--;
	}
}
