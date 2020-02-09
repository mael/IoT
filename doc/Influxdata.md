# Instalación influxdata

A continuación, se describen los pasos básicos para instalar y configurar influxDB, telegraf y chronograf

## Instalación influxDB

https://docs.influxdata.com/influxdb/v1.7/introduction/installation/

```
wget -qO- https://repos.influxdata.com/influxdb.key sudo apt-key add - 
source /etc/os-release
echo "deb https://repos.influxdata.com/debian $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/influxdb.list
```

A continuación instalamos e iniciamos el servicio
```
sudo apt-get update && sudo apt-get install influxdb
sudo service influxdb start
```

## Configuración influxDB

Desde la terminal: 
```
influx
```
Una vez en la consola de **influx>** 
```
CREATE DATABASE sensors
```

Opcional, creación de usuarios
```
CREATE USER telegraf WITH PASSWORD 'telegraf' WITH ALL PRIVILEGES
GRANT ALL ON sensors TO telegraf
```

Inicialmente NO modificaremos el fichero de configruación de influxdb
```
sudo vim /etc/inluxdb/influxdb.conf
```

Reiniciar servicio
```
sudo service influxdb restart
```


## Telegraf

Instalar telegraf 
```
sudo apt-get install telegraf
```

Modificar fichero de configruación 
```
sudo vim /etc/telegraf/telegraf.conf
```
https://docs.influxdata.com/telegraf/v1.13/introduction/installation/


## Chronograf

Instalar
```
sudo apt-get install chronograf
```

Acceso web
```
http://SERVER_IP:8888
```
https://docs.influxdata.com/chronograf/v1.7/


## Kapacitor

Instalar
```
sudo apt-get install kapacitor
```

## Enlaces complementarios

* https://docs.influxdata.com/platform/introduction
* https://portal.influxdata.com/downloads/
* https://www.nociones.de/instalacion-y-primeros-pasos-con-influxdb-en-ubuntu-18-04/#Que_es_InfluxDB