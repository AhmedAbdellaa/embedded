#ifndef DCM_INTERFACE_H
#define DCM_INTERFACE_H


typedef struct DCM_Config_t
{
    DIO_port_t port;
    DIO_pin_t Pin0;
    DIO_pin_t Pin1;
}DCM_Config_t;

void DCM_voidRotateCW(DCM_Config_t* referance_motor );
void DCM_voidRotateCCW(DCM_Config_t* referance_motor );
void DCM_voidStop(DCM_Config_t* referance_motor );

#endif
