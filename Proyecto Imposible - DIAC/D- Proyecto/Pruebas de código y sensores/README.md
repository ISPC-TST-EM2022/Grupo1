### **Pruebas de código en MicroPython**

Probamos dos sensores, en este caso el Sensor Magnético y el Sensor PIR,
usando la placa de desarrollo ESP 32(30 pines), un buzzer activo, y el led integrado
de la placa para visualizar el comportamiento.
Con respecto al sensor PIR, se simula una alarma de advertencia ante la presencia
de una persona por unos segundos con el buzzer. Advertencia que le llegará también al usuario.
Por otro lado, el sensor magnético se probó su funcionalidad, simulando una alarma distinta con el buzzer, en realidad se usará una bocina de automóvil para implementarlo y el magnético iría 
colocado en la masa de la rueda, y el imán en la propia cubierta.

También, probamos el modulo relé HW-482, y la bocina simulando una alarma, como se muestra
en el segundo video. Además se actualiza dicho código.

El código está implementado en MicroPython, utilizando VSCode con la extensión Pymarkr,
la placa previamente se cargó con la última versión del firmware de Micropython.

## **Video demostrativo de lo descripto incluido**


https://user-images.githubusercontent.com/109010330/195707575-e06d6121-44d4-486e-abd5-f7b727d61655.mp4

