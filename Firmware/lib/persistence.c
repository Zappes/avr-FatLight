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

FatLightPersistenceHeader persHeader = {0,0};
FatLightPersistenceData persData = {0,0,0,0,1,0xFF};

void persistence_restore(uint8_t slot) {
	if(slot >= PERSISTENCE_NUM_SLOTS)
		return;

	cli();
	eeprom_read_block((void*)&persData, (void*)(sizeof(persHeader) + (slot * sizeof(persData))), sizeof(persData));
	sei();

	if(persData.magic == PERSISTENCE_EEPROM_MAGIC) {
		anim_set_step(persData.step);
		anim_set_delay(persData.delay);
		anim_set_mode(persData.mode);
		anim_set_rgb_numeric(persData.rgb);
		anim_set_level(persData.level);
	}
	else {
		anim_set_step(1);
		anim_set_delay(0);
		anim_set_mode(ANIM_MODE_SET);
		anim_set_level(0x70);
	}

	if(slot != persHeader.slot) {
		persHeader.magic = PERSISTENCE_EEPROM_MAGIC;
		persHeader.slot = slot;

		cli();
		eeprom_write_block((void*)&persHeader, (void*)0, sizeof(persHeader));
		sei();
	}
}

void persistence_persist(uint8_t slot) {
	if(slot >= PERSISTENCE_NUM_SLOTS)
		return;

	uint32_t rgb = anim_get_current_rgb_numeric();
	uint8_t delay = anim_get_delay();
	uint8_t mode = anim_get_mode();
	uint8_t step = anim_get_step();
	uint8_t level = anim_get_level();

	// only persist if it differs from the last read state
	if(rgb != persData.rgb || delay != persData.delay || mode != persData.mode || step != persData.step || level != persData.level) {
		persData.magic = PERSISTENCE_EEPROM_MAGIC;
		persData.rgb = rgb;
		persData.mode = mode;
		persData.delay = delay;
		persData.step = step;
		persData.level = level;

		cli();
		eeprom_write_block((void*)&persData, (void*)(sizeof(persHeader) + (slot * sizeof(persData))), sizeof(persData));
		sei();
	}

	if(slot != persHeader.slot) {
		persHeader.magic = PERSISTENCE_EEPROM_MAGIC;
		persHeader.slot = slot;

		cli();
		eeprom_write_block((void*)&persHeader, (void*)0, sizeof(persHeader));
		sei();
	}
}

uint8_t persistence_get_current_slot(void) {
	if(persHeader.magic == 0) {
		cli();
		eeprom_read_block((void*)&persHeader, (void*)0, sizeof(persHeader));
		sei();
	}

	if(persHeader.magic == PERSISTENCE_EEPROM_MAGIC) {
		return persHeader.slot;
	}
	else {
		return 0;
	}
}
