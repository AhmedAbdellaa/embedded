#include <util/delay.h>
#include "../../libraries/STD_TYPES_H.h"
#include "HAMO_interface.h"
#include "HAMO_prv.h"
#include "../../1-HAL/CLCD/CLCD_interface.h"





void _voidIniWalk(){
    CLCD_u8WriteSpecialChar(0X06,MOVEZERO);
    CLCD_u8WriteSpecialChar(0X07,MOVEONE);
}

void _voidIniDance(){
    CLCD_u8WriteSpecialChar(0X04,DANCE0);
    CLCD_u8WriteSpecialChar(0X05,DANCE1);
    CLCD_u8WriteSpecialChar(0X06,DANCE2);
    CLCD_u8WriteSpecialChar(0X07,DANCE3);
}

void _voidIniBall(){
    CLCD_u8WriteSpecialChar(0X03,RUN0);
    CLCD_u8WriteSpecialChar(0X04,RUN1);
    CLCD_u8WriteSpecialChar(0X05,PASSUP);
    CLCD_u8WriteSpecialChar(0X06,BALLDOWN);
    CLCD_u8WriteSpecialChar(0X07,BALLUP);
}

void _voidIniKill(){
    CLCD_u8WriteSpecialChar(0X03,STAND);
    CLCD_u8WriteSpecialChar(0X04,GUN);
    CLCD_u8WriteSpecialChar(0X05,BULLET);
    CLCD_u8WriteSpecialChar(0X06,BODYFIRSTHALF);
    CLCD_u8WriteSpecialChar(0X07,BODYSECONDHALF);
}

void Hamo_voidWalkScene(){
    _voidIniWalk();
    CLCD_voidGoToXY(0u,0u);
    CLCD_VoidPrintChars(" I can walk...");
    uint8 Local_u8counter=0;
	while(Local_u8counter<16){
		CLCD_voidGoToXY(Local_u8counter-1,1U);
		CLCD_VoidSendData(' ');

        CLCD_voidGoToXY(Local_u8counter,1U);
		CLCD_VoidSendData(6);
		_delay_ms(150);
		
		CLCD_voidGoToXY(Local_u8counter,1U);
		CLCD_VoidSendData(7);
		_delay_ms(150);

        Local_u8counter++;
    }
    CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
}

void Hamo_voidDanceScene(){
    _voidIniDance();
    CLCD_voidGoToXY(0u,0u);
    CLCD_VoidPrintChars(" I can dance...");
    uint8 Local_u8counter=0;
	while(Local_u8counter<16){
        CLCD_voidGoToXY(Local_u8counter,1U);
		CLCD_VoidSendData(4);
		_delay_ms(300);

        CLCD_voidGoToXY(Local_u8counter,1U);
		CLCD_VoidSendData(5);
		_delay_ms(300);

        CLCD_voidGoToXY(Local_u8counter,1U);
		CLCD_VoidSendData(6);
		_delay_ms(300);

        CLCD_voidGoToXY(Local_u8counter,1U);
		CLCD_VoidSendData(7);
		_delay_ms(300);


        CLCD_voidGoToXY(Local_u8counter,1U);
		CLCD_VoidSendData(' ');

		Local_u8counter +=4;
    }
    CLCD_VoidSendCommand(CLCD_CLEAR_CMD);

}

void Hamo_voidballScene(){
    _voidIniBall();
    CLCD_voidGoToXY(0u,0u);
    CLCD_VoidPrintChars("I can play football...");
    uint8 Local_u8counter=0;
	while(Local_u8counter<16){
        CLCD_voidGoToXY(Local_u8counter,1U);
		CLCD_VoidSendData(3u); //run0
		_delay_ms(250);
		CLCD_voidGoToXY(Local_u8counter,1U);
		CLCD_VoidSendData(4u);//run1
		_delay_ms(250);

		CLCD_voidGoToXY(Local_u8counter,1U);
		CLCD_VoidSendData(' ');
		Local_u8counter++;
//		CLCD_VoidSendCommand(0b00011100);//shift right
		CLCD_voidGoToXY(Local_u8counter,1U);
		CLCD_VoidSendData(5u); //pass up
		_delay_ms(250);
		CLCD_voidGoToXY(Local_u8counter+1,1U);
		CLCD_VoidSendData(7u);
		_delay_ms(250);
		CLCD_voidGoToXY(Local_u8counter+1,1U);
		CLCD_VoidSendData(6u);
		_delay_ms(250);

    }
    CLCD_VoidSendCommand(CLCD_CLEAR_CMD);

}

void Hamo_voidKillScene(){
    _voidIniKill();
    CLCD_voidGoToXY(0u,0u);
    CLCD_VoidPrintChars(" Don't Kill me ");
    CLCD_voidGoToXY(0,1U);
    CLCD_VoidSendData(4);
    CLCD_voidGoToXY(15,1U);
    CLCD_VoidSendData(3);
    uint8 Local_u8counter=1;
	while(Local_u8counter<15){
        CLCD_voidGoToXY(Local_u8counter,1U);
        CLCD_VoidSendData(5);
		_delay_ms(150);
		CLCD_voidGoToXY(Local_u8counter,1U);
		CLCD_VoidSendData(' ');
		
        Local_u8counter++;
    }
     CLCD_voidGoToXY(14,1U);
    CLCD_VoidSendData(6);
    CLCD_voidGoToXY(15,1U);
    CLCD_VoidSendData(7);
    _delay_ms(700);
    CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
}
