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

//define registers
#define SREG *((volatile uint8 *)0x5F) //global open interrupts
#define SREG_I 7U
#define GICR *((volatile uint8 *)0x5B) //enable interrupt
#define GICR_INT1 7U
#define GICR_INT0 6U

#define MCUCR *((volatile uint8 *)0x55) //configure trigger
#define MCUCR_IS00 0u
#define MCUCR_IS01 1u
#define MCUCR_IS10 2u
#define MCUCR_IS11 3u

void __vector_1(void) __attribute__((signal));
void __vector_1(void){
	DIO_u8_TogglePinVal(DIO_PORTC,DIO_PIN0);
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void){
	DIO_u8_TogglePinVal(DIO_PORTC,DIO_PIN0);
}
void main(){



// 	uint8 Local_u8_keypadStatus ;
 	Port_voidInit();
// 	LED_Config_t Local_LED_0 = {LED_ACTIVE_HIGH,DIO_PORTC,DIO_PIN0};
// 	DIO_u8_PinPullUp(DIO_PORTD,DIO_PIN2);
 	//enable interrupts
 	SET_BIT(SREG,7);

 	//enable interrupt 0
	SET_BIT(GICR,6);
	SET_BIT(GICR,7);

	//configure interrupt falling edge
	CLS_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);

	//configure interrupt falling edge
	CLS_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);



 	while(1){

 	}

 }
