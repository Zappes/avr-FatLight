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
	BUTTONS_DDR &= ~(_BV(BUTTONS_BUT0) | _BV(BUTTONS_BUT1) | _BV(BUTTONS_BUT2) | _BV(BUTTONS_BUT3) | _BV(BUTTONS_BUT4) | _BV(BUTTONS_BUT5));

	// enable pull-ups
	BUTTONS_PORT |= (_BV(BUTTONS_BUT0) | _BV(BUTTONS_BUT1) | _BV(BUTTONS_BUT2) | _BV(BUTTONS_BUT3) | _BV(BUTTONS_BUT4) | _BV(BUTTONS_BUT5));
}


uint8_t pressed(uint8_t button) {
	return (!(BUTTONS_INP & _BV(button)));
}

void buttons_process(void) {
	// wrote this in a hurry, should really be cleaned up ...
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
	else if(pressed(BUTTONS_BUT3) && lastButton != 3) {
		persistence_restore(3);
		lastButton = 3;
		uart_writeln_string("Loaded settings from slot: 03");
	}
	else if(pressed(BUTTONS_BUT4) && lastButton != 4) {
		persistence_restore(4);
		lastButton = 4;
		uart_writeln_string("Loaded settings from slot: 04");
	}
	else if(pressed(BUTTONS_BUT5) && lastButton != 5) {
		persistence_restore(5);
		lastButton = 5;
		uart_writeln_string("Loaded settings from slot: 05");
	}
}

