#define BUTTON_PIN 2
#define LED_PIN 4
#define BUZZ_PIN 18

int buttonState;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZ_PIN, OUTPUT);
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);
  digitalWrite(LED_PIN, buttonState);
  if (buttonState == HIGH) {
    tone(BUZZ_PIN, 400);
  }
}