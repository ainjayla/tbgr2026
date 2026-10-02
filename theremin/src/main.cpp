#include <Arduino.h>

#define RED 7
#define BLUE 4
#define GREEN 2

#define BUZZER 8
#define PHOTORESISTOR A0

void green();
void blue();
void red();
void off();

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(PHOTORESISTOR, INPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int res = analogRead(PHOTORESISTOR);
  if (res > 350) {
    tone(BUZZER, res);
  } else {
    noTone(BUZZER);
  }
  if (res >= 650) {
    red();
  } else if (res < 650 && res >= 500) {
    blue();
  } else if (res < 500 && res > 350) {
    green();
  } else {
    off();
  }
}

void green() {
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, LOW);
  digitalWrite(RED, LOW);
}

void blue() {
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, HIGH);
  digitalWrite(RED, LOW);
}

void red() {
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  digitalWrite(RED, HIGH);
}

void off() {
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  digitalWrite(RED, LOW);
}
