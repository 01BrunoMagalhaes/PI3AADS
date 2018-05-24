#include <Wire.h> //Built-in
#include <RtcDS3231.h> //RTC
#include <OneWire.h> //Temperatura
//Declarando portas
//Relés
#define portaRele1 1
//#define portaRele2 2
#define portaRele3 3
#define portaRele4 4
#define portaRele5 5
#define portaRele6 6
#define portaRele7 7
#define portaRele8 8
//PWM's
#define portaPWM1 9
//#define portaPWM2 10
//Temperatura
#define portaTemperatura 2
//boia
#define portaBoia 12

void setup() {
  pinMode(portaRele1, OUTPUT);
  //pinMode(portaRele2, OUTPUT);
  pinMode(portaRele3, OUTPUT);
  pinMode(portaRele4, OUTPUT);
  pinMode(portaRele5, OUTPUT);
  pinMode(portaRele6, OUTPUT);
  pinMode(portaRele7, OUTPUT);
  pinMode(portaRele8, OUTPUT);
  pinMode(portaBoia, INPUT);

  inicializarRtc();
  inicializarEthernet();
  
  Serial.begin(9600);
}

void loop() {
  Serial.println("");
  Serial.println("Inicio loop.");
  
  Serial.print("Temperatura: ");
  Serial.println(temperaturaAtual());
  Serial.print("Data: ");
  Serial.print(retornarData());
  Serial.print(" Hora: ");
  Serial.println(retornarHora());
  
  verificaClients();

  ligarDesligarRele(portaRele7, true);
  delay(3000);
  ligarDesligarRele(portaRele7, false);
  Serial.println("Final loop."); Serial.println("");
  delay(2000);
}
