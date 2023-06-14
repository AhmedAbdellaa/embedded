
#include "../../libraries/STD_TYPES_H.h"
#include "../../libraries/ErrType.h"
#include "../../libraries/MAP.h"
#include "../../0-MCAL/1-DIO/DIO_interface.h"
#include "../../0-MCAL/5-ADC/ADC_interface.h"
#include "../../1-HAL/CLCD/CLCD_interface.h"
#include "AVO_interface.h"

uint16 AVO_u16MesaureVoltage(ADC_channel_t copy_Channel){
    uint16 Local_u16Reading ;
    ADC_u8StartConverstionSync(copy_Channel,&Local_u16Reading);
    uint16 Local_u16AnalogReading = (uint16)MAP(0,1023,0,5000,(sint32)Local_u16Reading);
    return Local_u16AnalogReading;
    
}

uint16 AVO_u16MesaureOhm(ADC_channel_t copy_Channel,uint16 copy_u16R2){
    uint16 Local_u16VoltReading = AVO_u16MesaureVoltage(copy_Channel);
    // using voltage divider low R1= ((vin*r2)/vout)-r2	  r2=220
    return (uint16)(((MAX_VOLT*(uint32)copy_u16R2)/(uint32)Local_u16VoltReading)-copy_u16R2);

}

