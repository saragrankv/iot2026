#define SENSORPIN 32
#define SENSOR_DIGITAL_PIN 12
#define LED_PIN 4

int sensorValue, sensorMax, sensorMin;

void setup() {
  pinMode(SENSORPIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  sensorValue = analogRead(SENSORPIN);
  sensorMax = sensorValue;
  sensorMin = sensorValue;
  while (millis() < 5000) {
    sensorValue = analogRead(SENSORPIN);
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  }
  Serial.print("Minimum value (lightest): ");
  Serial.println(sensorMin);
  Serial.print("Maximum value (darkest): ");
  Serial.println(sensorMax);

}

void loop() {
  sensorValue = analogRead(SENSORPIN);
  // Since we're using a photoresistor, the value gets lover the
  // more light there is. Therefore we compare to the max value
  if (sensorValue > sensorMax) {
    digitalWrite(LED_PIN, HIGH);
  }
  else {
    digitalWrite(LED_PIN, LOW);
  }
  delay(10); // this speeds up the simulation
}
