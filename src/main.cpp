#include <Arduino.h>
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

#define ONBOARD_LED  2
#define D1_I1 32
#define D1_I2 33
#define D1_I3 25
#define D1_I4 26
#define D2_I1 13
#define D2_I2 12
#define D2_I3 14
#define D2_I4 27

const int freq = 15000;
const int resolution = 8;
const int channel11 = 0;
const int channel12 = 1;
const int channel13 = 2;
const int channel14 = 3;
const int channel21 = 4;
const int channel22 = 5;
const int channel23 = 6;
const int channel24 = 7;

int init_pwms[8] = {0, 0, 0, 0, 0, 0, 0, 0};

void setPWMs(int pwms[8]);

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



void setup() {
  pinMode(ONBOARD_LED,OUTPUT);

  ledcSetup(channel11, freq, resolution);
  ledcSetup(channel12, freq, resolution);
  ledcSetup(channel13, freq, resolution);
  ledcSetup(channel14, freq, resolution);
  ledcSetup(channel21, freq, resolution);
  ledcSetup(channel22, freq, resolution);
  ledcSetup(channel23, freq, resolution);
  ledcSetup(channel24, freq, resolution);//*/

  ledcAttachPin(D1_I1, channel11);
  ledcAttachPin(D1_I2, channel12);
  ledcAttachPin(D1_I3, channel13);
  ledcAttachPin(D1_I4, channel14);
  ledcAttachPin(D2_I1, channel21);
  ledcAttachPin(D2_I2, channel22);
  ledcAttachPin(D2_I3, channel23);
  ledcAttachPin(D2_I4, channel24);//*/

  setPWMs(init_pwms);

  Dabble.begin("Mecanum Car"); //set bluetooth name of your device
}

void loop() {
  //test1();
  //test2();
  //test3();

  Dabble.processInput();

  if (GamePad.isUpPressed()){
    forward();
    delay(350);
    stopped();
  }

  if (GamePad.isDownPressed()){
    backwards();
    delay(350);
    stopped();
  }

  if (GamePad.isLeftPressed()){
    left();
    delay(350);
    stopped();
  }

  if (GamePad.isRightPressed()){
    right();
    delay(350);
    stopped();
  }

  if (GamePad.isSquarePressed()){
    ccw();
    delay(150);
    stopped();
  }

  if (GamePad.isCirclePressed()){
    cw();
    delay(150);
    stopped();
  }

  int joystick_ang = GamePad.getAngle();
  int joystick_rad = GamePad.getRadius();

  if (joystick_rad>3){
    if (joystick_ang<30){
      // Move Right
      right();
      delay(350);
      stopped();
    }
    else if (joystick_ang<60){
      // Move FR
      fr();
      delay(350);
      stopped();
    }
    else if (joystick_ang<105){
      // Move Forward
      forward();
      delay(350);
      stopped();
    }
    else if (joystick_ang<135){
      // Move FL
      fl();
      delay(350);
      stopped();
    }
    else if (joystick_ang<210){
      // Move Left
      left();
      delay(350);
      stopped();
    }
    else if (joystick_ang<225){
      // Move BL
      bl();
      delay(350);
      stopped();
    }
    else if (joystick_ang<300){
      // Move Backwards
      backwards();
      delay(350);
      stopped();
    }
    else if (joystick_ang<330){
      // Move BR
      br();
      delay(350);
      stopped();
    }
    else {
      // Move Right
      right();
      delay(350);
      stopped();
    }
  }
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
  int pwms[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  setPWMs(pwms);
}

void forward(){
  int pwms[8] = {200, 0, 0, 200, 0, 200, 200, 0};
  setPWMs(pwms);
}

void backwards(){
  int pwms[8] = {0, 200, 200, 0, 200, 0, 0, 200};
  setPWMs(pwms);
}

void left(){
  int pwms[8] = {0, 200, 0, 200, 200, 0, 200, 0};
  setPWMs(pwms);
}

void right(){
  int pwms[8] = {200, 0, 200, 0, 0, 200, 0, 200};
  setPWMs(pwms);
}

void cw(){
  int pwms[8] = {200, 0, 200, 0, 200, 0, 200, 0};
  setPWMs(pwms);
}

void ccw(){
  int pwms[8] = {0, 200, 0, 200, 0, 200, 0, 200};
  setPWMs(pwms);
}

void fl(){
  int pwms[8] = {0, 0, 0, 200, 0, 0, 200, 0};
  setPWMs(pwms);
}

void fr(){
  int pwms[8] = {200, 0, 0, 0, 0, 200, 0, 0};
  setPWMs(pwms);
}

void bl(){
  int pwms[8] = {0, 200, 0, 0, 200, 0, 0, 0};
  setPWMs(pwms);
}

void br(){
  int pwms[8] = {0, 0, 200, 0, 0, 0, 0, 200};
  setPWMs(pwms);
}

void setPWMs(int pwms[8]){
  ledcWrite(channel11, pwms[0]);
  ledcWrite(channel12, pwms[1]);
  ledcWrite(channel13, pwms[2]);
  ledcWrite(channel14, pwms[3]);
  ledcWrite(channel21, pwms[4]);
  ledcWrite(channel22, pwms[5]);
  ledcWrite(channel23, pwms[6]);
  ledcWrite(channel24, pwms[7]);
}