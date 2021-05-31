/*
 * MotorInc.h
 *
 * Created: 31/05/2021 21:10:30
 *  Author: kaspe
 */ 


#ifndef MOTORINC_H_
#define MOTORINC_H_
void setupMotor (unsigned int n); // sets PORTD.n to be an output
void spinMotor1 (unsigned int n); // sets the output value of pin PORTD.n High 
void setupBUTonPORTB(unsigned char n);  //sets PORTB.n to be an input Button connected to ground
unsigned char getBUT(unsigned char n);  //  gets the immediate status of Button n....true for being pressed


#endif /* MOTORINC_H_ */