/*
 * Button_Example_New.c
 *
 * Created: 11/28/2016 1:28:53 PM
 *  Author: Seyam
 */ 


#include <avr/io.h>

/*
 * Button_Input.c
 *
 * Created: 11/28/2016 11:57:34 AM
 *  Author: Seyam
 */ 


# include <avr/io.h>

int main (void)
{
	
	//DDRD = 0xFF;
	DDRD = 0x03;
	//DDRD &= ~(1 << PD1);
	
	
	
	DDRC &= ~(1 << PC0);
	//DDRC.0 = 1;          

	while (1)
	{
		if (PINC & (1<<PC0)){
			PORTD |= (1<<PD0);
			//PORTD |= (1<<PD1);
		}
		else{
			PORTD &= ~(1<<PD0);
			//PORTD &= ~(1<<PD1);			
		}
		
	}
	return 0;
}