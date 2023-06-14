#ifndef AVO_INTERFACE_H
#define AVO_INTERFACE_H

//max input voltage
#define MAX_VOLT   5000
//total resolution 2^10 -> 1024
#define TOTAL_RESOLUTION  1024

uint16 AVO_u16MesaureVoltage(ADC_channel_t copy_Channel);  
uint16 AVO_u16MesaureOhm(ADC_channel_t copy_Channel,uint16 copy_u16R2);

#endif
