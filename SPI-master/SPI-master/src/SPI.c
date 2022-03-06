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
	DDRB = 0x00;
	DDRB |= (1<<SSPin) | (1<<SCKPin) | (1<<MOSIPin) ;  //set MOSI, clock and SlaveSelect as output
	//DDRB &= ~(1<<MISOPin);											//Set MOSI[MISO of nRF] as Input
	
	SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0) ;				// Enable SPI as master
	
	set_SS_high;							//SlaveSelect To HIGH- not sending any command
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
Name:		send_spi()
Inputs:		data to be sent
Outputs:	data of the register
Description:Reads the called register
******************************************************************** */
void send_spi(uint8_t data)
{
	set_SS_low;							
	spi_tranceiver(data);
	set_SS_high;		
}

