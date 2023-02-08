/*
 * USART.c
 *
 * Created: 12/6/2016 12:54:19 AM
 * Author : Krishna Ray
 */ 
#define F_CPU 16000000UL  // 16 MHz
#include <avr/io.h>
#include <avr/interrupt.h>

//Define Baud
#define USART_BAUDRATE 19200
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

 uint8_t value = 0;// volatile so both main and RX interrupt can use it
volatile uint8_t newData = 0;
ISR(USART_RX_vect)
{
	value = UDR0;
	newData = 1;
}

void USART_Init(void)
{
	// Set baud rate
   UBRR0L = BAUD_PRESCALE;//lower 8-bits into the the UBRRL register
   UBRR0H = (BAUD_PRESCALE >> 8); //upper 8-bits into the UBRRH register
   UCSR0B = ((1<<TXEN0)|(1<<RXEN0) | (1<<RXCIE0));//enable tx and Rx. Receive interrupt
	
 /* Default frame format is 8 data bits, no parity, 1 stop bit to change use UCSRC, see AVR datasheet*/ 
}
void USART_SendByte(uint8_t data){

	// Wait until last byte has been transmitted
	while((UCSR0A & (1<<UDRE0)) == 0);

	// Transmit data
	UDR0 = data;
}
uint8_t USART_ReceiveByte(){
	while((UCSR0A &(1<<RXC0)) == 0);
	return UDR0;
}
void Led_init(void){
	DDRC =0xFF;
	PORTC = 0xFF;//All off//0 = LED off
}
int main(void)
{

	
	//Led_init();
	USART_Init();
	sei();
	USART_SendByte(0x49);
	USART_SendByte('O');
	USART_SendByte(0b01010100);
	USART_SendByte(45);
	USART_SendByte(0x41);
	USART_SendByte('R');
	USART_SendByte(0x4D);
	USART_SendByte(0b01011001);
	DDRB |=(1<<PORTB5);

    while (1) 
    {

		if(value == 'A')
			{
				PORTB ^=(1<<PORTB5);
			}


		if(newData >= 1)
		{
			USART_SendByte(value);
			//PORTB = ~value;
			newData = 0;
		}
    }
	return 0;
}

