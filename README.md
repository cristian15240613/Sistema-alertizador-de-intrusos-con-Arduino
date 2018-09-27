# Práctica 2
## Sistema alertizador de intrusos

###### Desarrollado por: Angel Christian Alvarez Trujillo
###### [Facebook](https://www.facebook.com/cristian.alvarez06)

<center><b>
Tecnológico Nacional de México <br>
Instituto Tecnológico de León <br>
Ingeniería en Sistemas Computacionales <br>
Sistemas programables <br>
</b></center>

### Material utilizado

* 1 Resistencia 1K
* 1 Resistencia 330
* Jumpers
* Protoboard
* Arduino UNO
* 1 Potenciometro 10K
* 1 Buzzer
* 1 Display LCD 16x2
* 1 Led rojo
* 1 Reed switch
* Cable USB tipo C
* PC con SO Kubuntu 18.04
* 1 Imán

### Software utilizado
* Arduino IDE
* Kubuntu 18.04

## Librerias usadas
* LiquidCrystal.h
* avr/sleep.h

## Contenido del repositorio
* Código del programa
* Diagrama del circuito
* 2 Fotos de la implementacion en físico
* README.me (Informacion acerca de la práctica)

## Programa

El programa al iniciar detecta el estado del reed switch, en caso de no estar accionado
lo primero que siempre hace es poner al arduino UNO en estado de ahorro de energía, en caso
contrario entra a la interrupción y primero desactiva el ahorro de energía para después 
seguir con el proceso de alarma.

###### NOTA: El potenciometro actúa para modificar el contraste del LCD Display

## Funcionamiento

Al acercar un imán al reed switch este se acciona, enseguida el led rojo, el buzzer y el
display LCD entran en acción, en caso del led, este enciende un segúndo y medio y se apaga medio segundo,
en caso del buzzer, suena un segundo y se apaga medio segundo y por último en caso del LCD
este enciende con una leyenda de "A L E R T A  D E  I N T R U S O.
