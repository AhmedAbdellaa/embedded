#include "./libraries/STD_TYPES_H.h"
#include "./libraries/BIT_MATH.h"
#include "DIO_reg.h"
#include "DIO_interface.h"

#include "ErrType.h"

uint8 dio_u8_setPinDir(DIO_port_t copy_port, DIO_pin_t copy_pinNum, DIO_pinDir_t copy_pinDir){
    uint8 Local_u8ErrorState = OK;
    if((copy_pinNum >= DIO_PIN0)  && (copy_pinNum<DIO_PIN7)){

        if(copy_pinDir == DIO_INPUT){
            switch (copy_port)
            {
            case DIO_PORTA : CLS_BIT(DDRA,copy_pinNum); break;
            case DIO_PORTB : CLS_BIT(DDRB,copy_pinNum); break;
            case DIO_PORTC : CLS_BIT(DDRC,copy_pinNum); break;
            case DIO_PORTD : CLS_BIT(DDRD,copy_pinNum); break;
            
            default: Local_u8ErrorState = NOK;  break;
            }
        }   
        else if(copy_pinDir == DIO_OUTPUT){
             switch (copy_port)
            {
            case DIO_PORTA : SET_BIT(DDRA,copy_pinNum); break;
            case DIO_PORTB : SET_BIT(DDRB,copy_pinNum); break;
            case DIO_PORTC : SET_BIT(DDRC,copy_pinNum); break;
            case DIO_PORTD : SET_BIT(DDRD,copy_pinNum); break;
            
            default: Local_u8ErrorState = NOK;  break;
            }
        }else
        Local_u8ErrorState = NOK;
    }else 
    Local_u8ErrorState = NOK;
    return Local_u8ErrorState;

}
uint8 dio_u8_setPortDir(DIO_port_t copy_port,  DIO_pinDir_t copy_pinDir){
    uint8 Local_u8ErrorState = OK;
        if(copy_pinDir == DIO_INPUT){
            switch (copy_port)
            {
            case DIO_PORTA :DDRA = 0x00; break;
            case DIO_PORTB :DDRB = 0x00; break;
            case DIO_PORTC :DDRC = 0x00; break;
            case DIO_PORTD :DDRD = 0x00; break;
            
            default: Local_u8ErrorState = NOK;  break;
            }
        }   
        else if(copy_pinDir == DIO_OUTPUT){
             switch (copy_port)
            {
            case DIO_PORTA : DDRA = 0xFF; break;
            case DIO_PORTB : DDRB = 0xFF; break;
            case DIO_PORTC : DDRC = 0xFF; break;
            case DIO_PORTD : DDRD = 0xFF; break;
            
            default: Local_u8ErrorState = NOK;  break;
            }
        }else
        Local_u8ErrorState = NOK;
    
    return Local_u8ErrorState;

}

uint8 dio_u8_setPinVal(DIO_port_t copy_port, DIO_pin_t copy_pinNum, DIO_pinVal_t copy_pinVal){
uint8 Local_u8ErrorState = OK;
    if((copy_pinNum >= DIO_PIN0)  && (copy_pinNum<DIO_PIN7)){

        if(copy_pinVal == DIO_LOW){
            switch (copy_port)
            {
            case DIO_PORTA : CLS_BIT(PORTA,copy_pinNum); break;
            case DIO_PORTB : CLS_BIT(PORTB,copy_pinNum); break;
            case DIO_PORTC : CLS_BIT(PORTC,copy_pinNum); break;
            case DIO_PORTD : CLS_BIT(PORTD,copy_pinNum); break;
            
            default: Local_u8ErrorState = NOK;  break;
            }
        }   
        else if(copy_pinVal == DIO_HIGH){
             switch (copy_port)
            {
            case DIO_PORTA : SET_BIT(PORTA,copy_pinNum); break;
            case DIO_PORTB : SET_BIT(PORTB,copy_pinNum); break;
            case DIO_PORTC : SET_BIT(PORTC,copy_pinNum); break;
            case DIO_PORTD : SET_BIT(PORTD,copy_pinNum); break;
            
            default: Local_u8ErrorState = NOK;  break;
            }
        }else
        Local_u8ErrorState = NOK;
    }else 
    Local_u8ErrorState = NOK;
    return Local_u8ErrorState;

}
uint8 dio_u8_setPortVal(DIO_port_t copy_port,  DIO_pinVal_t copy_pinVal){
    uint8 Local_u8ErrorState = OK;
        if(copy_pinVal == DIO_LOW){
            switch (copy_port)
            {
            case DIO_PORTA :PORTA = 0x00; break;
            case DIO_PORTB :PORTB = 0x00; break;
            case DIO_PORTC :PORTC = 0x00; break;
            case DIO_PORTD :PORTD = 0x00; break;
            
            default: Local_u8ErrorState = NOK;  break;
            }
        }   
        else if(copy_pinVal == DIO_HIGH){
             switch (copy_port)
            {
            case DIO_PORTA : PORTA = 0xFF; break;
            case DIO_PORTB : PORTB = 0xFF; break;
            case DIO_PORTC : PORTC = 0xFF; break;
            case DIO_PORTD : PORTD = 0xFF; break;
            
            default: Local_u8ErrorState = NOK;  break;
            }
        }else
        Local_u8ErrorState = NOK;
    
    return Local_u8ErrorState;

}

uint8 dio_u8_getPinVal(DIO_port_t copy_port, DIO_pin_t copy_pinNum, DIO_pinVal_t *copy_pinVal){
    uint8 Local_u8ErrorState = OK;
    if(*copy_pinVal !=NULL){
        if((copy_pinNum >= DIO_PIN0)  && (copy_pinNum<DIO_PIN7)){
            switch (copy_port)
            {
            case DIO_PORTA : *copy_pinVal = GET_BIT(PINA,copy_pinNum); break;
            case DIO_PORTB : *copy_pinVal = GET_BIT(PINB,copy_pinNum); break;
            case DIO_PORTC : *copy_pinVal = GET_BIT(PINC,copy_pinNum); break;
            case DIO_PORTD : *copy_pinVal = GET_BIT(PIND,copy_pinNum); break;
            
            default: Local_u8ErrorState = NOK;  break;
            }
            
        }else 
            Local_u8ErrorState = NOK;
    }
    else
        Local_u8ErrorState = NULL_PTR;
    return Local_u8ErrorState;
}
