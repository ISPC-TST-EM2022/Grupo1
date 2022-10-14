from machine import Pin
import time

pinRele = pinPir = Pin(22, Pin.OUT, Pin.PULL_UP)  # Pin de salida para el rele
pinRele.off()
p2 = Pin(2, Pin.OUT)
pbuz = Pin(23, Pin.OUT, Pin.PULL_UP)  # buzzer en pin 23 como salida
pbuz.off()  # buzzer apagado
pinPir = Pin(4, Pin.IN, Pin.PULL_UP)  # sensor de presencia en pin 4 como entrada
pinPir.off()  # sensor Pir apagado
pinMag = Pin(15, Pin.IN)  # sensor magnetico como entrada en pin 15
pinMag.off()  # sensor magnetico apagado


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
    while Presencia():  # si hay presencia
        Advertencia()  # se activa la advertencia
      
    val = pinMag.value()
    if val == 0:
        Alarma()

