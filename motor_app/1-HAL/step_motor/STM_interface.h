#ifndef STM_INTERFACE_H
#define STM_INTERFACE_H

typedef enum STM_DIRECTION_t{
    STM_CLOCK_WISE, STM_COUNTER_CLOCK_WISE
}STM_DIRECTION_t;

typedef struct STM_CONFIG_t
{
    DIO_port_t port;
    DIO_pin_t bluePin;
    DIO_pin_t pinkPin;
    DIO_pin_t yellowPin;
    DIO_pin_t orangePin;
}STM_CONFIG_t;

uint8 STM_u8Rotate(const STM_CONFIG_t* referance_stepper, uint16 copy_u16angle,STM_DIRECTION_t copy_STMdirection);

#endif
