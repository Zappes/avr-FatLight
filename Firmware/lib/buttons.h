/*
 * buttons.h
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
#define BUTTONS_BUT0	PC0
#define BUTTONS_BUT1	PC1
#define BUTTONS_BUT2	PC2

void buttons_init(void);
void buttons_process(void);

#endif /* BUTTONS_H_ */
