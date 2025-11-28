/*
 * end_sem_keypad_7seg.c
 *
 * Created: 11/27/2025 6:47:49 PM
 * Author : ANGELREBECCA1
 */ 

#include <avr/io.h>

int main(void)
{
	DDRD = 0b00001111; //(PD0-PD3 are outputs on decoder)
	DDRF = 0b11111000; //(PF3-PF6, outputs(rows), PF0-PF2, inputs(columns))
    /* Replace with your application code */
    while (1) 
    {
		
		PORTF = 0b11110111; //Row A low(PF3=0), others high
		//button 1
		if ((PINF & 0b00000001)==0){
			PORTD = 1;
			while((PINF & 0b00000001)==0);
		}
		
		//button 2
		PORTF = 0b11110111; //Row A low(PF3=0), others high
		if ((PINF & 0b00000010)==0){
			PORTD = 2;
			while((PINF & 0b00000010)==0);
		}
		
		//button 3
		PORTF = 0b11110111; //Row A low(PF3=0), others high
		if ((PINF & 0b00000100)==0){
			PORTD = 3;
			while((PINF & 0b00000100)==0);
		}
		
		//button 4
		PORTF = 0b11101111; //row B(PF4=0), others high
		if ((PINF &(1<<0))==0){
			PORTD = 4;
			while ((PINF &(1<<0))==0);
		}
		
		//button 5
		PORTF = 0b11101111; //row B(PF4=0), others high
		if ((PINF &(1<<1))==0){
			PORTD = 5;
			while ((PINF &(1<<1))==0);
		}
		
		//button 6
		PORTF = 0b11101111; //row B(PF4=0), others high
		if ((PINF &(1<<2))==0){
			PORTD = 6;
			while ((PINF &(1<<2))==0);
		}
		
		//button 7
		PORTF = 0b11011111; //row C(PF5=0), others high
		if ((PINF &(1<<0))==0){
			PORTD = 7;
			while ((PINF &(1<<0))==0);
		}
		
		//button 8
		PORTF = 0b11011111; //row C(PF5=0), others high
		if ((PINF &(1<<1))==0){
			PORTD = 8;
			while ((PINF &(1<<1))==0);
		}
		
		//button 9
		PORTF = 0b11011111; //row C(PF5=0), others high
		if ((PINF &(1<<2))==0){
			PORTD = 9;
			while ((PINF &(1<<2))==0);
		}
		
		//button 0
		PORTF = 0b10111111; //row D low(PF6), others high
		if ((PINF & (1<<1))==0){
			PORTD = 0;
			while ((PINF & (1<<1))==0);
		}
		
		}
		
    }


