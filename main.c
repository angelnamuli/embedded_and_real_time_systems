/*
 * sem_practice_LED.c
 *
 * Created: 11/7/2025 3:52:51 PM
 * Author : ANGELREBECCA1
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD = 0XFF;
	PORTD = 0x00;
	PORTF = 0x00; //button
	
	
	
	
	
    /* Replace with your application code */
    while (1) 
    {
		if((PINF & 0b00000001)==0){
			PORTD|= (1<<PD2);
		}
		else{
			PORTD &= ~ (1<<PD2);
		}
		//turn the LED on and off
		
		
    }
}

