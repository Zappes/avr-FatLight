/*
 * util.c
 *
 *  Created on: 05.01.2015
 *      Author: zaphod
 */

#include <avr/io.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "util.h"

void get_components_from_numeric(uint32_t color, uint8_t* r, uint8_t* g, uint8_t* b) {
	*b = (uint8_t)(color & 0x000000FF);
	*g = (uint8_t)((color & 0x0000FF00) >> 8);
	*r = (uint8_t)((color & 0x00FF0000) >> 16);
}

uint32_t get_long_from_hex(char* input) {
	if(strlen(input) <= 8) {
		return strtoul(input, NULL, 16);
	}
	else {
		return 0;
	}
}

uint8_t get_byte_from_hex(char* input) {
	return (uint8_t)(get_long_from_hex(input) & 0xFF);
}

