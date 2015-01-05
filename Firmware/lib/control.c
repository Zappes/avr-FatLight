/*
 * control.c
 *
 *  Created on: 05.01.2015
 *      Author: zaphod
 */
#include <avr/interrupt.h>
#include <avr/io.h>
#include <string.h>
#include <ctype.h>

#include "control.h"
#include "util.h"
#include "uart.h"
#include "stripcontrol.h"

void uart_handle_command(char* commandBuffer) {
	cli();

	// process the command string so that all parameters are separated with a 0 byte
	// and all letters are uppercased.
	char* p = commandBuffer;
	while(*p != 0) {
		if(*p == ' ' || *p == 10 || *p == 13) {
			*p = 0;
		}
		else {
			*p = toupper(*p);
		}
		p++;
	}

	if(strcmp(commandBuffer, "SET") == 0) {
		commandBuffer = commandBuffer + strlen(commandBuffer) + 1;
		uart_write_prompted_line("Setting color", commandBuffer);
		strip_set_color_hex(commandBuffer);
}
	else {
		uart_write_prompted_line("Unknown command", commandBuffer);
	}

	sei();
}

void control_init(void) {
	uart_set_callback(uart_handle_command);
}
