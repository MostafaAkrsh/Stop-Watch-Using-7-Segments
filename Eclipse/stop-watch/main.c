#include "Headers.h"

unsigned char seconds = 0;
unsigned char minutes = 0;
unsigned char hours = 0;

unsigned char flag = 0;

ISR(INT0_vect)
{
	seconds = 0;
	minutes = 0;
	hours = 0;
}

ISR(INT1_vect)
{	if(flag == 1)
	{
	TCCR1B = 0;
	}
	else flag = 1;
}

ISR(INT2_vect)
{
	TCCR1B = (1<<WGM12) | (1<<CS10) | (1<<CS12);
}

ISR(TIMER1_COMPA_vect)
{
	seconds++;
	if(seconds > 60)
	{
		minutes++;
		seconds = 0;
	}
	if (minutes > 60)
	{
		hours++;
		minutes = 0;
	}
	PORTC ^= (1<<PC5);
}

int main()
{
	IO_Init();
	Timer1_Init();
	External_Interrupts_Init();
	SREG |= (1<<7);

	while(1)
	{
		 Display_Seconds1(seconds);
		 _delay_ms(5);
		 Display_Seconds2(seconds);
		 _delay_ms(5);
		 Display_Minutes1(minutes);
		 _delay_ms(5);
		 Display_Minutes2(minutes);
		 _delay_ms(5);
		 Display_Hours1(hours);
		 _delay_ms(5);
		 Display_Hours2(hours);
		 _delay_ms(5);
	}
}
