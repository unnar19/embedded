#include <avr/io.h>

class Digital_out{
    public:

    Digital_out(int PIN_NR);
    void init();
    void set_hi();
    void set_lo();
    void toggle();

    private:
    uint8_t pinMask;
};

Digital_out::Digital_out(int PIN_NR){
    pinMask = (1 << PIN_NR); //Þarf að breyta þessu í hex, spurja kennara
}

void Digital_out::init(){
    DDRB |= pinMask;
    set_hi(); 
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