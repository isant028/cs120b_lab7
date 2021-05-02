/*	Author: Isabella Santiago
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 7  Exercise 2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *  DEMO LINK: 
 * 
 * MAX VALUE: 1010001111 //value saw with flashlight 
 * MIN VALUE: 0000110000 //value saw when photoresistor was covered
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init(){
	ADCSRA |= (1 << ADEN)  | (1 << ADSC) | (1 << ADATE);	
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00; 
    DDRD = 0xFF; PORTD = 0x00; 
    /* Insert your solution below */
	ADC_init();

    while (1) {
	    unsigned short adc = ADC;
	    PORTB = (short)adc;
	    PORTD = (short)(adc >> 8);

    }
    return 1;
}
