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
    return PIND & pinMask;
}

bool Digital_in::is_lo(){
    return !is_hi();
}