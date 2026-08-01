#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);

const char* ssid = "ТВОЙ_WIFI";      // сюда впиши свой Wi-Fi
const char* password = "ПАРОЛЬ_WIFI";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  Serial.println("Connecting...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected!");

  server.on("/", []() {
    server.send(200, "text/html", "<h1>Hello ESP32 WebPanel!</h1>");
  });
  server.begin();
}

void loop() {
  server.handleClient();
}
