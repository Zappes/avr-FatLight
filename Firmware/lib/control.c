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

	if (strcmp(commandBuffer, "MODE") == 0) {
		uint8_t mode = parser_get_byte_hex(&commandBuffer);

		if(mode == ANIM_MODE_FADE || mode == ANIM_MODE_SET || ANIM_MODE_DISCO) {
			uart_writeln_formatted("Setting mode: %02X", mode);
			anim_set_mode(mode);
		}
		else {
			uart_writeln_formatted("ERROR - Unknown mode: %02X", mode);
		}
	}
	else if (strcmp(commandBuffer, "STEP") == 0) {
		uint8_t step = parser_get_byte_hex(&commandBuffer);

		if(step != 0) {
			uart_writeln_formatted("Setting step: %02X", step);
			anim_set_step(step);
		}
		else {
			uart_writeln_string("ERROR - Step may not be 0");
		}
	}
	else if (strcmp(commandBuffer, "SET") == 0) {
		uint32_t color_numeric = parser_get_long_hex(&commandBuffer);

		uart_writeln_formatted("Setting color: %06lX", color_numeric);

		anim_set_rgb_numeric(color_numeric);
	}
	else if (strcmp(commandBuffer, "DELAY") == 0) {
		uint8_t delay = parser_get_byte_hex(&commandBuffer);

		uart_writeln_formatted("Setting delay: %02X", delay);

		anim_set_delay(delay);
	}
	else if (strcmp(commandBuffer, "STORE") == 0) {
		uint8_t slot = parser_get_byte_hex(&commandBuffer);

		if(slot < PERSISTENCE_NUM_SLOTS) {
			persistence_persist(slot);
			uart_writeln_formatted("Saving settings in slot: %02X", slot);
		}
		else {
			uart_writeln_formatted("ERROR - Slot out of range: %02X", slot);
		}
	}
	else if (strcmp(commandBuffer, "LOAD") == 0) {
		uint8_t slot = parser_get_byte_hex(&commandBuffer);

		if(slot < PERSISTENCE_NUM_SLOTS) {
			persistence_restore(slot);
			uart_writeln_formatted("Loaded settings from slot: %02X", slot);
		}
		else {
			uart_writeln_formatted("ERROR - Slot out of range: %02X", slot);
		}
	}
	else if (strcmp(commandBuffer, "STATUS") == 0) {
		uart_writeln_formatted("Current RGB : %06lX", anim_get_current_rgb_numeric());
		uart_writeln_formatted("Target RGB  : %06lX", anim_get_target_rgb_numeric());
		uart_writeln_formatted("Anim mode   : %02X", anim_get_mode());
		uart_writeln_formatted("Anim delay  : %02X", anim_get_delay());
		uart_writeln_formatted("Anim step   : %02X", anim_get_step());
		uart_writeln_formatted("Current slot: %02X", persistence_get_current_slot());
	}
	else if (strcmp(commandBuffer, "BT_SETNAME") == 0) {
		char* name = parser_get_string(&commandBuffer);
		bt_set_device_name(name);
	}
	else if (strcmp(commandBuffer, "BT_GETNAME") == 0) {
		bt_get_device_name();
	}
	else if (strcmp(commandBuffer, "BT_SETPASS") == 0) {
		char* passcode = parser_get_string(&commandBuffer);
		bt_set_passcode(passcode);
	}
	else if (strcmp(commandBuffer, "BT_GETPASS") == 0) {
		bt_get_passcode();
	}
	else if (strcmp(commandBuffer, "BT_VERSION") == 0) {
		bt_get_version();
	}
	else {
		uart_writeln_formatted("Unknown command: %s", commandBuffer);
	}

	sei();
}

void control_init(void) {
	uart_set_callback(handle_command);
}
