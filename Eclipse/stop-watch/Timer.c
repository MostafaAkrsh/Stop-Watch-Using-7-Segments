/*
 * Timer.cpp
 *
 *  Created on: Sep 19, 2021
 *      Author: LENOVO
 */
#include "Timer.h"
void Timer1_Init(){
	/* Current Timer */
	TCNT1 = 0;

	/* Compare Value */
	OCR1A = 1000;

	/* Enable Compare Interrupt */
	TIMSK = (1<<OCIE1A);

	/* Configuration */
	TCCR1B = (1<<WGM12) | (1<<CS10) | (1<<CS12);

}
