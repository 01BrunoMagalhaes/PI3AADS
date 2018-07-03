void inicializarIluminacao(){
  pinMode(canalAzul, OUTPUT); pinMode(canalBranco, OUTPUT);
}  

void verificaIluminacao(){
  if(iluminacaoAutomatica){
    verificaCanalAzul();
    verificaCanalBranco();
  }else if(testeIluminacao){
    testarIluminacao(valoresTesteIluminacao);
  }
}

void simularIluminacaoAutomatica(){
  analogWrite(canalAzul, map(0, 0, 100, 0, 255));
  analogWrite(canalBranco, map(0, 0, 100, 0, 255));
  delay(2000);
  analogWrite(canalAzul, map(b10, 0, 100, 0, 255));
  analogWrite(canalBranco, map(b20, 0, 100, 0, 255));
  delay(5000);
  analogWrite(canalAzul, map(b11, 0, 100, 0, 255));
  analogWrite(canalBranco, map(b21, 0, 100, 0, 255));
  delay(5000);
  analogWrite(canalAzul, map(b12, 0, 100, 0, 255));
  analogWrite(canalBranco, map(b22, 0, 100, 0, 255));
  delay(5000);
  analogWrite(canalAzul, map(b13, 0, 100, 0, 255));
  analogWrite(canalBranco, map(b23, 0, 100, 0, 255));
  delay(5000);
  analogWrite(canalAzul, map(b14, 0, 100, 0, 255));
  analogWrite(canalBranco, map(b24, 0, 100, 0, 255));
  delay(5000);
  analogWrite(canalAzul, map(b15, 0, 100, 0, 255));
  analogWrite(canalBranco, map(b25, 0, 100, 0, 255));
  delay(5000);
  analogWrite(canalAzul, map(b16, 0, 100, 0, 255));
  analogWrite(canalBranco, map(b26, 0, 100, 0, 255));
  delay(5000);
  analogWrite(canalAzul, map(b17, 0, 100, 0, 255));
  analogWrite(canalBranco, map(b27, 0, 100, 0, 255));
  delay(5000);
  analogWrite(canalAzul, map(b18, 0, 100, 0, 255));
  analogWrite(canalBranco, map(b28, 0, 100, 0, 255));
  delay(5000);
  analogWrite(canalAzul, map(b19, 0, 100, 0, 255));
  analogWrite(canalBranco, map(b29, 0, 100, 0, 255));
  delay(5000);
  analogWrite(canalAzul, map(0, 0, 100, 0, 255));
  analogWrite(canalBranco, map(0, 0, 100, 0, 255));
  delay(2000);
}

String retornaStatusIluminacao(){
  if(iluminacaoAutomatica){
    return "Automática";
  }else{
    return "Manual";
  }
}

void testarIluminacao(String a){
  if(!a.equalsIgnoreCase("")){
    if(a.equalsIgnoreCase("0&0")){
      valoresTesteIluminacao = "0&0";
      testeIluminacao = true;
      iluminacaoAutomatica = false;
      potenciaAzulAtual = 0;
      potenciaBrancaAtual = 0;
      analogWrite(canalAzul, map(0, 0, 100, 0, 255));
      analogWrite(canalBranco, map(0, 0, 100, 0, 255));
    }else if(a.equalsIgnoreCase("200&200")){
      testeIluminacao = false;
      iluminacaoAutomatica = true;  
      potenciaAzulAtual = 0;
      potenciaBrancaAtual = 0;
      analogWrite(canalAzul, map(0, 0, 100, 0, 255));
      analogWrite(canalBranco, map(0, 0, 100, 0, 255));  
    }else if(a.equalsIgnoreCase("300&300")){
      testeIluminacao = true;
      iluminacaoAutomatica = false;  
      potenciaAzulAtual = valoresTesteIluminacao.substring(0, valoresTesteIluminacao.indexOf("&")).toFloat();
      potenciaBrancaAtual = valoresTesteIluminacao.substring(valoresTesteIluminacao.indexOf("&")+1, valoresTesteIluminacao.length()).toFloat();
      analogWrite(canalAzul, map(valoresTesteIluminacao.substring(0, valoresTesteIluminacao.indexOf("&")).toFloat(), 0, 100, 0, 255));
      analogWrite(canalBranco, map(valoresTesteIluminacao.substring(valoresTesteIluminacao.indexOf("&")+1, valoresTesteIluminacao.length()).toFloat(), 0, 100, 0, 255));
    }else{
      valoresTesteIluminacao = a;
      testeIluminacao = true;
      iluminacaoAutomatica = false;
      potenciaAzulAtual = a.substring(0, a.indexOf("&")).toFloat();
      potenciaBrancaAtual = a.substring(a.indexOf("&")+1, a.length()).toFloat();
      analogWrite(canalAzul, map(a.substring(0, a.indexOf("&")).toFloat(), 0, 100, 0, 255));
      analogWrite(canalBranco, map(a.substring(a.indexOf("&")+1, a.length()).toFloat(), 0, 100, 0, 255));
    }
  }
}

void programarCanalAzul1(String a){
  if(!a.equalsIgnoreCase("")){
    c10 = tratarHora(a.substring(0,4));
    b10 = tratarPotencia(a.substring(4,7));
    c11 = tratarHora(a.substring(7,11));
    b11 = tratarPotencia(a.substring(11,14));
    c12 = tratarHora(a.substring(14,18));
    b12 = tratarPotencia(a.substring(18,21));
    c13 = tratarHora(a.substring(21,25));
    b13 = tratarPotencia(a.substring(25,28));
    c14 = tratarHora(a.substring(28,32));
    b14 = tratarPotencia(a.substring(32,35));
  }
}

void programarCanalAzul2(String a){
  if(!a.equalsIgnoreCase("")){
    c15 = tratarHora(a.substring(0,4));
    b15 = tratarPotencia(a.substring(4,7));
    c16 = tratarHora(a.substring(7,11));
    b16 = tratarPotencia(a.substring(11,14));
    c17 = tratarHora(a.substring(14,18));
    b17 = tratarPotencia(a.substring(18,21));
    c18 = tratarHora(a.substring(21,25));
    b18 = tratarPotencia(a.substring(25,28));
    c19 = tratarHora(a.substring(28,32));
    b19 = tratarPotencia(a.substring(32,35));
  }
}

void programarCanalBranco1(String a){
  if(!a.equalsIgnoreCase("")){
    c20 = tratarHora(a.substring(0,4));
    b20 = tratarPotencia(a.substring(4,7));
    c21 = tratarHora(a.substring(7,11));
    b21 = tratarPotencia(a.substring(11,14));
    c22 = tratarHora(a.substring(14,18));
    b22 = tratarPotencia(a.substring(18,21));
    c23 = tratarHora(a.substring(21,25));
    b23 = tratarPotencia(a.substring(25,28));
    c24 = tratarHora(a.substring(28,32));
    b24 = tratarPotencia(a.substring(32,35));
  }
}

void programarCanalBranco2(String a){
  if(!a.equalsIgnoreCase("")){
    c25 = tratarHora(a.substring(0,4));
    b25 = tratarPotencia(a.substring(4,7));
    c26 = tratarHora(a.substring(7,11));
    b26 = tratarPotencia(a.substring(11,14));
    c27 = tratarHora(a.substring(14,18));
    b27 = tratarPotencia(a.substring(18,21));
    c28 = tratarHora(a.substring(21,25));
    b28 = tratarPotencia(a.substring(25,28));
    c29 = tratarHora(a.substring(28,32));
    b29 = tratarPotencia(a.substring(32,35));
  }
}

void verificaCanalAzul(){
  if(!c10.equalsIgnoreCase("") || !c11.equalsIgnoreCase("") || !c12.equalsIgnoreCase("") || !c13.equalsIgnoreCase("") || !c14.equalsIgnoreCase("")
      || !c15.equalsIgnoreCase("") || !c16.equalsIgnoreCase("") || !c17.equalsIgnoreCase("") || !c18.equalsIgnoreCase("") || !c19.equalsIgnoreCase("")){
    iluminacaoAutomatica = true;
    if(retornaHoraInteira(retornarHoraSemSegundos()) >= retornaHoraInteira(c10) && retornaHoraInteira(retornarHoraSemSegundos()) < retornaHoraInteira(c11)){
      int brilho = map(b10, 0, 100, 0, 255);
      analogWrite(canalAzul, brilho);
      potenciaAzulAtual = b10;
    }else if(retornaHoraInteira(retornarHoraSemSegundos()) >= retornaHoraInteira(c11) && retornaHoraInteira(retornarHoraSemSegundos()) < retornaHoraInteira(c12)){
      int brilho = map(b11, 0, 100, 0, 255);
      analogWrite(canalAzul, brilho);
      potenciaAzulAtual = b11;
    }else if(retornaHoraInteira(retornarHoraSemSegundos()) >= retornaHoraInteira(c12) && retornaHoraInteira(retornarHoraSemSegundos()) < retornaHoraInteira(c13)){
      int brilho = map(b12, 0, 100, 0, 255);
      analogWrite(canalAzul, brilho);
      potenciaAzulAtual = b12;
    }else if(retornaHoraInteira(retornarHoraSemSegundos()) >= retornaHoraInteira(c13) && retornaHoraInteira(retornarHoraSemSegundos()) < retornaHoraInteira(c14)){
      int brilho = map(b13, 0, 100, 0, 255);
      analogWrite(canalAzul, brilho);
      potenciaAzulAtual = b13;
    }else if(retornaHoraInteira(retornarHoraSemSegundos()) >= retornaHoraInteira(c14) && retornaHoraInteira(retornarHoraSemSegundos()) < retornaHoraInteira(c15)){
      int brilho = map(b14, 0, 100, 0, 255);
      analogWrite(canalAzul, brilho);
      potenciaAzulAtual = b14;
    }else if(retornaHoraInteira(retornarHoraSemSegundos()) >= retornaHoraInteira(c15) && retornaHoraInteira(retornarHoraSemSegundos()) < retornaHoraInteira(c16)){
      int brilho = map(b15, 0, 100, 0, 255);
      analogWrite(canalAzul, brilho);
      potenciaAzulAtual = b15;
    }else if(retornaHoraInteira(retornarHoraSemSegundos()) >= retornaHoraInteira(c16) && retornaHoraInteira(retornarHoraSemSegundos()) < retornaHoraInteira(c17)){
      int brilho = map(b16, 0, 100, 0, 255);
      analogWrite(canalAzul, brilho);
      potenciaAzulAtual = b16;
    }else if(retornaHoraInteira(retornarHoraSemSegundos()) >= retornaHoraInteira(c17) && retornaHoraInteira(retornarHoraSemSegundos()) < retornaHoraInteira(c18)){
      int brilho = map(b17, 0, 100, 0, 255);
      analogWrite(canalAzul, brilho);
      potenciaAzulAtual = b17;
    }else if(retornaHoraInteira(retornarHoraSemSegundos()) >= retornaHoraInteira(c18) && retornaHoraInteira(retornarHoraSemSegundos()) < retornaHoraInteira(c19)){
      int brilho = map(b18, 0, 100, 0, 255);
      analogWrite(canalAzul, brilho);
      potenciaAzulAtual = b18;
    }else if(retornaHoraInteira(retornarHoraSemSegundos()) >= retornaHoraInteira(c19) && retornaHoraInteira(retornarHoraSemSegundos()) < retornaHoraInteira(c10)){
      int brilho = map(b19, 0, 100, 0, 255);
      analogWrite(canalAzul, brilho);
      potenciaAzulAtual = b19;
    }
  }
}

void verificaCanalBranco(){
  if(!c20.equalsIgnoreCase("") || !c21.equalsIgnoreCase("") || !c22.equalsIgnoreCase("") || !c23.equalsIgnoreCase("") || !c24.equalsIgnoreCase("")
      || !c25.equalsIgnoreCase("") || !c26.equalsIgnoreCase("") || !c27.equalsIgnoreCase("") || !c28.equalsIgnoreCase("") || !c29.equalsIgnoreCase("")){
    iluminacaoAutomatica = true;
    if(retornaHoraInteira(retornarHoraSemSegundos()) >= retornaHoraInteira(c20) && retornaHoraInteira(retornarHoraSemSegundos()) < retornaHoraInteira(c21)){
      int brilho = map(b20, 0, 100, 0, 255);
      analogWrite(canalBranco, brilho);
      potenciaBrancaAtual = b20;
    }else if(retornaHoraInteira(retornarHoraSemSegundos()) >= retornaHoraInteira(c21) && retornaHoraInteira(retornarHoraSemSegundos()) < retornaHoraInteira(c22)){
      int brilho = map(b21, 0, 100, 0, 255);
      analogWrite(canalBranco, brilho);
      potenciaBrancaAtual = b21;
    }else if(retornaHoraInteira(retornarHoraSemSegundos()) >= retornaHoraInteira(c22) && retornaHoraInteira(retornarHoraSemSegundos()) < retornaHoraInteira(c23)){
      int brilho = map(b22, 0, 100, 0, 255);
      analogWrite(canalBranco, brilho);
      potenciaBrancaAtual = b22;
    }else if(retornaHoraInteira(retornarHoraSemSegundos()) >= retornaHoraInteira(c23) && retornaHoraInteira(retornarHoraSemSegundos()) < retornaHoraInteira(c24)){
      int brilho = map(b23, 0, 100, 0, 255);
      analogWrite(canalBranco, brilho);
      potenciaBrancaAtual = b23;
    }else if(retornaHoraInteira(retornarHoraSemSegundos()) >= retornaHoraInteira(c24) && retornaHoraInteira(retornarHoraSemSegundos()) < retornaHoraInteira(c25)){
      int brilho = map(b24, 0, 100, 0, 255);
      analogWrite(canalBranco, brilho);
      potenciaBrancaAtual = b24;
    }else if(retornaHoraInteira(retornarHoraSemSegundos()) >= retornaHoraInteira(c25) && retornaHoraInteira(retornarHoraSemSegundos()) < retornaHoraInteira(c26)){
      int brilho = map(b25, 0, 100, 0, 255);
      analogWrite(canalBranco, brilho);
      potenciaBrancaAtual = b25;
    }else if(retornaHoraInteira(retornarHoraSemSegundos()) >= retornaHoraInteira(c26) && retornaHoraInteira(retornarHoraSemSegundos()) < retornaHoraInteira(c27)){
      int brilho = map(b26, 0, 100, 0, 255);
      analogWrite(canalBranco, brilho);
      potenciaBrancaAtual = b26;
    }else if(retornaHoraInteira(retornarHoraSemSegundos()) >= retornaHoraInteira(c27) && retornaHoraInteira(retornarHoraSemSegundos()) < retornaHoraInteira(c28)){
      int brilho = map(b27, 0, 100, 0, 255);
      analogWrite(canalBranco, brilho);
      potenciaBrancaAtual = b27;
    }else if(retornaHoraInteira(retornarHoraSemSegundos()) >= retornaHoraInteira(c28) && retornaHoraInteira(retornarHoraSemSegundos()) < retornaHoraInteira(c29)){
      int brilho = map(b28, 0, 100, 0, 255);
      analogWrite(canalBranco, brilho);
      potenciaBrancaAtual = b28;
    }else if(retornaHoraInteira(retornarHoraSemSegundos()) >= retornaHoraInteira(c29) && retornaHoraInteira(retornarHoraSemSegundos()) < retornaHoraInteira(c20)){
      int brilho = map(b29, 0, 100, 0, 255);
      analogWrite(canalBranco, brilho);
      potenciaBrancaAtual = b29;
    }
  }
}
