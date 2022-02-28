/*
 * SPI.h
 *
 * Created: 22.02.2022 19:21:29
 *  Author: lenovo
 */ 


#ifndef SPI_H_
#define SPI_H_

	/* Communication Pins */

	#define PORT_SPI PORTB

	//#define PORT_MOSI PINB

	#define SSPin		PINB2
	#define SCKPin		PINB5
	#define MISOPin		PINB3
	#define MOSIPin		PINB4

	/* Macros */


	/* Functions prototypes */
	void init_SPI(void);
	uint8_t spi_tranceiver (uint8_t);
	uint8_t receive_spi(void);
	
#endif /* SPI_H_ */