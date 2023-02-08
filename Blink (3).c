/*
 * GccApplication1.c
 *
 * Created: 11/27/2016 2:42:48 PM
 *  Author: Seyam
 */ 



#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC = 0xFF;
	while(1) //infinite loop
	{
		PORTC = 0xFF; 
		_delay_ms(1000); 
		PORTC= 0x00; 
		_delay_ms(1000);
	}
}