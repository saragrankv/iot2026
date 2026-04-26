#define BUTTON_PIN 2
#define LED_PIN 4
#define BUZZ_PIN 18

int buttonState;
int previousButtonState = HIGH;
unsigned long buttonpressStartMillis = 0;
unsigned long buttonpressEndMillis = 0;
unsigned long ledMillis = 0;
unsigned long currentMillis;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZ_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);
  currentMillis = millis();
  if (buttonState == LOW && previousButtonState == HIGH) {
    buttonpressStartMillis = currentMillis;
    previousButtonState = buttonState;
  }
  else if (buttonState == HIGH && previousButtonState == LOW) {
    buttonpressEndMillis = currentMillis;
    previousButtonState = buttonState;
  }
  if (buttonpressEndMillis > buttonpressStartMillis) {
    unsigned long pressDuration = buttonpressEndMillis-buttonpressStartMillis;
    Serial.println(pressDuration);
    if (pressDuration > 5000) {
      tone(BUZZ_PIN, 400, 2000);
    }
    else {
      digitalWrite(LED_PIN, HIGH);
      delay(2000);
      digitalWrite(LED_PIN, LOW);
    }
    // Do not run this if-statement until the button is pressed again:
    buttonpressEndMillis = 0;
  }
}