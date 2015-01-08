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

void advance_buffer_pointer(char** bufferPointer) {
	// first seek to the first 0 character
	while(**bufferPointer != 0) {
		*bufferPointer+=1;
	}

	// now skip all 0s
	while(**bufferPointer == 0) {
		*bufferPointer+=1;
	}

	// at this point, the pointer points to the next string.
}

uint32_t parser_get_long_hex(char** bufferPointer) {
	advance_buffer_pointer(bufferPointer);
	return get_long_from_hex(*bufferPointer);
}

uint8_t parser_get_byte_hex(char** bufferPointer) {
	advance_buffer_pointer(bufferPointer);
	return get_byte_from_hex(*bufferPointer);
}

char* parser_get_string(char** bufferPointer) {
	advance_buffer_pointer(bufferPointer);
	return *bufferPointer;
}


