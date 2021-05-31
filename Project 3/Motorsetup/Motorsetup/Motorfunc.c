/*
 * Motorfunc.c
 *
 * Created: 31/05/2021 21:10:14
 *  Author: kaspe
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

void setupMotor (unsigned int n) // sets PORTD.n to be an output
{
	DDRD |= (1 << n);
} 




void spinMotor1 (unsigned int n) // sets the output value of pin PORTD.n High 
{
	PORTD |= (1 << n);
	_delay_ms(1000);
	PORTD &= ~(1 << n);
}

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