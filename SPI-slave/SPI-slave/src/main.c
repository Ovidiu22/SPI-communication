#ifndef F_CPU
#define F_CPU 16000000UL
#endif

/*----------------- Include -------------------*/
#include <avr/io.h>
#include <util/delay.h>
#include "SPI.h"
#include "LED.h"

/*-------------- Main function ----------------*/
int main (void)
{
	uint8_t spi_res = 0;
	init_LED();		// LED initialization
	init_SPI();		// SPI initialization

	while (1)
	{
		spi_res = spi_tranceiver(0xFF);	// Send back to master 0xFF as dummy
		if (spi_res > 0)	// if button is pressed
		{
			set_LED_high;	// Turn on LED
		}
		else
		{
			set_LED_low;	// Turn off LED
		}

	}
}
