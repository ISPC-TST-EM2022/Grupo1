#define BLYNK_TEMPLATE_ID "TMPLMCxuUHG0"                    // Id del dipositivo en app movil Blynk
#define BLYNK_DEVICE_NAME "temperatura "                    // Nobre del dispositivo en app movil Bynk
#define BLYNK_AUTH_TOKEN "x-pr6jh-fBK2H1pEFyDtAIJnvNUouQHk" // Token otorgado por app movil Bynk
#define BLYNK_PRINT Serial

#include <WiFi.h>             // Librería para conexión WIFI
#include <WiFiClient.h>       //Libre de uso para WIFI
#include <BlynkSimpleEsp32.h> // Libreria de interfaz entre modulo y app Blynk
#include <DHT.h>              // Libreria de sensor DHT11
#include <DHT_U.h>            // Librería de control DTH11
#include <NewPing.h>          // Libreria par facilitar el uso del sensor de ultrasonido
#include <ESP32Servo.h>       //  librería para controlar el servomotor SG90

char auth[] = BLYNK_AUTH_TOKEN; // Variable para token Blynk
                                // para definir con que frecuencia se envian datos a la app Blynk
char ssid[] = "Familia 2.4GHz"; // Variable con Nombre de red WIFI
char pass[] = "01427077394";    // Variable con Contraseña WIFI

Servo servoMotor; // variable para controlar el servoSg90

#define DHTPIN 13 // PIN digital elegido para obter datos del Sensor DHT11(temperatura y humedad)

#define DHTTYPE DHT11 // difino cual es el sensor que ese usa, en este caso DHT 11

DHT dht(DHTPIN, DHTTYPE); // Inicializo el sensor DHT11

// aqui hay que definir Trig y Echo
#define trigPin 12
#define echoPin 18

#define DistanciaTope 250 // Defino la distancia máxima en centimetros

NewPing Sonar(trigPin, echoPin, DistanciaTope); // Creo objeto llamado Sonar para tomar valor del ultrasonido
BlynkTimer timer;                               // para definir con que frecuencia se envian datos a la app Blynk
// Motores A
int IN1 = 5;  // Asigno pin 4 al pin 1 del lado A del driver L298N
int IN2 = 4;  // Asigno pin 2 al pin 1 del lado A del driver L298N
int ENA = 15; // Asigno pin pin 15 para la habilitacion de motores del lado A
// Motores B
int IN3 = 27; // Asigno pin 27 al pin 1 del lado B del driver L298N
int IN4 = 26; // Asigno pin 26 al pin 1 del lado B del driver L298N
int ENB = 25; // Asigno pin pin 14 para la habilitacion de motores del lado B

bool adelante = 0; // variable logica para controlar auto hacia adelante
bool atras = 0;    // variable logica para controlar auto hacia adtras
bool izq = 0;      // variable logica para controlar auto hacia izquierda
bool der = 0;      // variable logica para controlar auto hacia aderecha

void RegistroTempHum() ////// -------Funcion para obtener temperatura y humedad---------//////
{
  float h = dht.readHumidity();    // Tomo en la variable el dato de la humedad
  float t = dht.readTemperature(); // Tomo en la variable el dato de la humedad

  if (isnan(h) || isnan(t)) // Chequeo que las lecturas sean correctas
  {
    Serial.println("Error al obtener lecturas del sensor!"); // Pruebas por pantalla serie
    return;
  }

  Blynk.virtualWrite(V5, h); // Entrego la lectura de humedad al pin virtual en la app Blynk
  Blynk.virtualWrite(V6, t); // Entrego la lectura de humedad al pin virtual en la app Blynk

} //---------------- Fin funcion RegistroTempHum()------------------//

void setup() ////////////---- SETUP Configuracion Inicial ----------//////////////
{

  Serial.begin(9600);                        // Inicializo puerto Serie
  servoMotor.attach(19);                     //  El servo va a trabajar con el pin 13
  servoMotor.write(90);                      // Inicializo en ángulo 90 del servo motor
  Blynk.begin(auth, ssid, pass);             // Inicializo app Blynk con datos de WIFI
  dht.begin();                               // Inicializo el sensor DTH
  timer.setInterval(5000L, RegistroTempHum); // envio cada 5 segundos informancion del sensor DHT11
  ///////// Todos los pines involucrados con los motores como salida//////////////
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(2, OUTPUT);

} /////////////--------------- Fin SETUP --------------//////////////////

void Detenido() //////// Funcion que detiene todos los motores/////////
{
  servoMotor.write(90);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0); // Velocidad motor A
  //  Direccion motor B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0); // Velocidad motor B
}
void Adelantar() ///////////Funcion para mover hacia adelante el auto/////////////
{
  servoMotor.write(90);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 255); // Velocidad motor A
  // Direccion motor B
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 255); // Velocidad motor B
}

void Retroceso() //////// Funcion para mover hacia atras el auto //////////////
{
  servoMotor.write(90);
  // Direccion motor A
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 200); // Velocidad motor A
  // Direccion motor B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 200); // Velocidad motor B
}
void HaciaIzquierda() /////// Funcion para girar hacia la izquierda el auto///////////
{
  servoMotor.write(135);
  // Direccion motor A
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 200); // Velocidad motor A
  // Direccion motor B
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0); // Velocidad motor B
}
void HaciaDerecha() //////////// Funcion para girar hacia la derecha el auto ////////////////
{
  // Direccion motor A
  servoMotor.write(45);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0); // Velocidad motor A
  // Direccion motor B
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 200); // Velocidad motor B
}
BLYNK_WRITE(V0) // funcion para registro de dato en pin virtual de app Blynk
{
  adelante = param.asInt(); // Si es valor es 1 el auto va ahcia adelante
}

BLYNK_WRITE(V1) // funcion para registro de dato en pin virtual de app Blynk

{
  atras = param.asInt(); // Si es valor es 1 el auto va ahcia atras
}
BLYNK_WRITE(V2) // funcion para registro de dato en pin virtual de app Blynk
{
  izq = param.asInt(); // si es valor es 1 el auto gira a la izquierda
}

BLYNK_WRITE(V3) // funcion para registro de dato en pin virtual de app Blynk
{
  der = param.asInt(); // si es valor es 1 el auto gira a la derecha
}
void MoverAuto() ////// Funcion para combinar joystick digital con movimientos///////
{
  delay(200);
  int distancia = Sonar.ping_cm();                            // variable que obtiene en valor del Sonar(ultrasonido)
  Serial.println("Distancia = " + String(distancia) + " CM"); // Pruebas por pantalla serie
  if (distancia > 30)
  {
    if (adelante == 1)
    {
      Adelantar();
    }
    else if (atras == 1)
    {
      Retroceso();
    }
    else if (izq == 1)
    {
      HaciaIzquierda();
    }
    else if (der == 1)
    {
      HaciaDerecha();
    }
    else if (adelante == 0 && atras == 0 && izq == 0 && der == 0)
    {
      Detenido();
    }
  }
  else
  {
    Detenido();
    delay(200);
    Retroceso();
    delay(400);
    Detenido();
  }
  if ((distancia < 30))
  {
    digitalWrite(2, HIGH);
  }
  else
  {
    digitalWrite(2, LOW);
  }
} ///////////// fin funcion mover auto/////////////////

void loop() /////////---------------Ejecucion del Loop------------------ //////////
{
  Blynk.run(); // Ejecuto plataforma Blynk para conexion y transmision de datos
  timer.run(); // Ejecuto temporizado para el envio de datos
  MoverAuto(); // Movilidad del auto robot
}

//////////////////////////////////////////////////////////////////
