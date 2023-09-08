#include <Arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include <motor_encoder.h>
#include <digital_out.h>

Motor_Encoder enc(4, 5); // D3 and D4
Digital_out led(5); // Onboard led


 ISR (INT0_vect);

int main() {
  // double rpm = 155;       //Part 1 and 2
  // double rps = rpm/60.0;       //Part 1 and 2
  // double ratio = 100;       //Part 1 and 2
  // double ppr = 14;       //Part 1 and 2

   Serial.begin(115200);       //Part 1 and 2
  // double PPS_encoder = rps*ppr*ratio; // Pulses per sec       //Part 1 and 2

  // double sleep_time_us = 1000000.0/PPS_encoder;       //Part 1 and 2

  enc.init();
  led.init();

  while(1) {
    // _delay_us(sleep_time_us);       //Part 1 and 2

    // led.set_lo();                   //Part 1 and 2
    //enc.position();                  // Part 1
    // Serial.println(enc.position()); // Part 2
    //_delay_us(sleep_time_us);        // Used in Part 1
    // led.set_hi();                   // Part 1 and 2
    _delay_ms(500);
    Serial.println(enc.pos_counter);
  }

  return 0;
}

ISR (INT0_vect) {
  enc.position();
  led.toggle();
}
