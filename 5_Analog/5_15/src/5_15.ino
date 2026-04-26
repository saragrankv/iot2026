#include <ESP32Servo.h>

#define SERVO_PIN 2

Servo servo;
void setup() {
  servo.attach(SERVO_PIN);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    long value = Serial.parseInt();
    if (value >= 0 && value <= 180) {
      servo.write((int)value);
      delay(15);
    }
    else {
      Serial.println("Enter a value between 0 and 180");
    }
  }
}
