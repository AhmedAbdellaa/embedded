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
#include "0-MCAL/5-ADC/ADC_interface.h"
#include "0-MCAL/3-EXTI/EXTI_interface.h"
#include "0-MCAL/4-GIE/GIE_interface.h"
#include "1-HAL/CLCD/CLCD_interface.h"
#include "1-HAL/voltameter/AVO_interface.h"

void _voidDisplayVoltage(uint16 copy_u16_VoltMesure);
void _voidDisplayOhm(uint16 copy_u16_ohmMesure);

void main()
{
	/*Initialize*/
	Port_voidInit();
	ADC_voidInit();
	CLCD_VoidInit();
//	GIE_voidEnableGlobal();
//	EXTI_voidInit();

//	EXTI_u8SetCallBack(INT0, &INT0ISR);
	uint16 Local_u16VoltageReading1 = 0u,Local_u16VoltageReading2=0u;
	uint16 Local_u16OhmReading1=0u,Local_u16OhmReading2=0u;
	uint16 Local_u16Reading;
	ADC_u16startConverstionSync(ADC0_SINGLE_ENDED,&Local_u16Reading);

	while (1)
	{
		//voltameter
//		if (Global_u8flag == 0){
			Local_u16VoltageReading2 = AVO_u16MesaureVoltage(ADC0_SINGLE_ENDED);
			if (Local_u16VoltageReading1 != Local_u16VoltageReading2){
				Local_u16VoltageReading1 = Local_u16VoltageReading2;
				_voidDisplayVoltage(Local_u16VoltageReading2);
				_delay_ms(350);
			}else
				continue;
//		}//ohmeter
//		else if (Global_u8flag == 1){
			Local_u16OhmReading2 = AVO_u16MesaureOhm(ADC0_SINGLE_ENDED,220);
//			if (Local_u16OhmReading1 != Local_u16OhmReading2){
//				Local_u16OhmReading1 = Local_u16OhmReading2;
//				_voidDisplayOhm(Local_u16OhmReading2);
//			_delay_ms(350);
//			}else
//				continue;
//		}else
//			continue;
//		/*do nothing*/

	}
}

void _voidDisplayOhm(uint16 copy_u16_ohmMesure){

    CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
    CLCD_VoidPrintChars("ohmmeter:");
    CLCD_voidGoToXY(0,1);
    CLCD_VoidPrintInt((sint32)copy_u16_ohmMesure);
    CLCD_VoidPrintChars(" Ohm");

}

void _voidDisplayVoltage(uint16 copy_u16_VoltMesure){
    CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
    CLCD_VoidPrintChars("Voltameter:");
    CLCD_voidGoToXY(0,1);
    CLCD_VoidPrintInt((sint32)copy_u16_VoltMesure);
    CLCD_VoidPrintChars(" mV");

}
