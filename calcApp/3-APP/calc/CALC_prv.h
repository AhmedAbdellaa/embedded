#ifndef CALC_PRV_H
#define CALC_PRV_H

typedef enum CALC_CURSOR_t{
    CALC_CURSOR0,CALC_CURSOR_OP,CALC_CURSOR1,CALC_CURSOR_RESULT=4
}CALC_CURSOR_t;

typedef enum CALC_OP_t{
    CALC_OP_PLUS,CALC_OP_MIN,CALC_OP_MUL,CALC_OP_DIV
}CALC_OP_t;

static uint8 CALC_Arrow[] = {  0B00100,  0B01110,  0B11111,  0B01110,  0B01110,  0B01110,  0B01110,  0B01110};

static void CALC_voidDoOperation();
static void CALC_voidInc();
static void CALC_voidDec();
static void CALC_VoidOkClick();
static void _VoidDisplayArrow();
void iniitsca();
#endif
