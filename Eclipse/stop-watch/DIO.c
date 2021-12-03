/*
 * DIO.cpp
 *
 *  Created on: Sep 19, 2021
 *      Author: LENOVO
 */

#include "DIO.h"

void IO_Init()
{
	DDRA |= 0x3F;

	DDRC |= 0x0F;
	PORTC &= ~(0x0F);
}

void Display_Seconds1(unsigned char seconds)
{

		seconds = seconds%10;


	PORTA = (1<<5);
	PORTC = (seconds & 0x0F) | (PORTC & 0xF0);
}

void Display_Seconds2(unsigned char seconds)
{
	if(seconds >= 10)
	{
		seconds = seconds /10;
	}
	else
	{
		seconds = 0;
	}

	PORTA = (1<<4);

	PORTC = seconds;
	//PORTC = (seconds & 0x0F) | (PORTC & 0xF0);
}

void Display_Minutes1(unsigned char minutes)
{

		minutes = minutes%10;

	PORTA = (1<<3);
	PORTC = (minutes & 0x0F) | (PORTC & 0xF0);
}

void Display_Minutes2(unsigned char minutes)
{
	if(minutes >= 10)
	{
		minutes = minutes /10;
	}
	else
	{
		minutes = 0;
	}

	PORTA = (1<<2);
	PORTC = ((minutes) & 0x0F) | (PORTC & 0xF0);
}

void Display_Hours1(unsigned char hours)
{

		hours = hours%10;


	PORTA = (1<<1);
	PORTC = (hours & 0x0F) | (PORTC & 0xF0);
}

void Display_Hours2(unsigned char hours)
{
	if(hours >= 10)
	{
		hours = hours /10;
	}
	else
	{
		hours = 0;
	}

	PORTA = (1<<0);
	PORTC = ((hours) & 0x0F) | (PORTC & 0xF0);
}

