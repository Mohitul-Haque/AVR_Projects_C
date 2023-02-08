#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)
int main (void)
{
	UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0); // Turn on the transmission and reception circuitry
	//UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1); // Use 8-bit character sizes
	UBRRH = (BAUD_PRESCALE >> 8); // Load upper 8-bits of the baud rate value into the high byte of the UBRR register
	UBRRL = BAUD_PRESCALE; // Load lower 8-bits of the baud rate value into the low byte of the UBRR register
	UCSRB |= (1 << RXC); // Enable the USART Recieve Complete interrupt (USART_RXC)
	sei(); // Enable the Global Interrupt Enable flag so that interrupts can be processed
	DDRA = 0XFF;
	while (1) // Loop forever
	{
		// Do nothing - echoing is handled by the ISR instead of in the main loop
		char line[20];
		if (strcmp(line, "on") == 0)
		{
			PORTA = 0xFF;
		}
	}
}
ISR(USART_RXC_vect)
{
	char line[20];
	int  i = 0;
	while(1) {
		line[i] = getchar();
		if (line[i] == '\n') break;
		i++;
	}
	line[i] = 0;
	// Echo back the received byte back to the computer
}