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

#define RX_BUFFER_SIZE 128

char rxBuffer[RX_BUFFER_SIZE];
unsigned int rxReadPos =0;
unsigned int rxWritePos =0;

char getChar(void);
char peekChar(void);

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


void USART_Init( unsigned int ubrr)
{
	/*Set baud rate */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	
	UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0);
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
	DDRB=(1<<PORTB5);
	
	sei();
	
	USART_Init(MYUBRR);
	
    while(1)
    {
		
		
		//USART_Transmit('A');
		//_delay_ms(1000);
		
		
       //USART_Transmit(USART_Receive());
	   //string x= (string)USART_Receive();
	   
	    char c = getChar();
			 
		if (strcmp(c, "on") == 0)
		 {
						
			PORTB |=(1<<PORTB5);
					 
	     }
		 
		 
	    if(strcmp(c, "off") == 0)
	     {			
			PORTB &=~(1<<PORTB5);
				
		 } 
	   
	   
	   
	  /* if(USART_Receive()=="*1#"){
			PORTB |=(1<<PORTB5);
			USART_Transmit('1');
	   }
	   if(USART_Receive()=="*0#"){
		   PORTB &=~(1<<PORTB5);
		   USART_Transmit('O');
		   
	   }*/
	  
    }
}


char peekChar(void)
{
	char ret = '\0';
	
	if(rxReadPos != rxWritePos)
	{
		ret = rxBuffer[rxReadPos];
	}
	
	return ret;
}

char getChar(void)
{
	char ret = '\0';
	
	if(rxReadPos != rxWritePos)
	{
		ret = rxBuffer[rxReadPos];
		
		rxReadPos++;
		
		if(rxReadPos >= RX_BUFFER_SIZE)
		{
			rxReadPos = 0;
		}
	}
	
	return ret;
}





ISR(USART_RX_vect)
{
	rxBuffer[rxWritePos] = UDR0;
	
	rxWritePos++;
	
	if(rxWritePos >= RX_BUFFER_SIZE)
	{
		rxWritePos = 0;
	}
}