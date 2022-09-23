## **Explicando funcionalidad**
Como se ve en el video nuestro TANGO06, auto robot de 4 ruedas y 4 motores con tracción en todos, alimentados estos últimos con batería recargable de 12v(no se ven, están entre chasis), y controlados por un drive L298N(tampoco se me muy bien aquí), implementado el proyecto con una placa de desarrollo ESP32, en este caso NodeMCU
de 30 pines, que controla propiamente los 4 motores a  través del puente L298N, un servo motor SG90 con posición fija en centro(90°) haciendo ángulos de + - 45° según hacia donde gire el robot(izquierda o derecha) acompañando el movimiento, el mismo tiene montada una estructura para sostener un sensor de ultrasonido, en este caso el modelo HC-SR04, que cumple la función de detectar y hacer evitar obstáculos al robot.<br />
Para esta demostración, como el auto es controlado manualmente, la actitud evasiva es frenarse al encontrar un objeto a menos de 30 cm, detenerse, retroceder medio segundo de tiempo, y esperar detenido el próximo comando de quien lo opera. Para distinguir éste accionar (el sensor detecta un objeto) se hace encender el led azul integrado en la ESP32.<br />
Además, el auto robot para cumplir el propósito específico, cuenta con un sensor de temperatura y humedad, modelo DHT11, que tampoco se ve, ya que se encuentra entre chasis.<br />
Este último, al igual que la placa ESP32, el motor servo y el sensor de ultrasonido están alimentados con un rack de 4 pilas AA de 1.5v.<br />
Para comandar el auto robot, se eligió Blynk, una plataforma de internet de las cosas (IoT) de marca blanca que ofrece software, firmware, soluciones web y aplicaciones móviles a miles de pequeñas, medianas y grandes empresas de todo el mundo y es muy popular. Sirve para conectar dispositivos a la nube, diseñar aplicaciones para controlarlos y supervisarlos de forma remota, y administrar miles de productos implementados.<br />
<br />
<br />
![image](https://user-images.githubusercontent.com/110072008/191876814-94c83670-7be3-4e1f-b07f-95930612ebd9.png)
<br />
<br />
En nuestro caso, utilizamos la App Móvil para simular un joystick de 4 botones (Adelante, Atrás, Derecha, Izquierda) que se encarga de dirigir los movimientos del auto, a través de una conexión WIFI inicial, que como se ve en lo últimos segundos, se desconecta la señal WIFI de Móvil, y el auto sigue conectado al mismo quedando establecida una conexión temporal entre ambos dispositivos.<br />
<br />
![image](https://user-images.githubusercontent.com/110072008/191876867-575621bb-593d-4b52-b6c6-858d929e413c.png)
<br />
<br />
La utilización de la plataforma es muy sencilla, se descarga la App móvil al teléfono, y también se puede utilizar la consola a través de su página web: https://blynk.io/
<br />
<br />
![image](https://user-images.githubusercontent.com/110072008/191876890-fa9d3a08-e84d-4260-8c8e-85aacb63b57e.png)
<br />
<br />
Desde la aplicación móvil se puede crear un usuario e ingresar luego de un mail de confirmación, y en la versión gratuita se puede utilizar hasta dos placas de desarrollo, se crea un proyecto eligiendo la placa y tipo de conexión.
<br />
<br />
![image](https://user-images.githubusercontent.com/110072008/191876945-18d71c92-c226-43a7-abc6-827489168435.png)
<br />
<br />
Se genera un Token, que actualemte se envía por mail, que junto con el nombre del proyecto y un ID del mismo, que servirá para la implementación del código donde se podrá establecer la conexión entre la placa y la plataforma.<br />
Para ello existe una librería llamada Blynk, en nuestro caso incluiremos en nuestro código la sentencia: #include <BlynkSimpleEsp32.h>.<br />
Tanto disponible en Arduino IDE como en PlatformIO.<br />
En el modo de desarrollador podemos realizar nuestra App de propósito.
<br />
<br />
![image](https://user-images.githubusercontent.com/110072008/191877034-02e608a8-be61-4262-9964-5409d4dbeed1.png)![image](https://user-images.githubusercontent.com/110072008/191877041-1052e541-03a1-4769-acea-71002d540292.png)
<br />
<br />
Como se observa en la imagen de arriba las variables V1, V2, V3 Y V4 representan pines “virtuales” lo cuales pueden ser asociados correctamente dentro de la implementación de código a pines propios de la placa, o a cualquier dato, valor o registro que la misma pueda parametrizar, y así ser enviado a la nube propia de Blynk y ser visualizada en su app.<br />
También en la imagen se ven definidos los pines virtuales V5 y V6 que representan la humedad y temperatura respectivamente, valores que son tomados por el sensor DHT11, que a través de la placa, el uso de la librería de Blynk, y el desarrollo correcto para obtener esos valores , se los puede observar en la App móvil instantáneamente.<br />
Se puede ver en el video demostrativo que la humedad comienza el 20%, baja a 18% y termina en 32%.<br />
La temperatura no varió por estar dentro del mismo espacio reducido.<br />
Cumpliendo así con el proyecto del auto robot, transformándose en un termómetro móvil.<br />




## **Videos de pruebas y presentaciones del prototipo**<br />



https://user-images.githubusercontent.com/98425890/191367561-6fd66b97-0647-47c9-959d-df17609023cf.mp4

<br />
<br />

https://user-images.githubusercontent.com/98425890/191367609-da9fbb38-49bc-4bca-8253-b68af4e093d6.mp4

<br />
<br />

## **Imágenes del grupo trabajando en el proyecto**<br />
<br />
<br />

![WhatsApp Image 2022-09-17 at 16 04 15](https://user-images.githubusercontent.com/98425890/191368559-6df27015-76ac-408a-ae79-1ab5fd8a80e6.jpeg)
<br />
<br />

![WhatsApp Image 2022-09-17 at 16 04 46](https://user-images.githubusercontent.com/98425890/191368613-cdbcae79-39bc-45d6-a909-bfa6c4540df6.jpeg)
<br />
<br />

![WhatsApp Image 2022-09-17 at 16 04 38](https://user-images.githubusercontent.com/98425890/191368639-1290b414-f41e-421d-98fd-d11e5f769457.jpeg)
<br />
<br />

![WhatsApp Image 2022-09-20 at 17 22 51](https://user-images.githubusercontent.com/98425890/191368722-465be86f-c426-4979-a1b3-4c5012962953.jpeg)
<br />
<br />

![WhatsApp Image 2022-09-17 at 16 04 50](https://user-images.githubusercontent.com/98425890/191368845-26c05d34-f616-4c9e-b4af-32c581fb60df.jpeg)
<br />
<br />

![WhatsApp Image 2022-09-17 at 15 44 33 (1)](https://user-images.githubusercontent.com/98425890/191368908-09ecfc80-a959-4b6e-963b-1db0ea97e15c.jpeg)

