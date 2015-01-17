/*
 * buttons.h
 *
 * This firmware supports three buttons connected to the pins PC0-PC2. Internal pullups are
 * enabled, so pressing a button must pull the corresponding line LOW.
 *
 * PC0/PC1 are used to load the stored profiles 0 and 1 respectively. PC2 toggles between
 * enabled and disabled state of the entire strip.
 *
 *  Created on: 07.01.2015
 *      Author: zaphod
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_

#include <avr/io.h>

#define BUTTONS_DDR		DDRC
#define BUTTONS_INP 	PINC
#define BUTTONS_PORT 	PORTC
#define BUTTONS_BUT0	PC3
#define BUTTONS_BUT1	PC4
#define BUTTONS_BUT2	PC5

void buttons_init(void);
void buttons_process(void);

#endif /* BUTTONS_H_ */
