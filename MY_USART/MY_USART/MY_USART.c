/*
 * MY_USART.c
 *
 * Created: 12/11/2016 10:25:42 AM
 *  Author: Seyam
 */ 
#define F_CPU 16000000
#define FOSC 16000000 // Clock Speed
#define BAUD 19200
#define MYUBRR FOSC/16/BAUD-1



#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <util/delay.h>


void USART_Init( unsigned int ubrr)
{
	/*Set baud rate */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	/* Set frame format: 8data, 2stop bit */
	UCSR0C = (3<<UCSZ00);
}


unsigned char USART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)) );
	/* Get and return received data from buffer */
	return UDR0;
}


void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) );
	/* Put data into buffer, sends the data */
	UDR0 = data;
}

int main(void)
{
	DDRB=0xFF;
	
	//sei();
	
	USART_Init(MYUBRR);
	
    while(1)
    {
		
		
		
		//USART_Transmit(USART_Receive());
			   
	   if(USART_Receive()=='1'){
		   
			PORTB |=(1<<PORTB5);
			USART_Transmit('1');
	   }
	   
	   if(USART_Receive()=='0'){
		   PORTB &=~(1<<PORTB5);
		   USART_Transmit('O');
		   
	   }
    }
}