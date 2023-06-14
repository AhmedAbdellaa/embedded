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
#include "1-HAL/LDR/LDR_interface.h"
#include "1-HAL/LED/LED_interface.h"

void main()
{
	/*Initialize*/
	Port_voidInit();
	ADC_voidInit();
	CLCD_VoidInit();

	LDR_Config_t Local_LDR0 = {ADC0_SINGLE_ENDED,5000ul,0};
	LED_Config_t Local_LedRed = {LED_ACTIVE_HIGH,DIO_PORTC,DIO_PIN0};
	uint16 Local_u16Reading0=0,Local_u16Reading1=0;
	while (1)
	{
		LDR_u8GetLighlevel(&Local_LDR0);
		Local_u16Reading1 = Local_LDR0.LightLevel;
		if (Local_u16Reading1  != Local_u16Reading0){
			Local_u16Reading0 = Local_u16Reading1;
			CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
//			CLCD_VoidPrintChars("LightLevel :");
			CLCD_VoidPrintInt((sint32)AVO_u16MesaureVoltage(ADC0_SINGLE_ENDED));
			CLCD_voidGoToXY(0,1);
			CLCD_VoidPrintInt((sint32)(Local_LDR0.LightLevel));
			//evening
			if (Local_LDR0.LightLevel < 5){
				LED_u8SetON(&Local_LedRed);
				CLCD_VoidPrintChars("  evening");
			}//morning
			else{
				LED_u8SetOFF(&Local_LedRed);
				CLCD_VoidPrintChars("  morning");
			}
			_delay_ms(500);
		}
		else
			continue;

	}
}
