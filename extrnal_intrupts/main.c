/*
 * main.c
 *
 *  Created on: May 7, 2023
 *      Author: ahmed
 */

#include <util/delay.h>
#include "./0-MCAL/1-DIO/DIO_interface.h"
#include "0-MCAL/2-Port/PORT_interface.h"
#include "libraries/STD_TYPES_H.h"
#include "libraries/BIT_MATH.h"
#include "1-HAL/LED/LED_interface.h"
#include "0-MCAL/4-GIE/GIE_interface.h"
#include "0-MCAL/3-EXTI/EXTI_interface.h"

void INT0ISR(void){
	DIO_u8_TogglePinVal(DIO_PORTC,DIO_PIN0);
}

void INT1ISR(void){
	DIO_u8_TogglePinVal(DIO_PORTC,DIO_PIN0);
}
void main(){



 	Port_voidInit();
 	GIE_voidEnableGlobal();
 	EXTI_voidInit();

 	EXTI_u8SetCallBack(INT0,&INT0ISR);
 	EXTI_u8SetCallBack(INT1,&INT1ISR);

 	while(1){

 	}

 }
