#ifndef UART_INTERFACE
#define UART_INTERFACE

void UART_voidInit(void);
void UART_voidTransmit(uint8 copy_u8Data);
uint8 UART_voidReceive(void);

void UART_VoidPrintChars(const uint8* copy_u8charArray);
void UART_VoidPrintInt(sint32 copy_s32number);
void UART_VoidPrintFloat(f64 copy_f64number);
#endif
