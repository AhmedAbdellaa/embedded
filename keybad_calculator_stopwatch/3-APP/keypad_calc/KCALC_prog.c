#include "../../libraries/STD_TYPES_H.h"

#include "../../1-HAL/CLCD/CLCD_interface.h"

#include "./KCALC_interface.h"



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

uint8 _voidCompute(CALCULATOR_t* referance_calculator,sint32* referance_result,uint32* referance_Fractionresult){

    switch (referance_calculator->operation)
    {
    case '+' : *referance_result= referance_calculator->prev_operand + referance_calculator->current_operand;break;
    case '-' : *referance_result= referance_calculator->prev_operand - referance_calculator->current_operand;break;
    case '*' : *referance_result= referance_calculator->prev_operand * referance_calculator->current_operand;break;
    case '/' : *referance_result= referance_calculator->prev_operand / referance_calculator->current_operand;
    *referance_Fractionresult = _u32fractionpart(referance_calculator->prev_operand,referance_calculator->current_operand);
    break;
    default: return 0;//Fail
    }
    return 1;//Success return result
}

void KCALC_voidInit(CALCULATOR_t* referance_calculator){
    CLCD_VoidSendCommand(CLCD_CLEAR_CMD);

    referance_calculator->current_operand = 0;
    referance_calculator->prev_operand = 0;
    referance_calculator->operation ='\0';
    referance_calculator->second_op_flag = 0;
}

void KCALC_voidAddNumber(CALCULATOR_t* referance_calculator,uint8 copy_u8Number){
    //add digit to calculator class
	//if equal button already pressed
    if(referance_calculator->second_op_flag== 1){
    	// Reinitialize the calculator
    	KCALC_voidInit(referance_calculator);
    	referance_calculator->current_operand = copy_u8Number;
    	}
    else//add new digit to the current number
    	referance_calculator->current_operand = (referance_calculator->current_operand *10) +copy_u8Number;

    //display on lcd
        CLCD_VoidSendData(copy_u8Number+'0');
}

void KCALC_voidAddOperation(CALCULATOR_t* referance_calculator,uint8 copy_u8Operation){
	//if equal button already pressed
	if(referance_calculator->second_op_flag== 1){
		CLCD_VoidSendCommand(CLCD_CLEAR_CMD); //clear screen
		CLCD_VoidPrintInt(referance_calculator->current_operand);//display previous operation result as current operand
		referance_calculator->second_op_flag = 0;// reset the second operation"equal" flag
	}
	//display operation on LCD
    CLCD_VoidSendData(copy_u8Operation);

    //add to the calculator
    //if no operation defined before : prevent +++ ,+*-,---
    if(referance_calculator->operation == '\0'){
    	//move the current operand to prev and the operation to the calculator class
        referance_calculator->prev_operand = referance_calculator->current_operand;
        referance_calculator->current_operand = 0;
        referance_calculator->operation = copy_u8Operation;
    }else{
    	//if add operation after current operand like 1+1+5
    	if(referance_calculator->current_operand != 0){
    		KCALC_voidEqual(referance_calculator);
    		KCALC_voidAddOperation(referance_calculator,copy_u8Operation);
    	}
    }
}


void KCALC_voidEqual(CALCULATOR_t* referance_calculator){
    sint32 Local_s32Result=0;
    uint32 Local_u32FractionResult = 0;

    uint8 Local_u8Compute = _voidCompute(referance_calculator,&Local_s32Result,&Local_u32FractionResult);
    if (Local_u8Compute){
    	referance_calculator->operation='\0';
    	referance_calculator->current_operand = Local_s32Result;
    	referance_calculator->second_op_flag = 1;
//    	CLCD_VoidSendData('=');
        CLCD_voidGoToXY(0,1);
        if(Local_u32FractionResult)
            CLCD_VoidPrintFloat(Local_s32Result,Local_u32FractionResult);
        else
            CLCD_VoidPrintInt(Local_s32Result);
    }

}

