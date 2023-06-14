#include "../../libraries/STD_TYPES_H.h"

#include "../../1-HAL/CLCD/CLCD_interface.h"

#include "./STW_interface.h"


void STW_voidUpdate(STW_config_t* referance_stw,uint8 copy_u8Num){
	uint8 Local_u8res;
    switch (referance_stw->pos){
        case 0 :Local_u8res = referance_stw->minutes%10 + copy_u8Num*10 ;
        	if(Local_u8res <=60) referance_stw->minutes = Local_u8res; break;
        case 1 :Local_u8res = referance_stw->minutes/10*10 + copy_u8Num;
        	if( Local_u8res<= 60)
        			referance_stw->minutes=Local_u8res; break;

        case 3 :Local_u8res =referance_stw->seconds%10 + copy_u8Num*10;
        	if(copy_u8Num*10 <=60)  referance_stw->seconds = Local_u8res; break;
        case 4 :Local_u8res =referance_stw->seconds/10*10 + copy_u8Num ;
        	if( Local_u8res<= 60)
        			referance_stw->seconds =Local_u8res ; break;
        default: break;
    }
}
void STW_VoidInit(STW_config_t* referance_stw){
	CLCD_VoidSendCommand(CLCD_CLEAR_CMD);
	CLCD_voidGoToXY(0, 0);
	CLCD_VoidPrintChars("00:00");
	CLCD_voidGoToXY(0, 1);
	CLCD_VoidSendData(0);

    referance_stw->minutes=0;
    referance_stw->pos=0;
    referance_stw->seconds=0;
}
