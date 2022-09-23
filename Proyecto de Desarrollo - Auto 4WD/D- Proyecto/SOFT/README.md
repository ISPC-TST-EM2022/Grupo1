###**Carpeta Auto 4WD**
Carpeta con el desarrollo de código para el funcionamiento del auto robot, controlar sus motores mediante una app móvil que se conecta por WIFI y un servo motor que acompaña los movimientos de giro, configurar el sensor de obstáculos, y el sensor de temperatura y humedad.

librerías utilizadas(con sintaxis del código) y breve explicación.

#include <WiFi.h>             

Librería para la conectividad Wifi entre la placa ESP32 y el teléfono móvil.

#include <WiFiClient.h>       

librería para establecer la conexión Wifi.

#include <DHT.h>              

Librería del sensor de temperatura y humedad, modelo DHT11.

#include <DHT_U.h>            

Librería para funcionalidades del sensor.

#include <NewPing.h>          

Librería que facilita la codificación para el uso del sensor de ultrasonido, en este caso el modelo HC SR-04. 

#include <ESP32Servo.h>      

Librería para controlar funcionamiento del servo motor modelo SG90

#include <BlynkSimpleEsp32.h> 

Librería para gestionar la conexión entre la placa ESP32 y el teléfono móvil, a través de la app que ofrece la plataforma Blynk, que nos permite controlar los movimientos del robot y además recibir los parámetros de lectura del sensor DHT11 y verlos de manera casi instantánea.
