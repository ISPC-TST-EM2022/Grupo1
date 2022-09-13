
## 6. Realizar una función bool cerradura({tipo} clave); que retorne true cuando la clave 
## numérica sea 2147483648. Elija el “tipo” de dato apropiadamente. Implemente el 
## circuito que active un rele; Utilice el terminal virtual.

### Desarrollo:
	Utilizando VS Code con la extensión de plataformIO se desarrolo un codigo
	para que el usuario ingrese una clave válida(para éste ejercicio: 2147483648),
	la misma se solicita por pantalla, el programa muestra el la terminal virtual si
	la clave es correcta o no. En caso de ser incorrecta se vuelve a solicitar hasta que
	la misma sea válida.
### Simulación:	
	En Proteus, a través de La terminal virtual se solcita al usuario que ingrese una clave valida
	Si es incorrecta muestra un mensaje y sigue solicitando la clave.
	Si es correcta muestra un mensaje, y como solicita el ejercicio, activa un rele y
	se enciende un iodo led para una mejor visualizacion del resultado.
	Para dicho caso se elige el pin 10 del puerto B.
