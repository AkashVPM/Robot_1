#include "CytronMotorDriver.h"

CytronMD motor1(PWM_DIR, 9, 8);
CytronMD motor2(PWM_DIR, 52, 50);
CytronMD motor3(PWM_DIR, 15, 14);
CytronMD motor4(PWM_DIR, 17, 16);

#define CH1_PIN 28
#define CH2_PIN 24
#define CH4_PIN 26

void setup() {
  Serial.begin(115200);
}

int readPWM(int pin) {
  int duration = pulseIn(pin, HIGH);
  return map(duration, 1000, 2000, -255, 255);
}

void loop() {
  int ch1 = readPWM(CH1_PIN);
  int ch2 = readPWM(CH2_PIN);
  int ch4 = readPWM(CH4_PIN);

  int speed1 = 0, speed2 = 0, speed3 = 0, speed4 = 0;

  if (ch2 <= -70 | ch2 >= 70) { // Forward
    speed1 = ch2; speed2 = -ch2; speed3 = -ch2; speed4 = ch2;}
  // } else if (ch2 >= 70) { // Backward
  //   speed1 = 128; speed2 = -128; speed3 = -128; speed4 = 128;
  // }

  if (ch1 <= -70 | ch1 >= 70) { // Turn left
    speed1 = ch1; speed2 = ch1; speed3 = -ch1; speed4 = -ch1;
  }
  //  else if (ch1 >= 70) { // Turn right
  //   speed1 = -128; speed2 = -128; speed3 = 128; speed4 = 128;
  // }

  if (ch4 <= -90 | ch4 >= 90) { // Right rotation
    speed1 = ch4; speed2 = ch4; speed3 = ch4; speed4 = ch4;
  } 
  // else if (ch4 >= 90) { // Left rotation
  //   speed1 = 128; speed2 = 128; speed3 = 128; speed4 = 128;
  // }

  if ((ch1 < 70 && ch1 > -70) && (ch2 < 70 && ch2 > -70) && (ch4 < 90 && ch4 > -90)) {
    speed1 = 0; speed2 = 0; speed3 = 0; speed4 = 0;
  }

  motor1.setSpeed(speed1);
  motor2.setSpeed(speed2);
  motor3.setSpeed(speed3);
  motor4.setSpeed(speed4);
  
  Serial.print("CH1: ");
  Serial.print(ch1);
  Serial.print(", CH2: ");
  Serial.println(ch2);
  Serial.print(", CH4: ");
  Serial.println(ch4);}