/*
 * main.c
 *
 *  Created on: May 7, 2023
 *      Author: ahmed
 */

#include <util/delay.h>

#include "libraries/STD_TYPES_H.h"
#include "libraries/BIT_MATH.h"
#include "libraries/ErrType.h"
#include "0-MCAL/1-DIO/DIO_interface.h"
#include "0-MCAL/2-Port/PORT_interface.h"
#include "0-MCAL/4-GIE/GIE_interface.h"
#include "0-MCAL/3-EXTI/EXTI_interface.h"
#include "1-HAL/DC_motor/DCM_interface.h"
#include "1-HAL/LED/LED_interface.h"
#include "1-HAL/CLCD/CLCD_interface.h"
#include "3-app/system/LOGIN_interface.h"
// global
static uint8 Gloabl_INTFlag = 0;

LED_Config_t Gloabl_red_led ={LED_ACTIVE_HIGH,DIO_PORTC,DIO_PIN0};
LED_Config_t GLoabl_green_led= {LED_ACTIVE_HIGH,DIO_PORTC,DIO_PIN1};
DCM_Config_t Gloabl_motor= {DIO_PORTC,DIO_PIN2,DIO_PIN3};
void _void_testlogin();
void INT0ISR(void)
{
	Gloabl_INTFlag =1;
	DIO_u8_TogglePinVal(DIO_PORTC,DIO_PIN4);
}

////******left screen***////////
void main()
{
	/*Initialize*/
	Port_voidInit();
	GIE_voidEnableGlobal();
	EXTI_voidInit();
	CLCD_VoidInit();
	/*initialize ISR*/
	EXTI_u8SetCallBack(INT0, &INT0ISR);
	
	

	while (1)
	{
		if (Gloabl_INTFlag == 1){
			
			LOGIN_voidSystemStart();
			 _void_testlogin();

		}
	}
}

void _void_testlogin(){
	uint8 Local_u8LoginState = LOGIN_u8login(&Gloabl_INTFlag);
	if(Local_u8LoginState == LOGIN_SUCCESS){
		LED_u8SetON(&GLoabl_green_led);
		CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
		CLCD_voidGoToXY(0u, 0u);
		CLCD_VoidPrintChars("System unlocked");


		while (Gloabl_INTFlag == 0)//==
		{
			DCM_voidRotateCW(&Gloabl_motor);
			_delay_ms(1000);
			DCM_voidRotateCCW(&Gloabl_motor);
			_delay_ms(1000);
		}
		DCM_voidStop(&Gloabl_motor);
		LED_u8SetOFF(&GLoabl_green_led);
		CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
	}else if(Local_u8LoginState == LOGIN_ID_FAILD){
		LED_u8SetON(&Gloabl_red_led);
		CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
		CLCD_voidGoToXY(0u, 0u);
		CLCD_VoidPrintChars("ID not Found");
		_delay_ms(500);
		CLCD_voidGoToXY(0u, 1u);
		CLCD_VoidPrintChars("System locked");
		_delay_ms(2000);
		CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
		LED_u8SetOFF(&Gloabl_red_led);
	}else if(Local_u8LoginState == LOGIN_PASS_FAILD){
		LED_u8SetON(&Gloabl_red_led);
		CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
		CLCD_voidGoToXY(0u, 0u);
		CLCD_VoidPrintChars("wrong password");
		_delay_ms(500);
		CLCD_voidGoToXY(0u, 1u);
		CLCD_VoidPrintChars("System locked");
		_delay_ms(2000);
		CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
		LED_u8SetOFF(&Gloabl_red_led);
	}


}
