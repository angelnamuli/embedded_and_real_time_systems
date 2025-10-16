/*
 * serial_comm_withLED.c
 *
 * Created: 10/16/2025 5:51:24 PM
 * Author : ANGELREBECCA1
 */ 

#include <avr/io.h>
#define F_CPU 4000000UL


int main(void)
{
	UBRRH = 0x00;
	UBRRL = 0x19;
	DDRC = 0xff;
	unsigned char instruction[] = "Enter a number";
	UCSRC |= (1<<4) | (1<<5); //odd parity
	UCSRC |= (1<<1) | (1<<2); //8 bit size
	UCSRB |= (1<<TXEN) | (1<<RXEN); // initializing TX and RX pins for serial communication
	
	//Transmission
	for (int i=0;i <=14; i++){
		while ((UCSRA & (1<<UDRE))==0);
				UDR = instruction[i];
	}
	
	
    /* Replace with your application code */
    while (1) 
    { //receiving and LED logic
		while ((UCSRA &(1<<RXC))==0);
			char res = UDR;
			
			//controlling LED
			if (res == '0'){
				PORTC = (1<<PC0);
			}
			
			if (res == '1'){
				PORTC = (1<<PC1);	
			}
			
			if (res == '2'){
				PORTC = (1<<PC2);
			}
			
			if (res == '3'){
				PORTC = (1<<PC3);
			}
    }
}

