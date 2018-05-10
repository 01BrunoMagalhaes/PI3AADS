
//Declarando portas
//Relés
#define portaRele1 1
#define portaRele2 2
#define portaRele3 3
#define portaRele4 4
#define portaRele5 5
#define portaRele6 6
#define portaRele7 7
#define portaRele8 8
//PWM's
#define portaPWM1 9
#define portaPWM2 10
//Temperatura
#define portaTemperatura 11
//boia
#define portaBoia 12

void setup() {
  
  pinMode(portaRele1, OUTPUT);
  pinMode(portaRele2, OUTPUT);
  pinMode(portaRele3, OUTPUT);
  pinMode(portaRele4, OUTPUT);
  pinMode(portaRele5, OUTPUT);
  pinMode(portaRele6, OUTPUT);
  pinMode(portaRele7, OUTPUT);
  pinMode(portaRele8, OUTPUT);
  pinMode(portaBoia, INPUT);
  
  
  Serial.begin(9600);
  
}

void loop() {
  
}
