/*
 * serial_comm_with_LEDChat.c
 *
 * Created: 12/3/2025 3:02:57 PM
 * Author : ANGELREBECCA1
 */ 

#include <avr/io.h>


int main(void)
{
	DDRC = 0xff; // LEDs are output
	unsigned char instruction[] = "Welcome to USART test";
	
	UBRRH = 0x00;
	UBRRL = 0x19;
	UCSRB |= (1<<TXEN)|(1<<RXEN); //configure Rx and Tx for serial comm
	UCSRC = (1<<URSEL); 
	UCSRC |= (1<<2)|(1<<1); //8 bit character size
	UCSRC |= (1<<5);//even parity
	UCSRC &=~(1<<4); //even parity
	UCSRC &= ~(1<<3); // 1 stop bit
	
	//transmission
	for(int i=0;i<21;i++){
		while ((UCSRA & (1<<5))==0);
		UDR = instruction[i]; //pick instruction at given index
	}
	
    /* Replace with your application code */
    while (1) 
    {
		//receiving
		while ((UCSRA & (1<<RXC))==0);
		char rec = UDR;
		
		//controlling LEDs
		if(rec =='0'){
			PORTC = (1<<PC0);
		}
		
		if(rec =='1'){
			PORTC = (1<<PC1);
		}
		
		if(rec =='2'){
			PORTC = (1<<PC2);
		}
    }
}

