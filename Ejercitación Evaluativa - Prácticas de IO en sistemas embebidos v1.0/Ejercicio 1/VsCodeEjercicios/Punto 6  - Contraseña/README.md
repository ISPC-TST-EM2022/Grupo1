
## 6. Realizar una función bool cerradura({tipo} clave); que retorne true cuando la clave 
## numérica sea 2147483648. Elija el “tipo” de dato apropiadamente. Implemente el 
## circuito que active un rele; Utilice el terminal virtual.

# Desarrollo:
	Utilizando VS Code con la extensión de plataformIO se desarrolo un codigo<br />
	para que el usuario ingrese una clave válida(para éste ejercicio: 2147483648),<br />
	la misma se solicita por pantalla, el programa muestra el la terminal virtual si<br />
	la clave es correcta o no. En caso de ser incorrecta se vuelve a solicitar hasta que<br />
	la misma sea válida.<br />
# Simulación:	
	En Proteus, a través de La terminal virtual se solcita al usuario que ingrese una clave valida<br />
	Si es incorrecta muestra un mensaje y sigue solicitando la clave.<br />
	Si es correcta muestra un mensaje, y como solicita el ejercicio, activa un rele y<br />
	se enciende un iodo led para una mejor visualizacion del resultado.<br />
	Para dicho caso se elige el pin 10 del puerto B.<br />
