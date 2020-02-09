# Grafana en UBUNTU

A continuación, se describen los pasos básicos para instalar y configurar Grafana en Ubuntu

## Instalación

Descargar .deb correspondiente a nuestra arquitectura.

https://grafana.com/grafana/download


### Instalar Grafana

Desde la terminal, 

```
sudo apt-get install -y adduser libfontconfig1
wget https://dl.grafana.com/oss/release/grafana_6.6.0_amd64.deb
sudo dpkg -i grafana_6.6.0_amd64.deb
```

## Habilitar e inicar el servicio grafana 

```
sudo systemctl enable grafana-server
sudo systemctl start grafana-server

```
## Acceso a Grafana

Las credenciales predeterminadas son **admin/admin**
```
http://SERVER_IP:3000
```

## Notas
Si instalas un plugin nuevo, debes reiniciar el servicio de Grafana con el siguiente comando:
```
sudo systemctl restart grafana-server
```
## Enlaces complementarios

* https://grafana.com/docs/grafana/latest/installation/debian/
* https://grafana.com/grafana/download