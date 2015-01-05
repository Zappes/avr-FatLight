/*
 * Controller code for a device that reads analog sensor values and sleeps
 * while it isn't used. Check the README at Github for more information.
 *
 * Written by Gregor Ottmann, https://github.com/Zappes
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "lib/stripcontrol.h"
#include "lib/uart.h"
#include "lib/control.h"

/*
 * This one doesn't do much. It just calls the two other functions.
 */
int main(void)
{
	strip_init();
	uart_init();
	control_init();

	strip_set_color_hex("FF00FF");
	_delay_ms(50);
	strip_set_color_hex("000000");

	// required for serial input and the animation loop to work!
	sei();

	while(1)
	{
		// everything is done in the interrupt routines ...
	}

	return 0;
}
