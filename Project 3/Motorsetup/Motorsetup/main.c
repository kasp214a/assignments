/*
 * Motorsetup.c
 *
 * Created: 31/05/2021 21:07:23
 * Author : kaspe
 */ 


#include <avr/io.h>
#include "MotorInc.h"



int main(void)
{
	setupMotor(1);
	setupBUTonPORTB(0);  //sets PORTB.n to be an input Button connected to ground
    /* Replace with your application code */
    while (1) 
    {
		if (getBUT(0)) spinMotor1(1);
    }
}

