/*	Author: Jessie Lu
 *  Partner(s) Name: 
 *	Lab Section: 23
 *	Assignment: Lab #2  Exercise #4
 *	Exercise Description: Outputs port D first bit to 1 if weight > 140 and second bit to 1 if difference between A and C is greater than 80. The remaining bits are for the total weight.
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;

	unsigned char tmp = 0x00;
	unsigned char tmpD = 0x00;
	unsigned char totalW = 0x00;

    	while (1) {
		totalW = PINA + PINB + PINC; // total weight
		tmp = ((totalW >> 2) & 0xFC); // shift 2 to the right and set first 2 bits to 0

		// checks if weight is > 140
		if (totalW > 0x8C) {
			tmpD = 0x01;
		}

		// checks if difference is greater than 80
		if ((PINA - PINC) > 0x50 || (PINC - PINA) > 0x50) {
			tmpD = tmpD | 0x02;
		}

		tmpD = tmp | tmpD;

		PORTD = tmpD;
    	}
    	return 0;
}
