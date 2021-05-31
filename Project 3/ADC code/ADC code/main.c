/*
 * ADC code.c
 *
 * Created: 28/05/2021 00:08:29
 * Author : kaspe
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>

static double Digitalvalue = 0;
static double Weightvalue = 0;
static double TargetWeight = 2.63; 
int bit = 1024;
int voltref= 5;


void setupADC()
{
	ADMUX |= (1  << REFS0) | (1 << MUX0) | (1 << MUX2); // set the Voltage reference to be AVCC (REFS0) and Enable ADC5 which is on PC5 
	ADCSRA |= (1 << ADEN) | (1 << ADIE) | (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2); // ADC Enable (ADEN) make the ADC Interrupt on completions (ADIE), Set Presacler to 128 
	DIDR0 |= (1 << ADC5D);
	
	sei();
}

void AdcConversion()
{
	ADCSRA |= (1 << ADSC); // set's a one to the register that starts the conversion when it's done it'll trigger an interrupt and set this bit to be 0 again to restart just set it to 1 again and it'll start again.
}

int main(void)
{
	DDRD |= (1 << 0);
	setupADC();
	AdcConversion();
    /* Replace with your application code */
    while (1) 
    {
		if (Weightvalue >= TargetWeight )
			{
				PORTD |= (1<< 0);
			}
    }
}

ISR(ADC_vect)
{
	Digitalvalue=ADC; //set's a variable to equal the analog to digital conversion value 
	Weightvalue = (Digitalvalue*bit)/voltref;
}