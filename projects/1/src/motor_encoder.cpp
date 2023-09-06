#include <Arduino.h>
#include <avr/io.h>
#include <motor_encoder.h>

// ISR (INT0_vect);
Motor_Encoder::Motor_Encoder(int pin_1, int pin_2): input_C1(pin_1), input_C2(pin_2){   }

void Motor_Encoder::init(){
    input_C1.init();
    input_C2.init();
    DDRD &= ~(1 << DDD2);   //setting pin D2 as an input
    PORTD |= (1 << PORTD2); //enabling pull-up resistor on D2
    EICRA |= (1 << ISC00);  //setting INT0 to trigger on any logic change
    EIMSK |= (1 << INT0);   //Turning on INT0
    sei();                  //enabling interrupts
}

int Motor_Encoder::position(){

    if (input_C1.is_hi()) {
        if(input_C2.is_lo()){
            pos_counter += 1;
        }
        else{
            pos_counter -= 1;
        }
    } 
    else {
        if(input_C2.is_hi()){
            pos_counter += 1;
        }
        else{
            pos_counter -= 1;
        }
    }
    return pos_counter;
}

