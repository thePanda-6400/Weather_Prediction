#include <Arduino.h>
#include "DHT.h"

#define DHTPIN 15
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("DHT22 read error");
  } else {
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print("°C   Humidity: ");
    Serial.println(h);
  }

  delay(2000);
}
