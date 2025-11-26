#include <Arduino.h>
#include "DHT.h"

#define DHTPIN 15
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println("DHT22 PlatformIO + Wokwi Ready");
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Sensor read error!");
  } else {
    Serial.println("Temperature: " + String(temperature) + "°C   Humidity: " + String(humidity) + "%");
  }

  delay(2000);
}
