/*
Code geschreven door Jordy de Vries (22082115)
*/

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    setup();
    int counter = 1;
    int limit;
    while(1)
    {
        limit = counter;
        if((PINF &(1<<PF1)) == 0)
        {
            if((PINF &(1<<PF2)) == 0)
            {
                if(limit < 5)
                {
                    counter = counter + 1;
                    _delay_ms(40);
                }
                if(limit > 4)
                {
                    counter = counter;
                    _delay_ms(30);
                }
            }
            else
            {
                if(limit > 1)
                {
                    counter = counter - 1;
                    _delay_ms(40);
                }
                if(limit < 2)
                {
                    counter = counter;
                    _delay_ms(30);
                }
            }
        }

        switch (counter)
        {
        case 1:
            PORTB |= (1<<PB7);

            PORTB &= ~(1<<PB6) & (1<<PB5) & (1<<PB4) & (1<<PB3);
            break;

        case 2:
            PORTB |= (1<<PB6) | (1<<PB7);

            PORTB &= ~(1<<PB5) & (1<<PB4) & (1<<PB3);
            break;

        case 3:
            PORTB |= (1<<PB5) | (1<<PB6) | (1<<PB7);

            PORTB &= ~(1<<PB4) & (1<<PB3);
            break;

        case 4:
            PORTB |= (1<<PB4) | (1<<PB5) | (1<<PB6) | (1<<PB7);

            PORTB &= ~(1<<PB3);
            break;

        case 5:
            PORTB |= (1<<PB3) | (1<<PB4) | (1<<PB5) | (1<<PB6) | (1<<PB7);
            break;
        }
        if((PINF &(1<<PF3)) == 0)
        {

        }
    }
}

void setup()
{
    DDRF &= ~(1<<PF1) | (1<<PF2) | (1<<PF3); // PIN A (CLK) en PIN B (DT) op A1 en A2
    DDRB |= (1<<PB7) | (1<<PB6) | (1<<PB5) | (1<<PB4) | (1<<PB3);       //PIN 13 voor de LED
    //PORTB &= ~(1<<PB7);     //Initialiseer laag

    //SW op reset om te resetten met de rotary
}
