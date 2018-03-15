/* En el presente codigo se explicara el codigo de una alarma de una puerta,
  en la cual al momento de abrirla, genera un sonido y enciende una luz la 
  cual indica que la puerta esta abierta, y cuando la puerta esta cerrada
  el arduino entra en modo sleep, y el buzzer de sonido y el led que nos 
  indica que la puerta esta abierta se apagan, y al momento de que el reed 
  switch detecta que se encuetra abierta la puerta, el arduino deja el modo 
  sleep y entra en funcionamiento de nuevo. Teniendo un ahorro de energia
*/

//Se importan las librerias a utilizar
#include "LowPower.h" //Libreria con la cual dormimos el arduino
#include "Arduino.h"  
#include <avr/sleep.h>  //Libreria de los modos sleep
#include <avr/power.h>
#include <avr/wdt.h>

const int contacto=2; //Creacion la variable del Reed switch
int led=13; //En este caso el led es la creacion de la variable del buzzer
int alarma=12;//Creacion de la variable del Led

void setup() {
   wdt_disable(); // Desactiva la función mientras se configura el tiempo en el que se reseteara
    wdt_enable(WDTO_2S); // Configuramos el contador de tiempo para que se reinicie en 2s

  pinMode(contacto, INPUT); //Inicializamos la entrada del Reed switch
  pinMode(led, OUTPUT); //Inicializamos la salida del buzzer
  pinMode(alarma, OUTPUT); //Inicializamos la salida del Led 
  Serial.begin(9600);//Llamamos el serial

}

void loop() {
int valor = analogRead(A1); //Asignamos a la variable valor, lo que lea del Reed switch     
Serial.println(valor);  //Imprime el valor por la consola     //Si el valor es mayor o igual a 500   
if (valor >= 500)   {  //De acuerdo a la condicion de la lectura del switch, y determina si esta haciendo contacto
  //En este caso es cuando esta abierta la puerta 
  digitalWrite(led,HIGH);//Enciendo el buzzer, que se encendera y se apagara cada 50 milisegundos
  delay(500);
  digitalWrite(led,LOW);
  delay(500);
  digitalWrite(alarma, HIGH);//Enciendo el Led, que se encendera y se apagara cada 50 milisegundos
  delay(50);
  digitalWrite(alarma, LOW);
  wdt_reset();//Resetea el whatchDog, el cual hace que el arduino despierte
  
  }else   {     

  //En esta parte, es cuando el reed switch esta en contacto con el iman, el cual simila que la puerta esta cerrada  
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);//Duerme el arduino
 
   
}
  
}}
