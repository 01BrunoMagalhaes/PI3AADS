#include <Wire.h> //Built-in
#include <RtcDS3231.h> //RTC
#include <OneWire.h> //Temperatura

//Relés
#define r1 3 //Resfriamento
#define r2 4 //Aquecedor
#define r3 5
#define r4 6
#define r5 7 
#define r6 8
#define r7 9 
#define r8 13
//PWM's
#define p1 8 //canal cor azul 
#define p2 9 //canal cor branca
#define t 2 //Temperatura
#define bo 12 //boia

void setup() {
  inicializarBoia();
  inicializarIluminacao();
  inicializarReles();
  inicializarEthernet();
  inicializarRtc();
  
  Serial.begin(9600);
}

void loop() {
  Serial.println(F("")); Serial.println(F("Inicio loop."));

  verificaTemperatura(27, 26);
  
  Serial.print(F("Temperatura: ")); Serial.println(temperaturaAtual());
  Serial.println(retornarData());
  Serial.println(retornarHora());
  verificaClients();

  Serial.println(F("Final loop.")); Serial.println(F(""));
  delay(2000);
}
