#define POT_PIN 2

void setup() {
  Serial.begin(115200);
  pinMode(POT_PIN, INPUT);
}

void loop() {
  int pot_value = analogRead(POT_PIN);
  Serial.println(pot_value);
  delay(10); // this speeds up the simulation
}
