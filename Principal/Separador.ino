void verificarComandos(String conteudo){
  int inicio = conteudo.indexOf("/") +1;
  int fim = conteudo.indexOf("&end");

  acao = conteudo.substring(inicio, fim);

  Serial.print("Conteúdo: ");
  Serial.println(conteudo);
  
  Serial.print("Ação: ");
  Serial.println(acao);
}

