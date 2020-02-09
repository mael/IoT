# ARDUINO CODE

## Ejemplos básicos

### HC-SR04

El HC-SR04, un sensor de ultra sonidos, diseñado para medir distancias, calculando el tiempo entre la emisión de un pulso y su recepción. 

El rango de medición teórico del sensor HC-SR04 es de 2cm a 400 cm, con una resolución de 0.3cm. Pero en la realidad no es tan preciso.

Para este cometido, también se utilizan sensores ópticos o infrarrojos.

[Código de ejemplo](https://github.com/mael/iot/blob/master/arduinoExamples/basic/ESP32_HC-SR04.ino)


* https://www.luisllamas.es/medir-distancia-con-arduino-y-sensor-de-ultrasonidos-hc-sr04/
* https://www.instructables.com/id/Pocket-Size-Ultrasonic-Measuring-Tool-With-ESP32/

### TSL2561 

El sensor TSL2561, es un sensor que mide el nivel de luminosidad.
Este sensor se comunica mediante la interfaz i2c.

Rango dinámico (Lux): 0.1 - 40.000

[Código de ejemplo](https://github.com/mael/iot/blob/master/arduinoExamples/basic/ESP32_TSL2561.ino)

Instalar librerías:
```
Adafruit_TSL2561
Adafruit Unified Sensor -> (install all) 
```

* https://learn.adafruit.com/tsl2561/
* https://tecarduino.blogspot.com/2018/03/nivel-de-luminosidad-con-tsl2561.html 

### DHT22

El sensor DHT22, permite realizar la medición simultánea de temperatura y humedad. Dispone de un procesador interno que realiza el proceso de medición, proporcionando la medición mediante una señal digital, simplificado el proceso de comunicacion con la placa a la que se conecte. 

- Medición de temperatura entre -40 a 125, con una precisión de 0.5ºC
- Medición de humedad entre 0 a 100%, con precisión del 2-5%.
- Frecuencia de muestreo de 2 muestras por segundo (2 Hz)


[Código de ejemplo](https://github.com/mael/iot/blob/master/arduinoExamples/basic/ESP32_DHT22_Serial.ino)


Instalar librería 
```
DHT sensor library by Adafruit
```

* https://www.luisllamas.es/arduino-dht11-dht22/
* https://randomnerdtutorials.com/esp32-dht11-dht22-temperature-humidity-sensor-arduino-ide/


### KY038 

Es un sensor que envía una señal digital cuando detecta un sonido por el pin D0.
Dispone de un potenciómetro para ajustar la sensibilidad de detección (el valor analógico del potenciómetro nos lo proporciona el pin A0).

[Código de ejemplo > Digital](https://github.com/mael/iot/blob/master/arduinoExamples/basic/ESP32_KY038_Digital.ino)

[Código de ejemplo > Analog](https://github.com/mael/iot/blob/master/arduinoExamples/basic/ESP32_KY038_Analog.ino)


* https://www.luisllamas.es/detectar-sonido-con-arduino-y-microfono-ky-038/
* https://www.infootec.net/deteccion-de-sonido/

### ESP32 Capacitive Touch PIN

La placa ESP32 tiene 10 GPIO táctiles capacitivos. Estos GPIO pueden detectar variaciones de carga eléctrica, como la piel humana.

[Código de ejemplo](https://github.com/mael/iot/blob/master/arduinoExamples/basic/ESP32_Capacitive_Touch.ino)

* https://randomnerdtutorials.com/esp32-touch-pins-arduino-ide/


### ESP32 Led RGB

[Código de ejemplo](https://github.com/mael/iot/blob/master/arduinoExamples/basic/ESP32_Colors_Led_RGB.ino)


### PIR_HC-SR501

Se trata de un sensor de infrarrojos pasivos (PIR); es un dispositivo para la detección de movimiento.

El dispositivo PIR dispone de un sensor piezo eléctrico capaz de captar esta radiación y convertirla en una señal eléctrica.

[Código de ejemplo](https://github.com/mael/iot/blob/master/arduinoExamples/basic/ESP32_PIR_HC-SR501.ino)

***Descripción de los ajustes en la documentación.***

* https://www.luisllamas.es/detector-de-movimiento-con-arduino-y-sensor-pir/
* https://randomnerdtutorials.com/esp32-pir-motion-sensor-interrupts-timers/


### Relé de estado sólido

* https://www.prometec.net/reles-estado-solido/



## Ejemplos avanzados 

### WebServer

Web server DHT22 en ESP32

Instalar librerías:
* https://github.com/me-no-dev/ESPAsyncWebServer
* https://github.com/me-no-dev/AsyncTCP

Programa de ejemplo

[Código de ejemplo](https://github.com/mael/iot/blob/master/arduinoExamples/advanced/ESP32_LAB_DHT22_WebServer/ESP32_LAB_DHT22_WebServer.ino)

* https://randomnerdtutorials.com/esp32-dht11-dht22-temperature-humidity-web-server-arduino-ide/

### Ejemplo para el envío de datos ESP32 > mosquitto > telegraf > influxdb > grafana

**Requiere servidor**

```
ESP32_IOT_LAB_DHT22
```

Instalar la librería <PubSubClient by Nick O'Leary>

