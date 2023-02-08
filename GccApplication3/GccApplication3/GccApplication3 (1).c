#include <avr/io.h>
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
		
		//if(PINC & (1<<PC0)){
			for(int i=1; i<=128; i=i*2){
				PORTD =i;
				_delay_ms(100);
			}
			
			
			//else{
				
				for(int i=128; i>=1; i=i/2){
					PORTD =i;
					_delay_ms(100);
				}
			//}
			
		}
		return 0;
	}