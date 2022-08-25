
## 5. Ingresar una secuencia de 8 bits por terminal , que activaran los leds 
## correspondientes por el puerto D. 

# Desarrollo:
	Utilizando VS Code con la extensión de plataformIO se desarrolo el codigo<br />
	para que el usuario ingrese una secuencia de 8 bits por terminal virtual,<br />
	Dicha secuencia enciende una led si el bit es 1, en correlacion a los bits ingresados.<br />
Nota: el ejercicio solicta que se utilice el puerto D(de 8 pines), pero los dos primeros(0 y 1)<br />
están siendo utilizados para la terminal virtual. Por lo tanto, en la ejecucion se detiene<br />
el monitor serie y se inicializan como salida los pines correspondientes<br />
	
# Simulación:	
	En Proteus, a través de La terminal virtual se solcita al usuario que ingrese la <br />
	secuencia de 8 bits, y se le advierte que de no ingresar datos validos(0 y 1) la secuencia<br />
	no será válida.<br />
	la posicion de cada bits va desde 0 a 7 y se corresponde a cada pin desde 0 a 7.<br />
	Si el bit ingresado es 1 en cierta posicion, se enciende el diodo led correspondiente<br />
	a dicha posicion:<br />
	Pin 0	posición 0<br />
	Pin 1	posición 1<br />
	Pin 2	posición 2<br />
	Pin 3	posición 3<br />
	Pin 4	posición 4<br />
	Pin 5	posición 5<br />
	Pin 6	posición 6<br />
	Pin 7	posición 7<br />
