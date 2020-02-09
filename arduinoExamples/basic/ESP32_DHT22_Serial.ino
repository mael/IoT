
/**
 * DHT22, sensor de temperatura y humedad
 * 
 *  Author: Mael T.
 *  Date: 18/01/2020
 */

/**
 * Arduino libraries:
 * "DHT Sensor Library" by Adafruit
 * "Adafruit Unified Sensor" by Adafruit
 * 
 * PINOUT
 * ======
 * Positive +5v or +3.3v
 * GND
 * Data: D4
**/
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321


// Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println(F("DHT22 reading ..."));
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.println(F(" %"));
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));
  Serial.println("- - -");
}
