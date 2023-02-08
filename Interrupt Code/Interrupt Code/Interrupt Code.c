/*
 * Interrupt_Code.c
 *
 * Created: 11/30/2016 3:35:17 PM
 *  Author: Seyam
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>


volatile unsigned int timeVariable=0;

ISR(TIMER0_OVF_vect){
	timeVariable++;
	if(timeVariable>=225){
		timeVariable=0;
		PORTB ^=(1<<PORTB5);
	}
	
}

int main(void)
{
	DDRB = 0x20;  //DDRB = 0b0010 0000
	TCCR0B = (1<<CS02); // clock/256
	TIFR0 = 1 << TOV0; // RESETS OVERFLOW FLAG REGISTER
	TIMSK0 = 1<< TOIE0; // GIVES AN INTERRUPT IF OVERFLOW HAPPENS
	sei(); //CALLS THE ISR IF INTERRUPT HAPPENS
	
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}