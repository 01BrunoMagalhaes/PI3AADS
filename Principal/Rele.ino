void inicializarReles(){
  pinMode(r1, OUTPUT); pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT); pinMode(r4, OUTPUT);
  pinMode(r5, OUTPUT); pinMode(r6, OUTPUT);
  pinMode(r7, OUTPUT); pinMode(r8, OUTPUT);

  ligarDesligarRele(r1, false);
  ligarDesligarRele(r2, false);
}

void ligarDesligarRele(int posicaoRele, boolean ligar){
  Serial.print("O relé " + String(posicaoRele) + " ");
  if(ligar){  
    digitalWrite(posicaoRele, LOW);  //Liga rele
    Serial.println("ligou.");
  }else{
    Serial.println("desligou.");
    digitalWrite(posicaoRele, HIGH);  //Desliga rele
  }
}

String statusRele(int posicaoRele){
  int s = digitalRead(posicaoRele);
  if(s == 1){
    return "Desligado";
  }else{
    return "Ligado";
  }
}

