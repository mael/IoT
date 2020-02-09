# Instalación Node-RED

```
sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install curl
bash <(curl -sL https://raw.githubusercontent.com/node-red/linux-installers/master/deb/update-nodejs-and-nodered)
```

### Ejecutar
Desde el entorno gráfico o mendiante este comando en la terminal 
```
node-red
```
Desde una navegador ir a:
```
http://<hostname>:1880
```

### Instalar plugins 

Directorio de plugins para Node-RED https://flows.nodered.org/search?type=node

Para inslatar un plugin, abrir una terminal y ejecutar:
```
cd  ~.node-red/
npm install <nombre del paquete>
```

O desde el navegador web: Menu > Settings > Palette > Install

## Enlaces complementarios

* https://nodered.org/docs/getting-started/raspberrypi
* https://cookbook.nodered.org/#mqtt
* https://flows.nodered.org/node/node-red-node-random
* https://flows.nodered.org/node/node-red-contrib-telegrambot