String verificarComando(String conteudo){
  int inicio = conteudo.indexOf("/?") +2;
  int fim = conteudo.indexOf("&end");

  acao = conteudo.substring(inicio, fim);

  Serial.print("ACAO=========== ");
  Serial.println(acao);
  return acao; 
}

