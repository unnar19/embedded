#include <Arduino.h>
#include <avr/io.h>
#include <digital_in.h>

Digital_in::Digital_in(int PIN_NR){
    pinMask = (1 << PIN_NR); 
}

void Digital_in::init(){
    DDRD &= ~pinMask;  
    PORTD |= pinMask; 
}

bool Digital_in::is_hi(){
    bool isOpen = PIND & pinMask;
    return !isOpen;
}

bool Digital_in::is_lo(){
    bool isOpen = PIND & pinMask;
    return isOpen;
}