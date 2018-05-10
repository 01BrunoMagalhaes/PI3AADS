boolean isBoiaAcionada(){
  int estado = digitalRead(pinoBoia);

  if(estado >= 1){
    return true;
  }else if(estado < 1){
    return false;
  }
}

#define pinoBoia = 3; 

  Serial.begin(9600);
  pinMode(pinoBoia, INPUT);



  int estado = digitalRead(pinoBoia);
  Serial.print("Estado da bóia: ");
  Serial.print(estado);
  Serial.print("\n");

  delay(1000);


