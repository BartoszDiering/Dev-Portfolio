#define F_CPU 16000000UL // Częstotliwość zegara (16MHz dla Uno)
#include <avr/io.h>
#include <util/delay.h>

int main(void) {

    DDRB |= (1 << PB5); 
    DDRD &= ~(1 << PD2);
    DDRB |= (1 << PB4); 

    while (1) {
        if (PIND & (1 << PD2)) {
    PORTB |= (1 << PB5); // LED świeci
    
    // Generowanie dźwięku dla buzzera PASYWNEGO
    // Szybkie włączanie i wyłączanie pinu PB4
    for(int i=0; i<100; i++) {
        PORTB |= (1 << PB4);  // Włącz
        _delay_us(10000);       // Czekaj 0.5ms
        PORTB &= ~(1 << PB4); // Wyłącz
        _delay_us(10000);       // Czekaj 0.5ms
    }
}
        else {
            // Jeśli brak ruchu -> Zgaś diodę na PB5
            PORTB &= ~(1 << PB5);
            PORTB &= ~(1 << PB4);
        }

        _delay_ms(50); // Małe opóźnienie dla stabilności
    }

    return 0;
}