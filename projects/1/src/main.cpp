#include <Arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include <motor_encoder.h>
#include <digital_out.h>


// ISR (INT0_vect);
int main() {
  double rpm = 155;
  double rps = rpm/60.0;
  double ratio = 100;
  double ppr = 14;

  Serial.begin(115200);
  double PPS_encoder = rps*ppr*ratio; // Pulses per sec
  double sleep_time_us = 1000000.0/PPS_encoder;

  Motor_Encoder enc(3, 4); // D3 and D4
  Digital_out led(5); // Onboard led

  enc.init();
  led.init();

  while(1) {
    _delay_us(sleep_time_us);

    led.set_lo();
    //enc.position();               // Part 1
    Serial.println(enc.position()); // Part 2
    //_delay_us(sleep_time_us);
    led.set_hi();

  }

  return 0;
}


// ISR (INT0_vect) {
//   position = enc.position();
// }
