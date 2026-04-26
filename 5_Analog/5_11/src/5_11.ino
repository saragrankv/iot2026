// Edited to work with ESP32 and Wokwi
// Using button as there is no touch
// sensor simulated in Wokwi
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define BUTTON_PIN 2

LiquidCrystal_I2C lcd(0x27, 16, 2);

int counter = 0;
int buttonPos = HIGH;

void setup() {
  pinMode(2, INPUT_PULLUP);
  // set up the LCD's number of columns and rows:
  lcd.init();
  lcd.backlight();
  // Print a message to the LCD.
  lcd.print("Press counter:");
  
  delay(1000);
}

void loop() {
  int pressed = digitalRead(BUTTON_PIN);
  if (buttonPos == HIGH && pressed == LOW) {
    counter++;
  }
  buttonPos = pressed;
  // set the cursor to column 0, line 1
  lcd.setCursor(0, 1);
  lcd.print(counter);
  delay(100);
}
