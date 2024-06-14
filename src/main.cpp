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
#define D2_I3 18
#define D2_I4 27

#define STEP_PIN 21
#define DIR_PIN 19

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

int joystick_ang = 0;
int joystick_rad = 0;

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

void forkliftUp();
void forkliftDown();

void test1();
void test2();
void test3();
void test4();

void setup() {
  pinMode(ONBOARD_LED,OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);

  Serial.begin(115200);

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
  //test4();

  Dabble.processInput();

  if (GamePad.isUpPressed()){
    Serial.println("Up");
    forward();
    delay(350);
    stopped();
  }

  if (GamePad.isDownPressed()){
    Serial.println("Down");
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
    Serial.println("Square");
    ccw();
    delay(150);
    stopped();
  }

  if (GamePad.isCirclePressed()){
    Serial.println("Circle");
    cw();
    delay(150);
    stopped();
  }

  if (GamePad.isTrianglePressed()){
    forkliftUp();
  }

  if (GamePad.isCrossPressed()){
    forkliftDown();
  }

  joystick_ang = GamePad.getAngle();
  joystick_rad = GamePad.getRadius();

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
  }//*/
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

void test4(){
  // Goes Down 8 mm (200 steps)
  digitalWrite(DIR_PIN, HIGH);
  for (int i = 0; i < 200; i++){
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(1000);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(1000);
  }
  delay(2000);
  // Goes Up 8 mm (200 steps)
  digitalWrite(DIR_PIN, LOW);
  for (int i = 0; i < 200; i++){
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(1000);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(1000);
  }
  delay(2000);
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

void forkliftUp(){
  // Goes Up 8 mm (200 steps)
  digitalWrite(DIR_PIN, LOW);
  for (int i = 0; i < 200; i++){
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(1000);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(1000);
  }
  delay(50);
}

void forkliftDown(){
  // Goes Down 8 mm (200 steps)
  digitalWrite(DIR_PIN, HIGH);
  for (int i = 0; i < 200; i++){
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(1000);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(1000);
  }
  delay(50);
}