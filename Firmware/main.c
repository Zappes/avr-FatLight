/*
 * Controller code for a device that reads analog sensor values and sleeps
 * while it isn't used. Check the README at Github for more information.
 *
 * Written by Gregor Ottmann, https://github.com/Zappes
 */
#include <avr/io.h>
#include <util/delay.h>

#include "lib/stripcontrol.h"

/*
 * This one doesn't do much. It just calls the two other functions.
 */
int main(void)
{
	strip_init();

	while(1)
	{
		strip_set_colors(1, 0 , 0);
		_delay_ms(1000);
		strip_set_colors(0, 1 , 0);
		_delay_ms(1000);
		strip_set_colors(0, 0 , 1);
		_delay_ms(1000);
	}

	return 0;
}

