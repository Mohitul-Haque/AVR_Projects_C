/*
 * USART.c
 *
 * Created: 12/6/2016 12:54:19 AM
 * Author : Krishna Ray
 */ 
#define F_CPU 16000000  // 16 MHz

#define LED_ON PORTB |=(1<<PORTB5)
#define LED_OFF PORTB &=~(1<<PORTB5)
#define LED_TOGGLE PINB |=(1<<PINB5)

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR(ADC_vect){
	LED_ON;
	_delay_ms(1000);
	LED_OFF;
	_delay_ms(1000);
}

void adc_init(void){
	
	ADMUX = (1<<REFS0)|(1<<MUX0); //Reference Selection to Vcc
	ADCSRA = (1<<ADEN)|(1<<ADSC)|(1<<ADIE)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0); //prescaled to 125Khz
	sei();
}

uint16_t adc_read(void)
{
	
	//ADMUX = ADMUX & 0b11110000; // clears the lower 4 bits to select A0 channel
	
	//ADCSRA |= (1<<ADSC);
	
	while(ADCSRA & (1<<ADSC));
	
	return (ADC);
}


void led_init(){
	DDRB=0xFF;
}



int main(void)
{
	led_init();
	adc_init();
		
    while (1) 
    {
		
		//uint16_t i = adc_read();
				
    }
}

