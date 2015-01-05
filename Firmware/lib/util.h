/*
 * util.h
 *
 *  Created on: 05.01.2015
 *      Author: zaphod
 */

#ifndef UTIL_H_
#define UTIL_H_

#include <avr/io.h>
#include <stdio.h>
#include <string.h>
#include "uart.h"

void dump_hex(char* string) {
	char buffer[4];

	char* p = string;
	while(*p != 0) {
		sprintf(buffer, "%02x ", *p++);
		uart_write_string(buffer);
	}

	uart_write_string("\r\n");
}
#endif /* UTIL_H_ */
