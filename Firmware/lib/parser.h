/*
 * parser.h
 *
 *  Created on: 06.01.2015
 *      Author: zaphod
 */

#ifndef PARSER_H_
#define PARSER_H_

void parser_prepare_buffer(char* commandBuffer);
char* parser_get_string(char** bufferPointer);
uint32_t parser_get_long_hex(char** bufferPointer);
uint8_t parser_get_byte_hex(char** bufferPointer);

#endif /* PARSER_H_ */
