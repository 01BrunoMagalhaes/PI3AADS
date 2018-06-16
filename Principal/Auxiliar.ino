void inicializarModulos(){
  pinMode(53, OUTPUT); //Configuração para funcionar o módulo ethernet no Mega
  inicializarBoia();
  inicializarIluminacao();
  inicializarReles();
  inicializarEthernet();
  inicializarRtc();
}
