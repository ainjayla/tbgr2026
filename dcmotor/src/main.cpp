#include <Arduino.h>

#define INA 5
#define INB 6

void stopMotor() {
  analogWrite(INA, 0);
  analogWrite(INB, 0);
}

void breakMotor() {
  analogWrite(INA, 255);
  analogWrite(INB, 255);
}

void setMotor(int speed) {
  speed = constrain(speed, -255, 255);
  if (speed > 0) {
    analogWrite(INA, speed);
    analogWrite(INB, 0);
  } else if (speed < 0) {
    analogWrite(INA, 0);
    analogWrite(INB, -speed);
  } else {
    stopMotor();
  }
}

void rampTo(int target, int stepDelayMs = 10) {
  int cur = 0;
  int step = (target > cur) ? 1 : -1;
  while (cur != target) {
    cur += step;
    setMotor(cur);
    delay(stepDelayMs);
  }
}

void setup() {
  pinMode(INA, OUTPUT);
  pinMode(INB, OUTPUT);
  stopMotor();
}

void loop() {
  rampTo(200);
  delay(1500);
  rampTo(0);
  delay(200);
  rampTo(-200);
  delay(1500);
  rampTo(0);
  delay(800);
}
