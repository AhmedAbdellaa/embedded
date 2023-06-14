/*
 * main.c
 *
 *  Created on: May 7, 2023
 *      Author: ahmed
 */

#include <util/delay.h>
#include "./0-MCAL/1-DIO/DIO_interface.h"
#include "0-MCAL/2-Port/PORT_interface.h"

#include "1-HAL/CLCD/CLCD_interface.h"
#include "1-HAL/KEYPAD/KPD_interface.h"

#include "3-APP/stopWatch/STW_interface.h"

#include "1-HAL/DC_motor/DCM_interface.h"
#include "1-HAL/step_motor/STM_interface.h"
#include "3-APP/hmaoksha/HAMO_interface.h"

void void_MainChooseMenue(){
	//choose menu
	CLCD_VoidSendCommand(CLCD_CLEAR_CMD);

	CLCD_voidGoToXY(0u,0u);
	CLCD_VoidPrintChars("DC Motor -> 1");

	CLCD_voidGoToXY(0u,1u);
	CLCD_VoidPrintChars("Stepper Motor->2");
}
void void_RotaionChooseMenue(){
	//choose menu
	CLCD_VoidSendCommand(CLCD_CLEAR_CMD);

	CLCD_voidGoToXY(0u,0u);
	CLCD_VoidPrintChars("RCW -> 1");

	CLCD_voidGoToXY(0u,1u);
	CLCD_VoidPrintChars("RCCW -> 2");
}

uint16 _u16_get_number(){
	uint8 Local_u8Row,Local_u8Col ,Local_u8_keypadStatus=0xff;
	uint16 Local_number = 0;
	while(Local_u8_keypadStatus != 'o'){
		Local_u8_keypadStatus = KPD_u8GetPressedKey(&Local_u8Row,&Local_u8Col);
		if(Local_u8_keypadStatus >=0 && Local_u8_keypadStatus <=9){
			CLCD_VoidSendData(Local_u8_keypadStatus+'0');
			Local_number = (Local_number*10) + Local_u8_keypadStatus;
		}
	}
	return Local_number;
}


void main(){

 	uint8 Local_u8_keypadStatus ;
 	Port_voidInit();
 	CLCD_VoidInit();

 	uint8 Local_u8Row,Local_u8Col;

 	DCM_Config_t Local_DCM_motor0 = {DIO_PORTC,DIO_PIN0,DIO_PIN1};
	STM_CONFIG_t Local_STM_motor0 = {DIO_PORTC,DIO_PIN2,DIO_PIN3,DIO_PIN4,DIO_PIN5};

	Hamo_voidWalkRightScene();
	void_MainChooseMenue();
	while(1){

			Local_u8_keypadStatus = KPD_u8GetPressedKey(&Local_u8Row,&Local_u8Col);
			if (Local_u8_keypadStatus != 0xff){
				if (Local_u8_keypadStatus == 1){
					//DC motor
					void_RotaionChooseMenue();
					while(1){
						Local_u8_keypadStatus = KPD_u8GetPressedKey(&Local_u8Row,&Local_u8Col);
						if (Local_u8_keypadStatus == 1){
							//RCW
							DCM_voidRotateCW(&Local_DCM_motor0);
							CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
							CLCD_VoidPrintChars("for stop press s");
							while(Local_u8_keypadStatus != 's'){
								Local_u8_keypadStatus = KPD_u8GetPressedKey(&Local_u8Row,&Local_u8Col);
							}
							DCM_voidStop(&Local_DCM_motor0);
							Hamo_voidWalkLeftScene();

							void_MainChooseMenue();
							break;
						}else if(Local_u8_keypadStatus == 2){
							//RCCW
							DCM_voidRotateCCW(&Local_DCM_motor0);
							CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
							CLCD_VoidPrintChars("for stop press s");
							while(Local_u8_keypadStatus != 's'){
								Local_u8_keypadStatus = KPD_u8GetPressedKey(&Local_u8Row,&Local_u8Col);
							}
							DCM_voidStop(&Local_DCM_motor0);
							Hamo_voidWalkLeftScene();

							void_MainChooseMenue();
							break;
						}
					}
				}else if(Local_u8_keypadStatus == 2){
					//Stepper motor

					//read the angle
					CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
					CLCD_VoidPrintChars("Angle: ");

					uint16 Local_u16Angle = _u16_get_number();
					//choose direction
					void_RotaionChooseMenue();

					while(1){
							Local_u8_keypadStatus = KPD_u8GetPressedKey(&Local_u8Row,&Local_u8Col);
							if (Local_u8_keypadStatus == 1){
								//RCW

								CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
								CLCD_VoidPrintChars("Rotating");
								STM_u8Rotate(&Local_STM_motor0,Local_u16Angle,STM_CLOCK_WISE);
								Hamo_voidWalkLeftScene();

								void_MainChooseMenue();
								break;
							}else if(Local_u8_keypadStatus == 2){
								//RCCW
								CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
								CLCD_VoidPrintChars("Rotating");
								STM_u8Rotate(&Local_STM_motor0,Local_u16Angle,STM_COUNTER_CLOCK_WISE);
								Hamo_voidWalkLeftScene();

								void_MainChooseMenue();
								break;
							}
						}
				}
			}else
				continue;


		}

 }
