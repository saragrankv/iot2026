void setup() {
  pinMode(4, OUTPUT);
}

unsigned long previousMillis = 0;
bool ledState = LOW;

void loop() {
  unsigned long currentMillis = millis();
  if (ledState == HIGH && currentMillis - previousMillis >= 500) {
    previousMillis = currentMillis;
    ledState = LOW;
    digitalWrite(4, ledState);
  }
  else if (ledState == LOW && currentMillis - previousMillis >= 2000) {
    previousMillis = currentMillis;
    ledState = HIGH;
    digitalWrite(4, ledState);
  }
}
