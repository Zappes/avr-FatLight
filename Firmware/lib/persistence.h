/*
 * persistence.h
 *
 *  Created on: 11.07.2014
 *      Author: zaphod
 */

#ifndef PERSISTENCE_H_
#define PERSISTENCE_H_

#include <avr/io.h>

#define PERSISTENCE_EEPROM_MAGIC	0x1601
#define PERSISTENCE_NUM_SLOTS			3

typedef struct {
  uint16_t magic;
  uint8_t slot;
} FatLightPersistenceHeader;

typedef struct {
  uint16_t magic;
  uint32_t rgb;
  uint8_t mode;
  uint8_t delay;
} FatLightPersistenceData;

void persistence_restore(uint8_t slot);
void persistence_persist(uint8_t slot);

uint8_t persistence_get_current_slot(void);

#endif /* PERSISTENCE_H_ */
