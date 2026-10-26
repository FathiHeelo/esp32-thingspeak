#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"

#define DHTPIN 15
#define DHTTYPE DHT22

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* apiKey = "YOUR_WRITE_API_KEY";   // حط هون الـ Write API Key الخاص فيك
const char* universityId = "12323885";
const char* serverName = "http://api.thingspeak.com/update";

DHT dht(DHTPIN, DHTTYPE);
unsigned long lastSend = 0;
const unsigned long interval = 20000;   // كل 20 ثانية

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.begin(ssid, password, 6);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected! IP: " + WiFi.localIP().toString());
}

void loop() {
  if (millis() - lastSend >= interval) {
    lastSend = millis();

    float t = dht.readTemperature();
    float h = dht.readHumidity();

    if (isnan(t) || isnan(h)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      String url = String(serverName) + "?api_key=" + apiKey +
                   "&field1=" + String(t, 1) + "&field2=" + String(h, 1);
      http.begin(url);
      int code = http.GET();
      Serial.printf("[ID %s] Temp=%.1f C, Hum=%.1f %% -> HTTP %d\n",
                    universityId, t, h, code);
      http.end();
    }
  }
}
