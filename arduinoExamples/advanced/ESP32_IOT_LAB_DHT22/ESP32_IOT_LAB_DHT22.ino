
/**
 * Client IOT LAB, using DHT22
 * 
 * 
 *  Author: Mael T.
 *  Date: 18/01/2020
 */

#include <WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"          // Library for DHT sensors

#define wifi_ssid "ssid"         //wifi ssid
#define wifi_password "password"     //wifi password

#define mqtt_server "10.1.4.1"  // VW ubuntu

#define mqtt_user "username"      // username
#define mqtt_password "password"   // password


// Set your Static IP address
IPAddress local_IP(192, 168, 2, 51);
// Set your Gateway IP address
IPAddress gateway(192, 168, 2, 254);
IPAddress subnet(255, 255, 0, 0);
IPAddress primaryDNS(10, 1, 2,3);

#define temperature_topic "lab/temperature"       //Topic temperature
#define humidity_topic "lab/humidity"         //Topic humidity

#define debug_topic "debug"

/* definitions for deepsleep */
#define uS_TO_S_FACTOR 1000000        /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP 20              /* Time ESP32 will go to sleep for 15 minutes (in seconds) */
#define TIME_TO_SLEEP_ERROR 3600       /* Time to sleep in case of error (1 hour) */

bool debug = true;             //Display log message if True

#define DHTPIN 4               // DHT Pin 
#define DHTTYPE DHT22         // DHT 22  (AM2302)

// Create objects
DHT dht(DHTPIN, DHTTYPE);     
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);     
  setup_wifi();                           //Connect to Wifi network
   
  client.setServer(mqtt_server, 1883);    // Configure MQTT connection, change port if needed.

  if (!client.connected()) {
    reconnect();
  }
  dht.begin();
  
  // Read temperature in Celcius
    float t = dht.readTemperature();
  // Read humidity
    float h = dht.readHumidity();
  

  // Nothing to send. Warn on MQTT debug_topic and then go to sleep for longer period.
    if ( isnan(t) || isnan(h)) {
      Serial.println("[ERROR] Please check the DHT sensor !");
      client.publish(debug_topic, "[ERROR] Please check the DHT sensor !", true);      // Publish humidity on mosohomes/humid1
      esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR); //go to sleep
      Serial.println("Setup ESP32 to sleep for every " + String(TIME_TO_SLEEP) + " Seconds");
      Serial.println("Going to sleep now because of ERROR");
      esp_deep_sleep_start();
      return;
    }
  
    if ( debug ) {
      Serial.print("Temperature : ");
      Serial.print(t);
      Serial.print(" | Humidity : ");
      Serial.println(h);
    } 

    // Publish values to MQTT topics
    client.publish(temperature_topic, String(t).c_str(), true);   // Publish temperature on mosohomes/temp1
    if ( debug ) {    
      Serial.println("Temperature sent to MQTT.");
    }
    delay(100); //some delay is needed for the mqtt server to accept the message
    //client.publish(humidity_topic, String(h).c_str(), true);      // Publish humidity on mosohomes/humid1
    if ( debug ) {
      Serial.println("Humidity sent to MQTT.");
    }   

  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR); //go to sleep
  Serial.println("Setup ESP32 to sleep for every " + String(TIME_TO_SLEEP) + " Seconds");
  Serial.println("Going to sleep as normal now.");
  esp_deep_sleep_start();
}

//Setup connection to wifi
void setup_wifi() {
  delay(20);
    
    
  // Configures static IP address
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS)) {
    Serial.println("STA Failed to configure");
  }
  
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(wifi_ssid);

  WiFi.begin(wifi_ssid, wifi_password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }

 Serial.println("");
 Serial.println("WiFi is OK ");
 Serial.print("=> ESP32 new IP address is: ");
 Serial.print(WiFi.localIP());
 Serial.println("");
}

//Reconnect to wifi if connection is lost
void reconnect() {

  while (!client.connected()) {
    Serial.print("Connecting to MQTT broker ...");
    if (client.connect("ESP32Client", mqtt_user, mqtt_password)) {
      Serial.println("OK");
    } else {
      Serial.print("[Error] Not connected: ");
      Serial.print(client.state());
      Serial.println("Wait 5 seconds before retry.");
      delay(5000);
    }
  }
}

void loop() { 
}
