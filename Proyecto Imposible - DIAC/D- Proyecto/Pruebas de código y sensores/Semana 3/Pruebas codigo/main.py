import BlynkLib
import network
import blynktimer
from machine import Pin
import time

WIFI_SSID = "Familia 2.4GHz"
WIFI_PASS = "01427077394"
BLYNK_AUTH = "x-pr6jh-fBK2H1pEFyDtAIJnvNUouQHk"

print("Connecting to WiFi network '{}'".format(WIFI_SSID))
wifi = network.WLAN(network.STA_IF)
wifi.active(True)
wifi.connect(WIFI_SSID, WIFI_PASS)
while not wifi.isconnected():
    time.sleep(1)
    print("WiFi connect retry ...")
print("WiFi IP:", wifi.ifconfig()[0])

print("Connecting to Blynk server...")
blynk = BlynkLib.Blynk(BLYNK_AUTH)


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


@blynk.on("V7")
def v7_write_handler(value):
    global encendido
    # print("Current slider value: {}".format(value[0]))
    # print(value[0])
    if value == ["1"]:
        p2.on()
        encendido = True
        print("Dispositivo Encendido")
    else:
        p2.off()
        encendido = False
        print("Dispositivo Apagado")


activar = False  # Variable global para activar y desactivar la alarma


@blynk.on("V0")
def v0_write_handler(value):
    global activar
    # print("Current slider value: {}".format(value[0]))
    if value == ["1"]:
        activar = True
        pbuz.on()
        print("Alarma activada por el usuario")
    else:
        activar = False
        pbuz.off()
        print("Alarma desactivada por el usuario")


def Advertencia():  # Advertencia sonora de unos 10 segundos
    for i in range(5):
        p2.on()
        pbuz.on()
        time.sleep_ms(200)
        p2.off()
        pbuz.off()
        time.sleep_ms(200)


def Presencia():
    if pinPir.value() == 1:
        return True
    else:
        return False


def Alarma():  # Alarma sonora con bocina

    pinRele.on()
    time.sleep_ms(600)
    pinRele.off()
    time.sleep_ms(600)


while 1:  # será con un boton de encendido y apagado
    blynk.run()
    if encendido:

        #     while Presencia():  # si hay presencia
        #         Advertencia()  # se activa la advertencia
        val = pinMag.value()
        if val == 0:
            pbuz.on()
            Alarma()
        else:
            pbuz.off()
    if activar:
        Alarma()
