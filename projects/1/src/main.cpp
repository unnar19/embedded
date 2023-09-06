#include <Arduino.h>
#include <avr/io.h>
#include <motor_encoder.cpp>
#include <avr/interrupt.h>
#include <digital_out.h>

int position;

// ISR (INT0_vect);

int main(){
  double PPS_encoder = ((155/100)*1400)/60;
  double sleep_time_ms = (1/PPS_encoder)/1000;
  Motor_Encoder enc(3, 4); // D3 and D4
  enc.init();
  Digital_out led(5);
  led.init();
  while(1){
    unsigned long start_time = millis();
    while(millis() - start_time > 5000){ 
      led.set_lo();
      unsigned long last_run = millis();
      if (millis() - last_run > sleep_time_ms){
        last_run = millis();
        position = enc.position();
      }
      Serial.print("Current position count: ");
      Serial.print(position);
    }
    led.set_hi();
  }
  return 0;
}


// ISR (INT0_vect) {
//   position = enc.position();
// }
