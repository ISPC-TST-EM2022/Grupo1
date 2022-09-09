#include <Arduino.h>

/* Definiciones */

/* Variables */

bool flag = false; // Flag para indicar laa lectura de numeros desde el puerto serial

int num1, num2, suma = 0; // Variables para almacenar los numeros ingresados y calcular la suma

/* SETUP */

void setup()
{
    Serial.begin(9600);                                             // Inicializacion del puerto serial
    Serial.println("Programa para la suma de dos numeros enteros"); // Breve intro al programa
    Serial.println("");
}

void loop()
{

    if (!flag)
    {
        Serial.println("Ingrese el primer numero entero para sumar:");
        while (!Serial.available())
        {
            //   // Espera a que el usuario ingrese un valor
        }
        num1 = Serial.parseInt(); // almaceno el primer numero
        Serial.println(' ');
        Serial.println("Ingrese un Segundo num para sumar:");
        while (!Serial.available())
        { //   // Espera a que el usuario ingrese un valor
        }
        num2 = Serial.parseInt(); // Almaceno el segundo numero
        Serial.println(' ');
        delay(200);
        Serial.print("La suma es: ");
        Serial.println(num1 + num2); // Muestro y calculo la suma de los 2 numeros ingresados
        Serial.println(' ');
        flag = true; // Cambio bandera para queno se repita mensaje
    }
}