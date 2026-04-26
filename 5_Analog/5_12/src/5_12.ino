// Edited to work with ESP32 and Wokwi
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define POT_PIN 2

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(POT_PIN, INPUT);
  // set up the LCD's number of columns and rows:
  lcd.init();
  lcd.backlight();
  // Print a message to the LCD.
  lcd.print("Sensor value:");
  delay(1000);
}

void loop() {
  // Clear the counter space
  lcd.setCursor(0, 1);
  lcd.print("    ");
  int pot = analogRead(POT_PIN);
  // set the cursor to column 0, line 1
  lcd.setCursor(0, 1);
  lcd.print(pot);
  delay(100);
}
