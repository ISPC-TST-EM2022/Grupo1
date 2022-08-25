
## 5. Ingresar una secuencia de 8 bits por terminal , que activaran los leds 
## correspondientes por el puerto D. 

### Desarrollo:
	Utilizando VS Code con la extensión de plataformIO se desarrolo el codigo
	para que el usuario ingrese una secuencia de 8 bits por terminal virtual,
	Dicha secuencia enciende una led si el bit es 1, en correlacion a los bits ingresados.
Nota: el ejercicio solicta que se utilice el puerto D(de 8 pines), pero los dos primeros(0 y 1)
están siendo utilizados para la terminal virtual. Por lo tanto, en la ejecucion se detiene
el monitor serie y se inicializan como salida los pines correspondientes
	
### Simulación:	
	En Proteus, a través de La terminal virtual se solcita al usuario que ingrese la 
	secuencia de 8 bits, y se le advierte que de no ingresar datos validos(0 y 1) la secuencia
	no será válida.
	la posicion de cada bits va desde 0 a 7 y se corresponde a cada pin desde 0 a 7.
	Si el bit ingresado es 1 en cierta posicion, se enciende el diodo led correspondiente
	a dicha posicion:
	Pin 0	posición 0
	Pin 1	posición 1
	Pin 2	posición 2
	Pin 3	posición 3
	Pin 4	posición 4
	Pin 5	posición 5
	Pin 6	posición 6
	Pin 7	posición 7
