/*
 * buttons.c
 *
 *  Created on: 07.01.2015
 *      Author: zaphod
 */

#include <avr/io.h>
#include "buttons.h"
#include "persistence.h"
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
	else if(pressed(BUTTONS_BUT2) && lastButton != 2) {
		persistence_restore(2);
		lastButton = 2;
		uart_writeln_string("Loaded settings from slot: 02");
	}
}

