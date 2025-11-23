Download Arduino IDE 📥

Berikut panduan lengkap download dan install Arduino IDE:

🌐 Download Arduino IDE

Website Resmi:

https://www.arduino.cc/en/software

Pilihan Version:

· Arduino IDE 2.x (Recommended - lebih modern)
· Arduino IDE 1.x (Stable - klasik)

💻 Untuk Windows:

Step-by-Step:

1. Buka website https://www.arduino.cc/en/software
2. Pilih "Windows Win 7 and newer"
3. Klik "Windows ZIP file" atau "Windows installer"
4. Download file .zip atau .exe
5. Ekstrak (jika .zip) atau Run installer (jika .exe)
6. Ikuti wizard installation

Opsi Download:

· Windows Installer (.exe) - Auto install
· Windows ZIP - Portable, no installation needed

🍎 Untuk Mac:

1. Pilih "macOS"
2. Download file .dmg
3. Drag Arduino ke Applications folder

🐧 Untuk Linux:

1. Pilih "Linux 64 bits"
2. Download file .tar.xz
3. Ekstrak dan run

📱 Alternatif untuk HP (Android/iOS):

Android:

· ArduinoDroid (Play Store) - Free
· Arduino IDE Android - Limited features

iOS:

· Arduino IDE (App Store) - Berbayar
· Blink - Untuk basic coding

Rekomendasi: Gunakan PC/Laptop untuk experience terbaik!

🔧 Setup Arduino IDE Pertama Kali

Setelah Install:

1. Buka Arduino IDE
2. Install Board Definitions:

Untuk Arduino Uno:

· Sudah include default

Untuk ESP32 (Tambahan):

1. File → Preferences
2. Additional Boards Manager URLs: tambahkan:

```
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```

1. Tools → Board → Boards Manager
2. Cari "esp32" → Install

3. Install Library NeoPixel:

1. Tools → Manage Libraries
2. Cari "Adafruit NeoPixel"
3. Klik Install

🚀 Cara Test Kode LED Rainbow

Step 1: Siapkan Kode

1. Buka Arduino IDE
2. Copy kode ini:

```cpp
#include <Adafruit_NeoPixel.h>

#define LED_PIN     6
#define LED_COUNT   30
#define BRIGHTNESS  100

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
  strip.setBrightness(BRIGHTNESS);
  Serial.begin(9600);
  Serial.println("LED Rainbow Ready!");
}

void loop() {
  // Rainbow effect
  rainbow(20);
  
  // Color effects
  colorWipe(strip.Color(255, 0, 0), 50);    // Red
  colorWipe(strip.Color(0, 255, 0), 50);    // Green  
  colorWipe(strip.Color(0, 0, 255), 50);    // Blue
}

void colorWipe(uint32_t color, int wait) {
  for(int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
  }
}

void rainbow(int wait) {
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    for(int i = 0; i < strip.numPixels(); i++) {
      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show();
    delay(wait);
  }
}
```

Step 2: Setup Board

1. Tools → Board → Arduino Uno
2. Tools → Port → Pilih COM port (Windows) atau /dev/ttyUSB0 (Linux) atau /dev/cu.usbmodem (Mac)

Step 3: Upload

1. Klik Verify (✓) untuk compile
2. Klik Upload (→) untuk upload ke board
3. Tunggu sampai "Done uploading"

🎯 Quick Download Links:

Direct Download:

· Windows: https://downloads.arduino.cc/arduino-ide/arduino-ide_2.3.2_Windows_64bit.zip
· Mac: https://downloads.arduino.cc/arduino-ide/arduino-ide_2.3.2_macOS_arm64.dmg
· Linux: https://downloads.arduino.cc/arduino-ide/arduino-ide_2.3.2_Linux_64bit.zip

💡 Tips:

1. Gunakan Arduino IDE 2.x - lebih user friendly
2. Simpan sketch dengan nama "led_rainbow"
3. Test dengan 1 LED dulu sebelum full strip
4. Cek koneksi kabel jika LED tidak nyala

❌ Troubleshooting:

Jika error upload:

· Pastikan board terpilih dengan benar
· Cek driver USB terinstall
· Coba ganti USB cable (gunakan data cable, bukan charge-only)

Jika library error:

· Install manual: Sketch → Include Library → Manage Libraries

Mau saya bantu install step-by-step? Atau ada error tertentu? 😊
