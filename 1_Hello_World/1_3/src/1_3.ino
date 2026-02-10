// Inspired by the BlinkWithoutDelay example in the Arduino docs

void setup() {
  Serial.begin(9600);
}

unsigned long previousMillis = 0;
unsigned long secCounter = 0;

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= 1000) {
    // Save the last time the counter was increased:
    previousMillis = currentMillis;
    if (secCounter >= 10) {
      secCounter = 0;
    }
    else {
      secCounter += 1;
    }
    Serial.println(secCounter);
  }
}
