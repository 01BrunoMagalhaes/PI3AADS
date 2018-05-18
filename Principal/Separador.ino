void verificarComando(String conteudo){
  int inicio = conteudo.indexOf("?a=") + 3;
  int fim = conteudo.indexOf("&end");

  String acao = conteudo.substring(inicio, fim);
  
  Serial.print("AÇÃO: ");
  Serial.println(acao);
  Serial.println("###################");
  acao = "";
}

