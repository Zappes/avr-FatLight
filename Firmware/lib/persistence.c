/*
 * persistence.c
 *
 *  Created on: 11.07.2014
 *      Author: zaphod
 */

#include "persistence.h"
#include "animation.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>

FatLightPersistenceData pers_data = {0,0};

void persistence_restore() {
	cli();
	eeprom_read_block((void*)&pers_data, (void*)0, sizeof(pers_data));
	sei();

	if(pers_data.magic == EEPROM_MAGIC) {
		anim_set_direct_rgb_numeric(pers_data.rgb);
		anim_set_delay(pers_data.delay);
	}
	else {
		anim_set_direct_rgb_numeric(0);
		anim_set_delay(0);
	}
}

void persistence_persist() {
	uint32_t rgb = anim_get_current_rgb_numeric();
	uint8_t delay = anim_get_delay();

	// only persist if it differs from the last read state
	if(rgb != pers_data.rgb || delay != pers_data.delay) {
		pers_data.magic = EEPROM_MAGIC;
		pers_data.rgb = rgb;
		pers_data.delay = delay;

		cli();
		eeprom_write_block((void*)&pers_data, (void*)0, sizeof(pers_data));
		sei();
	}
}

