/*
 * buttons.c
 *
 *  Created on: 07.01.2015
 *      Author: zaphod
 */

#include <avr/io.h>
#include <util/delay.h>
#include "buttons.h"
#include "persistence.h"
#include "stripcontrol.h"
#include "uart.h"

uint8_t lastButton = 0xFF;

void buttons_init(void) {
	// this is not strictly required, but at least it's nicely explicit:
	// set buttons as input pins
	BUTTONS_DDR &= ~(_BV(BUTTONS_BUT0) | _BV(BUTTONS_BUT1) | _BV(BUTTONS_BUT2));

	// enable pull-ups
	BUTTONS_PORT |= (_BV(BUTTONS_BUT0) | _BV(BUTTONS_BUT1) | _BV(BUTTONS_BUT2));
}


uint8_t pressed(uint8_t button) {
	return (!(BUTTONS_INP & _BV(button)));
}

uint8_t power_toggled() {
	static uint8_t lastState = 0;

	// this debouncing algorithm is fucking primitive, but yes ... it works most of the
	// time, and that's good enough here.
	if(pressed(BUTTONS_BUT2)) {
		_delay_ms(10);

		if(pressed(BUTTONS_BUT2)) {
			if(lastState == 0) {
				lastState = 1;
				return 1;
			} else {
				return 0;
			}
		}
	} else {
		_delay_ms(10);
		if(!pressed(BUTTONS_BUT2)) {
			lastState = 0;
			return 0;
		}
	}

	return 0;
}

void buttons_process(void) {
	if(pressed(BUTTONS_BUT0) && lastButton != 0) {
		persistence_restore(0);
		lastButton = 0;
		uart_writeln_string("Loaded settings from slot: 00");
	}
	else if(pressed(BUTTONS_BUT1) && lastButton != 1) {
		persistence_restore(1);
		lastButton = 1;
		uart_writeln_string("Loaded settings from slot: 01");
	}
	else if(power_toggled()) {
		if(strip_is_on()) {
			strip_switch_off();
			uart_writeln_string("Strip switched off");
		} else {
			strip_switch_on();
			uart_writeln_string("Strip switched on");
		}
	}
}

