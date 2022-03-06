#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

#include "SPI.h"
#include "Btn.h"


int main(void)
{
	init_Btn();
	init_SPI();
	uint8_t btn_state = 0;
	while (1)
	{
		btn_state = Btn_pin & (1<<Btn_bit);
		send_spi(btn_state);
	}
}

