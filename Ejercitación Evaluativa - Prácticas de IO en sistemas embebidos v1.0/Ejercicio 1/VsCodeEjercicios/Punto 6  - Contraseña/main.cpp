#include <Arduino.h>

/* Definiciones */

/* Variables */

bool flag = false;                // Bandera para indicar lectura de datos desde el puerto serial
String key, mykey = "2147483648"; // Clave para leer desde puerto serial, y la clave correcta
int pin = 10;                     // Elijo el pin 10 para mostrar resulado el simulacion con Proteus

/* SETUP */
void setup()
{
  Serial.begin(9600);                                            // Inicializacion del puerto serial
  pinMode(pin, OUTPUT);                                          // Configuro PIN como salida
  Serial.print("Programa para validar el ingreso de su clave."); // Intro del programa
  Serial.println("");
}
bool Cerradura(String clave) // Implementación de la funcion Cerradura, chequea si la clave ingresada es válida
{
  if ((clave.length() - 1) != (mykey.length())) // Chequeo que las claves tengan la misma longitud
  {
    return false; // Si las longitudes son distintas devuelvo Falso
  }
  else
  {
    for (int i = 0; i < 10; i++) // Chequeo caracter a caracter sí son iguales
    {
      if ((clave[i]) != mykey[i])
      {
        return false; // En el primer caso que no coincidan devuelvo Falso
      }
    }
  }
  return true; //  Si ninguna condicion anterior se cumple, la clave ingresada es valida
} // Fin función Cerradura

void loop()

{
  if (!flag)
  {
    Serial.print("Ingrese su clave por favor: "); // Menasaje para pedir clave
    Serial.println("");
    while (!Serial.available())
    {
      // Espero a que el usuario ingrese la clave
    }
    key = Serial.readString(); // Leo la clave como cadena de caracteres
    Serial.println(" ");
    flag = true;        // Cambio bandera para que no se repita el mensaje
    if (Cerradura(key)) // Invoco la funcion cerradura con la clave ingresada, solo para mostrar mensaje
    {
      Serial.println("Clave CORRECTA");
    }
    else
    {
      Serial.println("Clave INCORRECTA");
      flag = false; // Cambio bandera, para que se repita el mensaje hasta ingresar clave correcta
    }
  }
  if (Cerradura(key)) // Invoco la funcion cerradura con la clave ingresada
  {
    analogWrite(pin, 255); // Si la clave es valida, en la simulacion en proteus se activa un relé
  }
  // y se enciende un Led para mejor vizualización del resultado
}