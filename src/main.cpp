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

  /*pinMode(D1_I1, OUTPUT);
  pinMode(D1_I2, OUTPUT);
  pinMode(D1_I3, OUTPUT);
  pinMode(D1_I4, OUTPUT);
  pinMode(D2_I1, OUTPUT);
  pinMode(D2_I2, OUTPUT);
  pinMode(D2_I3, OUTPUT);
  pinMode(D2_I4, OUTPUT);//*/

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

  Dabble.begin("Mecanum Car");       //set bluetooth name of your device
  Serial.begin(115200); 
}

void loop() {
  //test1();
  //test2();
  //test3();

  Dabble.processInput();

  if (GamePad.isUpPressed()){
    forward();
    delay(800);
    stopped();
  }

  if (GamePad.isDownPressed()){
    backwards();
    delay(800);
    stopped();
  }

  if (GamePad.isLeftPressed()){
    left();
    delay(800);
    stopped();
  }

  if (GamePad.isRightPressed()){
    right();
    delay(800);
    stopped();
  }

  if (GamePad.isSquarePressed()){
    ccw();
    delay(800);
    stopped();
  }

  if (GamePad.isCirclePressed()){
    cw();
    delay(800);
    stopped();
  }

  int a = GamePad.getAngle();
  Serial.print("Angle: ");
  Serial.print(a);
  Serial.print('\t');
  int b = GamePad.getRadius();  
  Serial.print("Radius: ");
  Serial.print(b);
  Serial.print('\t');
  float c = GamePad.getXaxisData();
  Serial.print("x_axis: ");
  Serial.print(c);
  Serial.print('\t');
  float d = GamePad.getYaxisData();
  Serial.print("y_axis: ");
  Serial.println(d);
  Serial.println();

  if (b>4){
    if (a<30){
      // Move Right
    }
    else if (a<75){
      // Move FR
    }
    else if (a<120){
      // Move Forward
    }
    else if (a<165){
      // Move FL
    }
    else if (a<210){
      // Move Left
    }
    else if (a<255){
      // Move BL
    }
    else if (a<300){
      // Move Backwards
    }
    else if (a<345){
      // Move BR
    }
    else {
      // Move Right
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
  /*ledcWrite(channel11, 0);
  ledcWrite(channel12, 0);
  ledcWrite(channel13, 0);
  ledcWrite(channel14, 0);*/
  /*digitalWrite(D1_I1, LOW);
  digitalWrite(D1_I2, LOW);
  digitalWrite(D1_I3, LOW);
  digitalWrite(D1_I4, LOW);
  digitalWrite(D2_I1, LOW);
  digitalWrite(D2_I2, LOW);
  digitalWrite(D2_I3, LOW);
  digitalWrite(D2_I4, LOW);//*/
}

void forward(){
  int pwms[8] = {200, 0, 0, 200, 0, 200, 200, 0};
  setPWMs(pwms);
  /*ledcWrite(channel11, 200);
  ledcWrite(channel12, 0);
  ledcWrite(channel13, 0);
  ledcWrite(channel14, 200);*/
  /*digitalWrite(D1_I1, HIGH);
  digitalWrite(D1_I2, LOW);
  digitalWrite(D1_I3, LOW);
  digitalWrite(D1_I4, HIGH);
  digitalWrite(D2_I1, LOW);
  digitalWrite(D2_I2, HIGH);
  digitalWrite(D2_I3, HIGH);
  digitalWrite(D2_I4, LOW);//*/
}

void backwards(){
  int pwms[8] = {0, 200, 200, 0, 200, 0, 0, 200};
  setPWMs(pwms);
  /*ledcWrite(channel11, 0);
  ledcWrite(channel12, 200);
  ledcWrite(channel13, 200);
  ledcWrite(channel14, 0);*/
  /*digitalWrite(D1_I1, LOW);
  digitalWrite(D1_I2, HIGH);
  digitalWrite(D1_I3, HIGH);
  digitalWrite(D1_I4, LOW);
  digitalWrite(D2_I1, HIGH);
  digitalWrite(D2_I2, LOW);
  digitalWrite(D2_I3, LOW);
  digitalWrite(D2_I4, HIGH);//*/
}

void left(){
  int pwms[8] = {0, 200, 0, 200, 200, 0, 200, 0};
  setPWMs(pwms);
  /*ledcWrite(channel11, 0);
  ledcWrite(channel12, 200);
  ledcWrite(channel13, 0);
  ledcWrite(channel14, 200);*/
  /*digitalWrite(D1_I1, LOW);
  digitalWrite(D1_I2, HIGH);
  digitalWrite(D1_I3, LOW);
  digitalWrite(D1_I4, HIGH);
  digitalWrite(D2_I1, HIGH);
  digitalWrite(D2_I2, LOW);
  digitalWrite(D2_I3, HIGH);
  digitalWrite(D2_I4, LOW);//*/
}

void right(){
  int pwms[8] = {200, 0, 200, 0, 0, 200, 0, 200};
  setPWMs(pwms);
  /*ledcWrite(channel11, 200);
  ledcWrite(channel12, 0);
  ledcWrite(channel13, 200);
  ledcWrite(channel14, 0);*/
  /*digitalWrite(D1_I1, HIGH);
  digitalWrite(D1_I2, LOW);
  digitalWrite(D1_I3, HIGH);
  digitalWrite(D1_I4, LOW);
  digitalWrite(D2_I1, LOW);
  digitalWrite(D2_I2, HIGH);
  digitalWrite(D2_I3, LOW);
  digitalWrite(D2_I4, HIGH);//*/
}

void cw(){
  int pwms[8] = {200, 0, 200, 0, 200, 0, 200, 0};
  setPWMs(pwms);
  /*ledcWrite(channel11, 200);
  ledcWrite(channel12, 0);
  ledcWrite(channel13, 200);
  ledcWrite(channel14, 0);*/
  /*digitalWrite(D1_I1, HIGH);
  digitalWrite(D1_I2, LOW);
  digitalWrite(D1_I3, HIGH);
  digitalWrite(D1_I4, LOW);
  digitalWrite(D2_I1, HIGH);
  digitalWrite(D2_I2, LOW);
  digitalWrite(D2_I3, HIGH);
  digitalWrite(D2_I4, LOW);//*/
}

void ccw(){
  int pwms[8] = {0, 200, 0, 200, 0, 200, 0, 200};
  setPWMs(pwms);
  /*ledcWrite(channel11, 0);
  ledcWrite(channel12, 200);
  ledcWrite(channel13, 0);
  ledcWrite(channel14, 200);*/
  /*digitalWrite(D1_I1, LOW);
  digitalWrite(D1_I2, HIGH);
  digitalWrite(D1_I3, LOW);
  digitalWrite(D1_I4, HIGH);
  digitalWrite(D2_I1, LOW);
  digitalWrite(D2_I2, HIGH);
  digitalWrite(D2_I3, LOW);
  digitalWrite(D2_I4, HIGH);//*/
}

void fl(){
  int pwms[8] = {0, 0, 0, 200, 0, 0, 200, 0};
  setPWMs(pwms);
  /*ledcWrite(channel11, 0);
  ledcWrite(channel12, 0);
  ledcWrite(channel13, 0);
  ledcWrite(channel14, 200);*/
  /*digitalWrite(D1_I1, LOW);
  digitalWrite(D1_I2, LOW);
  digitalWrite(D1_I3, LOW);
  digitalWrite(D1_I4, HIGH);
  digitalWrite(D2_I1, LOW);
  digitalWrite(D2_I2, LOW);
  digitalWrite(D2_I3, HIGH);
  digitalWrite(D2_I4, LOW);//*/
}

void fr(){
  int pwms[8] = {200, 0, 0, 0, 0, 200, 0, 0};
  setPWMs(pwms);
  /*ledcWrite(channel11, 200);
  ledcWrite(channel12, 0);
  ledcWrite(channel13, 0);
  ledcWrite(channel14, 0);*/
  /*digitalWrite(D1_I1, HIGH);
  digitalWrite(D1_I2, LOW);
  digitalWrite(D1_I3, LOW);
  digitalWrite(D1_I4, LOW);
  digitalWrite(D2_I1, LOW);
  digitalWrite(D2_I2, HIGH);
  digitalWrite(D2_I3, LOW);
  digitalWrite(D2_I4, LOW);//*/
}

void bl(){
  int pwms[8] = {0, 200, 0, 0, 200, 0, 0, 0};
  setPWMs(pwms);
  /*ledcWrite(channel11, 0);
  ledcWrite(channel12, 200);
  ledcWrite(channel13, 0);
  ledcWrite(channel14, 0);*/
  /*digitalWrite(D1_I1, LOW);
  digitalWrite(D1_I2, HIGH);
  digitalWrite(D1_I3, LOW);
  digitalWrite(D1_I4, LOW);
  digitalWrite(D2_I1, HIGH);
  digitalWrite(D2_I2, LOW);
  digitalWrite(D2_I3, LOW);
  digitalWrite(D2_I4, LOW);//*/
}

void br(){
  int pwms[8] = {0, 0, 200, 0, 0, 0, 0, 200};
  setPWMs(pwms);
  /*ledcWrite(channel11, 0);
  ledcWrite(channel12, 0);
  ledcWrite(channel13, 200);
  ledcWrite(channel14, 0);*/
  /*digitalWrite(D1_I1, LOW);
  digitalWrite(D1_I2, LOW);
  digitalWrite(D1_I3, HIGH);
  digitalWrite(D1_I4, LOW);
  digitalWrite(D2_I1, LOW);
  digitalWrite(D2_I2, LOW);
  digitalWrite(D2_I3, LOW);
  digitalWrite(D2_I4, HIGH);//*/
}

void setPWMs(int pwms[8]){  
  /*digitalWrite(D1_I1, LOW);
  digitalWrite(D1_I2, LOW);
  digitalWrite(D1_I3, LOW);
  digitalWrite(D1_I4, LOW);
  digitalWrite(D2_I1, LOW);
  digitalWrite(D2_I2, LOW);
  digitalWrite(D2_I3, LOW);
  digitalWrite(D2_I4, LOW);//*/
  ledcWrite(channel11, pwms[0]);
  ledcWrite(channel12, pwms[1]);
  ledcWrite(channel13, pwms[2]);
  ledcWrite(channel14, pwms[3]);
  ledcWrite(channel21, pwms[4]);
  ledcWrite(channel22, pwms[5]);
  ledcWrite(channel23, pwms[6]);
  ledcWrite(channel24, pwms[7]);//*/
}