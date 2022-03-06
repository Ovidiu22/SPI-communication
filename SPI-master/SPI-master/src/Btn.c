
#include <avr/io.h>
#include "Btn.h"


/* *****************************************************************
Name:		init_Btn()
Inputs:		none
Outputs:	none
Description:initializes PIN D2 as interrupt triggered by low level
******************************************************************** */
void init_Btn(void)
{
	/* Input port with pull-up */
	DDRD |= (1<<Btn_bit);
	PORTD &= ~(1<<Btn_bit);
}
