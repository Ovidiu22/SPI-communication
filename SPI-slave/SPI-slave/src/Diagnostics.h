/*
 * Diagnostics.h
 *
 * Created: 24.03.2020 17:44:04
 *  Author: lenovo
 */ 


#ifndef DIAGNOSTICS_H_
#define DIAGNOSTICS_H_

#define red		1
#define blue	2
#define green	3
//enum colours { red, blue, green };

#define RED_pin		PIND4
#define BLUE_pin	PIND5
#define GREEN_pin	PIND6

/* Macros */
#define set_RGB_low		PORTD &= ~((1<<RED_pin) | (1<<BLUE_pin) | (1<<GREEN_pin))
#define set_RED_high	PORTD |= (1<<RED_pin)
#define set_BLUE_high	PORTD |= (1<<BLUE_pin)
#define set_GREEN_high	PORTD |= (1<<GREEN_pin)

/* Prototype functions */
uint8_t getBatterySOC( uint8_t * );
void init_RGB(void);
void set_RGB(uint8_t);

#endif /* DIAGNOSTICS_H_ */