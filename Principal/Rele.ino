void inicializarReles(){
  pinMode(r1, OUTPUT); 
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT); 
  pinMode(r4, OUTPUT);
  pinMode(r5, OUTPUT); 
  pinMode(r6, OUTPUT);
  pinMode(r7, OUTPUT); 
  pinMode(r8, OUTPUT);

  ligarDesligarRele(r1, 0);
  ligarDesligarRele(r2, 0);
  ligarDesligarRele(r3, 0);
  ligarDesligarRele(r4, 0);
  ligarDesligarRele(r5, 0);
  ligarDesligarRele(r6, 0);
  ligarDesligarRele(r7, 0);
  ligarDesligarRele(r8, 0);
}

void ligarDesligarRele(int posicaoRele, int ligar){
  if(ligar == 1){  
    digitalWrite(posicaoRele, LOW);  //Liga rele
  }else if(ligar == 0){
    digitalWrite(posicaoRele, HIGH);  //Desliga rele
  }
}

void ligarDesligarRele(int posicaoRele, String ligar){
  if(ligar.equalsIgnoreCase("1")){  
    digitalWrite(posicaoRele, LOW);  //Liga rele
  }else if(ligar.equalsIgnoreCase("0")){
    digitalWrite(posicaoRele, HIGH);  //Desliga rele
  }
}

String statusRele(int posicaoRele){
  int s = digitalRead(posicaoRele);
  if(s == 1){
    return "Desligada";
  }else{
    return "Ligada";
  }
}

String statusRele2(int posicaoRele){
  int s = digitalRead(posicaoRele);
  if(s == 1){
    return "Desligado";
  }else{
    return "Ligado";
  }
}

int statusRele3(int posicaoRele){
  int s = digitalRead(posicaoRele);
  if(s == 1){
    return 0;
  }else{
    return 1;
  }
}

void verificaReles(String a){
  if(!a.equalsIgnoreCase("")){
    ligarDesligarRele(r4, a.substring(0,1));
    ligarDesligarRele(r5, a.substring(1,2));
    ligarDesligarRele(r6, a.substring(2,3));
    ligarDesligarRele(r7, a.substring(3,4));
    ligarDesligarRele(r8, a.substring(4,5));
  }
}
