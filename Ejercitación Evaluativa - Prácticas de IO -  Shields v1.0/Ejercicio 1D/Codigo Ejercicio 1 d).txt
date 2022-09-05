#include <Wire.h>             // libreria del puerto I2c
#include <Adafruit_GFX.h>     // libreria para visulizar texto y grafico en la pantalla
#include <Adafruit_SSD1306.h> // libreria del controlador SSD1306

#define ANCHO_PANTALLA 128 // defino en 128 pixeles el ancho de la pantalla
#define ALTO_PANTALLA 64   // defino en 64 pixeles el alto de la pantalla

Adafruit_SSD1306 display(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire, -1); // Se genera la pantalla ccon los parametros indicados

void setup()
{

  Wire.begin(); // inicializacion de puerto I2C

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // inicializo pantalla con variable para la alimentacion definida por la libreria(3.3v) y la direccion pra identificarla
}

void loop()
{
  display.clearDisplay();      // limpio pantalla
  display.setTextSize(1);      // doy tamaño al texto
  display.setTextColor(WHITE); // color para el texto
  display.setCursor(20, 20);   // inicio cordenadas para el texto
  display.println("  NO Es facil ");
  display.setCursor(20, 30);
  display.println(" el desarrollo ");
  display.setCursor(20, 40);
  display.println("  con shields ");
  display.display(); // Muestro por pantalla lo anterior
}