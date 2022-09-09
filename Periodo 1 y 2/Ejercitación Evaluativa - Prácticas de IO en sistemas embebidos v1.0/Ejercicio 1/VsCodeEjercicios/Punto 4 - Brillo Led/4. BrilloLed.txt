#include <Arduino.h>

/* Definiciones */

/* Variables */

bool flag = false; // Bandera para indicar la lectura del brillo solicitado desde el puerto serial
int pin = 3;       // Se elige el pin 3 del puerto D para la simulación en proteus
int brillo;        // Variable donde se alacena el valor ingresado

/* SETUP */
void setup()
{
    Serial.begin(9600); // Inicializacion del puerto serial
    Serial.println("Ingrese un valor entre 0 y 255");
    Serial.println("Para indicar la intensidad de brillo del led"); // Breve intro al programa
}

void loop()
{
    if (!flag)
    {
        while (!Serial.available())
        {
            // Espera a que el usuario ingrese los datos
        }
        brillo = Serial.parseInt();     // Leo el valor para el brillo
        if (brillo < 0 or brillo > 255) // Chequeo que el valor se valido
        {
            Serial.println("Valor incorrecto. Ingrese un valor entre 0 y 255");
        }
        else
        {
            flag = true; // Indico que ya leí el valor correcto
        }
    }
    analogWrite(pin, brillo); // Doy el brillo ingresado a el pin elegido
}