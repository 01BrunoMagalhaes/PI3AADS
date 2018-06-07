#include <Wire.h> //Built-in
#include <RtcDS3231.h> //RTC
#include <OneWire.h> //Temperatura

//Relés
#define r1 3 //Resfriamento
#define r2 4 //Aquecedor
#define r3 5 //Bomba nivel
#define r4 8
//#define r5 7 
//#define r6 8
//#define r7 9 
#define r8 13
//PWM's
#define p1 6 //canal cor azul 
#define p2 9 //canal cor branca
#define t 2 //Temperatura
#define bo 7 //boia

float tMin = 0;
float tMax = 0;
boolean validarNivel = false;

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
  Serial.print(F("Temperatura: ")); Serial.println(temperaturaAtual());
  Serial.print(F("Data: ")); Serial.print(retornarData()); Serial.print(F(" Hora: ")); Serial.println(retornarHora());

  verificaTemperatura(tMin, tMax);
  verificaNivelAgua(validarNivel);
  verificaClients();

  Serial.println(F("Final loop.")); Serial.println(F(""));
  delay(2000);
}
