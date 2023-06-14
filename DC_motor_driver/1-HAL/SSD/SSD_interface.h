#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H

typedef enum SSD_ConType_t{
    SSD_ComCathod,SSD_ComAnod,SSD_ETA_KIT
}SSD_ConType_t;
typedef struct SSD_Config_t
{
    SSD_ConType_t type;
    DIO_port_t port;
    DIO_pin_t LEDAPin;
    DIO_port_t enable_port;
    DIO_pin_t enable_Pin;
}SSD_Config_t;



uint8 SSD_u8SetNumber(const SSD_Config_t* copy_SSD_Object,uint8 copy_u8Number);
uint8 SSD_u8Enable(const SSD_Config_t* copy_SSD_Object);
uint8 SSD_u8Disable(const SSD_Config_t* copy_SSD_Object);

#endif
