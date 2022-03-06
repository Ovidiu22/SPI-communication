
#ifndef SPI_H_
#define SPI_H_

	/* SPI Pins */
	#define PORT_SPI PORTB

	#define SSPin		PINB2
	#define SCKPin		PINB5
	#define MISOPin		PINB4
	#define MOSIPin		PINB3

	/* Macros */
	#define set_SS_high		PORT_SPI |= (1<<SSPin)
	#define set_SS_low		PORT_SPI &= ~(1<<SSPin)

	/* Functions prototypes */
	void init_SPI(void);
	uint8_t spi_tranceiver (uint8_t);
	void send_spi(uint8_t);
	
#endif /* SPI_H_ */