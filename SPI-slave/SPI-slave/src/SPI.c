/*
 * SPI.c
 *
 * Created: 22.02.2022 19:17:57
 *  Author: lenovo
 */

#ifndef F_CPU
#define F_CPU 16000000ul
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "SPI.h"

/* *****************************************************************
Name:		Init_SPI()
Inputs:		none
Outputs:	none
Description:Initialization of SPI pins
******************************************************************** */
void init_SPI()
{
	DDRB |= (1<<MISOPin) ;	//
	
	DDRB &= ~(1<<MOSIPin);
	DDRB &= ~(1<<SCKPin);
	DDRB &= ~(1<<SSPin);
	
	SPCR |= (1 << SPE);				// Enable SPI as 

}

/* *****************************************************************
Name:		spi_tranceiver()
Inputs:		input for the SPI buffer
Outputs:	SPI buffer
Description:Reads the SPI transceiver buffer
******************************************************************** */
uint8_t spi_tranceiver (uint8_t data)
{
	/* Load data in the buffer */
	SPDR = data;
	/* Wait for the complete transmission */
	while(!(SPSR & (1<<SPIF)));
	/* Return received data */
	return(SPDR);
}

/* *****************************************************************
Name:		receive_spi()
Inputs:		name of register to be read
Outputs:	data of the register
Description:Reads the called register
******************************************************************** */
uint8_t receive_spi(void)
{
	uint8_t res = 0;
	//_delay_us(10);						//Delay for 10us
	res = spi_tranceiver(0xFF);
	//_delay_us(12);						//Delay 12us
	return res;
}

