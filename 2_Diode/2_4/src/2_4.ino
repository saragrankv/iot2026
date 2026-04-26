void setup() {
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}

unsigned long previousLedMillis = 0;
unsigned long previousCountMillis = 0;
unsigned long countSec = 0;
bool ledState = LOW;

void loop() {
  unsigned long currentLedMillis = millis();
  unsigned long currentCountMillis = currentLedMillis;
  if (ledState == HIGH && currentLedMillis - previousLedMillis >= 500) {
    previousLedMillis = currentLedMillis;
    ledState = LOW;
    digitalWrite(4, ledState);
  }
  else if (ledState == LOW && currentLedMillis - previousLedMillis >= 2000) {
    previousLedMillis = currentLedMillis;
    ledState = HIGH;
    digitalWrite(4, ledState);
  }
  if (currentCountMillis - previousCountMillis >= 1000) {
    previousCountMillis = currentCountMillis;
    countSec += 1;
    Serial.println(countSec);
  }  
}
