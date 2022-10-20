## **Explicando funcionalidad** 👇🏼👇🏼

Funcionalidad
De acuerdo a la presentación previa, el dispositivo DIAC, que previene y alerta ante la presencia humana el posible 
robo de cubiertas en un automóvil, esta implementado con una placa de desarrollo ESP32 para controlar a un sensor 
de presencia o proximidad, en este caso el modelo PIR HC-SR501, un buzzer activo, un sensor magnético del tipo 
utilizado en puertas y ventanas, como el modelo MC38, un Relé HW-482 para enviar órdenes a una bocina de 
automóvil genérica alimentada por una batería de 12 volts que cumple la función de alarma para la demostración, ya 
que todos los componentes nombrados están alimentados por un rack de 4 pilas AA, dando una alimentación de 6 
volts.
El sensor PIR cumple la función de detectar la proximidad de una presencia, y con el buzzer activo se genera una 
advertencia sonora buscando disuadir la presencia. Si esto no ocurre, luego de cierta cantidad de eventos generados 
por el señor PIR la alarma se activará, es decir, se envía una señal al relé para que active la alimentación de la bocina 
y la misma emita sonido simulando ser una alarma.
El sensor magnético se encarga de disparar la alarma en caso de ser la cubierta removida, estando el dispositivo 
activado.

El usuario interactúa con el dispositivo al través de una App en su teléfono móvil. En este caso se utilizó para la 
demostración la App Blynk en su versión free limitada.
Blynk una plataforma de internet de las cosas (IoT) de marca blanca que ofrece software, firmware, soluciones web y 
aplicaciones móviles a miles de pequeñas, medianas y grandes empresas de todo el mundo y es muy popular. Sirve 
para conectar dispositivos a la nube, diseñar aplicaciones para controlarlos y supervisarlos de forma remota, y 
administrar miles de productos implementados.

![image](https://user-images.githubusercontent.com/106460135/196862236-f208bac3-29c9-4197-bb8e-98226b36df82.png)



![image](https://user-images.githubusercontent.com/106460135/196862181-5d6269ea-f46f-4c38-9a72-9dc4f121d08c.png)


Se utiliza la App Móvil como si fuera un control remoto del dispositivo DIAC donde se puede 
encender o apagar el mismo, o se puede activar o desactivar la alarma de forma manual a
través de una conexión WIFI.
Además, en el centro se muestra el número de presencias detectadas por el sensor PIR. En la 
tercera detección directamente se activa la alarma sonora simulada con la bocina. Si es una 
falsa alarma el usuario puede desactivarla manualmente. Para este propósito lo ideal es 
utilizar notificaciones push, pero la versión free de Blynk las restringe.
La utilización de la plataforma es muy sencilla, se descarga la App móvil al teléfono, y también se puede utilizar la 
consola a través de su página web: https://blynk.io/




