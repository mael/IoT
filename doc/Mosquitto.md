#  MQTT (Broker) -> mosquitto 

## Lectura inicial

https://www.luisllamas.es/que-son-y-como-usar-los-topics-en-mqtt-correctamente/


### Instalar mosquitto
A continuación, se describen los pasos básicos para instalar y configurar **mosquitto** un (broker)  de MQTT 

Desde la terminal, ejecutamos los siguientes comandos: 

```
sudo apt-add-repository ppa:mosquitto-dev/mosquitto-ppa
sudo apt-get update
sudo apt-get install mosquitto mosquitto-clients
```

### Prueba de funcionamiento

**Terminal 1:**
```
mosquitto_sub -v -t "#"
```

Filtrando mensajes [debug, verbose, topicSuscribe]
```
mosquitto_sub –d –v -t lab/temperature 
```

**Terminl 2:**
```
mosquitto_pub -d -t lab/temperature -m "22.10"
```


### mqtt_explorer

Emisor/receptor de paquetes mqtt

Desde el instalador de paquetes de ubuntu


## Enlaces complementarios

* https://mosquitto.org/download/
* https://www.luisllamas.es/que-es-mqtt-su-importancia-como-protocolo-iot/
* https://www.digitalocean.com/community/tutorials/how-to-install-and-secure-the-mosquitto-mqtt-messaging-broker-on-ubuntu-18-04
