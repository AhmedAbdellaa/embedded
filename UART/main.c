/*
 * main.c
 *
 *  Created on: May 7, 2023
 *      Author: ahmed
 */

#include <util/delay.h>
#include "libraries/STD_TYPES_H.h"

#include "0-MCAL/2-Port/PORT_interface.h"
#include "0-MCAL/UART/UART_interface.h"
#include "1-HAL/CLCD/CLCD_interface.h"



void main(){
	uint8 Local_u8ReceivedData;
	Port_voidInit();
	UART_voidInit();

	CLCD_VoidInit();
//
	CLCD_VoidPrintInt(125);

	while(1){
		Local_u8ReceivedData = UART_voidReceive();
		if(Local_u8ReceivedData == '0'){
			UART_voidTransmit(' ');
			UART_VoidPrintChars("hello mother fuckers");
		}else if(Local_u8ReceivedData == '1'){
			UART_VoidPrintInt(11u);
			UART_voidTransmit(' ');
			UART_VoidPrintFloat(1.235);
		}
		_delay_ms(100);
	}
}
