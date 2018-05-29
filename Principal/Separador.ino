void verificarComandos(String comandos){
  String acoes =  "";
  int i = comandos.indexOf("/") +1;
  int f = comandos.indexOf(" HTTP");

  Serial.print("Conteúdo da URL: "); Serial.println(comandos);
  //Serial.print("Inicio: "); Serial.println(i);
  //Serial.print("Fim: "); Serial.println(f);

  acoes = comandos.substring(i,f);
  
  Serial.print("Conteúdo ações: "); Serial.println(acoes);

  while(!acoes.equals("")){
    String acaoSeparada = "";
    acaoSeparada = separaAcao(acoes);
    acoes.replace(acaoSeparada, "");
    acaoSeparada.replace("&","");
    
    Serial.print("Ação separada: "); Serial.println(acaoSeparada);
    
    Serial.print("Ações final: "); Serial.println(acoes);
  }
  
}

String separaAcao(String acoesURL){
  Serial.print("Ações URL inicio: "); Serial.println(acoesURL);
  
  if(acoesURL.indexOf("&") != -1){
    int inicio = 0;
    int fim = acoesURL.indexOf("&") + 1;
      
    return acoesURL.substring(inicio, fim);
  }else{
    int inicio = 0;
    int fim = acoesURL.length();
    return acoesURL.substring(inicio, fim);
  }
}
