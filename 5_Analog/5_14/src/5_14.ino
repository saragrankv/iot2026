#define POT_PIN 2
#define BUZZ_PIN 4

void setup() {
  pinMode(POT_PIN, INPUT);
  pinMode(BUZZ_PIN, OUTPUT);
}

void loop() {
  int pot = analogRead(POT_PIN);
  // Play a frequency according to the value of the potentiometer
  tone(BUZZ_PIN, pot);
  delay(100);
}
