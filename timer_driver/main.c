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

//#include "1-HAL/LED/LED_interface.h"
#include "1-HAL/SSD/SSD_interface.h"
//#include "1-HAL/CLCD/CLCD_interface.h"

///*3leds assignments*/
///* initlize all leds with high*/
//LED_Config_t Gloable_LED0 = {LED_ACTIVE_HIGH, DIO_PORTC, DIO_PIN0};
//LED_Config_t Gloable_LED1 = {LED_ACTIVE_HIGH, DIO_PORTC, DIO_PIN1};
//LED_Config_t Gloable_LED2 = {LED_ACTIVE_HIGH, DIO_PORTC, DIO_PIN2};
//uint8 Local_u8_LedCounter = 0u; // count until reach 3 leds in isr


/*multiplexed ssd*/
SSD_Config_t Gloable_rightseg ={SSD_ComCathod,DIO_PORTA,DIO_PIN1,DIO_PORTC,DIO_PIN6};
SSD_Config_t Gloable_leftseg ={SSD_ComCathod,DIO_PORTA,DIO_PIN1,DIO_PORTC,DIO_PIN7};
sint8 Gloable_counterUp = 0;
sint8 Gloable_counterDown = 9;

///*timer as counter*/
//uint8 Gloable_u8Counter=0;
void TIMER0ISR(void)
{

	///*test timer deriver*/
	// DIO_u8_TogglePinVal(DIO_PORTC,DIO_PIN0);

	///*3leds assignments*/
	//	switch (Local_u8_LedCounter)
	//	{
	//		// 5 ms pass
	//	case 0:
	//		LED_u8Toggle(&Gloable_LED0);
	//		break;
	//		// 10 ms pass
	//	case 1:
	//		LED_u8Toggle(&Gloable_LED1);
	//		break;
	//		// 15 ms pass
	//	case 2:
	//		LED_u8Toggle(&Gloable_LED2);
	//		break;
	//		//20ms pass
	//	case 3:
	//		LED_u8SetON(&Gloable_LED0);
	//		LED_u8SetON(&Gloable_LED1);
	//		LED_u8SetON(&Gloable_LED2);
	//		Local_u8_LedCounter = 0u;
	//		return;
	//	default:
	//		break;
	//	}
	//	Local_u8_LedCounter++;

	/*multiplexed ssd*/
//	DIO_u8_TogglePinVal(DIO_PORTC,DIO_PIN0);
	//count 100 of 10ms to change counter
	static uint16 local_u16ms_second_counter = 0;
	//for each one second reset ms_counter  and update status of counter down and up
	if(local_u16ms_second_counter < 100u){
		local_u16ms_second_counter++;
	}else{
		local_u16ms_second_counter = 0;
		if(Gloable_counterDown==0){
			Gloable_counterDown = 9;
		}else{
			Gloable_counterDown--;
		}
		if(Gloable_counterUp==9){
			Gloable_counterUp = 0;
		}else{
			Gloable_counterUp++;
		}
	}
	//every 10ms will disable one ssd and enable the other one after put number in it
	if(local_u16ms_second_counter % 2 == 0){
		SSD_u8Disable(&Gloable_rightseg);
		SSD_u8SetNumber(&Gloable_leftseg,Gloable_counterUp);
		SSD_u8Enable(&Gloable_leftseg);
	}else{
		SSD_u8Disable(&Gloable_leftseg);
		SSD_u8SetNumber(&Gloable_rightseg,Gloable_counterDown);
		SSD_u8Enable(&Gloable_rightseg);
	}
	//	/*timer as counter*/
	//	Gloable_u8Counter++;
	//	CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
	//	CLCD_VoidPrintChars("counter : ");
	//	CLCD_VoidPrintInt((sint32)Gloable_u8Counter);
}

void main()
{

	Port_voidInit();
	GIE_voidEnableGlobal();
	TIMER_voidInit();
	CLCD_VoidInit();
	///*test timer deriver*/
	/* 1S ,res = 8, sysfreq=16M ,prescaler = 256, tovf =((prescaler/sysfreq) * 2^res) = 128us,cov = 7812.5
	 * preload = 2^res(1-0.25878906)= 189.75 ~190
	 */
	/*multiplexed ssd*/
	TIMER_CALLBACK_CONFIG_t Local_Timer0config = {99,1};
	TIMER_u8SetCallBack(TIMER0,&Local_Timer0config,&TIMER0ISR);

	/*3leds assignments*/
	/*
	 * 5 ms,res = 8,sysfreq=16M ,prescaler = 1024, tovf =((prescaler/sysfreq) * 2^res) = 4096us,cov = 1.2207
	 * preload = 2^res(1-0.25878906)= 199.5 ~200
	 */
	//	TIMER_CALLBACK_CONFIG_t Local_Timer0config = {242, 3};
	//	TIMER_u8SetCallBack(TIMER0, &Local_Timer0config, &TIMER0ISR);
	/*timer counter*/
	//		TIMER_CALLBACK_CONFIG_t Local_Timer0config = {0,1};
	//		TIMERCompare_u8SetCallBack(TIMER0,&Local_Timer0config,&TIMER0ISR);
	//		CLCD_VoidPrintChars("counter : ");
	//		CLCD_VoidPrintInt((sint32)Gloable_u8Counter);
	//		DIO_pinVal_t local_u8buttonstate;
	while (1)
	{
		/*timer counter*/
		//		DIO_u8_GetPinVal(DIO_PORTB,DIO_PIN4,&local_u8buttonstate);
		//		DIO_u8_SetPinVal(DIO_PORTB,DIO_PIN0,local_u8buttonstate);
		//		DIO_u8_SetPinVal(DIO_PORTD,DIO_PIN0,local_u8buttonstate);
		//		/*multiplexed ssd*/
		//		SSD_u8SetNumber(&Gloable_leftseg,Gloable_counterUp);
		//		SSD_u8Enable(&Gloable_leftseg);
		//		_delay_ms(10);
		//		SSD_u8Disable(&Gloable_leftseg);
		//
		//		SSD_u8SetNumber(&Gloable_rightseg,Gloable_counterDown);
		//		SSD_u8Enable(&Gloable_rightseg);
		//		_delay_ms(10);
		//		SSD_u8Disable(&Gloable_rightseg);
	}
}
