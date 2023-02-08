/*
 * Interrupt.c
 *
 * Created: 11/28/2016 3:13:55 PM
 *  Author: Seyam
 */ 


#include <avr/io.h>


//#include <avr/interrupt.h>
#include <util/delay.h>


int main (void)
{
	
	DDRD = 0xFF;
	//DDRD = 0x03;
	//DDRD &= ~(1 << PD1);
	
	
	
	//DDRC &= ~(1 << PC0);
	
	//DDRC.0 = 1;

	while (1)
	{
		
		
			for(int i=0; i<=128; i=i*2){
				PORTD =i;
				_delay_ms(100);
			}
	
	
			
			for(int i=128; i>=1; i=i/2){
				PORTD =i;
				_delay_ms(100);
			}
	
		
	}
	return 0;
}