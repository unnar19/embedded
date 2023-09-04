#include <avr/io.h>
#include <digital_in.h>

Digital_in::Digital_in(int pin) {
    PDX = pin;
}

void Digital_in::init() {
    DDRD &= ~(1 << PDX);
    PORTD |= (1 << PDX);
}

bool Digital_in::is_hi() {
    return PIND & (1 << PDX);
}

bool Digital_in::is_lo() {
    return !(PIND & (1 << PDX));

}
