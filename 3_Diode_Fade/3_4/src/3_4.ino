const int LED_PIN = 3;
int pwm_value = 0;
bool increasing = true;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  analogWrite(LED_PIN, pwm_value);
  if (increasing) {
    if (pwm_value < 255) {
      pwm_value++;
    }
    else {
      increasing = false;
      pwm_value--;
    }
  }
  else {
    if (pwm_value > 0) {
      pwm_value--;
    }
    else {
      increasing = true;
      pwm_value++;
    }
  }
  delay(10);
}
