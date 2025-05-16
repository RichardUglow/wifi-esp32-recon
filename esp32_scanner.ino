#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "yourssidhere";
const char* password = "yourpasswordhere";
const char* serverUrl = "http://---/wifi"; // ← Your Pi's IP here

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
}

void loop() {
  Serial.println("Scanning Wi-Fi...");

  int n = WiFi.scanNetworks();
  String data = "";
  for (int i = 0; i < n; ++i) {
    data += "SSID: " + WiFi.SSID(i);
    data += ", RSSI: " + String(WiFi.RSSI(i));
    data += ", MAC: " + WiFi.BSSIDstr(i) + "\n";
  }

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverUrl);
    http.addHeader("Content-Type", "text/plain");
    int code = http.POST(data);
    String response = http.getString();
    Serial.printf("Sent scan: HTTP %d - %s\n", code, response.c_str());
    http.end();
  }

  delay(10000); // Scan every 10s
}