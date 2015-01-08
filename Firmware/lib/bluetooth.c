/*
 * bluetooth.c
 *
 *  Created on: 05.01.2015
 *      Author: zaphod
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>

#include "bluetooth.h"
#include "uart.h"

uart_callback_t defaultCallback = 0;
char resultBuffer[BT_RESULTBUFFER_SIZE];

void bt_init(void) {
	BT_DDR |= _BV(BT_KEY);
	BT_PORT &= ~_BV(BT_KEY);
}

void handle_bt_result(char* commandBuffer) {

	if(strcmp("OK", commandBuffer) == 0 || strcmp("FAIL", commandBuffer) == 0 || strncmp("ERROR", commandBuffer, 5) == 0) {
		BT_PORT &= ~_BV(BT_KEY);

		_delay_ms(BT_MODESWITCH_DELAY_MS);

		if(resultBuffer[0] != 0) {
			uart_writeln_formatted("%s: %s", commandBuffer, resultBuffer);
			resultBuffer[0] = 0;
		}
		else {
			uart_writeln_formatted("BT: %s", commandBuffer);
		}

		uart_set_callback(defaultCallback);
	}
	else
	{
		strncpy(resultBuffer, commandBuffer, BT_RESULTBUFFER_SIZE);
	}
}

void init_at_mode() {
	// put the module in AT mode by pulling the key pin high
	BT_PORT |= _BV(BT_KEY);

	// wait for the switch to command mode.
	_delay_ms(BT_MODESWITCH_DELAY_MS);

	defaultCallback = uart_set_callback(handle_bt_result);
}

void bt_set_device_name(char* name) {
	init_at_mode();
	uart_writeln_formatted("AT+NAME=%s", name);
}

void bt_get_device_name() {
	init_at_mode();
	uart_writeln_string("AT+NAME?");
}

void bt_set_passcode(char* passcode) {
	init_at_mode();
	uart_writeln_formatted("AT+PSWD=%s", passcode);
}

void bt_get_passcode() {
	init_at_mode();
	uart_writeln_string("AT+PSWD?");
}

void bt_get_version() {
	init_at_mode();
	uart_writeln_string("AT+VERSION?");
}

