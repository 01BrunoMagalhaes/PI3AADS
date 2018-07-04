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
#define canalAzul 2 //canal cor azul 
#define canalBranco 3 //canal cor branca

#define t 30 //Temperatura
#define bo 31 //boia

int qtdReposicoes = 0;
float tMin = 0;
float tMax = 0;
float tIdeal = 0;
boolean validarNivel = false;
boolean validarTemperatura = false;
boolean iluminacaoAutomatica = false;
boolean testeIluminacao = false;
boolean reposicaoLigada = false;

float potenciaAzulAtual = 0, potenciaBrancaAtual = 0;

String valoresTesteIluminacao = "0&0";
String c10 = "", c11 = "", c12 = "", c13 = "", c14 = "", c15 = "", c16 = "", c17 = "", c18 = "", c19 = "";//horarios da iluminacao azul 
float b10 = 0, b11 = 0, b12 = 0, b13 = 0, b14 = 0, b15 = 0, b16 = 0, b17 = 0, b18 = 0, b19 = 0;//potencias da iluminacao azul
String c20 = "", c21 = "", c22 = "", c23 = "", c24 = "", c25 = "", c26 = "", c27 = "", c28 = "", c29 = "";//horarios da iluminacao branca
float b20 = 0, b21 = 0, b22 = 0, b23 = 0, b24 = 0, b25 = 0, b26 = 0, b27 = 0, b28 = 0, b29 = 0;//potencias da iluminacao branca

void setup() {
  inicializarModulos();
  Serial.begin(9600);
}

void loop() {
  Serial.println(F("")); Serial.println(F("Inicio loop."));
  Serial.print(F("Temperatura: ")); Serial.println(temperaturaAtual());
  Serial.print(F("Data: ")); Serial.print(retornarData()); Serial.print(F(" Hora: ")); Serial.println(retornarHora());

  verificaTemperatura(tMin, tMax, tIdeal);
  verificaNivelAgua(validarNivel);
  verificaIluminacao();
  verificaClients();
  Serial.println(F("Final loop.")); Serial.println(F(""));
  delay(2000);
}
