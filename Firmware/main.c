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
#include "lib/animation.h"
#include "lib/bluetooth.h"
#include "lib/persistence.h"

int main(void)
{
	strip_init();
	uart_init();
	control_init();
	anim_init();
	bt_init();

	persistence_restore(persistence_get_current_slot());

	// required for serial input and the animation loop to work!
	sei();

	while(1)
	{
		// everything is done in the interrupt routines ...
	}

	return 0;
}
