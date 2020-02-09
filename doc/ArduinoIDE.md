# Instalación de Arduino IDE y ESP32 en UBUNTU

A continuación, se describen los pasos básicos para instalar y configurar el IDE Arduino con la placa ESP32 en Linux (Ubuntu) o versiones derivadas.

## Instalación

Si ya tienes instalado Arduino IDE (1.6 o más ) en tu equipo, puedes ir directamente al paso de **Configuración**

### Descargar Arduino IDE

Si todavía no tienes instalado Arduino, descargar la versión Linux 64-bit de la web oficial.

```
https://www.arduino.cc/en/Main/Software
```

### Instalar Arduino IDE

Desde la terminal, navegamos a la carpeta de descargas

```
cd ~/Descargas
```

Descomprimimos el archivo descargado

```
tar –xf [arduino-tar.xz]
cd [carpeta descomprimida arduino]
sudo ./install.sh
```

### Configuración

Abrir Arduino IDE para instalar la placa ESP32 e ir a **Archivo > Preferencias**, añadir

```
https://dl.espressif.com/dl/package_esp32_index.json
```

en “Additional Board Manager URLs” y pulsar el botón de “OK”.

Desde el menú de Arduino, ir a **Herramientas > Placa... > Gestor de tarjetas...**

Escribir en "Filtro de búsqueda" **ESP32** seleccionar "ESP32 by Espressif Systems" e instalar.

_Reiniciar equipo_

## Prueba de funcionamiento

Seleccionar la placa desde:

```
Herramientas > Placa > ESP32 Dev Module
```

Seleccionar puerto serie:

```
Herramientas > Puerto > /dev/ttUSBX
```

Cargaremos un ejemplo desde:

```
Archivo > Ejemplos > WiFi > WiFiScan
```

Pulsamos sobre el botón de "subir" y cuando inicie la carga en la placa pulsamos el botón de "boot"
Abrimos "Monitor Serie" y ajustamos la velocidad (baudios) según esté definida en el programa. 

***Da error py-serial***

## Errores py-serial 
Desde la terminal, instalar el siguiente paquete

```
sudo apt-get install python-serial
```

## Enlaces complementarios

- https://www.arduino.cc/
- https://vitux.com/how-to-install-arduino-ide-on-ubuntu/
- https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/
- https://www.hackster.io/patrickstrasser/install-arduino-ide-1-8-2-on-linux-8ef105
