#include <avr/io.h>
#include <avr/interrupt.h>
#include <motor_encoder.h>

// ISR (INT0_vect);
Motor_Encoder::Motor_Encoder(int pin_1, int pin_2): input_C1(pin_1), input_C2(pin_2){   }

void Motor_Encoder::init(){
    input_C1.init();
    input_C2.init();

    prev_C1 = false;
    prev_C2 = false;

    DDRD &= ~(1 << DDD2);   //setting pin D2 as an input
    PORTD |= (1 << PORTD2); //enabling pull-up resistor on D2
    EICRA |= (1 << ISC00);  //setting INT0 to trigger on any logic change
    EIMSK |= (1 << INT0);   //Turning on INT0
    sei();                  //enabling interrupts
}



int Motor_Encoder::position(){
    current_C1 = input_C1.is_hi();
    current_C2 = input_C2.is_hi();

    if (current_C1 != prev_C1) {

        if (current_C2 != current_C1) {
            pos_counter++;
        } else {
            pos_counter--;
        }

    } 
    prev_C1 = current_C1;
    return pos_counter;
}



