#ifndef TIMER_INTERFACE
#define TIMER_INTERFACE



typedef enum {
    TIMER0,
    TIMER1A,
    TIMER1B,
    TIMER2,
    
}TIMER_TINum_t;

typedef struct TIMER_CALLBACK_CONFIG_t {

uint16 TIMER_u16OCR_TCNT_initVal; 
uint32 TIMER_U32ISRDoNum; //number of go into isrinclude preload overflow step
}TIMER_CALLBACK_CONFIG_t;


void TIMER_voidInit(void);
uint8 TIMER_u8SetCallBack(TIMER_TINum_t copy_TINum,TIMER_CALLBACK_CONFIG_t* referance_TimerCallbackConf,void(*copy_pvFuncPtr)(void));

uint8 TIMERPWM_u8SetCallBack(TIMER_TINum_t copy_TINum,uint8 copy_u8OC_value);
// uint8 TIMER_u8IntEnable(TIMER_TINum_t copy_IntNum);
// uint8 TIMER_u8IntDisable(TIMER_TINum_t copy_IntNum);



#endif
