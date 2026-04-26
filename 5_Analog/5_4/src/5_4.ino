#define POT_PIN 2
#define LED_PIN 4

void setup() {
  pinMode(POT_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int pot_value = analogRead(POT_PIN);
  int led_value = map(pot_value, 0, 4096, 0, 255);
  analogWrite(LED_PIN, led_value);
  delay(10); // this speeds up the simulation
}
