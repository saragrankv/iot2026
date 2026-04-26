#include <ESP32Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SENSOR_ANALOG_PIN 2
#define SENSOR_DIGITAL_PIN 4
#define BUZZ_PIN 15
#define SERVO_PIN 16
#define BUTTON_PIN 12

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo;
bool resetAlarm = false;

void setup() {
  pinMode(SENSOR_ANALOG_PIN, INPUT);
  pinMode(SENSOR_DIGITAL_PIN, INPUT);
  pinMode(BUZZ_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  servo.attach(SERVO_PIN);
  servo.write(0);
  lcd.init();
  lcd.backlight();
  delay(1000);
}

void loop() {
  // Read value from sensor, write to LCD
  int gasLevel = analogRead(SENSOR_ANALOG_PIN);
  lcd.setCursor(0,0);
  lcd.print(gasLevel);
  // Check digital pin, sound alarm if LOW unless alarm has already been reset
  // Set Servo to 180 to "open door"
  int threshold = digitalRead(SENSOR_DIGITAL_PIN);
  lcd.setCursor(0,1);
  if (threshold == LOW) {
    lcd.setCursor(0,1);
    lcd.print("ALARM");
    if (!resetAlarm) {
      tone(BUZZ_PIN, 500, 200);
    }
    servo.write(180);
    delay(200);
  }
  else {
    lcd.setCursor(0,1);
    lcd.print("OK   ");
    servo.write(0);
    delay(200);
  }
  int buttonPressed = digitalRead(BUTTON_PIN);
  if (buttonPressed == LOW) {
    resetAlarm = true;
    lcd.setCursor(0,1);
    lcd.print("ALARM (muted)");
  }
  delay(10); // this speeds up the simulation
}
