/*
 * DIO.h
 *
 *  Created on: Sep 19, 2021
 *      Author: LENOVO
 */

#ifndef DIO_H_
#define DIO_H_
#include "Headers.h"


void IO_Init();
void Display_Seconds1(unsigned char seconds);
void Display_Seconds2(unsigned char seconds);
void Display_Minutes1(unsigned char minutes);
void Display_Minutes2(unsigned char minutes);
void Display_Hours1(unsigned char hours);
void Display_Hours2(unsigned char hours);


#endif /* DIO_H_ */
