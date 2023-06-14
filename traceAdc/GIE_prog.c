
#include "./BIT_MATH.h"
#include "./ErrType.h"
#include "./STD_TYPES_H.h"
#include "GIE_interface.h"
#include "GIE_reg.h"
void GIE_voidEnableGlobal(){
    // SET_BIT(SREG,SREG_I);
    __asm volatile ("SEI");
}
void GIE_voidDisabledGlobal(){
    // cls_BIT(SREG,SREG_I);
    __asm volatile ("CLI");
}
