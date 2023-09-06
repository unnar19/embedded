#include <Arduino.h>
#include <avr/io.h>
#include <digital_in.cpp>

class Motor_Encoder {
    private:
    Digital_in input_C1;
    Digital_in input_C2;

    bool value_C1;
    bool value_C2;
    bool old_value;
    int pos_counter1;
    int pos_counter2;
         
    public:
    Motor_Encoder(int pin_1, int pin_2);
    void init();
    int position();
    

};