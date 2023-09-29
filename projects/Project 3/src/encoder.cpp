#include <encoder.h>

Encoder::Encoder(int pin1, int pin2) : input_C1(pin1), input_C2(pin2) { }

void Encoder::init() {
    input_C1.init();
    input_C2.init();
}

int Encoder::position() {
    value_C1 = input_C1.is_lo();

    if (old_value != value_C1) {
        pos_counter += 1;
    }

    old_value = value_C1;

    return pos_counter;
}
