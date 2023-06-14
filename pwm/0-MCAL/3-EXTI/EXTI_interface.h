#ifndef EXTI_INTERFACE
#define EXTI_INTERFACE

typedef enum {
    INT0,
    INT1,
    INT2,
    
}EXTI_IntNum_t;


void EXTI_voidInit(void);
uint8 EXTI_u8SetSenceCtrl(EXTI_IntNum_t copy_IntNum,uint8 copy_SenseCtrl);
uint8 EXTI_u8IntEnable(EXTI_IntNum_t copy_IntNum);
uint8 EXTI_u8IntDisable(EXTI_IntNum_t copy_IntNum);

uint8 EXTI_u8SetCallBack(EXTI_IntNum_t,void(*copy_pvFuncPtr)(void));

#endif
