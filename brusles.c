#include <xc.h>
#include"brusles.h"
#include "delay.h"
#include "delay.c"
void configurazione(void);
unsigned char combinazioni [] = {
    0b00100010,
    0b00100001,
    0b00010001,
    0b00010100,
    0b00001100,
    0b00001010,
};
unsigned char giro = 0;
unsigned char ritardo = 10;

void main(void) {
    configurazione();
    ritardo = 10;
    while (1) {
        for (unsigned char i = 0; i < 6; i++) {
            PORTB = combinazioni [i];
            delay_ms(ritardo);
        }
        if (giro = 3) {
            ritardo = ritardo--;
        }
        giro = giro++;
    }
}

void configurazione(void) {
    LATA = 0x00;
    TRISA = 0xff; //PORTA all input

    LATB = 0x00;
    TRISB = 0x00; //PORTB ALL OUTPUTS

}