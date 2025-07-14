#include <WiFi.h>
#include <BluetoothSerial.h>
#include <Servo.h>

#define SERVO_PIN 15
#define PILL_SENSOR_PIN 34
#define LED_PIN 2

Servo pillServo;
BluetoothSerial SerialBT;

const char* ssid = "YourSSID";
const char* password = "YourPassword";

void setup() {
  Serial.begin(115200);
  SerialBT.begin("PillBoxAI");

  WiFi.begin(ssid, password);
  pinMode(LED_PIN, OUTPUT);
  pinMode(PILL_SENSOR_PIN, INPUT);
  pillServo.attach(SERVO_PIN);

  Serial.println("Initializing PillBox AI...");
  pillServo.write(0); // Initial position
}

void loop() {
  if (SerialBT.available()) {
    String command = SerialBT.readStringUntil('\n');
    handleBluetoothCommand(command);
  }

  if (digitalRead(PILL_SENSOR_PIN) == LOW) {
    Serial.println("Pill Taken");
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(500);
}

void handleBluetoothCommand(String cmd) {
  cmd.trim();
  if (cmd == "DISPENSE") {
    pillServo.write(90);
    delay(1500);
    pillServo.write(0);
    Serial.println("Pill Dispensed");
    SerialBT.println("Pill Dispensed");
  } else {
    SerialBT.println("Unknown Command");
  }
}
