#ifndef CLCD_INTERFACE_H
#define CLCD_INTERFACE_H

void CLCD_VoidSendCommand(uint8 copy_u8command);
void CLCD_VoidSendData(uint8 copy_u8Data);
void CLCD_VoidInit(void);

#endif