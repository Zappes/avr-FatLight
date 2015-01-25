/*
 * animation.h
 *
 *  Created on: 05.01.2015
 *      Author: zaphod
 */

#ifndef ANIMATION_H_
#define ANIMATION_H_

#define ANIM_MODE_SET		0
#define ANIM_MODE_FADE	1
#define ANIM_MODE_DISCO	2

void anim_init(void);

void anim_set_delay(uint8_t delay);
uint8_t anim_get_delay(void);

void anim_set_mode(uint8_t delay);
uint8_t anim_get_mode(void);

void anim_set_step(uint8_t step);
uint8_t anim_get_step(void);

void anim_set_level(uint8_t step);
uint8_t anim_get_level(void);


void anim_set_rgb_components(uint8_t red, uint8_t green, uint8_t blue);
void anim_set_rgb_numeric(uint32_t colVal);

uint32_t anim_get_target_rgb_numeric(void);
uint32_t anim_get_current_rgb_numeric(void);


#endif /* ANIMATION_H_ */
