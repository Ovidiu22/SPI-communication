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
	DDRB |= (1<<SSPin) | (1<<SCKPin) | (1<<MOSIPin) ;  //set MOSI, clock and SlaveSelect as output
	DDRB &= ~(1<<MISOPin);											//Set MOSI[MISO of nRF] as Input
	
	SPCR |= (1 << SPE) | (1 << MSTR);				// Enable SPI as master
	
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
Name:		GetReg()
Inputs:		name of register to be read
Outputs:	data of the register
Description:Reads the called register
******************************************************************** */
void send_spi(uint8_t data)
{
	_delay_us(10);						//Delay for 10us
	set_SS_low;							//Set SS Low - nRf starts listening for commands 10us after SS Low
	_delay_us(12);						//Delay for 12us
	spi_tranceiver(data);
	_delay_us(12);						//Delay 12us
	set_SS_high;						//SS High
}

/* *****************************************************************
Name:		receive_spi()
Inputs:		name of register to be read
Outputs:	data of the register
Description:Reads the called register
******************************************************************** */
/*uint8_t receive_spi(uint8_t data)
{
	uint8_t res = 0;
	_delay_us(10);						//Delay for 10us
	res = spi_tranceiver(data);
	_delay_us(12);						//Delay 12us
	return res;
}*/

