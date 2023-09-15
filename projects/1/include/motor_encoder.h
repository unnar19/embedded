#include <avr/io.h>
#include <digital_in.h>

class Motor_Encoder {
    private:
    Digital_in input_C1;
    Digital_in input_C2;

    bool value_C1;
    bool value_C2;

    bool prev_C1;
    bool prev_C2;

    bool current_C1;
    bool current_C2;

    int start_pos;
    int now_pos;
         
    public:
    int pos_counter = 0;
    Motor_Encoder(int pin_1, int pin_2);
    void init();
    int position();
    int velocity();
    

};