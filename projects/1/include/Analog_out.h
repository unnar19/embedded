#pragma once
#include <timer_msec.h>
#include <digital_out.h>

class Analog_out
{
public:
    Analog_out(int pin);
    void init(int period_ms = 1000);
    void set(float duty_cycle);

private:
    Timer_msec timer;

public:    
    Digital_out pin;
};