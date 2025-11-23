# led-rainbow-project
Project Lampu Led Warna - Warni  Arduino  ESP 32

# 🌈 LED Rainbow Project

Project lampu LED warna-warni menggunakan Arduino dan ESP32.

## ✨ Fitur
- ✅ Efek pelangi otomatis
- ✅ Kontrol warna dasar (Merah, Hijau, Biru)
- 📱 Kontrol via WiFi (ESP32)
- 🔧 Mudah dikustomisasi

## 🛠️ Bahan yang Diperlukan
- Arduino Uno/ESP32
- LED Strip WS2812B
- Breadboard & kabel jumper
- Power supply 5V

## 🚀 Cara Pakai

### Arduino Version
1. Upload `src/arduino/led_rainbow.ino`
2. Sambungkan LED strip:
   - 5V → VCC
   - GND → GND  
   - Pin 6 → DIN

### ESP32 Version  
1. Upload `src/esp32/led_wifi_control.ino`
2. Ganti SSID & password WiFi
3. Buka IP address di Serial Monitor
4. Kontrol via browser

## 📁 Struktur Project
