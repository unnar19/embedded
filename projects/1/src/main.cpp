#include <Arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <motor_encoder.h>
#include <digital_out.h>

  //ISR (INT0_vect);

Motor_Encoder enc(4, 5, 1); // D3 and D4
Digital_out led(5); // Onboard led

int main() {
  enc.init();


  // Digital_out motor(2); // Part 2  // int started = 0; // Part 2

  const int max_t = 100;
  float speed;
  float y[max_t];
  float e[max_t];
  float u[max_t];
  float Kp = 0.4;

  Serial.begin(115200); 
  led.init();

  // motor.init(); // Part 2
  // int index = 0; // Part 2
  // int recorder[10]; // Part 2


  float r[max_t];
  for (int i = 0; i < max_t; i++) {
    r[i] = -((14.0/25)*(i-50)*(i-50)) + 1400;
  }

  int t = 0; // Part 4
  enc.init_pwm(4);  // Part 4
  while(1) {
    
    // Part 4
  // enc.set_pwm(0.99);
    speed = enc.velocity();
    y[t] = abs(speed);
    e[t] = r[t] - y[t];
    u[t] = Kp * e[t];
    enc.set_pwm(u[t]/1400.0);


    if (t == (max_t - 1)) {
      t = 0;
      for (int i = 0; i < 100; i++) {
        Serial.print("t = ");
        Serial.print((1+i)*4);
        Serial.print("ms, speed = ");
        Serial.print(u[i]);
        Serial.println("pulses per second");
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
  enc.position();
  //led.toggle();
}

ISR (TIMER1_COMPA_vect) {
  enc.output_V1.pin.set_hi();
}

ISR (TIMER1_COMPB_vect) {
  enc.output_V1.pin.set_lo();
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