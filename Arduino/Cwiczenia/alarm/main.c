#define F_CPU 16000000UL // Częstotliwość zegara (16MHz dla Uno)
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
 
    DDRB |= (1 << PB5);  //ustawia PB5 (13) jako wyjscie (dioda)
    DDRD &= ~(1 << PD2); //usawia PD2 (2) jako wejscie (buzzer)
    DDRB |= (1 << PB4);  //ustawia PB3 (12) jako wyjscie (dioda)

    while (1) {
        if (PIND & (1 << PD2)) { //Sprawdza, czy na wejściu PD2 (pin 2) pojawił się stan wysoki
            PORTB |= (1 << PB5); //Włącza diodę LED
            PORTB |= (1 << PB4); //Włacza diodę buzzer
            
        }else {
            PORTB &= ~(1 << PB5); //Wylacza diodę LED
            PORTB &= ~(1 << PB4); //ylacza diodę buzzer
        }

        _delay_ms(50);
    }

    return 0;
}