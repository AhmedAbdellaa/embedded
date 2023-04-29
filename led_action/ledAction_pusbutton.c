#include <avr/io.h>
#include <util/delay.h>
#include "leds.h"


void main()
{
    // set pins as outputs
    DDRC = 0xff;  // port A as output
    PORTC = 0x00; // port a as low

    DDRD = 0x00; // port d as input
    uint8 status0, status1, status2;
    // loop
    while (1)
    {
        // get button status
        status0 = GET_BIT(PIND, 2);
        status1 = GET_BIT(PIND, 3);
        status2 = GET_BIT(PIND, 4);
        // debounsing push button
        _delay_ms(250);
        if (status0 == 0)
            if (status1 == 0)
            {
                if (status2 == 0)
                {
                    flashing(); // 000
                }
                else
                {
                    shiftleft(); // 001
                }
            }
            else
            {
                if (status2 == 0)
                {
                    shiftright(); // 010
                }
                else
                {
                    converging(); // 011
                }
            }
        else if (status1 == 0)
        {
            if (status2 == 0)
            {
                diverging(); // 100
            }
            else
            {
                pingpong(); // 101
            }
        }
        else
        {
            if (status2 == 0)
            {
                PORTC = 0x00;
                incrementing(); // 110
            }
            else
            {
                converging_diverging(); // 111
            }
        }
    }
}
