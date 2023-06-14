/*
 * main.c
 *
 *  Created on: Jun 4, 2023
 *      Author: ahmed
 */


#include <util/delay.h>

#include "libraries/STD_TYPES_H.h"
#include "0-MCAL/1-DIO/DIO_interface.h"
#include "0-MCAL/2-Port/PORT_interface.h"
#include "0-MCAL/5-ADC/ADC_interface.h"
#include "1-HAL/CLCD/CLCD_interface.h"
#include "1-HAL/LM35/LM_interface.h"
//#include "../../0-MCAL/UART/UART_interface.h"
void main()
{
	/*Initialize*/
	Port_voidInit();
	ADC_voidInit();
	CLCD_VoidInit();
	UART_voidInit();
	LM_Config_t Local_LM0 = {ADC7_SINGLE_ENDED,5000ul,0u};

	uint16 Local_u16Reading0 = 0u,Local_u16Reading1=0u;
	while (1)
	{
		LM_u8GetTemp(&Local_LM0);
		_delay_ms(500);
		Local_u16Reading1 = Local_LM0.Temprature;
		if (Local_u16Reading1  != Local_u16Reading0){
			Local_u16Reading0 = Local_u16Reading1;
			CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
			CLCD_VoidPrintChars("temprature :");
			CLCD_voidGoToXY(0,1);
			CLCD_VoidPrintInt((sint32)(Local_LM0.Temprature));
			CLCD_VoidPrintChars(" C");
			DIO_u8_SetPortVal(DIO_PORTC,Local_LM0.Temprature);
			_delay_ms(500);
		}
		else
			continue;

	}
}
