/*
 * stripcontrol.h
 *
 *  Created on: 04.01.2015
 *      Author: zaphod
 */

#ifndef STRIPCONTROL_H_
#define STRIPCONTROL_H_

#include <avr/io.h>

#define STRIP_RED PD6
#define STRIP_BLU PD3
#define STRIP_GRN PD5

#define STRIP_DDR		DDRD
#define STRIP_PORT	PORTD

void strip_init(void);
void strip_set_colors(uint8_t red, uint8_t green, uint8_t blue);

#endif /* STRIPCONTROL_H_ */
