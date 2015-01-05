/*
 * persistence.h
 *
 *  Created on: 11.07.2014
 *      Author: zaphod
 */

#ifndef PERSISTENCE_H_
#define PERSISTENCE_H_

#include <avr/io.h>

#define EEPROM_MAGIC 0x1337

typedef struct {
  uint16_t magic;
  uint32_t rgb;
  uint8_t delay;
} FatLightPersistenceData;

void persistence_restore();
void persistence_persist();

#endif /* PERSISTENCE_H_ */
