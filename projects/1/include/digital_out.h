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

