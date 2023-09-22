#include <Analog_out.h>

Analog_out::Analog_out(int pin) : pin(pin) {}


void Analog_out::init(int period_ms){
    pin.init();
    timer.init(period_ms);
}
void Analog_out::set(float duty_cycle){
    timer.set_duty_cycle(duty_cycle);
}

