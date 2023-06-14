#ifndef KCALC_INTERFACE_H
#define KCALC_INTERFACE_H

typedef struct CALCULATOR_t 
{
    sint32 prev_operand;
    sint32 current_operand;
    uint8 operation;
    uint8 second_op_flag;
}CALCULATOR_t ;

uint32 _u32fractionpart(uint8 copy_u8Num1,uint8 copy_u8Num2 );
uint8 _voidCompute(CALCULATOR_t* referance_calculator,sint32* referance_result,uint32* referance_Fractionresult);

void KCALC_voidAddNumber(CALCULATOR_t* referance_calculator,uint8 copy_u8Number);
void KCALC_voidAddOperation(CALCULATOR_t* referance_calculator,uint8 copy_u8Operation);
void KCALC_voidInit(CALCULATOR_t* referance_calculator);
void KCALC_voidEqual(CALCULATOR_t* referance_calculator);
#endif
