#include "STD_TYPES_H.h"
#include <util/delay.h>
#include "BIT_MATH.h"
#include "ErrType.h"

#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_cfg.h"
#include "CLCD_prv.h"

void CLCD_VoidSendCommand(uint8 copy_u8command){
    // 1-set RS pin to low for command 
    dio_u8_setPinVal(CLCD_u8CTRL_PORT, CLCD_u8RS_PIN, DIO_LOW)
    // 2-set Rw pin to low for write
    dio_u8_setPinVal(CLCD_u8CTRL_PORT, CLCD_u8RW_PIN, DIO_LOW)
    // 3- send the command
    dio_u8_setPortVal(CLCD_u8DATA_PORT, copy_u8command)
    // 4- send enable pulse
    dio_u8_setPinVal(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_HIGH)
    _delay_ms(2);
    dio_u8_setPinVal(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_LOW)

}
void CLCD_VoidSendData(uint8 copy_u8Data){
    // 1-set RS pin to low for command 
    dio_u8_setPinVal(CLCD_u8CTRL_PORT, CLCD_u8RS_PIN, DIO_HIGH)
    // 2-set Rw pin to low for write
    dio_u8_setPinVal(CLCD_u8CTRL_PORT, CLCD_u8RW_PIN, DIO_LOW)
    // 3- send the command
    dio_u8_setPortVal(CLCD_u8DATA_PORT, copy_u8command)
    // 4- send enable pulse
    dio_u8_setPinVal(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_HIGH)
    _delay_ms(2);
    dio_u8_setPinVal(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_LOW)
}
void CLCD_VoidInit(void){
    // 1- wait for more than 30ms after poweron
    _delay_ms(40)
    //2- function set command :2 lines, font size 5*7
    CLCD_VoidSendCommand(0b00110000);
    //3- Display on/off control: display on ,cursor off, blink cursor off 
    CLCD_VoidSendCommand(0b00001100);
    //4- Display clear 
    CLCD_VoidSendCommand(1)
}