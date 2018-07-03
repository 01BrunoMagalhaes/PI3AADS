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

void verificaNivelAgua(String a){
  if(!a.equalsIgnoreCase("")){
    if(a.substring(0,1).equalsIgnoreCase("1")){
      validarNivel = true;
    }else{
      qtdReposicoes = 0;
      validarNivel = false;
    }
  }
}  

String retornaStatusBoia(){
  if(validarNivel){
    return "Ligado";
  }else{
    return "Desligado";
  }
}

void verificaNivelAgua(boolean on){
  if(on){
    if(isBoiaAcionada()){
      qtdReposicoes ++;
    }
    while(isBoiaAcionada()){
      ligarDesligarRele(r3, 1);
    }
  }
  ligarDesligarRele(r3, 0);
}
