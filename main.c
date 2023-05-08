/*
 * main.c
 *
 *  Created on: May 3, 2023
 *      Author: ahmed
 */


#include "1-HAL/CLCD/CLCD_interface.h"

void main(void){

	CLCD_VoidInit();
	CLCD_VoidSendData('A');
}
