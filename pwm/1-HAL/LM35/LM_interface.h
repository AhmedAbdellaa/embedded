#ifndef LM_INTERFACE_H
#define LM_INTERFACE_H


typedef struct LM_Config_t
{
    uint16 AnalogChannel_DigitalSignal;
    uint16 max_volt;
    uint8 Temprature;
}LM_Config_t;

uint8 LM_u8GetTemp(LM_Config_t* refrance_LM);
uint8 LM_u8GetTempFromDigSignal(LM_Config_t* refrance_LM);
uint16 LM_u16convertToFahrenheit(uint8 copy_u8CelsiusDeggree);

#endif
