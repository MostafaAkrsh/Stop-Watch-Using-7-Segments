/*
 * Interrupts.c
 *
 *  Created on: Sep 19, 2021
 *      Author: LENOVO
 */

#include "Interrupts.h"

void External_Interrupts_Init(){

	/* Configure the input ports */
	DDRD &= ~(1<<2) & ~(1<<3);
	DDRB &= ~(1<<2);

	PORTB |= (1<<2);
	PORTD |= (1<<2);

	/* Configure the Interrupts */
	GICR |= (1<<7) | (1<<6) | (1<<5);

	/*Interrupt 0 - Failing Edge*/
	MCUCR |= (1<<ISC01);

	/*Interrupt 1 - Rising Edge */
	MCUCR |= (1<<ISC11) | (1<<ISC10);

	/*Interrupt 2 - Failing Edge*/
	MCUCR |= (1<<ISC2);
}
