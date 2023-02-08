/*
 * GccApplication9.c
 *
 * Created: 12/14/2016 11:31:17 AM
 *  Author: Seyam
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{	
	DDRB|=(1<<PORTB5);
	DDRB &=~(1<<PORTB5);
	//PORTB=
	
	
    while(1)
    {	
		
		while (PINB & (1<<PINB4))
		{
			PORTB |=(1<<PORTB5);
			_delay_ms(1000);
			PORTB &=~(1<<PORTB5);
			_delay_ms(1000);
		}
		
        
    }
}