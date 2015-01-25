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
#include "stripcontrol.h"

void handle_command(char* commandBuffer) {
	cli();

	parser_prepare_buffer(commandBuffer);

	if (strcmp(commandBuffer, "MODE") == 0) {
		uint8_t mode = parser_get_byte_hex(&commandBuffer);

		if (mode == ANIM_MODE_FADE || mode == ANIM_MODE_SET || ANIM_MODE_DISCO) {
			uart_writeln_formatted("YEAH MODE:%02X", mode);
			anim_set_mode(mode);
		} else {
			uart_writeln_formatted("FUCK Unknown mode: %02X", mode);
		}
	} else if (strcmp(commandBuffer, "ON") == 0) {

		uart_writeln_string("YEAH ACTIVE:01");
		strip_switch_on();
	} else if (strcmp(commandBuffer, "OFF") == 0) {

		uart_writeln_string("YEAH ACTIVE:00");
		strip_switch_off();
	} else if (strcmp(commandBuffer, "STEP") == 0) {
		uint8_t step = parser_get_byte_hex(&commandBuffer);

		if (step != 0) {
			uart_writeln_formatted("YEAH STEP:%02X", step);
			anim_set_step(step);
		} else {
			uart_writeln_string("FUCK Step may not be 0");
		}
	} else if (strcmp(commandBuffer, "SET") == 0) {
		uint32_t color_numeric = parser_get_long_hex(&commandBuffer);

		uart_writeln_formatted("YEAH TRGB:%06lX", color_numeric);

		anim_set_rgb_numeric(color_numeric);
	} else if (strcmp(commandBuffer, "DELAY") == 0) {
		uint8_t delay = parser_get_byte_hex(&commandBuffer);

		uart_writeln_formatted("YEAH DELAY:%02X", delay);

		anim_set_delay(delay);
	} else if (strcmp(commandBuffer, "LEVEL") == 0) {
		uint8_t cap = parser_get_byte_hex(&commandBuffer);

		uart_writeln_formatted("YEAH LEVEL:%02X", cap);

		anim_set_level(cap);
	} else if (strcmp(commandBuffer, "STORE") == 0) {
		uint8_t slot = parser_get_byte_hex(&commandBuffer);

		if (slot < PERSISTENCE_NUM_SLOTS) {
			persistence_persist(slot);
			uart_writeln_formatted("YEAH SLOT:%02X", slot);
		} else {
			uart_writeln_formatted("FUCK Slot out of range: %02X", slot);
		}
	} else if (strcmp(commandBuffer, "LOAD") == 0) {
		uint8_t slot = parser_get_byte_hex(&commandBuffer);

		if (slot < PERSISTENCE_NUM_SLOTS) {
			persistence_restore(slot);
			uart_writeln_formatted("YEAH SLOT:%02X", slot);
		} else {
			uart_writeln_formatted("FUCK Slot out of range: %02X", slot);
		}
	} else if (strcmp(commandBuffer, "STATUS") == 0) {
		uart_write_string("YEAH");
		uart_write_formatted(" CRGB:%06lX", anim_get_current_rgb_numeric());
		uart_write_formatted(" TRGB:%06lX", anim_get_target_rgb_numeric());
		uart_write_formatted(" MODE:%02X", anim_get_mode());
		uart_write_formatted(" DELAY:%02X", anim_get_delay());
		uart_write_formatted(" STEP:%02X", anim_get_step());
		uart_write_formatted(" CAP:%02X", anim_get_level());
		uart_write_formatted(" SLOT:%02X", persistence_get_current_slot());
		uart_writeln_formatted(" ACTIVE:%02X", strip_is_on());
	} else if (strcmp(commandBuffer, "BT_SETNAME") == 0) {
		char* name = parser_get_string(&commandBuffer);
		bt_set_device_name(name);
	} else if (strcmp(commandBuffer, "BT_GETNAME") == 0) {
		bt_get_device_name();
	} else if (strcmp(commandBuffer, "BT_SETPASS") == 0) {
		char* passcode = parser_get_string(&commandBuffer);
		bt_set_passcode(passcode);
	} else if (strcmp(commandBuffer, "BT_GETPASS") == 0) {
		bt_get_passcode();
	} else if (strcmp(commandBuffer, "BT_VERSION") == 0) {
		bt_get_version();
	} else {
		uart_writeln_formatted("FUCK Unknown command: %s", commandBuffer);
	}

	sei();
}

void control_init(void) {
	uart_set_callback(handle_command);
}
