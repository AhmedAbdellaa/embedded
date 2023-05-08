/*
 * main.c
 *
 *  Created on: May 7, 2023
 *      Author: ahmed
 */
#include "util/delay.h"
#include "./0-MCAL/DIO_interface.h"
#include "3-APP/calc/CALC_interface.h"
#include "3-APP/calc/CALC_cfg.h"
#include "1-HAL/CLCD/CLCD_interface.h"
#include "1-HAL/SWITCH/SWITCH_interface.h"
#include "3-APP/hmaoksha/HAMO_interface.h"
static uint8 Gloable_program= 0; //0 :name 1: calculator
void _app_VoidShowName(uint8 copy_nameLen,SWITCH_Config_t*  ssww){
	sint8 i,j;
	for (j=0;j<copy_nameLen;j++){
		 for(i=0;i<16/copy_nameLen;i++){
			SWITCH_u8GetState(ssww);
			if(ssww->state == SWITCH_PRESSED){
				_delay_ms(250);
				if(Gloable_program == 0){
					Gloable_program = 1;
					initi();
				}
				else{
					Gloable_program = 0;
					CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
				}

				return;
			}
			CLCD_VoidSendCommand(0b00011000);//shift left
			CLCD_voidGoToXY(16u+i,j%2==0?1:0);
			CLCD_VoidSendData(' ');
			CLCD_voidGoToXY(16u+i,j%2==0?0:1);
			CLCD_VoidSendData(i+1);
			_delay_ms(500);
		 }}
	for(i=0;i<copy_nameLen;i++){
		CLCD_VoidSendCommand(0b00011000);//shift left
		_delay_ms(500);
	}
	CLCD_VoidSendCommand(0b00000010);//return home original position
}

void main(){


	uint8 Achar[4][8] = {{0x00, 0x06, 0x01, 0x01, 0x1F, 0x1F, 0x00, 0x00},
	                    {0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x0A, 0x0E},
	                    {0x00, 0x04, 0x0A, 0x02, 0x1F, 0x1F, 0x00, 0x00},
	                    { 0x02,0x06,0x06,0x06,0x06,0x06,0x06,0x04}};

	SWITCH_Config_t Local_SWProgramChoise = {SWITCH_PULL_UP,DIO_PORTD,DIO_PIN5,SWITCH_RELEASED};
//initialize LCD display
	CLCD_VoidInit();

	sint8 i;




	DIO_u8_PinPullUp(CALC_BUTTONS_PORT,CALC_BUTTON_INC);
	DIO_u8_PinPullUp(CALC_BUTTONS_PORT,CALC_BUTTON_DEC);
	DIO_u8_PinPullUp(CALC_BUTTONS_PORT,CALC_BUTTON_OK);
	DIO_u8_PinPullUp(DIO_PORTD,DIO_PIN5);




	while(1){
		SWITCH_u8GetState(&Local_SWProgramChoise);
		if(Local_SWProgramChoise.state == SWITCH_PRESSED){
			_delay_ms(250);
			if(Gloable_program == 0){
				Gloable_program = 1;
				initi();
			}
			else if (Gloable_program == 1){
				Gloable_program = 2;
				CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
			}else if (Gloable_program == 2){
				Gloable_program = 0;
				CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
			}


		}
		if(Gloable_program == 0){
			//add 4 custom characters to LCD MC
			for(i=0;i<4;i++){
				CLCD_u8WriteSpecialChar(i+1,Achar[i]);
			}
			_app_VoidShowName(4,&Local_SWProgramChoise);
		}
		else if(Gloable_program == 1){

			CALC_VoidBTNClick();
			_delay_ms(100);
		}else if(Gloable_program == 2){
			CLCD_VoidPrintChars("Hello I'm hamoksha...");
			_delay_ms(2000);
			CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
			Hamo_voidWalkScene();
			_delay_ms(100);
			Hamo_voidDanceScene();
			_delay_ms(100);
			Hamo_voidballScene();
			_delay_ms(100);
			Hamo_voidKillScene();
			_delay_ms(100);
		}
	}
}
