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
      validarNivel = false;
    }
  }
}  

String retornaStatusBoia(){
  if(validarNivel){
    return "Ativo";
  }else{
    return "Desativado";
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
