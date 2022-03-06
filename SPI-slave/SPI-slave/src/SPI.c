
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
	DDRB = (1<<MISOPin) ;
	SPCR |= (1 << SPE);		// Enable SPI as slave
}

/* *****************************************************************
Name:		spi_tranceiver()
Inputs:		input for the SPI buffer
Outputs:	SPI buffer
Description:Loads data into SPI transceiver buffer and returns received data
******************************************************************** */
uint8_t spi_tranceiver (uint8_t data)
{
	/* Load data in the buffer */
	SPDR = data;
	/* Wait for the complete transmission */
	while(!(SPSR & (1<<SPIF)));
	/* Return received data */
	return SPDR;
}