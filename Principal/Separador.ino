void verificarComandos(String comandos){
  String acoes =  "";
  int i = comandos.indexOf("/") +1;
  int f = comandos.indexOf(" HTTP");

  Serial.print(F("Conteúdo da URL: ")); Serial.println(comandos);
  //Serial.print("Inicio: "); Serial.println(i);
  //Serial.print("Fim: "); Serial.println(f);
  acoes = comandos.substring(i,f);
  Serial.print(F("Conteúdo ações: ")); Serial.println(acoes);

  while(!acoes.equals("")){
    String acaoSeparada = "";
    //acaoSeparada = separaAcao(acoes);
    
    Serial.print(F("Ações URL inicio: ")); Serial.println(acoes);
    
    if(acoes.indexOf("&") != -1){
      int inicio = 0;
      int fim = acoes.indexOf("&") + 1;
        
      acaoSeparada = acoes.substring(inicio, fim);
    }else{
      int inicio = 0;
      int fim = acoes.length();
      acaoSeparada = acoes.substring(inicio, fim);
    }

    acoes.replace(acaoSeparada, "");
    acaoSeparada.replace("&","");

    if(acaoSeparada.equalsIgnoreCase("t1=1")){
      digitalWrite(r1, LOW);
    }else if(acaoSeparada.equalsIgnoreCase("t1=0")){
      digitalWrite(r1, HIGH);
    }
    
    Serial.print(F("Ação separada: ")); Serial.println(acaoSeparada);
    
    Serial.print(F("Ações final: ")); Serial.println(acoes);
  }
  
}
