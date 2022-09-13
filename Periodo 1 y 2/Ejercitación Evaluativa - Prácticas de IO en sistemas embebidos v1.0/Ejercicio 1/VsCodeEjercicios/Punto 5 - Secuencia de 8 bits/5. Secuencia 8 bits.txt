#include <Arduino.h>

/* Definiciones */

/* Variables */

bool flag = false; // Bandera para indicar la lectura de la secuencia de bits desde el puerto serial
char buffer[9];    // Variable para almacenar secuencia de 8 bits
/* SETUP */
void setup()
{
    Serial.begin(9600); // Inicializacion del puerto serial

    Serial.println("Programa para leer una secuencia de 8 bits");
    Serial.println("que enciende un led si el bit es 1");
    Serial.println("Nota: si los valores ingresados son distintos a cero(0) y (1)");
    Serial.println("el programa no toma como valida la secuencia.");
    Serial.println(""); // Breve intro al programa y su funcionamiento
}
void loop()
{
    if (!flag)
    {
        Serial.println("Ingrese una secuencia de 8 bits"); // Menasaje para pedir secuencia
        Serial.println("");
        while (!Serial.available())
        {
            // Espera a que el usuario ingrese los datos
        }
        byte dato = Serial.readBytes(buffer, 9); // Leo secuencia de bits
        flag = true;
    }
    Serial.end(); // Detengo el puerto serie par usar pin 0 y 1 como salida

    for (int i = 0; i < 9; i++)
    {
        pinMode(i, OUTPUT);   // Declaro cada pin como salida
        if (buffer[i] == '1') // Si el bit en la posicion es 1, se enciende el led
        {
            digitalWrite(i, HIGH);
        }
    }
}