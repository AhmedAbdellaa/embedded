#ifndef EXTI_INTERFACE
#define EXTI_INTERFACE

//typedef run in compilation step after preprocess step
// typedef enum EXTI_SenceCtrl{
//     LOW_LEVEL=1,
//     ON_CHANGE,
//     FALLING_EDGE,
//     RISING_EDGE
// }EXTI_SenceCtrl;

#define LOW_LEVEL 1
#define ON_CHANGE 2
#define FALLING_EDGE 3
#define RISING_EDGE 4
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
