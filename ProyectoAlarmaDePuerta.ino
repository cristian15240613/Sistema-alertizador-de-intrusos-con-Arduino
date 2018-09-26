/*
 * Tecnológico Nacional de México
 * Instituto Tecnológico de León
 * Ingeniería en Sistemas Computacionales
 * 
 * Para la materia de: Sistemas Programables
 * 
 * Desarrollo de una alarma para el acceso a una puerta.
 * Funcionamiento:
 *                - Cuando la puerta se abra, una alarma debe de sonar.
 *                - Cuando la puerta se cierre la alarma deberá de cerrar.
 * Requisitos:
 *            - Mientras la alarma no esté sonando el arduino deberá consumir
 *              la minima cantidad de energía.
 *            - Cuando la puerta se cierre debe regresar al estado de bajo consumo
 *              eléctrico.
 *            
 * Desarrollador: Angel Christian Alvarez Trujillo
 */

#include <LiquidCrystal.h>  // Librería del display LCD
#include <avr/sleep.h>      // Librería de ahorro de energía

#define LED_PUERTA 7        // Pin de salida del Led

#define ENTRADA_PUERTA 3    // Pin de entrada del readSwitch (Simulando la puerta)
#define ALARMA 6            // Pin de salida de la alarma

LiquidCrystal lcd(8,9,10,11,12,13); // Definicion de pines para envío de informacion al display
const int FRECUENCIA = 440;         // Frecuencia de salidas de la alarma (440 es la nota LA)
int estadoPuerta = 0;               // Variable de alamacenamiento del estado del readSwitch

void setup() {
  lcd.begin(16,2);                      // Se configura la resolucion del LCD
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);  // Se configura el modo de bajo consumo
  pinMode(LED_PUERTA, OUTPUT);          // Modo del pin del led de la puerta
  pinMode(ENTRADA_PUERTA, INPUT);       // Modo del pin del readswitch
  attachInterrupt(digitalPinToInterrupt(ENTRADA_PUERTA), interrupcion, RISING);    // Configuración de la interrupción
}

void loop() {
  estadoPuerta = digitalRead(ENTRADA_PUERTA);    // Guardado del estado del readSwitch

  if(estadoPuerta == LOW){        // Si no está accionado el readSwitch
    alarma();                     // Lanza advertencia
    
  }else{                          // En caso contrario
    iniciaAhorro();                   // Inicia el modo ahorro de energía
    digitalWrite(LED_PUERTA, LOW);    // El led debe permanecer apagado
    noTone(ALARMA);                   // La alarma debe permanecer apagada
  }
}

void interrupcion(){  // Proceso de interrupción
  sleep_disable();    // Desactiva el modo de bajo consumo
}

void iniciaAhorro(){
  sleep_enable();   // Iniciar el modo de bajo consumo para Arduino
  sleep_mode();     // Se activa el modo de bajo consumo
}

void alarma(){      // Metodo para indicar la advertencia
  
  for(int i = 0; i < 5; i++){
      digitalWrite(LED_PUERTA, HIGH);   // Enciende el led
      tone(ALARMA, FRECUENCIA);         // Enciende la alarma con la frecuencia marcada
      lcd.print("A L E R T A  D E");    // Impresion de leyenda en la primera fila del LCD
      lcd.setCursor(0,1);               // Cambio de puntero a la segunda fila
      lcd.print(" I N T R U S O");      // Impresion de leyenda en la segunda fila del LCD
      delay(1000);                      // Espera de un segundo
      digitalWrite(LED_PUERTA, LOW);    // Apaga el led
      noTone(ALARMA);                   // Apaga la alarma  
      lcd.clear();                      // Limpia el LCD
      delay(500);                       // Espera de medio segundo para volver a iniciar el tono y la luz
    } 
}
