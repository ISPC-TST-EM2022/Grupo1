
## 5. Ingresar una secuencia de 8 bits por terminal , que activaran los leds correspondientes por el puerto D. 

### Desarrollo:
	Utilizando VS Code con la extensión de plataformIO se desarrolo el codigo
	para que el usuario ingrese una secuencia de 8 bits por terminal virtual,
	Dicha secuencia enciende una led si el bit es 1, en correlacion a los bits ingresados.
#### Nota: el ejercicio solicta que se utilice el puerto D(de 8 pines), pero los dos primeros(0 y 1)
####  están siendo utilizados para la terminal virtual. Por lo tanto, del puerto D se utilizan los pines
####  desde el 2 al 7, y los pines 8 y 9 del puerto B, para un mejor manejo en el desarrolo del codigo.
	
### Simulación:	
	En Proteus, a través de La terminal virtual se solcita al usuario que ingrese la 
	secuencia de 8 bits, y se le advierte que de no ingresar datos validos(0 y 1) la secuencia
	no será válida.<br />
	la posicion de cada bits va desde 0 a 7 y se corresponde a cada pin desde 2 a 9.
	Si el bit ingresado es 1 en cierta posicion, se enciende el diodo led correspondiente
	a dicha posicion:
	Pin 2	posición 0
	Pin 3	posición 1
	Pin 4	posición 2
	Pin 5	posición 3
	Pin 6	posición 4
	Pin 7	posición 5
	Pin 8	posición 6
	Pin 9	posición 7
