#include <digital_out.h>

Digital_out::Digital_out(int PIN_NR){
    pinMask = (1 << PIN_NR); //Þarf að breyta þessu í hex, spurja kennara
}

void Digital_out::init(){
    DDRB |= pinMask;
}

void Digital_out::set_hi(){
    PORTB |= pinMask;
}

void Digital_out::set_lo(){
    PORTB &= ~pinMask;
}

void Digital_out::toggle(){
    PORTB ^= pinMask;
}