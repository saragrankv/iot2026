// Touch sensor is not available in Wokwi, 
// using proximity sensor instead, which 
// by default has a 5 second delay after 
// motion is detected

#define LED_PIN 4
#define TOUCH_PIN 2

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(TOUCH_PIN, INPUT);

}

void loop() {
  int touch = digitalRead(TOUCH_PIN);
  digitalWrite(LED_PIN, touch);
  delay(10); // this speeds up the simulation
}
