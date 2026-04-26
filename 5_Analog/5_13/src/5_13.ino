// Edited to work with ESP32 and Wokwi
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define POT_PIN 2
#define BUTTON_PIN 4

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(POT_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  // set up the LCD's number of columns and rows:
  lcd.init();
  lcd.backlight();
  delay(1000);
}

void loop() {
  int pot = analogRead(POT_PIN);
  int cursorPos = map(pot, 0, 4095, 0, 32);
  if (cursorPos < 16) {
    lcd.setCursor(cursorPos, 0);
  }
  else {
    lcd.setCursor(cursorPos/2, 1);
  }
  int button = digitalRead(BUTTON_PIN);
  if(button == LOW) {
    lcd.print("A");
  }
  delay(100);
}
