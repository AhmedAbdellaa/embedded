/*
 * main.c
 *
 *  Created on: Jun 4, 2023
 *      Author: ahmed
 */


#include <util/delay.h>

#include "STD_TYPES_H.h"
#include "BIT_MATH.h"
#include "ErrType.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "GIE_interface.h"
#include "ADC_interface.h"
#include "CLCD_interface.h"


static uint16 Global_u16Reading0;
static uint16 Global_u16Reading1;


void ADC0CallBack(void);
void ADC7CallBack(void);
void main()
{
	/*Initialize*/
	Port_voidInit();
	ADC_voidInit();
	CLCD_VoidInit();
	GIE_voidEnableGlobal();

	ADC_CHAIN_config_t Local_devises[] = {{ADC0_SINGLE_ENDED,&Global_u16Reading0,&ADC0CallBack},{ADC7_SINGLE_ENDED,&Global_u16Reading0,&ADC7CallBack}};
//	uint8 Local_u8LedVal;
//	sint32 Local_s32Leftpart;
	while (1)
	{
		ADC_u8StartChainConverstionAsync(Local_devises,1u);
//		ADC_u16startConverstionAsync(ADC0_SINGLE_ENDED,&Global_u16Reading,&ADC0CallBack);
		_delay_ms(200);
//		ADC_u16startConverstionSync(ADC0_SINGLE_ENDED,&Global_u16Reading);
//		Local_u8LedVal = MAP(0L,1023L,0L,255L,(sint32)Global_u16Reading);
//		CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
//		CLCD_VoidPrintInt(Local_u8LedVal);
//		CLCD_VoidPrintChars("  ");
//		CLCD_VoidPrintInt((sint32)Global_u16Reading);
//		Local_s32Leftpart = (sint32)(((uint32)Global_u16Reading*5000ul)/1023ul);
//		CLCD_voidGoToXY(0,1);
//		CLCD_VoidPrintInt(Local_s32Leftpart);
//		_delay_ms(200);
//		DIO_u8_SetPortVal(DIO_PORTC,Local_u8LedVal);

	}
}
void ADC0CallBack(void){
	uint8 Global_u8LedVal;
	Global_u8LedVal = MAP(0L,1023L,0L,255L,(sint32)Global_u16Reading0);
	CLCD_voidGoToXY(0,0);
	CLCD_VoidPrintInt(Global_u8LedVal);
	CLCD_VoidPrintChars("  ");
	CLCD_VoidPrintInt((sint32)Global_u16Reading0);
}

void ADC7CallBack(void){
	uint8 Global_u8LedVal;
	Global_u8LedVal = MAP(0L,1023L,0L,255L,(sint32)Global_u16Reading1);
	CLCD_voidGoToXY(0,1);
	CLCD_VoidPrintInt(Global_u8LedVal);
	CLCD_VoidPrintChars("  ");
	CLCD_VoidPrintInt((sint32)Global_u16Reading1);
}


