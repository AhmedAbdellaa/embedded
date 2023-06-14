/*
 * main.c
 *
 *  Created on: May 7, 2023
 *      Author: ahmed
 */
#include "util/delay.h"
#include "./0-MCAL/DIO_interface.h"
#include "0-MCAL/2-Port/PORT_interface.h"

#include "1-HAL/CLCD/CLCD_interface.h"
#include "1-HAL/KEYPAD/KPD_interface.h"

void main(){

	uint8 Local_u8KeyState ;
	Port_voidInit();
	CLCD_VoidInit();
	CLCD_VoidSendData('a');



	while(1){
		Local_u8KeyState =KPD_u8GetPressedKey();
		if(Local_u8KeyState != 0xff){
			CLCD_VoidPrintInt(Local_u8KeyState);
		}
	}
}
