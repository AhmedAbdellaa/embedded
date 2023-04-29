#include <avr/io.h>
#include <util/delay.h>
#include "STD_TYPES_H.h"
#include "BIT_MATH.h"

uint8 ssd_arr[10] = {0x7E, 0x0C, 0xB6, 0x9E, 0xCC, 0xDA, 0xFA, 0x0E, 0xFE, 0xDE};

void displayNumberred(char ones, char tens)
{

    PORTC = 0x41;
    PORTA = ssd_arr[ones];
    _delay_ms(1);
    PORTC = 0x81;
    PORTA = ssd_arr[tens];
    _delay_ms(1);
}
void displayNumbergreen(char ones, char tens)
{

    PORTC = 0x42;
    PORTA = ssd_arr[ones];
    _delay_ms(1);
    PORTC = 0x82;
    PORTA = ssd_arr[tens];
    _delay_ms(1);
}
void displayNumberblue(char ones, char tens)
{

    PORTC = 0x44;
    PORTA = ssd_arr[ones];
    _delay_ms(1);
    PORTC = 0x84;
    PORTA = ssd_arr[tens];
    _delay_ms(1);
}
void main()
{
    // 7SEG leds
    DDRA = 0xFF;
    PORTA = 0X00;
    // common 1,2 C6,C7 INPUT , 0,1,2 OUTPUT
    DDRC = 0B00000111;
    PORTC = 0X00;

    uint8 i = 0;
    uint16 j;
    uint8 ones, tens;
    while (1)
    {
        // RED
        for (i = 0; i < 15; i++)
        {
            ones = i % 10;
            tens = i / 10;
            for (j = 0; j < 450; j++)
            {

                displayNumberred(ones, tens);
            }
        }
        // GREEN
        for (i = 0; i < 15; i++)
        {
            ones = i % 10;
            tens = i / 10;
            for (j = 0; j < 450; j++)
            {

                displayNumbergreen(ones, tens);
            }
        }
        // YELLOW
        for (i = 0; i < 3; i++)
        {
            ones = i % 10;
            tens = i / 10;
            for (j = 0; j < 450; j++)
            {
                displayNumberblue(ones, tens);
            }
        }
    }
}