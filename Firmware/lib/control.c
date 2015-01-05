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
#include <stdio.h>

#include "control.h"
#include "uart.h"
#include "animation.h"
#include "util.h"
#include "persistence.h"

char outbuffer[32];

void prepare_command_string(char* commandBuffer) {
	// process the command string so that all parameters are separated with a 0 byte
	// and all letters are uppercased.
	char* p = commandBuffer;
	while (*p != 0) {
		if (*p == ' ' || *p == 10 || *p == 13) {
			*p = 0;
		} else {
			*p = toupper(*p);
		}
		p++;
	}
}

void uart_handle_command(char* commandBuffer) {
	cli();

	prepare_command_string(commandBuffer);

	if (strcmp(commandBuffer, "SET") == 0) {
		commandBuffer = commandBuffer + strlen(commandBuffer) + 1;

		uint32_t color_numeric = get_long_from_hex(commandBuffer);
		sprintf(outbuffer, "%06lX", color_numeric);
		uart_write_prompted_line("Setting color", outbuffer);
		anim_set_direct_rgb_numeric(color_numeric);
	}
	else if (strcmp(commandBuffer, "FADE") == 0) {
		commandBuffer = commandBuffer + strlen(commandBuffer) + 1;

		uint32_t color_numeric = get_long_from_hex(commandBuffer);
		sprintf(outbuffer, "%06lX", color_numeric);
		uart_write_prompted_line("Fading to color", outbuffer);
		anim_set_target_rgb_numeric(color_numeric);
	}
	else if (strcmp(commandBuffer, "DELAY") == 0) {
		commandBuffer = commandBuffer + strlen(commandBuffer) + 1;

		uint8_t delay = get_byte_from_hex(commandBuffer);
		sprintf(outbuffer, "%02X", delay);
		uart_write_prompted_line("Setting delay", outbuffer);
		anim_set_delay(delay);
	}
	else if (strcmp(commandBuffer, "STORE") == 0) {
		persistence_persist();
		uart_write_string("Settings stored.\r\n");
	}
	else if (strcmp(commandBuffer, "LOAD") == 0) {
		persistence_restore();
		uart_write_string("Settings loaded.\r\n");
	}
	else if (strcmp(commandBuffer, "STATUS") == 0) {
		sprintf(outbuffer, "%06lX", anim_get_current_rgb_numeric());
		uart_write_prompted_line("Current RGB", outbuffer);
		sprintf(outbuffer, "%06lX", anim_get_target_rgb_numeric());
		uart_write_prompted_line("Target RGB ", outbuffer);
		sprintf(outbuffer, "%02X", anim_get_delay());
		uart_write_prompted_line("Anim delay ", outbuffer);
	}
	else if (strcmp(commandBuffer, "RENAME") == 0) {
		commandBuffer = commandBuffer + strlen(commandBuffer) + 1;

		uart_write_prompted_line("Renaming device", commandBuffer);
		bt_rename_device(commandBuffer);
	}
	else {
		uart_write_prompted_line("Unknown command", commandBuffer);
	}

	sei();
}

void control_init(void) {
	uart_set_callback(uart_handle_command);
}
