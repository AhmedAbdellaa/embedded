/*
 * main.c
 *
 *  Created on: May 3, 2023
 *      Author: ahmed
 */

#include "0-MCAL/DIO_interface.h"
#include "1-HAL/CLCD/CLCD_interface.h"
#include <util/delay.h>
void main(void){
	uint8 Local_u8MyPattern[]={0x1F,0x11,0x11,0x11,0x11,0x11,0x11,0x1F};
	uint8 STAND[]= {0x0E,0x0E,0X04,0X0E,0X15,0X04,0X0A,0X0A};
	uint8 MOVEZERO[]={0X0E,0X0E,0X05,0X0E,0X0C,0X04,0X06,0X05};
	uint8 MOVEONE[]={0X0E,0X0E,0X04,0X0E,0X16,0X04,0X0C,0X14};

	uint8 run0[] = {  0x0E,			  0x0E,			  0x04,
			  0x0E,
			  0x0D,
			  0x04,
			  0x0E,
			  0x0A};
	uint8 run1[] = {  0x0E,
			  0x0E,
			  0x04,
			  0x0E,
			  0x0E,
			  0x04,
			  0x06,
			  0x05};
	uint8 passup[] = {
			  0x0E,
			  0x0E,
			  0x04,
			  0x0E,
			  0x0C,
			  0x04,
			  0x07,
			  0x04
			};
	uint8 balldown[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18};
	uint8 ballup[] = {0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00};

	DIO_u8_SetPortDir(DIO_PORTA,0xff);
	//DIO_u8_SetPinDir(DIO_PORTB,DIO_PIN0,DIO_PIN_OUTPUT);
	//DIO_u8_SetPinDir(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
	//DIO_u8_SetPinDir(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
	CLCD_VoidInit();
//	CLCD_VoidSendData('A');


//	CLCD_u8WriteSpecialChar(0X00,STAND);
//	CLCD_u8WriteSpecialChar(0X01,MOVEZERO);
//	CLCD_u8WriteSpecialChar(0X02,MOVEONE);

	CLCD_u8WriteSpecialChar(0X00,run0);
	CLCD_u8WriteSpecialChar(0X01,run1);
	CLCD_u8WriteSpecialChar(0X02,passup);
	CLCD_u8WriteSpecialChar(0X03,balldown);
	CLCD_u8WriteSpecialChar(0X04,ballup);

	CLCD_voidGoToXY(0U,0U);
	CLCD_VoidSendData(0u);
	CLCD_VoidSendData(3u);

//	CLCD_VoidSendData('A');
	uint8 Local_u8counter=0;
	while(Local_u8counter<16){
		CLCD_voidGoToXY(0U,0U);
		CLCD_VoidSendData(0u);
		_delay_ms(250);
		CLCD_voidGoToXY(0U,0U);
		CLCD_VoidSendData(1u);
		_delay_ms(250);
		CLCD_VoidSendCommand(0b00011100);//shift right
		CLCD_voidGoToXY(0U,0U);
		CLCD_VoidSendData(2u);
		_delay_ms(250);
		CLCD_voidGoToXY(1U,0U);
		CLCD_VoidSendData(4u);
		_delay_ms(250);
		CLCD_voidGoToXY(1U,0U);
		CLCD_VoidSendData(3u);
		_delay_ms(250);
//		CLCD_voidGoToXY(Local_u8counter,0U);
//		CLCD_VoidSendData(0);
//		_delay_ms(500);
//		CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
//		Local_u8counter++;
/*
		CLCD_voidGoToXY(Local_u8counter,0U);
		CLCD_VoidSendData(1);
		_delay_ms(500);
		Local_u8counter++;

		CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
		CLCD_voidGoToXY(Local_u8counter,0U);
		CLCD_VoidSendData(2);
		_delay_ms(500);
		CLCD_VoidSendCommand(CLCD_CLEAR_CMD);

		if(Local_u8counter >=15)
			Local_u8counter=0;
		else
			Local_u8counter++;
		*/
//		CLCD_VoidPrintChars("hello world!");
//		_delay_ms(1000);
//		CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
//
//		CLCD_VoidPrintInt(123456);
//		_delay_ms(1000);
//		CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
//
//		CLCD_VoidPrintInt(-2034);
//		_delay_ms(1000);
//		CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
//
//		CLCD_VoidPrintInt(10);
//		_delay_ms(1000);
//		CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
//
//		CLCD_VoidPrintInt(0);
//		_delay_ms(1000);
//		CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
	}
}
