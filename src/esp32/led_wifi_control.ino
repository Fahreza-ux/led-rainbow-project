#include <Adafruit_NeoPixel.h>
#include <WiFi.h>
#include <WebServer.h>

#define LED_PIN     18
#define LED_COUNT   30

const char* ssid = "WIFI_SSID";
const char* password = "WIFI_PASSWORD";

WebServer server(80);
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  strip.begin();
  strip.show();
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  
  server.on("/", []() {
    String html = "<html><body><h1>LED Controller</h1>";
    html += "<button onclick=\"location.href='/red'\">Merah</button>";
    html += "<button onclick=\"location.href='/green'\">Hijau</button>";
    html += "<button onclick=\"location.href='/blue'\">Biru</button>";
    html += "<button onclick=\"location.href='/off'\">Mati</button>";
    html += "</body></html>";
    server.send(200, "text/html", html);
  });
  
  server.on("/red", []() { 
    colorWipe(strip.Color(255, 0, 0), 0); 
    server.send(200, "text/plain", "LED Merah"); 
  });
  
  server.on("/green", []() { 
    colorWipe(strip.Color(0, 255, 0), 0); 
    server.send(200, "text/plain", "LED Hijau"); 
  });
  
  server.on("/blue", []() { 
    colorWipe(strip.Color(0, 0, 255), 0); 
    server.send(200, "text/plain", "LED Biru"); 
  });
  
  server.on("/off", []() { 
    colorWipe(strip.Color(0, 0, 0), 0); 
    server.send(200, "text/plain", "LED Dimatikan"); 
  });
  
  server.begin();
}

void loop() {
  server.handleClient();
}

void colorWipe(uint32_t color, int wait) {
  for(int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
  }
}
