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

	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char tmpD0 = 0x00;
	unsigned char tmpD1 = 0x00;
	unsigned char totalW = 0x00;

    	while (1) {
		tmpA = PINA & 0xFF; tmpB = PINB & 0xFF; tmpC = PINC & 0xFF;
		
		totalW = (tmpA + tmpB + tmpC);
	        
		// checks if weight is > 140
		if (totalW > 0x8C) {
			tmpD0 = 0x01;
		}
		else { // must include else statement
			tmpD0 = 0x00;
		}

		// checks if difference is greater than 80
		if ((tmpA - tmpC) > 0x50 || (tmpC - tmpA) > 0x50) {
			tmpD1 =  0x02;
		}
		else { // must include else statmeent
			tmpD1 = 0x00;
		}

		totalW = (totalW >> 2) & 0xFC;
	        
		PORTD = totalW | tmpD1 | tmpD0;
    	}
    	return 0;
}
