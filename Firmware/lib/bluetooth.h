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

#define BT_RESULTBUFFER_SIZE 64
#define BT_MODESWITCH_DELAY_MS 500

void bt_init(void);
void bt_set_device_name(char* name);
void bt_get_device_name(void);
void bt_set_passcode(char* passcode);
void bt_get_passcode(void);
void bt_get_version(void);

#endif /* BLUETOOTH_H_ */
