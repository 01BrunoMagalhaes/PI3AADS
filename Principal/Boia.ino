void inicializarBoia(){
  pinMode(bo, INPUT);
}

boolean isBoiaAcionada(){
  int estado = digitalRead(bo);
  Serial.print(F("Estado da boia: "));Serial.println(String(estado));
  if(estado >= 1){
    return true;
  }else if(estado < 1){
    return false;
  }
}

void verificaNivelAgua(boolean on){
  if(on){
    while(isBoiaAcionada()){
      ligarDesligarRele(r3, 1);
    }
  }
  ligarDesligarRele(r3, 0);
}


