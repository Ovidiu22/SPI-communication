
#ifndef SPI_H_
#define SPI_H_

	/* Communication Pins */
	#define PORT_SPI PORTB

	#define SSPin		PINB2
	#define SCKPin		PINB5
	#define MISOPin		PINB3
	#define MOSIPin		PINB4

	/* Functions prototypes */
	void init_SPI(void);
	uint8_t spi_tranceiver (uint8_t);
	
#endif /* SPI_H_ */