#define POT_PIN 2
#define LED_PIN 4

void setup() {
  pinMode(POT_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int pot_value = analogRead(POT_PIN);
  if (pot_value > 2048) {
    digitalWrite(LED_PIN, HIGH);
  }
  else {
    digitalWrite(LED_PIN, LOW);
  }
  delay(10); // this speeds up the simulation
}
