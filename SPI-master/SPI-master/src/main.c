#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

#include "SPI.h"
#include "Btn.h"
#include "Diagnostics.h"


int main(void)
{
	init_Btn();
	//init_RGB();
	uint8_t spi_reg = 0;
	while (1)
	{
		//spi_reg = Btn_pin & (1<<Btn_bit);
		spi_reg = 1;
		send_spi(spi_reg);
	}
}

