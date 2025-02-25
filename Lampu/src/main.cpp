#include <Arduino.h> // Wajib untuk PlatformIO + ESP32

// Deklarasi pin LED
const int lampuMerah = 26;
const int lampuKuning = 33;
const int lampuHijau = 32;

void setup() {
    Serial.begin(115200);
    
    // Atur pin sebagai OUTPUT
    pinMode(lampuMerah, OUTPUT);
    pinMode(lampuKuning, OUTPUT);
    pinMode(lampuHijau, OUTPUT);
}

void loop() {
    // Nyalakan lampu merah selama 22 detik
    digitalWrite(lampuMerah, HIGH);
    Serial.println("Lampu Merah ON");
    delay(22000);
    digitalWrite(lampuMerah, LOW);
    
    // Nyalakan lampu hijau selama 15 detik
    digitalWrite(lampuHijau, HIGH);
    Serial.println("Lampu Hijau ON");
    delay(15000);
    digitalWrite(lampuHijau, LOW);

    // Nyalakan lampu kuning selama 10 detik
    digitalWrite(lampuKuning, HIGH);
    Serial.println("Lampu Kuning ON");
    delay(10000);
    digitalWrite(lampuKuning, LOW);

    
}
