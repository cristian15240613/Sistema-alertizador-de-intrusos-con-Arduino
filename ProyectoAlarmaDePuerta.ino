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

#define ledPuerta 7         // Pin de salida del Led
#define ledStandby 13
#define entradaPuerta 3     // Pin de entrada del readSwitch (Simulando la puerta)
#define alarma 6            // Pin de salida de la alarma
int frecuencia = 440;       // Frecuencia de salidas de la alarma (440 es la nota LA)
int estadoPuerta = 0;       // Variable de alamacenamiento del estado del readSwitch

void setup() {
  pinMode(ledPuerta, OUTPUT);       // Modo del pin del led en OUTPUT
  pinMode(entradaPuerta, INPUT);    // Modo del pin del readswitch en INPUT
  attachInterrupt(digitalPinToInterrupt(entradaPuerta), interrupcion, RISING);    // Configuración de la interrupción
}

void loop() {
  estadoPuerta = digitalRead(entradaPuerta);    // Guardado del estado del readSwitch
  
  if(estadoPuerta == LOW){        // Si no está accionado el readSwitch
    digitalWrite(ledStandby, LOW);
    digitalWrite(ledPuerta, HIGH);    // Enciende el led
    tone(alarma, frecuencia);         // Enciende la alarma con la frecuencia marcada
    delay(1500);                      // Espera de un segundo y medio
    digitalWrite(ledPuerta, LOW);     // Apaga el led
    noTone(alarma);                   // Apaga la alarma
    
  }else{                          // En caso contrario
    digitalWrite(ledPuerta, LOW);     // El led debe permanecer apagado
    noTone(alarma);                   // La alarma debe permanecer apagada
    digitalWrite(ledStandby, HIGH);
  }
}

void interrupcion(){  // Proceso de interrupción
  
}
