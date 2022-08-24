#include <Arduino.h>

/* Definiciones */

/* Variables */

bool flag = false; // Flag para indicar una lectura de datos desde el puerto serial

String Apellido, Nombre, Direccion, Celular; // Variables para almacenar los datos ingresados

/* SETUP */
void setup()
{
    Serial.begin(9600);                                          // Inicializacion del puerto serial
    Serial.println("Programa para ingreso de datos personales"); // Breve intro al programa
    Serial.println("");
}

void loop()
{

    if (!flag)
    {
        Serial.print("Ingrese su apellido: "); // Solicito el apellido
        while (!Serial.available())
        {
        }                               // Espera los datos
        Apellido = Serial.readString(); // Guardo el dato ingresado en la variable
        Serial.print("Ingrese nombre: ");
        while (!Serial.available())
        {
        }                             // Espera los datos
        Nombre = Serial.readString(); // Guardo el dato ingresado en la variable
        Serial.print("Ingrese su direccion: ");
        while (!Serial.available())
        {
        }                                // Espera los datos
        Direccion = Serial.readString(); // Guardo el dato ingresado en la variable
        Serial.print("Ingrese su numero de celular: ");
        while (!Serial.available())
        {
        }                              // Espera los datos
        Celular = Serial.readString(); // Guardo el dato ingresado en la variable
        flag = true;                   // Cambio bandera para que no se repitan los mensajes
        Serial.println(' ');
        Serial.println("Datos cargados correctamente"); // Mensaje de carga correcta
    }
}