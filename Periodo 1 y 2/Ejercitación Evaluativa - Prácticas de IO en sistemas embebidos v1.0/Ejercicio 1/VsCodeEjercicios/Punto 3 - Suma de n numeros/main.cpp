#include <Arduino.h>

/* Definiciones */

/* Variables */

bool flag = false; // Flag para indicar una lectura de datos desde el puerto serial

int cont = 0, num1 = 0, cant = 0, suma = 0; // Variables para almacenar la cantidad de numeros, hacer la suma,
                                            // obtener el numero por pantalla y controlar la cantidad de instancias

/* SETUP */
void setup()
{
    Serial.begin(9600);                                                     // Inicializacion del puerto serial
    Serial.println("Programa para sumar una cantidad de numeros deseados"); // Breve intro al programa
    Serial.println("");
}

void loop()
{
    if (!flag)
    {
        delay(150);
        Serial.print("Ingrese la cantidad de numeros a sumar: "); // Solicito la cantidad numeros a sumar
        while (!Serial.available())
        {
            // Espera a que el usuario ingrese un valor
        }
        cant = Serial.parseInt(); // variable para la cantidad de numeros
        Serial.println(' ');
        while (!flag) // Pido numeros hasta la cantidad indicada
        {
            delay(150);
            Serial.print("Ingrese un numero para sumar: "); // Solicito el numero
            while (!Serial.available())
            { //   // Espera a que el usuario ingrese un valor
            }
            num1 = Serial.parseInt(); // Almaceno en numero de la instancia
            suma = suma + num1;       // Realizo la suma
            cont++;                   // controlo la cantidad de numeros ingresados
            if (cont == cant)         // cuando el control llega a la misma cantidad
            {
                Serial.println(' ');
                Serial.print("La suma es: "); // Muestro la suma
                Serial.println(suma);
                Serial.println(' ');
                Serial.print("El promedio es: ");
                Serial.println(suma / cant);
                flag = true; // y detengo la repeticion del mensaje
            }
        }
    }
}
