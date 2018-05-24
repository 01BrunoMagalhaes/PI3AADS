void verificarComandos(String conteudo){
  int inicio = conteudo.indexOf("/") +1;
  int fim = conteudo.indexOf("&end");

  acoes = " " + conteudo.substring(inicio, fim) + "&";

  while(!acoes.equals("")){
    
    String acaoSeparada = "";
    acaoSeparada = separaAcao(acoes);

    Serial.print("Ação separada: "); Serial.println(acaoSeparada);
    
    acoes.replace(acaoSeparada, "");
    acoes.replace(" &","");

    Serial.print("Ações final: ");
    Serial.println(acoes);
  }
  
}

String separaAcao(String acoes){
  int inicio = acoes.indexOf(" ") +1;
  int fim = acoes.indexOf("&");

    Serial.print("Ações inicio: "); Serial.println(acoes);
    Serial.print("Inicio: "); Serial.println(inicio);
    Serial.print("Fim: "); Serial.println(fim);
  
  return acoes.substring(inicio, fim);
}

