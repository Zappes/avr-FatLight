/*
 * stripcontrol.h
 *
 *  Created on: 04.01.2015
 *      Author: zaphod
 */

#ifndef STRIPCONTROL_H_
#define STRIPCONTROL_H_

#include <avr/io.h>

#define STRIP_RED 		PD6
#define STRIP_BLU 		PD3
#define STRIP_GRN 		PD5

#define STRIP_DDR			DDRD
#define STRIP_PORT		PORTD

// PWM registers for the different colors. 255 is off, 0 is full on
#define STRIP_REG_RED	OCR0A
#define STRIP_REG_GRN	OCR0B
#define STRIP_REG_BLU	OCR2B

void strip_init(void);
void strip_set_rgb_components(uint8_t red, uint8_t green, uint8_t blue);
void strip_set_rgb_numeric(uint32_t colVal);
void strip_set_rgb_hex(char* color);

#endif /* STRIPCONTROL_H_ */
