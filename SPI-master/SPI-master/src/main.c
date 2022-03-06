/*******************************/
/*** Created by Ovidiu Sabau ***/
/***	   06 March 2022	 ***/
/*******************************/

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

/*----------------- Include -------------------*/
#include <avr/io.h>
#include "SPI.h"
#include "Btn.h"

/*-------------- Main function ----------------*/
int main(void)
{
	init_Btn();				// Initialize button
	init_SPI();				// Initialize SPI 
	uint8_t btn_state = 0;	// Variable for button state (pressed / released)
	while (1)
	{
		btn_state = Btn_pin & (1<<Btn_bit);		// check button state
		send_spi(btn_state);		// Send status button over SPI
	}
}

