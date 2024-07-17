#include "CytronMotorDriver.h"
#include "Servo.h"

int pos = 0;

// define motor pins for stage 1
CytronMD motor5(PWM_DIR,8 , 9); // sappling gripper position motor
CytronMD motor6(PWM_DIR, 10, 11); // conveyor up and down motor                                                                  bgvf

Servo myservo;                    // sappling gripper servo
Servo myservo1;

// define motor pins for stage 2
CytronMD motor7(PWM_DIR, 20, 21); // sap up and down
CytronMD motor8(PWM_PWM, 22, 23); // sap gripper
CytronMD motor9(PWM_DIR, 24, 26); // actuator
// CytronMD motor10(PWM_DIR, 27, 28); // flywheel 1
// CytronMD motor11(PWM_DIR, 29, 30); // flywheel 2

// Define channel pins for sappling
#define CH3_PIN 2
#define CH6_PIN 3
#define CH7_PIN 4
#define CH8_PIN 5

#define LIMIT_SWITCH 36

void setup() {
  // Initialize Serial for debugging
  Serial.begin(9600);

  // // Initialize motor pins for stage 1
  // motor5.begin();
  // motor6.begin();

  // Initialize channel pins
  pinMode(CH3_PIN, INPUT);
  pinMode(CH6_PIN, INPUT);
  pinMode(CH7_PIN, INPUT);
  pinMode(CH8_PIN, INPUT);

  pinMode(LIMIT_SWITCH, INPUT);

  myservo.attach(36);
  myservo1.attach(34);
}

// Function to read PWM input
int readPWM(int pin) {
  int duration = pulseIn(pin, HIGH);
  return map(duration, 1000, 2000, -100, 100); // Adjust based on your transmitter
}

void loop() {
  int ch3 = readPWM(CH3_PIN);
  int ch6 = readPWM(CH6_PIN);
  int ch7 = readPWM(CH7_PIN);
  int ch8 = readPWM(CH8_PIN);

  if (ch7 >= 90) {           // stage 1 
    if (ch8 >= 90) {
      motor5.setSpeed(-255);
      Serial.print("stage 1");
    } else if (ch8 <= -90) {
      motor5.setSpeed(255);
    }else if (ch8 < 90 && ch8 > -90) {
    motor5.setSpeed(0);
    }

    if (ch3 >= 70) {
      motor6.setSpeed(255);
      Serial.print("conveyor up");
    } else if (ch3 <= -70) {
      motor6.setSpeed(-255);
      Serial.print("conveyor down");
    } else if (ch3 < 70 && ch3 > -70) {
      motor6.setSpeed(0);
    }

if (ch6 >= 90) {
    // for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(180);   
    myservo1.write(180);
   // open position
  // myservo1.write(180);
  Serial.print("servo open");
} else if (ch6 <= -90) {
  // for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  myservo.write(-180);    
  myservo1.write(-180); // close position
  Serial.print("servo close");}
 else if (ch6 < 90 && ch6 > -90) {
  myservo.write(90);
  myservo1.write(90); // neutral position
  Serial.print("servo neutral");
  // delay(100); // add a delay to ensure the servo stops
}
        }
    

//////////////////////////////

  
  else if (ch7 <= -90) {   
    myservo.detach();                                             // stage 2
    // motor10.setSpeed(100); // flywheel
    // motor11.setSpeed(100);
    Serial.print("Stage 2, flywheel on");

    if (ch8 >= 90) {
      motor7.setSpeed(-128);
      Serial.print("Gripper up");
    } else if (ch8 <= -90) {
      motor7.setSpeed(128);
      Serial.print("Gripper down");
    } else if (ch8 < 90 && ch8 > -90) {
      motor7.setSpeed(0);
    }

    if (ch6 >= 90) {
      motor8.setSpeed(255);
      Serial.print("gripper open");
      if (digitalRead(LIMIT_SWITCH) == HIGH) {
        motor8.setSpeed(0);
        Serial.print("limit switch on");
      }
    } else if (ch6 <= -90) {
      motor8.setSpeed(-255);
      Serial.print("gripper close");
    } else if (ch6 < 70 && ch6 > -70) {
      motor8.setSpeed(0);
    }

    if (ch3 >= 90) {
      motor9.setSpeed(255);
      Serial.print("actuator up");
    } else if (ch3 <= -90) {
      motor9.setSpeed(-255);
      Serial.print("actuator down");
    } else if (ch3 < 90 && ch3 > -90) {
      motor9.setSpeed(0);
    }
  } 
   else {
    motor5.setSpeed(0);
    motor6.setSpeed(0);
    motor7.setSpeed(0);
    motor8.setSpeed(0);
    motor9.setSpeed(0);
    // motor10.setSpeed(0);
    // motor11.setSpeed(0);
  
  }
   Serial.print("CH3: ");
   Serial.print(ch3);
   Serial.print("CH6: ");
   Serial.print(ch6);
   Serial.print(", CH7: ");
   Serial.println(ch7);
  Serial.print("CH8: ");
   Serial.println(ch8);
  // // delay(1000);
}