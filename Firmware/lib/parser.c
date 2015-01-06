/*
 * parser.c
 *
 *  Created on: 06.01.2015
 *      Author: zaphod
 */

#include <avr/io.h>
#include <string.h>
#include <ctype.h>

#include "parser.h"
#include "util.h"

void parser_prepare_buffer(char* commandBuffer) {
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

uint32_t parser_get_long_hex(char** bufferPointer) {
	*bufferPointer = *bufferPointer + strlen(*bufferPointer) + 1;
	return get_long_from_hex(*bufferPointer);
}

uint8_t parser_get_byte_hex(char** bufferPointer) {
	*bufferPointer = *bufferPointer + strlen(*bufferPointer) + 1;
	return get_byte_from_hex(*bufferPointer);
}

char* parser_get_string(char** bufferPointer) {
	*bufferPointer = *bufferPointer + strlen(*bufferPointer) + 1;
	return *bufferPointer;
}


