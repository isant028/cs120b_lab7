/*	Author: Isabella Santiago
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 7  Exercise 3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *  DEMO LINK: 
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
    //DDRD = 0xFF; PORTD = 0x00; 
    /* Insert your solution below */
	ADC_init();


    //MAX VALUE: 1010001111 (655) 
    int max = 550;
    while (1) {
	    unsigned short adc = ADC;
        if (adc == max){
            PORTB = 0xFF;
        }
        else if (adc >= max/2){
            PORTB =0x7F; 
        }
         else if (adc >= max/3){
            PORTB =0x3F; 
        }
         else if (adc >= max/4){
            PORTB =0x1F; 
        }
         else if (adc >= max/5){
            PORTB =0x0F; 
        }
         else if (adc >= max/6){
            PORTB =0x07; 
        }
         else if (adc >= max/7){
            PORTB =0x03; 
        }
        else if (adc >= max/8){
            PORTB =0x01; 
        }
        else{
            PORTB = 0x00; 
        }

        

    }
    return 1;

}
