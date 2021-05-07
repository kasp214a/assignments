/*
 * making_sound_1.c
 *
 * Created: 05/05/2021 10:43:09
 * Author : kaspe
 */ 
#ifndef F_CPU
#define F_CPU 8000000
#endif
#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include "Cat.h"
#include "Scream.h"
#include "Funcitions.h" 
#include "Monster.h"
static int count = 0;
static int option = 0;



int main(void)
{
	DDRD = 0b11111111;
	
	
	setupBUTonPORTB(2);
	setupBUTonPORTB(3);
	setupBUTonPORTB(4);
	Timersetup();
	
	while (1)
	{
			if(getBUT(2))
			{
				option = 1;
			}
			if(getBUT(3))
			{
				option = 2;
			}
			if(getBUT(4))
			{
				option = 3;
			}
	}
}

ISR(TIMER0_OVF_vect)
{
	TCNT0 = 247;
	if (option == 1)
	{
		PORTD = pgm_read_byte(&(girl_scream[count++]));
		if (count > 9289)
		{
			count = 0;
		}
	}
	if (option == 2)
	{
		PORTD = pgm_read_byte(&(Cat_scream[count++]));
		if (count > 8817)
		{
			count = 0;
		}
	}
	if (option == 3)
	{
		PORTD = pgm_read_byte(&(monster_scream[count++]));
		if (count > 11610)
		{
			count = 0;
		}
	}

}