/*
 * util.h
 *
 *  Created on: 05.01.2015
 *      Author: zaphod
 */

#ifndef UTIL_H_
#define UTIL_H_

#include <avr/io.h>

void get_components_from_numeric(uint32_t color, uint8_t* r, uint8_t* g, uint8_t* b);
uint32_t get_long_from_hex(char* input);
uint8_t get_byte_from_hex(char* input);

#endif /* UTIL_H_ */
