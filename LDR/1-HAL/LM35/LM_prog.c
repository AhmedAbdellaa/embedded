
#include "../../libraries/STD_TYPES_H.h"
#include "../../libraries/ErrType.h"
#include "../../libraries/MAP.h"
#include "../../0-MCAL/1-DIO/DIO_interface.h"
#include "../../0-MCAL/5-ADC/ADC_interface.h"
#include "LM_interface.h"

uint8 LM_u8GetTemp(LM_Config_t* refrance_LM){
    uint8 Local_u8ErrorState = OK;

    if(refrance_LM != NULL ){
    	uint16 Local_u16Reading ;
		ADC_u16startConverstionSync(refrance_LM->AnalogChannel_DigitalSignal,&Local_u16Reading);
		uint16 Local_u16VoltageReading = (uint16)MAP(0u,1023ul,0u,refrance_LM->max_volt,(sint32)Local_u16Reading);

        //return temperature in Celsius
        refrance_LM->Temprature =  Local_u16VoltageReading/10 ;
    }else{
        Local_u8ErrorState = NULL_PTR;
    }
    return Local_u8ErrorState;
}

uint8 LM_u8GetTempFromDigSignal(LM_Config_t* refrance_LM){
    uint8 Local_u8ErrorState = OK;

    if(refrance_LM != NULL ){
		uint16 Local_u16VoltageReading = (uint16)MAP(0u,1023ul,0u,refrance_LM->max_volt,(sint32)refrance_LM->AnalogChannel_DigitalSignal);

        //return temperature in Celsius
        refrance_LM->Temprature =  Local_u16VoltageReading/10 ;
    }else{
        Local_u8ErrorState = NULL_PTR;
    }
    return Local_u8ErrorState;
}


//convert Celsius to Fahrenheit
uint16 LM_u16convertToFahrenheit(uint8 copy_u8CelsiusDeggree){

    return ((((uint16)copy_u8CelsiusDeggree*9)/5)+32);

}
