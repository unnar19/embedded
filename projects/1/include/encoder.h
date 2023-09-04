#include <digital_in.h>

class Encoder
{
    private:
        Digital_in input_C1;
        Digital_in input_C2;

        bool value_C1;
        bool value_C2;

        bool old_value = 0;
        int pos_counter = 0;

    public:
        Encoder(int pin1, int pin2);
        void init();
        int position();



};
