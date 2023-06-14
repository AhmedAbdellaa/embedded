/*
 * main.c
 *
 *  Created on: May 3, 2023
 *      Author: ahmed
 */


#include <util/delay.h>
//#include "libraries/STD_TYPES_H.h"
//#include "ErrType.h"
#include "DIO_interface.h"

void main(void){

	DIO_u8_SetPortDir(DIO_PORTC,0xFF);

	/*activate pull up resistor on portD*/
	DIO_u8_SetPortDir(DIO_PORTD,0x00);// set port as input
	DIO_u8_SetPortVal(DIO_PORTD,0xFF);

	DIO_pinVal_t Local_u8PinReading ;

	while(1){

		DIO_u8_GetPinVal(DIO_PORTD,DIO_PIN0,&Local_u8PinReading);
		if (Local_u8PinReading == DIO_PIN_LOW){
			DIO_u8_SetPortVal(DIO_PORTC,0xFF);
		}else
			DIO_u8_SetPortVal(DIO_PORTC,0x00);
//		DIO_u8_SetPortVal(DIO_PORTC,0xFF);
//		_delay_ms(300);
//		DIO_u8_SetPortVal(DIO_PORTC,0x00);
//		_delay_ms(300);

	}


}
