#include <ESP32Servo.h> //Had to change this to work with ESP32
#define POT_PIN 2

Servo myservo; // create servo object to control a servo
int servo_value = 0; // variable to store the servo position

void setup() {
myservo.attach(5); // attaches the servo on pin 5 to the servo object
pinMode(POT_PIN, INPUT);
}

void loop() {
  int pot_value = analogRead(POT_PIN);
  servo_value = map(pot_value, 0, 4096, 0, 180);
  myservo.write(servo_value); // tell servo to go to position in variable 'servo_value'
  delay(15); // waits 15 ms for the servo to reach the position
}