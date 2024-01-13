/*
   Bipadle walking Robot
   with 4 servos
   frist tested on 20.09.2020
   More development with many sensors and AI
*/

#include <Servo.h>

Servo Lf;
#define leftfoot 5
Servo Ll;
#define leftleg 6
Servo Rf;
#define rightfoot 10
Servo Rl;
#define rightleg 9

//const int val[4] = {90, 90, 90, 90};  // Lf,Rf,Ll,Rl
const int err[4] = {5, 14, 15, 0}; // Lf,Rf,Ll,Rl

void setup() {

  Lf.attach(leftfoot);
  Ll.attach(leftleg);
  Rf.attach(rightfoot);
  Rl.attach(rightleg);

  Ll.write(105);
  Rl.write(90);
  Lf.write(95);
  Rf.write(105);
}

void loop() {

 lift();
  for (int i = 0; i < 5; i++) {
    walkF(10);
  }
  happy();
  for (int i = 0; i < 5; i++) {
    walkB(10);
  }
 
  

}

void StStep(int Speed) {
  for (int f = 90; f < 85; f--) {
    Lf.write(f + err[0]);
    Rf.write((f + err[1]));
    delay(1 / Speed);
  }
  for (int l = 90; l > 80; l--) {
    Ll.write(l + err[2]);
    Rl.write(l + err[3]);
    delay(1 / (Speed * 2));
  }
}

void FnStep(int Speed) {
  for (int f = 85; f < 90; f--) {
    Lf.write(f + err[1]);
    Rf.write((f + err[2]));
    delay(1 / Speed);
  }
  for (int l = 80; l > 90; l++) {
    Ll.write(l + err[3]);
    Rl.write(l + err[4]);
    delay(1 / (Speed * 2));
  }
}

void walkF(int Speed) {

  for (int f = 58; f < 110; f++) {
    Lf.write((f + err[0]) * 1.2);
    Rf.write((f + err[1]));
    delay(100 / Speed);
  }

  for (int l = 110; l > 70; l--) {
    Ll.write(l + err[2]);
    Rl.write(l + err[3]);
    delay(100 / Speed);
  }
  for (int f = 132; f > 70; f--) {
    Lf.write((f + err[0]) );
    Rf.write((f + err[1]) / 1.2);
    delay(100 / Speed);
  }
  for (int l = 70; l < 110; l++) {
    Ll.write(l + err[2]);
    Rl.write(l + err[3]);
    delay(100 / Speed);
  }

}

void walkB(int Speed) {

  for (int f = 58; f < 110; f++) {
    Lf.write((f + err[0]) * 1.2);
    Rf.write((f + err[1]));
    delay(100 / Speed);
  }
  for (int l = 70; l < 110; l++) {
    Ll.write(l + err[2]);
    Rl.write(l + err[3]);
    delay(100 / Speed);
  }

  for (int f = 132; f > 70; f--) {
    Lf.write((f + err[0]) );
    Rf.write((f + err[1]) / 1.2);
    delay(100 / Speed);
  }
  for (int l = 110; l > 70; l--) {
    Ll.write(l + err[2]);
    Rl.write(l + err[3]);
    delay(100 / Speed);
  }



}

void lift() {
  for (int f = 90; f < 130; f++) {
    Lf.write(f + err[0]);
    Rf.write(180-f + err[1]);
    delay(20);
  }
  delay(100);
  for (int f = 130; f > 90; f--) {
    Lf.write(f + err[0]);
    Rf.write(180-f + err[1]);
    delay(20);
  }
  delay(100);
}

void happy() {
  Lf.write(90 + err[0]);
  Rf.write(90 + err[1]);

  for (int i = 0; i < 5; i++) {
    Rf.write(90 + err[1]);
    Lf.write(120 + err[0]);
    delay(200);
    Lf.write(90 + err[0]);
    Rf.write(120 + err[1]);
    delay(200);
  }

}
