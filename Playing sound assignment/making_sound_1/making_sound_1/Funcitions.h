/*
 * Funcitions.h
 *
 * Created: 07/05/2021 16:36:19
 *  Author: kaspe
 */ 


#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

void setupBUTonPORTB(unsigned char n);  //sets PORTB.n to be an input Button connected to ground
unsigned char getBUT(unsigned char n);  //  gets the immediate status of Button n....true for being pressed
void Timersetup ();

#endif /* FUNCTIONS_H_ */