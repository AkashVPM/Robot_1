double ch1=2;
double ch2=3;
double ch3=4;
double ch4=5;
double ch5=6;
double ch6=7; // change channel to three position switch channel

int motorDirection1=8; int motorPWM1=9;    // locomotion
int motorDirection2=10; int motorPWM2=11;  // locomotion
int motorDirection3=14; int motorPWM3=15;  // locomotion
int motorDirection4=16; int motorPWM4=17;  // locomotion 
int motorDirection5=18; int motorPWM5=19;  // sappling gripper locating motor 
int motorDirection6=20; int motorPWM6=21;  // conveyor motion 
int motorDirection7=22; int motorPWM7=23;  // sappling gripper
int motorDirection8=24; int motorPWM8=25;  // Flywheel 1 
int motorDirection9=26; int motorPWM9=27;  // Flywheel 2 
int motorDirection10=28; int motorPWM10=29; // ball gripper alignment
int motorDirection11=30; int motorPWM11=31; // ball gripper open close
int motorDirection12=32; int motorPWM12=33; // linear actuator
// int motorDirection13=33; int motorPWM13=34;
// int motorDirection14=35; int motorPWM14=36;

void main()
{
  Serial.begin(9600);
  
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);


  pinMode(8,OUTPUT); pinMode(9,OUTPUT);
  pinMode(10,OUTPUT); pinMode(11,OUTPUT);
  // pinMode(12,OUTPUT); pinMode(13,OUTPUT);
  pinMode(14,OUTPUT); pinMode(15,OUTPUT);
  pinMode(16,OUTPUT); pinMode(17,OUTPUT);
  pinMode(18,OUTPUT); pinMode(19,OUTPUT);
  pinMode(20,OUTPUT); pinMode(21,OUTPUT);
  pinMode(22,OUTPUT); pinMode(23,OUTPUT);
  pinMode(24,OUTPUT); pinMode(25,OUTPUT);
  pinMode(26,OUTPUT); pinMode(27,OUTPUT);
  pinMode(28,OUTPUT); pinMode(29,OUTPUT);
  pinMode(30,OUTPUT); pinMode(31,OUTPUT);
  pinMode(32,OUTPUT); pinMode(33,OUTPUT);
  

}

void loop()
{

ch1 = pulseIn(2,HIGH);
ch2 = pulseIn(3,HIGH);
ch3 = pulseIn(4,HIGH);
ch4 = pulseIn(5,HIGH);
ch6 = pulseIn(6,HIGH);
ch7 = pulseIn(7,HIGH);

//  locomotion part code 

// forward run

if (ch1 > 50);
  {
  digitalWrite(motorDirection1, HIGH);  // Set direction to forward
  analogWrite(motorPWM1, 200);  // Set motor speed (0 to 255)
  digitalWrite(motorDirection2, LOW);  // Set direction to forward
  analogWrite(motorPWM2, 200);  // Set motor speed (0 to 255)
  digitalWrite(motorDirection3, HIGH);  // Set direction to forward
  analogWrite(motorPWM3, 200);  // Set motor speed (0 to 255)
  digitalWrite(motorDirection4, LOW);  // Set direction to forward
  analogWrite(motorPWM4, 200);  // Set motor speed (0 to 255
  }

// backward run

else if (ch1 < -50);
 {
  digitalWrite(motorDirection1, LOW);  // Set direction to forward
  analogWrite(motorPWM1, 200);  // Set motor speed (0 to 255)
  digitalWrite(motorDirection2, HIGH);  // Set direction to forward
  analogWrite(motorPWM2, 200);  // Set motor speed (0 to 255)
  digitalWrite(motorDirection3, LOW);  // Set direction to forward
  analogWrite(motorPWM3, 200);  // Set motor speed (0 to 255)
  digitalWrite(motorDirection4, HIGH);  // Set direction to forward
  analogWrite(motorPWM4, 200);  // Set motor speed (0 to 255)
 }

// left turn 

else if (ch2 > 50);
{
  digitalWrite(motorDirection1, HIGH);  // Set direction to forward
  analogWrite(motorPWM1, 200);  // Set motor speed (0 to 255)
  digitalWrite(motorDirection2, HIGH);  // Set direction to forward
  analogWrite(motorPWM2, 200);  // Set motor speed (0 to 255)
  digitalWrite(motorDirection3, LOW);  // Set direction to backward
  analogWrite(motorPWM3, 200);  // Set motor speed (0 to 255)
  digitalWrite(motorDirection4, LOW);  // Set direction to backward
  analogWrite(motorPWM4, 200);  // Set motor speed (0 to 255)
}

// right turn 

else if (ch2 < -50):
{
  digitalWrite(motorDirection1, LOW);  // Set direction to backward
  analogWrite(motorPWM1, 200);  // Set motor speed (0 to 255)
  digitalWrite(motorDirection2, LOW);  // Set direction to backward
  analogWrite(motorPWM2, 200);  // Set motor speed (0 to 255)
  digitalWrite(motorDirection3, HIGH);  // Set direction to forward
  analogWrite(motorPWM3, 200);  // Set motor speed (0 to 255)
  digitalWrite(motorDirection4, HIGH);  // Set direction to forward
  analogWrite(motorPWM4, 200);  // Set motor speed (0 to 255)
}

// stage 1 

if (Ch6 == 1);
{
 digitalWrite(motorDirection5, HIGH);  // motor on sappling gripper loacte to the sappling
 analogWrite(motorPWM5, 50);           // motor speed 
 delay(5000);                          // time shows in millisec
 analogWrite(motorPWM5, 0);            // motor stop after 5 sec

// conveyor moves up and down 

      if (ch3 > 50);
      {
        digitalWrite(motorDirection6, HIGH); // conveyor moves upward 
        analogWrite(motorPWM6, 10);
        delay(5000);
        analogWrite(motorPWM6, 0);           // motor stop after 5 sec
      }
      else if (ch3 < -50);
      { 
        digitalWrite(motorDirection6, LOW);  // conveyor moves upward 
        analogWrite(motorPWM6, 10);
        delay(5000);
        analogWrite(motorPWM6, 0);           // motor stop after 5 sec
      }

// sappling gripper 
      if (ch5 == 1);
      {
        digitalWrite(motorDirection7, HIGH); // Gripper open
        analogWrite(motorPWM7, 10);
        delay(5000);
        analogWrite(motorPWM7, 0);           // motor stop after 5 sec
      }
      else if (ch5 == 0);
      { 
        digitalWrite(motorDirection7, LOW); // Gripper close
        analogWrite(motorPWM7, 10);
        delay(5000);
        analogWrite(motorPWM7, 0);          // motor stop after 5 sec
      }


}

// stage 2
if (ch6 == -1);
{
digitalWrite(motorDirection5, LOW);  // motor on sappling gripper loacte to the sappling
analogWrite(motorPWM5, 0);            // motor stop after 5 sec
digitalWrite(motorDirection8, HIGH);  // flywheel right on
analogWrite(motorPWM8, 100);            
digitalWrite(motorDirection9, HIGH);  // flywheel right off
analogWrite(motorPWM9, 100);           

// ball gripper alignment 

      if (ch3 > 50);
      {
        digitalWrite(motorDirection10, HIGH); // ball gripper alignment
        analogWrite(motorPWM10, 10);
        delay(5000);
        analogWrite(motorPWM10, 0);           // motor stop after 5 sec
      }
      else if (ch3 < -50);
      { 
        digitalWrite(motorDirection10, LOW);  // ball feed to ball feeder
        analogWrite(motorPWM10, 10);
        delay(5000);
        analogWrite(motorPWM10, 0);           // motor stop after 5 sec
      }

// Ball gripper open 

      if (ch4 > 50);
      {
        digitalWrite(motorDirection11, HIGH); // Gripper open
        analogWrite(motorPWM11, 10);
        delay(5000);
        analogWrite(motorPWM11, 0);           // motor stop after 5 sec
      }
      else if (ch4 < -50);
      { 
        digitalWrite(motorDirection11, LOW); // Gripper close
        analogWrite(motorPWM11, 10);
        delay(5000);
        analogWrite(motorPWM11, 0);          // motor stop after 5 sec
      }

// electric actuator 

      if (ch5 == 1);
      {
        digitalWrite(motorDirection12, HIGH); // linear actuator 
        analogWrite(motorPWM12, 10);
        delay(5000);
        analogWrite(motorPWM12, 0);           // motor stop after 5 sec
      }
      else if (ch4 < -50);
      { 
        digitalWrite(motorDirection12, LOW); // linear actuator retract 
        analogWrite(motorPWM12, 10);
        delay(5000);
        analogWrite(motorPWM12, 0);          // motor stop after 5 sec
      }

}

}


// void setup()
// {
//   Serial.begin(9600);
  
//   pinMode(2,INPUT);
//   pinMode(4,OUTPUT); pinMode(5,OUTPUT);
  
//   pinMode(3,INPUT);
//   pinMode(6,OUTPUT); pinMode(7,OUTPUT);
  
// }

// void loop()
// {
// ch1 = pulseIn(2,HIGH);
// ch2 = pulseIn(3,HIGH);

// if((ch1==0)&&(ch2==0))
// {     
//  digitalWrite(a,LOW); digitalWrite(b,LOW);
//  digitalWrite(c,LOW);digitalWrite(d,LOW);
// }

// else if((ch1>1530)&&(ch2>1530))
// {     
// digitalWrite(a,HIGH); digitalWrite(b,LOW);
//  digitalWrite(c,LOW);digitalWrite(d,HIGH);    
// }

// else if((ch1>1530)&&(ch2<1460))
// { 
//    digitalWrite(a,HIGH); digitalWrite(b,LOW);
//  digitalWrite(c,HIGH);digitalWrite(d,LOW);    

// }

// else if((ch1<1460)&&(ch2>1530))
// {     
//   digitalWrite(a,LOW); digitalWrite(b,HIGH);
//  digitalWrite(c,LOW);digitalWrite(d,HIGH);
// }

// else if((ch1<1460)&&(ch2<1460))
// {  digitalWrite(a,LOW); digitalWrite(b,HIGH);
//  digitalWrite(c,HIGH);digitalWrite(d,LOW);
  

// }

// else
// {     
//  digitalWrite(a,LOW); digitalWrite(b,LOW);
//  digitalWrite(c,LOW);digitalWrite(d,LOW);
// }

// }