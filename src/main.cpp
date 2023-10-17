#include <Arduino.h>

#define ONBOARD_LED  2
#define D1_I1 32
#define D1_I2 33
#define D1_I3 25
#define D1_I4 26
#define D2_I1 13
#define D2_I2 12
#define D2_I3 14
#define D2_I4 27

void stopped();
void forward();
void backwards();
void left();
void right();
void cw();
void ccw();
void fl();
void fr();
void bl();
void br();

void test1();
void test2();
void test3();

const int freq = 15000;
const int resolution = 8;
const int channel11 = 0;
const int channel12 = 1;
const int channel13 = 2;
const int channel14 = 3;

void setup() {
  pinMode(ONBOARD_LED,OUTPUT);

  ledcSetup(channel11, freq, resolution);
  ledcSetup(channel12, freq, resolution);
  ledcSetup(channel13, freq, resolution);
  ledcSetup(channel14, freq, resolution);
  ledcAttachPin(D1_I1, channel11);
  ledcAttachPin(D1_I2, channel12);
  ledcAttachPin(D1_I3, channel13);
  ledcAttachPin(D1_I4, channel14);
  
  //pinMode(D1_I1, OUTPUT);
  //pinMode(D1_I2, OUTPUT);
  //pinMode(D1_I3, OUTPUT);
  //pinMode(D1_I4, OUTPUT);
  pinMode(D2_I1, OUTPUT);
  pinMode(D2_I2, OUTPUT);
  pinMode(D2_I3, OUTPUT);
  pinMode(D2_I4, OUTPUT);
}

void loop() {
  /*delay(1000);
  digitalWrite(ONBOARD_LED,HIGH);
  delay(100);
  digitalWrite(ONBOARD_LED,LOW);*/

  test1();
  //test2();
  //test3();

  /*for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);
    delay(50);
  }*/

  /*ledcWrite(channel11, 200);
  ledcWrite(channel12, 0);
  ledcWrite(channel13, 0);
  ledcWrite(channel14, 200);
  delay(1500);
  ledcWrite(channel11, 0);
  ledcWrite(channel12, 0);
  ledcWrite(channel13, 0);
  ledcWrite(channel14, 0);
  delay(1500);*/
}

void test1(){
  stopped();
  delay(1500);
  forward();
  delay(1500);
  stopped();
  delay(1500);
  backwards();
  delay(1500);
}

void test2(){
  stopped();
  delay(1500);
  left();
  delay(3000);
  stopped();
  delay(1500);
  right();
  delay(3000);
}

void test3(){
  stopped();
  delay(1500);
  forward();
  delay(1500);
  stopped();
  delay(1500);
  cw();
  delay(3000);
  stopped();
  delay(1500);
  fl();
  delay(3000);
  stopped();
  delay(1500);
  br();
  delay(3000);
  stopped();
  delay(1500);
  ccw();
  delay(3000);
  stopped();
  delay(1500);
  backwards();
  delay(1500);
  stopped();
  delay(1500);
}

void stopped(){
  ledcWrite(channel11, 0);
  ledcWrite(channel12, 0);
  ledcWrite(channel13, 0);
  ledcWrite(channel14, 0);
  /*digitalWrite(D1_I1, LOW);
  digitalWrite(D1_I2, LOW);
  digitalWrite(D1_I3, LOW);
  digitalWrite(D1_I4, LOW);*/
  digitalWrite(D2_I1, LOW);
  digitalWrite(D2_I2, LOW);
  digitalWrite(D2_I3, LOW);
  digitalWrite(D2_I4, LOW);
}

void forward(){  
  ledcWrite(channel11, 200);
  ledcWrite(channel12, 0);
  ledcWrite(channel13, 0);
  ledcWrite(channel14, 200);
  /*digitalWrite(D1_I1, HIGH);
  digitalWrite(D1_I2, LOW);
  digitalWrite(D1_I3, LOW);
  digitalWrite(D1_I4, HIGH);*/
  digitalWrite(D2_I1, LOW);
  digitalWrite(D2_I2, HIGH);
  digitalWrite(D2_I3, HIGH);
  digitalWrite(D2_I4, LOW);
}

void backwards(){  
  ledcWrite(channel11, 0);
  ledcWrite(channel12, 200);
  ledcWrite(channel13, 200);
  ledcWrite(channel14, 0);
  /*digitalWrite(D1_I1, LOW);
  digitalWrite(D1_I2, HIGH);
  digitalWrite(D1_I3, HIGH);
  digitalWrite(D1_I4, LOW);*/
  digitalWrite(D2_I1, HIGH);
  digitalWrite(D2_I2, LOW);
  digitalWrite(D2_I3, LOW);
  digitalWrite(D2_I4, HIGH);
}

void left(){ 
  ledcWrite(channel11, 0);
  ledcWrite(channel12, 200);
  ledcWrite(channel13, 0);
  ledcWrite(channel14, 200);
  /*digitalWrite(D1_I1, LOW);
  digitalWrite(D1_I2, HIGH);
  digitalWrite(D1_I3, LOW);
  digitalWrite(D1_I4, HIGH);*/
  digitalWrite(D2_I1, HIGH);
  digitalWrite(D2_I2, LOW);
  digitalWrite(D2_I3, HIGH);
  digitalWrite(D2_I4, LOW);
}

void right(){ 
  ledcWrite(channel11, 200);
  ledcWrite(channel12, 0);
  ledcWrite(channel13, 200);
  ledcWrite(channel14, 0);
  /*digitalWrite(D1_I1, HIGH);
  digitalWrite(D1_I2, LOW);
  digitalWrite(D1_I3, HIGH);
  digitalWrite(D1_I4, LOW);*/
  digitalWrite(D2_I1, LOW);
  digitalWrite(D2_I2, HIGH);
  digitalWrite(D2_I3, LOW);
  digitalWrite(D2_I4, HIGH);
}

void cw(){ 
  ledcWrite(channel11, 200);
  ledcWrite(channel12, 0);
  ledcWrite(channel13, 200);
  ledcWrite(channel14, 0);
  /*digitalWrite(D1_I1, HIGH);
  digitalWrite(D1_I2, LOW);
  digitalWrite(D1_I3, HIGH);
  digitalWrite(D1_I4, LOW);*/
  digitalWrite(D2_I1, HIGH);
  digitalWrite(D2_I2, LOW);
  digitalWrite(D2_I3, HIGH);
  digitalWrite(D2_I4, LOW);
}

void ccw(){ 
  ledcWrite(channel11, 0);
  ledcWrite(channel12, 200);
  ledcWrite(channel13, 0);
  ledcWrite(channel14, 200);
  /*digitalWrite(D1_I1, LOW);
  digitalWrite(D1_I2, HIGH);
  digitalWrite(D1_I3, LOW);
  digitalWrite(D1_I4, HIGH);*/
  digitalWrite(D2_I1, LOW);
  digitalWrite(D2_I2, HIGH);
  digitalWrite(D2_I3, LOW);
  digitalWrite(D2_I4, HIGH);
}

void fl(){ 
  ledcWrite(channel11, 0);
  ledcWrite(channel12, 0);
  ledcWrite(channel13, 0);
  ledcWrite(channel14, 200);
  /*digitalWrite(D1_I1, LOW);
  digitalWrite(D1_I2, LOW);
  digitalWrite(D1_I3, LOW);
  digitalWrite(D1_I4, HIGH);*/
  digitalWrite(D2_I1, LOW);
  digitalWrite(D2_I2, LOW);
  digitalWrite(D2_I3, HIGH);
  digitalWrite(D2_I4, LOW);
}

void fr(){ 
  ledcWrite(channel11, 200);
  ledcWrite(channel12, 0);
  ledcWrite(channel13, 0);
  ledcWrite(channel14, 0);
  /*digitalWrite(D1_I1, HIGH);
  digitalWrite(D1_I2, LOW);
  digitalWrite(D1_I3, LOW);
  digitalWrite(D1_I4, LOW);*/
  digitalWrite(D2_I1, LOW);
  digitalWrite(D2_I2, HIGH);
  digitalWrite(D2_I3, LOW);
  digitalWrite(D2_I4, LOW);
}

void bl(){ 
  ledcWrite(channel11, 0);
  ledcWrite(channel12, 200);
  ledcWrite(channel13, 0);
  ledcWrite(channel14, 0);
  /*digitalWrite(D1_I1, LOW);
  digitalWrite(D1_I2, HIGH);
  digitalWrite(D1_I3, LOW);
  digitalWrite(D1_I4, LOW);*/
  digitalWrite(D2_I1, HIGH);
  digitalWrite(D2_I2, LOW);
  digitalWrite(D2_I3, LOW);
  digitalWrite(D2_I4, LOW);
}

void br(){ 
  ledcWrite(channel11, 0);
  ledcWrite(channel12, 0);
  ledcWrite(channel13, 200);
  ledcWrite(channel14, 0);
  /*digitalWrite(D1_I1, LOW);
  digitalWrite(D1_I2, LOW);
  digitalWrite(D1_I3, HIGH);
  digitalWrite(D1_I4, LOW);*/
  digitalWrite(D2_I1, LOW);
  digitalWrite(D2_I2, LOW);
  digitalWrite(D2_I3, LOW);
  digitalWrite(D2_I4, HIGH);
}