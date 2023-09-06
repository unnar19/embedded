#include <Arduino.h>
#include <motor_encoder.cpp>
#include <avr/interrupt.h>
#include <digital_out.h>



int main(){
  Motor_Encoder enc(3, 4); // D3 and D4
  enc.init();
  while(1){
    enc.position();
    Digital_out led(5);
    led.init();
  }
}
