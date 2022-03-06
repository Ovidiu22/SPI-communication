/*
 * Diagnostics.c
 *
 * Created: 28.03.2020 18:17:38
 *  Author: lenovo
 */ 

#ifndef F_CPU
#define F_CPU 16000000ul
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "Diagnostics.h"

/* *****************************************************************
Name:		init_RGB()
Inputs:		none
Outputs:	none
Description:initializes the RGB Led
******************************************************************** */
void init_LED(void)
{
	DDRD |= (1<<LED_pin);  //
}

