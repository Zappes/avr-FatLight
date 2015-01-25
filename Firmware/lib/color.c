/*
 * color.c
 *
 *  Created on: 19.01.2015
 *      Author: zaphod
 */

#include <avr/io.h>
#include "color.h"

/*
 * adapted from http://tog.acm.org/resources/GraphicsGems/gems/HSLtoRGB.c
 * converts a HSL value to an RGB value.
 */
void hslToRgb(uint8_t h, uint8_t s, uint8_t l, uint8_t* r, uint8_t* g, uint8_t* b)
{
	int v = (l < 128)
		? (long int)l * (256 + (long int)s) >> 8
		: ((((long int)l + (long int)s) << 8) - (long int)l * (long int)s) >> 8;

	if (v <= 0)
	{
		*r = *g = *b = 0;
	}
	else
	{
		long int m;
		long int sextant;
		long int fract, vsf, mid1, mid2;
		int hue = h;

		m = l + l - v;
		hue *= 6;
		sextant = hue >> 8;
		fract = hue - (sextant << 8);
		vsf = v * fract * (v - m) / v >> 8;
		mid1 = m + vsf;
		mid2 = v - vsf;
		switch (sextant) {
			case 0: *r = v;    *g = mid1;  *b = m;    break;
			case 1: *r = mid2; *g = v;     *b = m;    break;
			case 2: *r = m;    *g = v;     *b = mid1; break;
			case 3: *r = m;    *g = mid2;  *b = v;    break;
			case 4: *r = mid1; *g = m;     *b = v;    break;
			case 5: *r = v;    *g = m;     *b = mid2; break;
		}
	}
}
