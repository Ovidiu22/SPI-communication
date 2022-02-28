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
	init_RGB();

	while (1)
	{
		spi_res = receive_spi();
		//spi_res = 1;
		if (spi_res >= 1)
		{
			set_BLUE_high;
		}
		{
			set_RGB_low;
		}
	}
}
