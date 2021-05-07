/*
 * Functions.c
 *
 * Created: 07/05/2021 16:29:05
 *  Author: kaspe
 */ 
#include <avr/io.h>
#include <stdbool.h>
#include <avr/interrupt.h>

//Function definitions
int count = 0;


void setupBUTonPORTB(unsigned char n)  //sets PORTB.n to be an input Button connected to ground
{
	DDRB &= ~(1<<n);
	PORTB |= (1<<n);
}

unsigned char getBUT(unsigned char n)  //  gets the immediate status of Button n....true for being pressed
{
	if (0 == (PINB & (1<<n)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Timersetup () //
{
	/*TCCR1B |= (1<< WGM12);
	OCR1A =  2187;
	TIMSK1 |= (1 << OCIE1A);
	
	sei();
	
	TCCR1B |= (1 << CS12); // set prescaler to 256*/
	
		TCCR1A |= (1<<COM1A1) | (1<<WGM10);
		TCCR1B |= (1<<CS10) | (1<<WGM12);
		// set up timer with prescaler = 256
		TCCR0B |= (1 << CS02);
		// initialize counter
		TCNT0 = 247;
		// enable overflow interrupt
		TIMSK0 |= (1 << TOIE0);   //error in original code TIMSK was chosen
		// enable global interrupts
		sei();
		// initialize overflow counter variable	
	

}

