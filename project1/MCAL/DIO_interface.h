#ifndef DIO_INTERFACE
#define DIO_INTERFACE

typedef enum DIO_port_t{
    DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD
}DIO_port_t;

typedef enum DIO_pin_t{
    DIO_PIN0,DIO_PIN1,DIO_PIN2,DIO_PIN3,
    DIO_PIN4,DIO_PIN5,DIO_PIN6,DIO_PIN7
}DIO_pin_t;

typedef enum DIO_pinDir_t{
    DIO_INPUT,DIO_OUTPUT
}DIO_pinDir_t;

typedef enum DIO_pinVal_t{
    DIO_LOW, DIO_HIGH
}DIO_pinVal_t;


uint8 dio_u8_setPinDir(DIO_port_t copy_port, DIO_pin_t copy_pinNum, DIO_pinDir_t copy_pinDir);
uint8 dio_u8_setPortDir(DIO_port_t copy_port,  uint8 copy_pinDir);

uint8 dio_u8_setPinVal(DIO_port_t copy_port, DIO_pin_t copy_pinNum, DIO_pinVal_t copy_pinVal);
uint8 dio_u8_setPortVal(DIO_port_t copy_port,  uint8 copy_pinVal);

uint8 dio_u8_getPinVal(DIO_port_t copy_port, DIO_pin_t copy_pinNum, DIO_pinVal_t *copy_pinVal);

#endif