#include <avr/io.h>
#include <util/delay.h>
#include "leds.h"

void flashing()
{
    _delay_ms(500);
    PORTC = 0x00;
    _delay_ms(500);
    PORTC = 0xff;
}
void shiftleft()
{

    uint8 i = 0;
    while (i < 8)
    {
        SET_BIT(PORTC, i);
        _delay_ms(250);
        CLS_BIT(PORTC, i);
        i++;
    }
}
void shiftright()
{
    uint8 i = 7;
    while (i > 0)
    {
        SET_BIT(PORTC, i);
        _delay_ms(250);
        CLS_BIT(PORTC, i);
        i--;
    }
}
void converging()
{

    uint8 i = 0;
    // loop
    while (i < 4)
    {
        SET_BIT(PORTC, i);
        SET_BIT(PORTC, 7 - i);
        _delay_ms(300);
        CLS_BIT(PORTC, i);
        CLS_BIT(PORTC, 7 - i);
        i++;
    }
}
void diverging()
{
    sint8 i = 3;
    // loop
    while (i >= 0)
    {
        SET_BIT(PORTC, i);
        SET_BIT(PORTC, 7 - i);
        _delay_ms(300);
        CLS_BIT(PORTC, i);
        CLS_BIT(PORTC, 7 - i);
        i--;
    }
}
void pingpong()
{
    shiftleft();
    shiftright();
}
void incrementing()
{
    uint8 i = 0;
    // loop
    while (i < 8)
    {
        SET_BIT(PORTC, i);
        _delay_ms(300);
        i++;
    }
}
void converging_diverging()
{
    converging();
    diverging();
}
