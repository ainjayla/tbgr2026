#include <Arduino.h>

#define LED 13
#define BUTTON 4

bool isOn = false;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available()) {
    String command = Serial.readString();
    command.trim();
    Serial.println("Received: " + command);
    if (command == "on") {
      digitalWrite(LED, HIGH);
      isOn = true;
    } else if (command == "off") {
      digitalWrite(LED, LOW);
      isOn = false;
    }
  }
  int but = digitalRead(BUTTON);
  if (but == 1) {
    if (isOn) {
      digitalWrite(LED, LOW);
      isOn = false;
    } else {
      digitalWrite(LED, HIGH);
      isOn = true;
    }
    delay(500);
  }
}
