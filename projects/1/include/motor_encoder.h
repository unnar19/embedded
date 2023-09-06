#include <avr/io.h>
#include <digital_in.h>

class Motor_Encoder {
    private:
    Digital_in input_C1;
    Digital_in input_C2;

    bool value_C1;
    bool value_C2;
    int pos_counter;
         
    public:
    Motor_Encoder(int pin_1, int pin_2);
    void init();
    int position();
    

};