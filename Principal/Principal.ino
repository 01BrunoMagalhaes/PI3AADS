#include <Wire.h> //Built-in
#include <RtcDS3231.h> //RTC
#include <OneWire.h> //Temperatura

//Relés
#define r1 3
#define r2 4
#define r3 5
#define r4 6
#define r5 7 
#define r6 8
#define r7 9 
#define r8 13
//PWM's
#define p1 10 
#define p2 9
#define t 2 //Temperatura
#define bo 12 //boia

void setup() {
  pinMode(p1, OUTPUT); pinMode(p2, OUTPUT);
  pinMode(bo, INPUT);

  inicializarReles();
  inicializarEthernet();
  inicializarRtc();
  
  Serial.begin(9600);
}

void loop() {
  Serial.println(F("")); Serial.println(F("Inicio loop."));

  verificaTemperatura(27, 26);
  
  int b1 = map(1, 0, 100, 0, 255);
  int b2 = map(1, 0, 100, 0, 255);
  analogWrite(p1, b1);
  analogWrite(p2, b2);
  
  Serial.print(F("Temperatura: ")); Serial.println(temperaturaAtual());
  Serial.println(retornarData());
  Serial.println(retornarHora());
  verificaClients();

  Serial.println(F("Final loop.")); Serial.println(F(""));
  delay(2000);
}
