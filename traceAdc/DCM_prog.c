
#include "./STD_TYPES_H.h"
#include "./ErrType.h"
#include "DIO_interface.h"
#include "DCM_interface.h"

void DCM_voidRotateCW(DCM_Config_t* referance_motor ){
    DIO_u8_SetPinVal(referance_motor->port, referance_motor->Pin0, DIO_PIN_LOW);
    DIO_u8_SetPinVal(referance_motor->port, referance_motor->Pin1, DIO_PIN_HIGH);
}
void DCM_voidRotateCCW(DCM_Config_t* referance_motor ){
    DIO_u8_SetPinVal(referance_motor->port, referance_motor->Pin1, DIO_PIN_LOW);
    DIO_u8_SetPinVal(referance_motor->port, referance_motor->Pin0, DIO_PIN_HIGH);
}
void DCM_voidStop(DCM_Config_t* referance_motor ){
    DIO_u8_SetPinVal(referance_motor->port, referance_motor->Pin0, DIO_PIN_LOW);
    DIO_u8_SetPinVal(referance_motor->port, referance_motor->Pin1, DIO_PIN_LOW);
}

