#include <Wire.h> //Built-in
#include <RtcDS3231.h> //RTC
#include <OneWire.h> //Temperatura

//Relés
#define r1 22 //Resfriamento
#define r2 23 //Aquecedor
#define r3 24 //Bomba nivel
#define r4 25
#define r5 26 
#define r6 27
#define r7 28
#define r8 29
//PWM's
#define p1 6 //canal cor azul 
#define p2 9 //canal cor branca
#define t 2 //Temperatura
#define bo 7 //boia

float tMin = 0;
float tMax = 0;
boolean validarNivel = false;

void setup() {
  inicializarModulos();
  Serial.begin(9600);
}

void loop() {
  Serial.println(F("")); Serial.println(F("Inicio loop."));
  Serial.print(F("Temperatura: ")); Serial.println(temperaturaAtual());
  Serial.print(F("Data: ")); Serial.print(retornarData()); Serial.print(F(" Hora: ")); Serial.println(retornarHora());

  verificaTemperatura(tMin, tMax);
  verificaNivelAgua(validarNivel);
  verificaIluminacao();
  verificaClients();

  Serial.println(F("Final loop.")); Serial.println(F(""));
  delay(2000);
}
