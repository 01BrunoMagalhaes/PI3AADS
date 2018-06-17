void inicializarModulos(){
  pinMode(53, OUTPUT); //Configuração para funcionar o módulo ethernet no Mega
  inicializarBoia();
  inicializarIluminacao();
  inicializarReles();
  inicializarEthernet();
  inicializarRtc();
}

String tratarHora(String a){
  if(!a.equalsIgnoreCase("")){
    if(a.equalsIgnoreCase("0000")){
      return "";
    }else{
      return String(a.substring(0,2) + ":" + a.substring(2,4));
    }
  }else{
    return "";
  }
}

float tratarPotencia(String a){
  if(!a.equalsIgnoreCase("")){
    if(a.equalsIgnoreCase("000")){
      return 0;
    }else{
      return a.substring(0,3).toFloat();
    }
  }else{
    return 0;
  }
}
