/*
 * main.c
 *
 *  Created on: Jun 4, 2023
 *      Author: ahmed
 */


#include <util/delay.h>

#include "libraries/STD_TYPES_H.h"
#include "libraries/BIT_MATH.h"
#include "libraries/ErrType.h"
#include "0-MCAL/1-DIO/DIO_interface.h"
#include "0-MCAL/2-Port/PORT_interface.h"
#include "1-HAL/DAC/DAC_interface.h"

void main()
{
	/*Initialize*/
	Port_voidInit();
	sint16 Local_u16_iter0=0;
	while (1)
	{
		while(Local_u16_iter0<=5000){
			DIO_u8_SetPortVal(DIO_PORTB,DAC_u8AnalogVolt(Local_u16_iter0));
			_delay_ms(250);
			Local_u16_iter0+=200;
		}
		_delay_ms(1000);
		Local_u16_iter0 = 5000;
		while(Local_u16_iter0>=0){
			DIO_u8_SetPortVal(DIO_PORTB,DAC_u8AnalogVolt(Local_u16_iter0));
			_delay_ms(250);
			Local_u16_iter0 -= 200;
		}
	}
}
