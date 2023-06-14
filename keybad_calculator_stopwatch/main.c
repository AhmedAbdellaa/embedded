/*
 * main.c
 *
 *  Created on: May 7, 2023
 *      Author: ahmed
 */

#include "util/delay.h"
#include "./0-MCAL/1-DIO/DIO_interface.h"
#include "0-MCAL/2-Port/PORT_interface.h"

#include "1-HAL/CLCD/CLCD_interface.h"
#include "1-HAL/KEYPAD/KPD_interface.h"
#include "1-HAL/LED/LED_interface.h"

#include "3-APP/keypad_calc/KCALC_interface.h"
#include "3-APP/stopWatch/STW_interface.h"

/*
void main()
{
	static uint8 Local_Arrow[] = {0B00100, 0B01110, 0B11111, 0B01110, 0B01110, 0B01110, 0B01110, 0B01110};
	static uint8 Local_STAND[]= {0x0E,0x0E,0X04,0X0E,0X15,0X04,0X0A,0X0A};

	uint8 Local_u8KeyState,Local_u8Row, Local_u8Col;
	sint16  Local_u16Iter0,Local_u16Iter1;
	STW_config_t Local_stw;
	LED_Config_t Local_LED ={LED_ACTIVE_HIGH,DIO_PORTC,DIO_PIN0};
	//init port direction and values
	Port_voidInit();
	CLCD_VoidInit();//init LCD

	

	CLCD_u8WriteSpecialChar(0, Local_Arrow);//add speacial character to cgram
	CLCD_u8WriteSpecialChar(1, Local_STAND);//add speacial character to cgram

	STW_VoidInit(&Local_stw);//init stopwatch program
	// loop
	while (1)
	{
		// read keypad
		Local_u8KeyState = KPD_u8GetPressedKey(&Local_u8Row, &Local_u8Col);
		if (Local_u8KeyState != 0xff)
		{
			// right
			if (Local_u8KeyState == '/')
			{
				// clear old
				CLCD_voidGoToXY(Local_stw.pos, 1);
				CLCD_VoidSendData(' ');
				//change pos
				if (Local_stw.pos == 1)
					Local_stw.pos = 3;

				else if (Local_stw.pos == 4)
					Local_stw.pos = 0;
				else
					Local_stw.pos += 1;
				// place new pos
				CLCD_voidGoToXY(Local_stw.pos, 1);
				CLCD_VoidSendData(0);
			}
			// left
			else if (Local_u8KeyState == '*')
			{
				// clear old
				CLCD_voidGoToXY(Local_stw.pos, 1);
				CLCD_VoidSendData(' ');
				//change pos
				if (Local_stw.pos == 0)
					Local_stw.pos = 4;
				else if (Local_stw.pos == 3)
					Local_stw.pos = 1;
				else
					Local_stw.pos -= 1;
				// place new pos
				CLCD_voidGoToXY(Local_stw.pos, 1);
				CLCD_VoidSendData(0);
			}
			
			//set number
			else if(Local_u8KeyState >= 0 && Local_u8KeyState <= 9){

				STW_voidUpdate(&Local_stw,Local_u8KeyState);

				if(Local_stw.pos <2){
					CLCD_voidGoToXY(0, 0);
					if(Local_stw.minutes<10)
						CLCD_VoidSendData('0');
					CLCD_VoidPrintInt(Local_stw.minutes);
				}else{
					CLCD_voidGoToXY(3, 0);
					if(Local_stw.seconds<10)
						CLCD_VoidSendData('0');
					CLCD_VoidPrintInt(Local_stw.seconds);
				}
			}			
			// start
			else if (Local_u8KeyState == '-'){
				CLCD_voidGoToXY(Local_stw.pos, 1);
				CLCD_VoidSendData(' ');

				Local_u16Iter0 = Local_stw.minutes;
				Local_u16Iter1 = Local_stw.seconds;
				do{
					Local_stw.minutes = Local_u16Iter0;
					CLCD_voidGoToXY(0,0);
					if(Local_u16Iter0<10)
						CLCD_VoidSendData('0');
					CLCD_VoidPrintInt(Local_u16Iter0);

					for(; Local_u16Iter1>=0;Local_u16Iter1--){
						Local_stw.seconds = Local_u16Iter1;
						CLCD_voidGoToXY(3,0);
						if(Local_u16Iter1<10)
							CLCD_VoidSendData('0');
						CLCD_VoidPrintInt(Local_u16Iter1);
						_delay_ms(900);

						Local_u8KeyState = KPD_u8GetPressedKey(&Local_u8Row, &Local_u8Col);
						if(Local_u8KeyState =='c'){
							STW_VoidInit(&Local_stw);
							break;
						}
					}
					Local_u16Iter1=60;

					Local_u16Iter0--;
				}while(Local_u16Iter0 >= 0);
				while(1){
					Local_u8KeyState = KPD_u8GetPressedKey(&Local_u8Row, &Local_u8Col);
					if(Local_u8KeyState =='c'){
						STW_VoidInit(&Local_stw);
						break;
					}
					//finish blink and show  hamoksh
					CLCD_voidGoToXY(0,1);
					CLCD_VoidSendData(1);
					CLCD_VoidPrintChars(" time up");
					//blink red
					LED_u8SetON(&Local_LED);
					_delay_ms(200);
					LED_u8SetOFF(&Local_LED);
					_delay_ms(200);
				}
			}


		}
	}
}
*/
 void main(){

 	uint8 Local_u8KeyState ;
 	Port_voidInit();
 	CLCD_VoidInit();
 	 CLCD_VoidSendData('a');
 	uint8 Local_u8Row,Local_u8Col;

 	CALCULATOR_t Local_calculator ;
 	KCALC_voidInit(&Local_calculator);
 //	CLCD_VoidSendData('a');

 	while(1){
 		Local_u8KeyState =KPD_u8GetPressedKey(&Local_u8Row,&Local_u8Col);
 		if(Local_u8KeyState != 0xff){
 			//operations buttons
 			if(Local_u8Col%3 == 0 && Local_u8Col != 0)
 				KCALC_voidAddOperation(&Local_calculator,Local_u8KeyState);

 			//numbers buttons
 			else if(Local_u8KeyState >= 0 && Local_u8KeyState <= 9)
 				KCALC_voidAddNumber(&Local_calculator,Local_u8KeyState);
 			//equal button
 			else if(Local_u8KeyState  == '='){
 				KCALC_voidEqual(&Local_calculator);
 //				while(Local_u8KeyState  != 'c'){
 //					Local_u8KeyState =KPD_u8GetPressedKey(&Local_u8Row,&Local_u8Col);
 //				}
 			}
 			//clear button
 			else if(Local_u8KeyState  == 'c')
 				KCALC_voidInit(&Local_calculator);
 //			CLCD_VoidPrintInt(Local_u8KeyState);
 		}
 	}
 }
