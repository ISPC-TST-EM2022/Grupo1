#include <Arduino.h>

/* Definiciones */

/* Variables */

bool flag = false; // Bandera para indicar la lectura de la secuencia de bits desde el puerto serial

int num1;   // Variable Auxiliar para recorrer los Pines
String cod; // Varaible para almacenar la secuencia de bits ingresada

/* SETUP */
void setup()
{
    Serial.begin(9600);          // Inicializacion del puerto serial
    for (int i = 2; i <= 9; i++) // Incializo cada pin como Salida
    {
        pinMode(i, OUTPUT);
    }
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
        cod = Serial.readString(); // Leo la secuencia de bits como cadena de caracteres
        Serial.println("");

        flag = true; // Cambio bandera para no repetir mensaje
    }
    num1 = 2;                   // Pin incial
    for (int i = 0; i < 8; i++) // Recorro cadena caracter a caracter
    {
        if ((cod[i] == '1') or (cod[i] == '0')) // Chequeo que sean bits
        {
            if (cod[i] == '1') // Si el bit es 1 enciendo led
            {
                analogWrite(num1, 255); // Enciendo led
            }
            num1++; // paso al siguiente pin
        }
    }
}