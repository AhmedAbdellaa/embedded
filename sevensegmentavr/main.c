/*
 * main.c
 *
 *  Created on: May 6, 2023
 *      Author: ahmed
 */

 #include <util/delay.h>
#include "0-MCAL/DIO_interface.h"
#include "1-HAL/SSD/SSD_interface.h"
#include "1-HAL/LED/LED_interface.h"
#include "1-HAL/SWITCH/SWITCH_interface.h"
#include <stdio.h>

int main()
{
     //7SEG leds
    DIO_u8_SetPortDir(DIO_PORTA,0x00);
    DIO_u8_SetPortVal(DIO_PORTA,0x00);

	SSD_Config_t Local_rightseg ={SSD_ComCathod,DIO_PORTA,DIO_PIN1,DIO_PORTC,DIO_PIN6};
	SSD_Config_t Local_leftseg ={SSD_ComCathod,DIO_PORTA,DIO_PIN1,DIO_PORTC,DIO_PIN7};

	//configure leds
	LED_Config_t Local_RedLED = {LED_ACTIVE_HIGH,DIO_PORTC,DIO_PIN0};
	LED_Config_t Local_GreedLED = {LED_ACTIVE_HIGH,DIO_PORTC,DIO_PIN1};
	LED_Config_t Local_YellowLED = {LED_ACTIVE_HIGH,DIO_PORTC,DIO_PIN2};
	LED_u8SetOFF(&Local_RedLED);
	LED_u8SetOFF(&Local_GreedLED);
	LED_u8SetOFF(&Local_YellowLED);

	//configure switch
	SWITCH_Config_t btn0 = {SWITCH_PULL_UP,DIO_PORTD,DIO_PIN2,SWITCH_RELEASED};
	DIO_u8_PinPullUp(btn0.port,btn0.Pin);



    sint8 i ;
    uint16 j;
    uint8 ones, tens;
    static uint8 counter =0;
    SSD_u8SetNumber(&Local_leftseg,counter%10);
	SSD_u8Enable(&Local_leftseg);

    while(1){
    	SWITCH_u8GetState(&btn0);
    	if(btn0.state == SWITCH_PRESSED){
    		SSD_u8SetNumber(&Local_leftseg,(counter++)%10);
    		_delay_ms(250);
    	}
    }
	/*
    while (1)
    {
        // RED
    	LED_u8SetOFF(&Local_YellowLED);
    	LED_u8SetON(&Local_RedLED);
    	i=15;
    	while(i>=0){
				ones = i % 10;
				tens = i / 10;
            j=0;
            while(j<50)

            {
            	SSD_u8SetNumber(&Local_leftseg,tens);
            	SSD_u8Enable(&Local_leftseg);
            	_delay_ms(10);
            	SSD_u8Disable(&Local_leftseg);

            	SSD_u8SetNumber(&Local_rightseg,ones);
				SSD_u8Enable(&Local_rightseg);
            	_delay_ms(10);
            	SSD_u8Disable(&Local_rightseg);
            j++;
            }
            i--;
        }
//        // GREEN
    	LED_voidToggle(&Local_RedLED);
    	LED_voidToggle(&Local_GreedLED);

//
        for (i = 15; i >=0; i--)
        {
				ones = i % 10;
				tens = i / 10;
            for (j = 0; j < 50; j++)
            {

            	SSD_u8SetNumber(&Local_leftseg,tens);
				SSD_u8Enable(&Local_leftseg);
				_delay_ms(10);
				SSD_u8Disable(&Local_leftseg);

				SSD_u8SetNumber(&Local_rightseg,ones);
				SSD_u8Enable(&Local_rightseg);
				_delay_ms(10);
				SSD_u8Disable(&Local_rightseg);
            }
        }
//        // YELLOW
        LED_u8SetOFF(&Local_GreedLED);
        LED_u8SetON(&Local_YellowLED);

        for (i = 3; i >=0; i--)
        {
        	ones = i % 10;
            tens = i / 10;
            for (j = 0; j < 50; j++)
            {
            	SSD_u8SetNumber(&Local_leftseg,tens);
				SSD_u8Enable(&Local_leftseg);
				_delay_ms(10);
				SSD_u8Disable(&Local_leftseg);

				SSD_u8SetNumber(&Local_rightseg,ones);
				SSD_u8Enable(&Local_rightseg);
				_delay_ms(10);
				SSD_u8Disable(&Local_rightseg);
            }
        }
    }
    */
}
