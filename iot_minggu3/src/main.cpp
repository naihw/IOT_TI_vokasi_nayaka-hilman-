#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Konfigurasi DHT22
#define DHTPIN 19
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// Konfigurasi LDR
#define LDR_PIN 34

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    Serial.begin(115200);
    dht.begin();
    lcd.init();
    lcd.backlight();
}

void loop() {
    // Membaca suhu dan kelembapan dari DHT22
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    // Membaca intensitas cahaya dari LDR (0-4095 untuk ESP32)
    int lightValue = analogRead(LDR_PIN);
    float lightPercentage = (lightValue / 4095.0) * 100.0; // Konversi ke persen

    // Jika pembacaan gagal, tampilkan pesan error
    if (isnan(temperature) || isnan(humidity)) {
        Serial.println("Gagal membaca dari sensor DHT!");
        return;
    }

    // Menampilkan data di Serial Monitor
    Serial.print("Suhu: ");
    Serial.print(temperature);
    Serial.print("°C, Kelembapan: ");
    Serial.print(humidity);
    Serial.print("%, Cahaya: ");
    Serial.print(lightPercentage);
    Serial.println("%");

    // Menampilkan data di LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.print(temperature);
    lcd.print("C H:");
    lcd.print(humidity);
    lcd.print("%");

    lcd.setCursor(0, 1);
    lcd.print("Cahaya: ");
    lcd.print(lightPercentage);
    lcd.print("%");

    delay(2000); // Tunggu 2 detik sebelum membaca lagi
}