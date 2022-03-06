
#ifndef LED_H_
#define LED_H_


#define LED_pin	PIND5

/* Macros */
#define set_LED_low		PORTD &= ~(1<<LED_pin)
#define set_LED_high	PORTD |= (1<<LED_pin)

/* Prototype functions */
void init_LED(void);

#endif /* LED_H_ */