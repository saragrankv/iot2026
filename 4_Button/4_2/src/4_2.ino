#define BUTTON_PIN 2
#define LED_PIN 4

int buttonState;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);
  digitalWrite(LED_PIN, !buttonState);
}