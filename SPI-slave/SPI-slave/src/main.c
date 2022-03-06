#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

#include "SPI.h"
#include "Diagnostics.h"

int main (void)
{
	uint8_t spi_res = 0;
	init_LED();
	init_SPI();

	while (1)
	{
		spi_res = spi_tranceiver(0xFF);
		if (spi_res > 0)
		{
			set_LED_high;
		}
		else
		{
			set_LED_low;
		}

	}
}
