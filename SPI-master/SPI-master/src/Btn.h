/*
 * Btn.h
 *
 * Created: 22.02.2022 19:37:28
 *  Author: lenovo
 */ 


#ifndef BTN_H_
#define BTN_H_

	#define Btn_bit			PORTD3
	#define Btn_pin			PIND                    // read only PIN

	void init_Btn(void);

#endif /* BTN_H_ */