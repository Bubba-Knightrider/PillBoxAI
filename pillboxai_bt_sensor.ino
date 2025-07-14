// ====== File: pillboxai_bt_sensor.ino ======
#include "BluetoothSerial.h" // Include the BluetoothSerial library for ESP32

BluetoothSerial BTSerial;  // Create a BluetoothSerial object

// Pin for the sensor (example: analog pin A0)
const int sensorPin = 34;

void setup() {
  Serial.begin(115200);

  // Start Bluetooth Serial and set the device name
  if (!BTSerial.begin("ESP32_Sensor_Module")) { 
    Serial.println("Bluetooth initialization failed!");
    while (1);
  }
  Serial.println("Bluetooth started. Device is ready to pair.");

  pinMode(sensorPin, INPUT);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  BTSerial.println("Sensor Value: " + String(sensorValue));
  Serial.println("Sensor Value: " + String(sensorValue));
  delay(1000);
}
