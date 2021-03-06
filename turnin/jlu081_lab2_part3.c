/*	Author: Jessie Lu
 *  Partner(s) Name: 
 *	Lab Section: 23
 *	Assignment: Lab #2  Exercise #3
 *	Exercise Description: Continues from lab 2 exercise 2 and outputs 1 to P7 if lot is full
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
	DDRB = 0xFF; PORTC = 0x00;
  
	unsigned char cntavail = 0x00; // available spaces
	unsigned char isFull = 0x00;	// is parking lot full  	
	
	while (1) {
	     isFull = PINA & 0x80;
	     // 1) Read input
	     // Use the lower nibble for spaces
	     // 1st bit is first space, 2nd bit is second space, and so on
	     // shift bits so that it is in the first bit
	     cntavail = ((PINA & 0x08) >> 3) + ((PINA & 0x04) >> 2) + ((PINA & 0x02) >> 1) + (PINA & 0x01);

	     // 2) Perform computation
	     if (cntavail == 4) {
		     cntavail = (4 - cntavail) | 0x80;
	     }
	     else {
		     cntavail = 4 - cntavail;	 // subtract total number of spaces from spaces taken
	     }
	     // Write output
	     PORTC = cntavail;
	 }
	 return 0;
}
