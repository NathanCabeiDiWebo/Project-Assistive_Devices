/*
Code geschreven door Jordy de Vries (22082115)
*/

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    setup();
    int counter = 0;
    while (1)
    {
        if ((PINF & (1 << PF1)) == 0)
        {
            if ((PINF & (1 << PF2)) == 0)
            {
                counter = counter + 1;
                _delay_ms(20);
            }
            else
            {
                counter = counter - 1;
                _delay_ms(20);
            }
        }

        if (counter > 0)
        {
            PORTB |= (1 << PB7);
        }
        else
        {
            PORTB &= ~(1 << PB7);
        }
    }
}

void setup()
{
    DDRF &= ~(1 << PF1) | (1 << PF2); // PIN A (CLK) en PIN B (DT) op A1 en A2
    DDRB |= (1 << PB7);               // PIN 13 voor de LED
    PORTB &= ~(1 << PB7);             // Initialiseer laag

    // SW op reset om te resetten met de rotary
}