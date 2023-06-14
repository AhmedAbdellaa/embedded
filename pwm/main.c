/*
 * main.c
 *
 *  Created on: May 7, 2023
 *      Author: ahmed
 */

#include <util/delay.h>

#include "libraries/STD_TYPES_H.h"
#include "libraries/BIT_MATH.h"
#include "0-MCAL/4-GIE/GIE_interface.h"
#include "0-MCAL/6-TIMER/TIMER_interface.h"
#include "0-MCAL/1-DIO/DIO_interface.h"
#include "0-MCAL/2-Port/PORT_interface.h"
#include "0-MCAL/5-ADC/ADC_interface.h"
#include "0-MCAL/UART/UART_interface.h"
#include "1-HAL/CLCD/CLCD_interface.h"
#include "1-HAL/DC_motor/DCM_interface.h"
void main()
{

	Port_voidInit();
	GIE_voidEnableGlobal();
	TIMER_voidInit();
	UART_voidInit();
	ADC_voidInit();
	CLCD_VoidInit();

//	DCM_Config_t Local_DCM0 = {DIO_PORTB,DIO_PIN3,DIO_PIN4};

//	TIMER_CALLBACK_CONFIG_t Local_Timer0config = {242, 3};
//	TIMER_u8SetCallBack(TIMER0, &Local_Timer0config, &TIMER0ISR);
	TIMERPWM_u8SetCallBack(TIMER0,120);

	uint16 Local_u16ADC_DigtalSignal ;
	while (1)
	{
		ADC_u8StartConverstionSync(ADC0_SINGLE_ENDED,&Local_u16ADC_DigtalSignal);
		///*debuging*/
		UART_VoidPrintInt((sint32)Local_u16ADC_DigtalSignal);
		UART_voidTransmit(10);
		///////////
		TIMERPWM_u8SetCallBack(TIMER0,(uint8)Local_u16ADC_DigtalSignal);
		_delay_ms(150);
		CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
//		CLCD_VoidPrintChars("dig signal ");

		CLCD_VoidPrintInt((sint32)Local_u16ADC_DigtalSignal);
	}
}
