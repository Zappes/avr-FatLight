/*
 * bluetooth.c
 *
 *  Created on: 05.01.2015
 *      Author: zaphod
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#include "bluetooth.h"
#include "uart.h"

void bt_init(void) {
	BT_DDR |= _BV(BT_KEY);
	BT_PORT &= ~_BV(BT_KEY);
}

void bt_rename_device(char* name) {
	// put the module in AT mode by pulling the key pin high
	BT_PORT |= _BV(BT_KEY);

	// no idea if this is necessary. won't hurt.
	_delay_ms(10);

	// set the new device name
	char outbuffer[64];
	sprintf(outbuffer, "AT+NAME=%s\r\n", name);
	uart_write_string(outbuffer);

	// pull the key pin low again. powering down the
	// device will be required, though.
	BT_PORT &= ~_BV(BT_KEY);
}
