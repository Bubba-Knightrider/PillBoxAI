#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "YourSSID";
const char* password = "YourPassword";
const char* server = "http://192.168.1.10:5000/api/pillbox/data";  // Local IP of server

void sendPillboxData(int sensorValue) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(server);
    http.addHeader("Content-Type", "application/json");

    String payload = "{\"timestamp\":\"" + String(millis()) +
                     "\",\"sensorValue\":" + String(sensorValue) +
                     ",\"status\":\"OK\"}";

    int httpResponseCode = http.POST(payload);
    Serial.println("POST Response: " + String(httpResponseCode));
    http.end();
  }
}
