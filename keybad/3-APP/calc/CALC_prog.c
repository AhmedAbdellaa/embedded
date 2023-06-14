#include <util/delay.h>
#include "../../libraries/STD_TYPES_H.h"
#include "../../libraries/BIT_MATH.h"
#include "../../libraries/ErrType.h"
#include "../../0-MCAL/DIO_interface.h"
#include "CALC_interface.h"
#include "CALC_cfg.h"
#include "CALC_prv.h"
#include "../../1-HAL/CLCD/CLCD_interface.h"
#include "../../1-HAL/SWITCH/SWITCH_interface.h"

// uint8 CALC_Global_u8NumberChose=0;
/*cursor state */
static CALC_CURSOR_t CALC_Global_CursorState=CALC_CURSOR0;
static uint8 CALC_Global_u8FirstNumber=1;
static uint8 CALC_Global_u8SecondNumber=1;
static CALC_OP_t CALC_Global_Operation=CALC_OP_PLUS;
static uint8 Local_u8AsciiOP []={'+','-','*','/'};
static uint8 CALC_Global_u8Result = 2;
static uint8 CALC_Global_u8FloatingResult = 0;

uint32 _u32fractionpart(uint8 copy_u8Num1,uint8 copy_u8Num2 ){
	uint8 counter=0;
	uint8 Local_u8Result = 0;
	uint8 Local_u8Reminder = copy_u8Num1 % copy_u8Num2 ;
	while( Local_u8Reminder && counter <3){
		Local_u8Reminder = Local_u8Reminder*10;
		if(Local_u8Reminder/copy_u8Num2 >0){
			Local_u8Result =(Local_u8Result*10)+(uint8)(Local_u8Reminder/copy_u8Num2);
		}
		Local_u8Reminder %=copy_u8Num2;
	counter++;

	}
	return Local_u8Result;
}

void CALC_voidDoOperation(){
    switch (CALC_Global_Operation)
    {
    case CALC_OP_PLUS : CALC_Global_u8Result= CALC_Global_u8FirstNumber + CALC_Global_u8SecondNumber;break;
    case CALC_OP_MIN : CALC_Global_u8Result= CALC_Global_u8FirstNumber - CALC_Global_u8SecondNumber;break;
    case CALC_OP_MUL : CALC_Global_u8Result= CALC_Global_u8FirstNumber * CALC_Global_u8SecondNumber;break;
    case CALC_OP_DIV : CALC_Global_u8Result= CALC_Global_u8FirstNumber / CALC_Global_u8SecondNumber;
    CALC_Global_u8FloatingResult = _u32fractionpart(CALC_Global_u8FirstNumber,CALC_Global_u8SecondNumber);
    break;
    default:CALC_Global_u8Result=0;break;
    }
}

void CALC_voidInc(){
    if(CALC_Global_CursorState == CALC_CURSOR0){
        if(CALC_Global_u8FirstNumber<9)
            CALC_Global_u8FirstNumber++;
        else
            CALC_Global_u8FirstNumber=0;

        CLCD_voidGoToXY(0,0);
		CLCD_VoidPrintInt(CALC_Global_u8FirstNumber);
    }
    else if (CALC_Global_CursorState == CALC_CURSOR1){
        if(CALC_Global_u8SecondNumber<9)
            CALC_Global_u8SecondNumber++;
        else {
            if(CALC_Global_Operation== CALC_OP_DIV)
                    CALC_Global_u8SecondNumber=1;
                else
                    CALC_Global_u8SecondNumber=0;
        }
        CLCD_voidGoToXY(2,0);
		CLCD_VoidPrintInt(CALC_Global_u8SecondNumber);
    }
    else if (CALC_Global_CursorState == CALC_CURSOR_OP){
        if(CALC_Global_Operation==CALC_OP_DIV) 
            CALC_Global_Operation = CALC_OP_PLUS;
        else 
            CALC_Global_Operation++;
        CLCD_voidGoToXY(1,0);
		CLCD_VoidSendData(Local_u8AsciiOP[CALC_Global_Operation]);
    }
  
    
}

void CALC_voidDec(){
     if(CALC_Global_CursorState == CALC_CURSOR0){
        if(CALC_Global_u8FirstNumber>0)
            CALC_Global_u8FirstNumber--;
        else
            CALC_Global_u8FirstNumber=9;
        CLCD_voidGoToXY(0,0);
		CLCD_VoidPrintInt(CALC_Global_u8FirstNumber);
    }
    else if (CALC_Global_CursorState == CALC_CURSOR1){
        if(CALC_Global_u8SecondNumber>1)
            CALC_Global_u8SecondNumber--;
        else {
            if(CALC_Global_Operation== CALC_OP_DIV)
                    CALC_Global_u8SecondNumber=9;
                else
                    CALC_Global_u8SecondNumber=0;
        }
        CLCD_voidGoToXY(2,0);
		CLCD_VoidPrintInt(CALC_Global_u8SecondNumber);
    }
     else if (CALC_Global_CursorState == CALC_CURSOR_OP){
        if(CALC_Global_Operation==CALC_OP_PLUS) 
            CALC_Global_Operation = CALC_OP_DIV;
        else 
            CALC_Global_Operation--;
        CLCD_voidGoToXY(1,0);
		CLCD_VoidSendData(Local_u8AsciiOP[CALC_Global_Operation]);
    }
    
    
}

void CALC_VoidOkClick(){
    
    switch (CALC_Global_CursorState)
    {
    case CALC_CURSOR0 :  CALC_Global_CursorState = CALC_CURSOR_OP;


    break;

    case CALC_CURSOR_OP :  CALC_Global_CursorState = CALC_CURSOR1;    break;
    case CALC_CURSOR1 :  
        CALC_Global_CursorState = CALC_CURSOR_RESULT;
        CALC_voidDoOperation();
        //display result
        CLCD_voidGoToXY(3,0);
		CLCD_VoidSendData('=');

		CLCD_voidGoToXY(4,0);
		if(CALC_Global_Operation ==CALC_OP_DIV)
			CLCD_VoidPrintFloat(CALC_Global_u8Result,CALC_Global_u8FloatingResult);
		else
			CLCD_VoidPrintInt(CALC_Global_u8Result);

        break;
    case CALC_CURSOR_RESULT:  CALC_Global_CursorState = CALC_CURSOR0;
    iniitsca();
    
    default:
        break;
    }
    _VoidDisplayArrow();
}

static void _VoidDisplayArrow(){

    CLCD_voidGoToXY(CALC_Global_CursorState == CALC_CURSOR_RESULT?CALC_CURSOR1:CALC_Global_CursorState-1,1);
    CLCD_VoidSendData(' ');
    CLCD_voidGoToXY(CALC_Global_CursorState,1);
    CLCD_VoidSendData(0u);

}

///btns configuration
SWITCH_Config_t Switch_inc = {SWITCH_PULL_UP,CALC_BUTTONS_PORT,CALC_BUTTON_INC,SWITCH_RELEASED};
SWITCH_Config_t Switch_dec = {SWITCH_PULL_UP,CALC_BUTTONS_PORT,CALC_BUTTON_DEC,SWITCH_RELEASED};
SWITCH_Config_t Switch_ok = {SWITCH_PULL_UP,CALC_BUTTONS_PORT,CALC_BUTTON_OK,SWITCH_RELEASED};

void CALC_VoidBTNClick(){

	SWITCH_u8GetState(&Switch_inc);
	if(Switch_inc.state == SWITCH_PRESSED){
		CALC_voidInc();
		_delay_ms(250);
	}

	SWITCH_u8GetState(&Switch_dec);
	if(Switch_dec.state == SWITCH_PRESSED){
		CALC_voidDec();
		_delay_ms(250);
	}
	SWITCH_u8GetState(&Switch_ok);
	if(Switch_ok.state == SWITCH_PRESSED){
		CALC_VoidOkClick();
		_delay_ms(250);
		}
}
void iniitsca(){
	CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
		CLCD_voidGoToXY(0,0);
		CLCD_VoidPrintInt(CALC_Global_u8FirstNumber);

		CLCD_voidGoToXY(2,0);
		CLCD_VoidPrintInt(CALC_Global_u8SecondNumber);

		CLCD_voidGoToXY(1,0);
		CLCD_VoidSendData(Local_u8AsciiOP[CALC_Global_Operation]);
}
void initi(){
	iniitsca();
	CLCD_u8WriteSpecialChar(0u,CALC_Arrow);
	_VoidDisplayArrow();
}


