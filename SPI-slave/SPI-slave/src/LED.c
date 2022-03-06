
#ifndef F_CPU
#define F_CPU 16000000ul
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "LED.h"

/* *****************************************************************
Name:		init_LED()
Inputs:		none
Outputs:	none
Description:initializes the LED
******************************************************************** */
void init_LED(void)
{
	DDRD |= (1<<LED_pin);
}

