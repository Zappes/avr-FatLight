/*
 * uart.c
 *
 * Created: 15.09.2013 03:05:59
 * Author: Paul Rogalinski, paul@paul.vc
 * Modified by Gregor Ottmann, http://elektroschrott.bluephod.net
 */

#ifndef USART_H_
#define USART_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>

#include "uart.h"

char commandBuffer[64];
volatile uint8_t bufferPos = 0;
volatile bool bufferReady = false;

uart_callback_t serialBufferReadyCallback = 0x00;

/*
 * Sets the callback reference for buffer ready events 
 */
void uart_set_callback(uart_callback_t cb) {
	serialBufferReadyCallback = cb;
}

/*
 * Initializes the USART registers, enables the ISR
 */
void uart_init(void) {
	UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01); // 1 Stop-Bit, 8 Bits
	UCSR0B = (1 << TXEN0) | (1 << RXEN0); // enable RX/TX
	UCSR0B |= (1 << RXCIE0); // Enable the USART Receive Complete interrupt (USART_RXC)
			
	/* UBRRL and UBRRH � USART Baud Rate Registers */
	UBRR0H = (uint8_t) (UART_BAUD_CALC(UART_BAUD_RATE,F_CPU) >> 8);
	UBRR0L = (uint8_t) (UART_BAUD_CALC(UART_BAUD_RATE, F_CPU));

	// enable interrupts with sei() in your main program.
	// this is required for this code to work, but it's not
	// done right here in order to not interfere with your code.
}

/*
 * Waits for the usart to become ready to send data and 
 * writes a single char.
 */
void uart_write_char(unsigned char c) {
	// UCSRA � USART Control and Status Register A
	// � Bit 5 � UDRE: USART Data Register Empty
	while (!(UCSR0A & (1 << UDRE0)));

	UDR0 = c;
}

/*
 * Writes a string/char[] to the serial port.
 */
void uart_write_string(char *str) {
	while (*str != 0x00)
		uart_write_char(*str++);
}

void uart_write_formatted(const char* format, ...) {
	char outbuffer[UART_FORMAT_BUFFER_SIZE];

  va_list argptr;
  va_start(argptr, format);
  vsnprintf(outbuffer, UART_FORMAT_BUFFER_SIZE, format, argptr);
  va_end(argptr);

	uart_write_string(outbuffer);
}

void uart_writeln_char(unsigned char c) {
	uart_write_char(c);
	uart_write_string("\r\n");
}

void uart_writeln_string(char *str) {
	uart_write_string(str);
	uart_write_string("\r\n");
}

void uart_writeln_formatted(const char* format, ...) {
	char outbuffer[UART_FORMAT_BUFFER_SIZE];

  va_list argptr;
  va_start(argptr, format);
  vsnprintf(outbuffer, UART_FORMAT_BUFFER_SIZE, format, argptr);
  va_end(argptr);

	uart_write_string(outbuffer);
	uart_write_string("\r\n");
}


/*
 * Handles bytes received from the serial port. Fills up the command buffer and calls
 * the bufferReadyCallback when the buffer overflows or a linefeed/newline has been
 * sent.
 */
ISR( USART_RX_vect) {
	char chrRead;
	chrRead = UDR0;
	commandBuffer[bufferPos++] = chrRead;
	commandBuffer[bufferPos] = 0x00;
	if ((bufferPos >= (sizeof(commandBuffer) - 1))
			|| ((chrRead == '\n' || chrRead == '\r'))) {
		bufferPos = 0;
		bufferReady = true;
		if (serialBufferReadyCallback != 0x00)
			serialBufferReadyCallback(commandBuffer);
	}
}

#endif /* USART_H_ */
