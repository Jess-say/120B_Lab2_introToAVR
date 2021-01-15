/*	Author: Jessie Lu
 *  Partner(s) Name: 
 *	Lab Section: 23
 *	Assignment: Lab #2  Exercise #1
 *	Exercise Description: Outputs 1 when garage door is open at night otherwise output 1
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    	/* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; // inputs 
	DDRB = 0xFF; PORTB = 0x00;
  
   	 unsigned char tmpA0 = 0x00; // holds A0
   	 unsigned char tmpA1 = 0x00; // holds A1
   	 unsigned char tmpB = 0x00;
   	
	 while (1) {
	     // 1) Read input
	     tmpA0 = PINA & 0x01;
	     tmpA1 = PINA & 0x02;

	     // 2) Perform computations
	     if ((tmpA0 == 0x01) && (tmpA1 != 0x02))
		    tmpB = (tmpB & 0xFE) | 0x01;	// FE gets only the last bit
	     else
		    tmpB = (tmpB & 0xFE);
	     // 3) write output
	     PORTB = tmpB;
	 }
	 return 0;
}
