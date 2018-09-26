/*
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

#include <avr/sleep.h>      // Librería de ahorro de energía

#define LED_PUERTA 7        // Pin de salida del Led

#define ENTRADA_PUERTA 3    // Pin de entrada del readSwitch (Simulando la puerta)
#define ALARMA 6            // Pin de salida de la alarma

const int FRECUENCIA = 440; // Frecuencia de salidas de la alarma (440 es la nota LA)
int estadoPuerta = 0;       // Variable de alamacenamiento del estado del readSwitch

void setup() {
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);   // Se configura el modo de bajo consumo
  pinMode(LED_PUERTA, OUTPUT);           // Modo del pin del led de la puerta
  pinMode(ENTRADA_PUERTA, INPUT);        // Modo del pin del readswitch
  attachInterrupt(digitalPinToInterrupt(ENTRADA_PUERTA), interrupcion, RISING);    // Configuración de la interrupción
}

void loop() {
  estadoPuerta = digitalRead(ENTRADA_PUERTA);    // Guardado del estado del readSwitch

  iniciaAhorro();                 // Siempre inicia el ciclo en modo ahorro de energía
  
  if(estadoPuerta == LOW){        // Si no está accionado el readSwitch
    
    digitalWrite(LED_PUERTA, HIGH);   // Enciende el led
    tone(ALARMA, FRECUENCIA);         // Enciende la alarma con la frecuencia marcada
    delay(1500);                      // Espera de un segundo y medio
    digitalWrite(LED_PUERTA, LOW);    // Apaga el led
    noTone(ALARMA);                   // Apaga la alarma
    
  }else{                          // En caso contrario
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
