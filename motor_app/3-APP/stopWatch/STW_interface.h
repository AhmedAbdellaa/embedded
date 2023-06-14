#ifndef STW_INTERFACE_H
#define STW_INTERFACE_H

typedef struct STW_config_t 
{
    uint8 pos;
    uint8 minutes;
    uint8 seconds;
    
}STW_config_t ;


void STW_voidUpdate(STW_config_t* referance_stw,uint8 copy_u8Num);
void STW_VoidInit(STW_config_t* referance_stw);

#endif
