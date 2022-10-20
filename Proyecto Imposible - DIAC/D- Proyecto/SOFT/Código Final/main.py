import BlynkLib  # Libreria Blynk
import network  # Libreria para conectarse a la red wifi
from machine import Pin  # Libreria para manejar los pines
import time  # Libreria para manejar el tiempo

WIFI_SSID = "Familia 2.4GHz"  # Nombre de la red wifi
WIFI_PASS = "01427077394"  # Contraseña de la red wifi
BLYNK_AUTH = "x-pr6jh-fBK2H1pEFyDtAIJnvNUouQHk"  # Token de la aplicacion Blynk

print("Connecting to WiFi network '{}'".format(WIFI_SSID))  # Conectando a la red wifi
wifi = network.WLAN(network.STA_IF)  # Creando objeto wifi
wifi.active(True)  # Activando wifi
wifi.connect(WIFI_SSID, WIFI_PASS)  # Conectando a la red wifi
while not wifi.isconnected():
    time.sleep(1)  # Esperando a que se conecte a la red wifi
    print("WiFi connect retry ...")  # Reintentando conexion a la red wifi
print("WiFi IP:", wifi.ifconfig()[0])  # Imprimiendo la IP de la red wifi

print("Connecting to Blynk server...")  # Conectando a la aplicacion Blynk
blynk = BlynkLib.Blynk(BLYNK_AUTH)
time.sleep_ms(5000)
# Definiendo los pines
pinRele = pinPir = Pin(22, Pin.OUT, Pin.PULL_UP)  # Pin de salida para el rele
pinRele.off()
p2 = Pin(2, Pin.OUT)
pbuz = Pin(23, Pin.OUT, Pin.PULL_UP)  # buzzer en pin 23 como salida
pbuz.off()  # buzzer apagado
pinPir = Pin(4, Pin.IN, Pin.PULL_UP)  # sensor de presencia en pin 4 como entrada
pinPir.off()  # sensor Pir apagado
pinMag = Pin(15, Pin.IN)  # sensor magnetico como entrada en pin 15
pinMag.off()  # sensor magnetico apagado

encendido = False  # Variable global para encender y apagar el dispositivo


@blynk.on("V7")  # Boton para encender y apagar el dispositivo
def v7_write_handler(value):  # Funcion para encender y apagar el dispositivo
    global encendido
    if value == ["1"]:
        p2.on()
        encendido = True
        blynk.virtual_write(1, " ")
        print("Dispositivo Encendido")
    else:
        p2.off()
        encendido = False
        print("Dispositivo Apagado")


activar = False  # Variable global para activar y desactivar la alarma


@blynk.on("V0")  # Boton para activar y desactivar la alarma
def v0_write_handler(value):  # Funcion para activar y desactivar la alarma
    global activar
    if value == ["1"]:
        activar = True
        print("Alarma activada por el usuario")
    else:
        activar = False
        print("Alarma desactivada por el usuario")


cant = 1


@blynk.on(
    "V2"
)  # Boton slider para configurar con que cantidad de presencias se activa la alarma
def v2_write_handler(value):  # funcion para leer el valor del slider
    global cant
    cant = int(value[0])
    print("Cantidad de veces: ", cant)


def Advertencia():  # Advertencia sonora de unos 10 segundos

    for i in range(5):
        pbuz.on()
        time.sleep_ms(200)
        pbuz.off()
        time.sleep_ms(200)


def Presencia():  # Alarma con sensor de presencia
    if pinPir.value() == 1:
        return True
    else:
        return False


def Alarma():  # Alarma sonora con bocina

    pinRele.on()
    time.sleep_ms(600)
    pinRele.off()
    time.sleep_ms(600)


def Magnetico():  # Alarma con sensor magnetico

    if pinMag.value() == 1:
        return True
    else:
        return False


cont = 0

while 1:  # Bucle infinito
    blynk.run()  # Corriendo la aplicacion Blynk

    if encendido:  # boton de encendido y apagado
        if Presencia():  # si hay presencia
            cont += 1
            blynk.virtual_write(1, "N° Presencia: ", cont)
            if (
                cont <= cant
            ):  # si la cantidad de presencias es menor a la elegida por el usuario
                Advertencia()
            else:
                blynk.virtual_write(0, 1)  # enciende el boton de la alarma
                activar = True  # activa la alarma
                if activar:  # si la alarma esta activada
                    Alarma()
                    print("Alarma por presencia")
                cont = 0
                blynk.virtual_write(1, " ")
        if Magnetico():  # si magnetico esta cerrado o no
            pass
        else:
            print("Alarma por sensor magnetico")
            blynk.virtual_write(0, 1)  # enciende el boton de la alarma
            activar = True
            if activar:
                Alarma()

    if activar:  # boton de activar y desactivar alarma
        Alarma()
