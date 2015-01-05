/*
 * bluetooth.h
 *
 *  Created on: 05.01.2015
 *      Author: zaphod
 */

#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include <avr/io.h>

#define BT_DDR	DDRD
#define BT_KEY	PD2
#define BT_PORT	PORTD

void bt_init(void);
void bt_rename_device(char* name);

#endif /* BLUETOOTH_H_ */
