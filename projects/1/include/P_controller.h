#pragma once
#include <motor_encoder.h>

class P_controller {
    private:
        double Kp = 0.8;
        double e;
        double u;
         
    public:
        P_controller();
        Motor_Encoder enc; // D3 and D4
        void init();
        double find_speed();
        double update(double ref, double actual);

};


