#include <Arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <motor_encoder.h>
#include <digital_out.h>

Motor_Encoder enc(4, 5); // D3 and D4
Digital_out led(5); // Onboard led


 ISR (INT0_vect);

int main() {

  Serial.begin(115200); 
  enc.init();
  led.init();

  while(1) {
    Serial.println(enc.velocity());
  }

  return 0;
}

ISR (INT0_vect) {
  enc.position();
  led.toggle();
}
