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

#define ledPuerta 7
#define entradaPuerta 3

void setup() {
  Serial.begin(9600);
  pinMode(ledPuerta, OUTPUT);
  pinMode(entradaPuerta, INPUT);
  attachInterrupt(digitalPinToInterrupt(entradaPuerta), interrupcion, RISING);

}

void loop() {
  digitalWrite(ledPuerta, HIGH);
  delay(500);
  digitalWrite(ledPuerta, LOW);
  delay(500);

}

void interrupcion(){
  Serial.println("Interrupcion");
}
