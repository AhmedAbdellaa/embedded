
#include "../../libraries/BIT_MATH.h"
#include "../../libraries/ErrType.h"
#include "../../libraries/STD_TYPES_H.h"
#include "./UART_interface.h" 
#include "UART_reg.h"
#include "UART_prv.h"
#include "UART_cfg.h"
void UART_voidInit(void){
	uint8 Local_u8USRCVal = 0u;

	/*Transmitter enable*/
	SET_BIT(UCSRB,UCSRB_TXEN);
	/*Receiver enable*/
	SET_BIT(UCSRB,UCSRB_RXEN);
	/*Async mode*/
	CLS_BIT(Local_u8USRCVal,UCSRC_UMSEL);
	/*Disable parity*/
	CLS_BIT(Local_u8USRCVal,UCSRC_UPM0);
	CLS_BIT(Local_u8USRCVal,UCSRC_UPM1);
	/*1-STOP BIT*/
	CLS_BIT(Local_u8USRCVal,UCSRC_USBS); 

	/*CHARCTER Size :8bits*/
	SET_BIT(Local_u8USRCVal,UCSRC_UCSZ0); 
	SET_BIT(Local_u8USRCVal,UCSRC_UCSZ1); 
	
	/*Register select: USRC*/
	SET_BIT(Local_u8USRCVal,UCSRC_URSEL);
	UCSRC = Local_u8USRCVal;
	/*Baud rate: 9600bps*/
	UBRRL = 103U;
}

void UART_voidTransmit(uint8 copy_u8Data){
	/*wait until transmit buffer is redy*/
	while((GET_BIT(UCSRA,UCSRA_UDRE))==0);

	UDR = copy_u8Data;
}
uint8 UART_voidReceive(void){
	/*wait until there is data in the receive buffer*/
	while((GET_BIT(UCSRA,UCSRA_RXC))==0);
	return UDR;
}

void UART_VoidPrintChars(const uint8* copy_u8charArray){
	uint8 Local_u8strCounter=0u;
	while(copy_u8charArray[Local_u8strCounter] != '\0'){
		UART_voidTransmit(copy_u8charArray[Local_u8strCounter]);
		Local_u8strCounter++;
	}
}

static void _helper_VoidNumToStr(sint32 copy_s32number){

	uint8 Local_u8Buffer[11];

    if (copy_s32number==0){
    	Local_u8Buffer[0]='0';
    	Local_u8Buffer[1]='\0';
        return;
    }

    uint8 Local_s8counter = 0;
    sint8 Local_s8PrintCounter;
    uint8 Local_s8MFlag = 0;

    if(copy_s32number<0){
    	Local_u8Buffer[Local_s8counter]='-';
            Local_s8counter++;
            copy_s32number *=-1;
            Local_s8MFlag = 1;
    }
	while(copy_s32number){
        //printf("%d ",copy_s32number);

		Local_u8Buffer[Local_s8counter]=(copy_s32number%10)+48;
		//printf("%d ",ref_u8Buffer[Local_u8counter]);
		copy_s32number /=10;
		Local_s8counter++;

	}
    Local_u8Buffer[Local_s8counter]='\0';

    for(Local_s8PrintCounter = Local_s8counter-1 ;Local_s8PrintCounter>=Local_s8MFlag;Local_s8PrintCounter-- ){
    	UART_voidTransmit(Local_u8Buffer[Local_s8PrintCounter]);
    }
}

void UART_VoidPrintInt(sint32 copy_s32number){
	_helper_VoidNumToStr(copy_s32number);
}

void UART_VoidPrintFloat(f64 copy_f64number){
	sint32 Local_s32IntegerPart = (sint32)copy_f64number;
	_helper_VoidNumToStr(Local_s32IntegerPart);
	UART_voidTransmit('.');
	_helper_VoidNumToStr((sint32)((copy_f64number-Local_s32IntegerPart)*10000));

}
