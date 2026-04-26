// Edited to work with ESP32 and Wokwi
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.init();
  lcd.backlight();
  // Print a message to the LCD.
  lcd.print("Sara Grankvist");
  delay(1000);
}

void loop() {
  // set the cursor to column 0, line 1
  lcd.setCursor(0, 1);
  lcd.print(millis()/1000);
  
  delay(100);
}