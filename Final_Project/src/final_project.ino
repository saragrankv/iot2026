#include <ESP32Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <PubSubClient.h>

#define SENSOR_ANALOG_PIN 35
#define SENSOR_DIGITAL_PIN 4
#define BUZZ_PIN 15
#define SERVO_PIN 32
#define BUTTON_PIN 12

// Wi-Fi credentials
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// MQTT broker configuration
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char* mqtt_topic = "saragrankv/gassensor";

WiFiClient espClient;
PubSubClient client(espClient);

//LCD and Servo configuration
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo ventservo;
bool resetAlarm = false;

void setup() {
  Serial.begin(115200);
  pinMode(SENSOR_ANALOG_PIN, INPUT);
  pinMode(SENSOR_DIGITAL_PIN, INPUT);
  pinMode(BUZZ_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  ventservo.attach(SERVO_PIN);
  ventservo.write(0);
  lcd.init();
  lcd.backlight();
  delay(500);

  // WiFi connection
  printMessage("Connecting WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    printMessage("...");
  }
  printMessage("Connected!");

  // MQTT connection
  client.setServer(mqtt_server, mqtt_port);
  connectToMQTT();
  delay(500);
  lcd.clear();
}

void printMessage(String msg) {
  // Sends status messages to both Serial monitor and LCD
  Serial.println(msg);
  lcd.setCursor(0,0);
  lcd.print(msg);
}

void connectToMQTT() {
  while (!client.connected()) {
    printMessage("Connecting MQTT");
    // Create a random client ID
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      printMessage("Connected!");
    }
    else {
      printMessage("Failed:");
      delay(500);
      printMessage(String(client.state()));
      printMessage("Retry in 5s...");
      delay(5000);
    }
  }
}

void loop() {
  // Check MQTT connection
  if(!client.connected()) {
    connectToMQTT();
  }
  client.loop();

  // Read value from sensor, write to LCD
  int gasLevel = analogRead(SENSOR_ANALOG_PIN);
  bool alarmOn = false;
  lcd.setCursor(0,0);
  lcd.print(gasLevel);
  // Check digital pin, sound alarm if LOW unless alarm has already been reset
  // Set Servo to 180 to "open door"
  int threshold = digitalRead(SENSOR_DIGITAL_PIN);
  lcd.setCursor(0,1);
  if (threshold == LOW) {
    alarmOn = true;
    lcd.setCursor(0,1);
    lcd.print("ALARM");
    if (!resetAlarm) {
      tone(BUZZ_PIN, 500, 500);
    }
    ventservo.write(180);
    delay(200);
  }
  else {
    lcd.setCursor(0,1);
    lcd.print("OK   ");
    ventservo.write(0);
    delay(200);
  }
  int buttonPressed = digitalRead(BUTTON_PIN);
  if (buttonPressed == LOW) {
    resetAlarm = true;
    lcd.setCursor(0,1);
    lcd.print("ALARM (muted)");
  }
  // Publish to MQTT
  String payload = "{\"reading\": " + String(gasLevel) + ", \"alarm\": " + String(!alarmOn) + "}";
  client.publish(mqtt_topic, payload.c_str());
  delay(1000);
}
