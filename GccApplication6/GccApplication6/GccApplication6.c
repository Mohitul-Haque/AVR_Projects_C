

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main (void)
{
	
	 DDRB |= 0b00100000;
	//DDRD = 0x03;
	//DDRD &= ~(1 << PD1);
	
	
	
	//DDRC &= ~(1 << PC0);
	//DDRC.0 = 1;          

	while (1)
	{
		
			PORTB |= 0b00100000;
	
			_delay_ms(1000); 
		
			PORTB &= 0b11011111;
			
			_delay_ms(1000);			
   }
   
}   