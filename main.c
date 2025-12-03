/*
 * lcd_reverse.c
 *
 * Created: 12/3/2025 8:40:27 PM
 * Author : ANGELREBECCA1
 */ 

#include <avr/io.h>
#include <util/delay.h>
unsigned char msg[] = "Welcome";
void latch(void);
void write_msg();

void latch(){
	PORTE |=(1<<PE5);
	_delay_ms(100);
	PORTE &= ~(1<<PE5);
	_delay_ms(100);
}

void write_msg(){
	PORTE &= ~(1<<PE3);
	PORTF = 0xC0;
	latch();
	PORTE |=(1<<PE3);
	for(int i=6; i>=0;i--){
		PORTF = msg[i];
		latch();
	}
	
}
int main(void)
{
	DDRE = 0xff;
	DDRF = 0xff; 
	
	
	
		PORTE &= ~(1<<PE3); // command mode
		latch();
		//clear screen
		PORTF = 0x01;
		latch();
		
		PORTF = 0x38;           // Function set: 8-bit, 2 lines, 5x7
		latch();

		PORTF = 0x0F;           // Display ON, cursor ON, blink
		latch();
		
		PORTF = 0x06;           // Entry mode: increment, no shift
		latch();
		write_msg();
		
		// Turn on display and Blink cursor
		PORTF= 0b00001111;
		latch();
	
	
    /* Replace with your application code */
    while (1) 
    {
		
    }
}

