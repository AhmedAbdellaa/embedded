#ifndef HAMO_PRV_H
#define HAMO_PRV_H

//special characters
uint8 MOVEZERO[]={0X0E,0X0E,0X05,0X0E,0X0C,0X04,0X06,0X05};
uint8 MOVEONE[]={0X0E,0X0E,0X04,0X0E,0X16,0X04,0X0C,0X14};


uint8 DANCE0[] = {0x0E,0x0E,0x15,0x0E,0x04,0x04,0x0E,0x11};
uint8 DANCE1[] = {0x0E,0x0E,0x04,0x0E,0x15,0x04,0x0E,0x0A};
uint8 DANCE2[] = {0x0E,0x0E,0x04,0x0E,0x0D,0x04,0x0E,0x12};
uint8 DANCE3[] = {0x0E,0x0E,0x04,0x0E,0x16,0x04,0x0E,0x09};

uint8 RUN0[] = {0x0E,0x0E,0x04,0x0E,0x0D,0x04,0x0E,0x0A};
uint8 RUN1[] = {0x0E,0x0E,0x04,0x0E,0x0E,0x04,0x06,0x05};
uint8 PASSUP[] = {0x0E,0x0E,0x04,0x0E,0x0C,0x04,0x07,0x04};
uint8 BALLDOWN[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18};
uint8 BALLUP[] = {0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00};

uint8 STAND[]= {0x0E,0x0E,0X04,0X0E,0X15,0X04,0X0A,0X0A};
uint8 GUN[] = {0x00,0x1F,0x1F,0x14,0x1C,0x18,0x18,0x00};
uint8 BULLET[] = {0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00};
uint8 BODYFIRSTHALF[] = {0x00,0x05,0x0A,0x00,0x16,0x07,0x06,0x10};
uint8 BODYSECONDHALF[] = {0x00,0x00,0x00,0x09,0x12,0x1E,0x12,0x09};

void _voidIniWalk();
void _voidIniDance();
void _voidIniBall();
void _voidIniKill();
#endif
