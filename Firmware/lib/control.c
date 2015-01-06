/*
 * control.c
 *
 *  Created on: 05.01.2015
 *      Author: zaphod
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>

#include "control.h"
#include "uart.h"
#include "animation.h"
#include "util.h"
#include "persistence.h"
#include "parser.h"
#include "bluetooth.h"


void handle_command(char* commandBuffer) {
	cli();

	parser_prepare_buffer(commandBuffer);

	if (strcmp(commandBuffer, "SET") == 0) {
		uint32_t color_numeric = parser_get_long_hex(&commandBuffer);

		uart_writeln_formatted("Setting color: %06lX", color_numeric);

		anim_set_direct_rgb_numeric(color_numeric);
	}
	else if (strcmp(commandBuffer, "FADE") == 0) {
		uint32_t color_numeric = parser_get_long_hex(&commandBuffer);

		uart_writeln_formatted("Fading to color: %06lX", color_numeric);

		anim_set_target_rgb_numeric(color_numeric);
	}
	else if (strcmp(commandBuffer, "DELAY") == 0) {
		uint8_t delay = parser_get_byte_hex(&commandBuffer);

		uart_writeln_formatted("Setting delay: %02X", delay);

		anim_set_delay(delay);
	}
	else if (strcmp(commandBuffer, "STORE") == 0) {
		persistence_persist();
		uart_writeln_string("Settings stored");
	}
	else if (strcmp(commandBuffer, "LOAD") == 0) {
		persistence_restore();
		uart_writeln_string("Settings loaded");
	}
	else if (strcmp(commandBuffer, "STATUS") == 0) {
		uart_writeln_formatted("Current RGB: %06lX", anim_get_current_rgb_numeric());
		uart_writeln_formatted("Target RGB : %06lX", anim_get_current_rgb_numeric());
		uart_writeln_formatted("Anim delay : %02X", anim_get_delay());
	}
	else if (strcmp(commandBuffer, "RENAME") == 0) {
		char* name = parser_get_string(&commandBuffer);

		uart_writeln_formatted("Renaming device: %s", name);
		bt_rename_device(name);
	}
	else {
		uart_writeln_formatted("Unknown command: %s", commandBuffer);
	}

	sei();
}

void control_init(void) {
	uart_set_callback(handle_command);
}
