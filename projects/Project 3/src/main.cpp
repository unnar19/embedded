#include <Arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <motor_encoder.h>
#include <digital_out.h>
#include <P_controller.h>

  //ISR (INT0_vect);

// Digital_out led(5); // Onboard led
P_controller motor;

int main() {


  // Digital_out motor(2); // Part 2  // int started = 0; // Part 2

  const int max_t = 100;
  double y[max_t];
  double u[max_t];

  Serial.begin(115200); 
  // led.init();

  // motor.init(); // Part 2
  // int index = 0; // Part 2
  // int recorder[10]; // Part 2


  float r[max_t];
  for (int i = 0; i < max_t; i++) {
    r[i] = -((14.0/25)*(i-50)*(i-50)) + 1400;
  }

  int t = 0; // Part 4
  while(1) {
    
    y[t]= motor.find_speed();
    u[t] = motor.update(r[t], y[t]);


    if (t == (max_t - 1)) {
      t = 0;
      for (int i = 0; i < 100; i++) {
        Serial.print("t = ");
        Serial.print((1+i)*4);
        Serial.print("ms, ref value = ");
        Serial.print(r[i]);
        Serial.print("pps, actual value =");
        Serial.print(y[i]);
        Serial.print("pps, PWM value =");
        Serial.print(u[i]);
        Serial.println("pps");
      }
    } else {
      t = t + 1;
    }
    // Part 2
  //   if (!started){
  //     motor.set_hi();
  //     started = 1;
  //   }
  //   if (started) {
  //     recorder[index] = enc.velocity();
      
  //     if (index == 9) {
  //       Serial.println("Measurement vvv");
  //       for (int i = 0; i < 10; i++) {
  //         Serial.print("t = ");
  //         Serial.print(i*10);
  //         Serial.print("ms, speed = ");
  //         Serial.print(recorder[i]);
  //         Serial.println("pulses per second");
  //       }
  //       index = 0;
  //       _delay_ms(1000);
  //     } else {
  //       index++;
  //     }
  //   }
  }
  return 0;
}

ISR (INT0_vect) {
  motor.enc.position();
  //led.toggle();
}

ISR (TIMER1_COMPA_vect) {
  motor.enc.output_V1.pin.set_hi();
}

ISR (TIMER1_COMPB_vect) {
  motor.enc.output_V1.pin.set_lo();
}

// #define PWM_16 (39999u) 		//   20 ms

// // Signal ranges of servo motors (16 and 8 bit PWM signals)
// #define SERVO_16BIT_MIN (999u) 	//  500 ms
// #define SERVO_16BIT_MAX (4599u) // 2300 ms


// void setupPWMD9() {
// 	// 16 bit digital pin 9
// 	DDRB   |= (1 << 1);
// 	TCCR1A |= (2 << COM1A0) | (2 << WGM10);
// 	TIMSK1 |= (1 << TOIE1) | (1 << OCIE1A);

// 	ICR1H 	= (PWM_16 & 0xFF00) >> 8;
// 	ICR1L 	= (PWM_16 & 0x00FF);

// 	OCR1AH 	= (SERVO_16BIT_MIN & 0xFF00) >> 8;
// 	OCR1AL 	= (SERVO_16BIT_MIN & 0x00FF);
// 	TCCR1B 	= (3 << WGM12) | (2 << CS10);
// }


// void setServoPosition(unsigned int pin_num, float duty) {
// 	if (duty > 1) duty = 1;

// 	duty = duty*((float)SERVO_16BIT_MAX - (float)SERVO_16BIT_MIN) + (float)SERVO_16BIT_MIN;

// 	unsigned int pwm_signal = (unsigned int)duty;

// 	OCR1AH = (pwm_signal & 0xFF00) >> 8;
// 	OCR1AL = (pwm_signal & 0x00FF);
// }