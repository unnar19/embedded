#include <P_controller.h>
#include <Arduino.h>
#include <avr/interrupt.h>


P_controller::P_controller() : enc(4,5,1){}

void P_controller::init(){
    enc.init();
    enc.init_pwm(4);
}

double P_controller::find_speed(){
    return abs(enc.velocity());
}

double P_controller::update(double ref, double actual){
    e = ref - actual;
    u = Kp * e;
    enc.set_pwm(u/1400.0);
    return u;
}