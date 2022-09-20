### **Codigos de prueba**<br />

Archivos con codigo donde se probó el funcionamiento de cada sensor.
Tambien dejo videos del funcionamiento.<br />

// Incluímos la librería para poder controlar el servo
#include <ESP32Servo.h><br />
// Declaramos la variable para controlar el servo
Servo servoMotor;<br />
void setup() {<br />
  // Iniciamos el monitor serie para mostrar el resultado<br />
  Serial.begin(9600);<br />
  // Iniciamos el servo para que empiece a trabajar con el pin 9<br />
  servoMotor.attach(13);<br />
  // Inicializamos al ángulo 0 el servomotor<br />
  servoMotor.write(0);<br />
}
void loop() {<br />
  // Vamos a tener dos bucles uno para mover en sentido positivo y otro en sentido negativo<br />
  // Para el sentido positivo<br />
  for (int i = 0; i <= 180; i++)<br />
  {<br />
    // Desplazamos al ángulo correspondiente<br />
    servoMotor.write(i);<br />
    // Hacemos una pausa de 25ms<br />
    delay(25);<br />
  }<br />
  // Para el sentido negativo<br />
  for (int i = 179; i > 0; i--)<br />
  {<br />
    servoMotor.write(i);<br />
    // Hacemos una pausa de 25ms<br />
    delay(25);<br />
  }<br />
  }<br />
  
  <br />
  <br />
  
## **Video de prueba Servo**<br />
https://user-images.githubusercontent.com/98425890/191370312-703f28d3-bd81-460d-bd04-4da35b60f0fe.mp4

