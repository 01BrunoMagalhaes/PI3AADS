void inicializarIluminacao(){
  pinMode(canalAzul, OUTPUT); pinMode(canalBranco, OUTPUT);
}  

void verificaIluminacao(boolean testeIluminacao){
  if(!testeIluminacao){
    verificaCanalAzul();
    verificaCanalBranco();
    Serial.println("Canal Azul");
    Serial.print("'"+c10+"'"); Serial.println("'"+String(b10)+"'");
    Serial.print("'"+c11+"'"); Serial.println("'"+String(b11)+"'");
    Serial.print("'"+c12+"'"); Serial.println("'"+String(b12)+"'");
    Serial.print("'"+c13+"'"); Serial.println("'"+String(b13)+"'");
    Serial.print("'"+c14+"'"); Serial.println("'"+String(b14)+"'");
    Serial.print("'"+c15+"'"); Serial.println("'"+String(b15)+"'");
    Serial.print("'"+c16+"'"); Serial.println("'"+String(b16)+"'");
    Serial.print("'"+c17+"'"); Serial.println("'"+String(b17)+"'");
    Serial.print("'"+c18+"'"); Serial.println("'"+String(b18)+"'");
    Serial.print("'"+c19+"'"); Serial.println("'"+String(b19)+"'");  
    Serial.println("Canal Branco");
    Serial.print("'"+c20+"'"); Serial.println("'"+String(b20)+"'");
    Serial.print("'"+c21+"'"); Serial.println("'"+String(b21)+"'");
    Serial.print("'"+c22+"'"); Serial.println("'"+String(b22)+"'");
    Serial.print("'"+c23+"'"); Serial.println("'"+String(b23)+"'");
    Serial.print("'"+c24+"'"); Serial.println("'"+String(b24)+"'");
    Serial.print("'"+c25+"'"); Serial.println("'"+String(b25)+"'");
    Serial.print("'"+c26+"'"); Serial.println("'"+String(b26)+"'");
    Serial.print("'"+c27+"'"); Serial.println("'"+String(b27)+"'");
    Serial.print("'"+c28+"'"); Serial.println("'"+String(b28)+"'");
    Serial.print("'"+c29+"'"); Serial.println("'"+String(b29)+"'");  
  }else{
    testarIluminacao(valoresTesteIluminacao);
  }
}

void testarIluminacao(String a){
  if(!a.equalsIgnoreCase("")){
    if(a.equalsIgnoreCase("0&0")){
      valoresTesteIluminacao = "";
      testeIluminacao = false;
      analogWrite(canalAzul, map(0, 0, 100, 0, 255));
      analogWrite(canalBranco, map(0, 0, 100, 0, 255));
    }else{
      valoresTesteIluminacao = a;
      testeIluminacao = true;
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

void verificaCanalAzul(){
  if(!c10.equalsIgnoreCase("") || !c11.equalsIgnoreCase("") || !c12.equalsIgnoreCase("") || !c13.equalsIgnoreCase("") || !c14.equalsIgnoreCase("")
      || !c15.equalsIgnoreCase("") || !c16.equalsIgnoreCase("") || !c17.equalsIgnoreCase("") || !c18.equalsIgnoreCase("") || !c19.equalsIgnoreCase("")){
    if(retornarHoraSemSegundos().equalsIgnoreCase(c10)){
      int brilho = map(b10, 0, 100, 0, 255);
      analogWrite(canalAzul, brilho);
    }else if(retornarHoraSemSegundos().equalsIgnoreCase(c11)){
      int brilho = map(b11, 0, 100, 0, 255);
      analogWrite(canalAzul, brilho);
    }else if(retornarHoraSemSegundos().equalsIgnoreCase(c12)){
      int brilho = map(b12, 0, 100, 0, 255);
      analogWrite(canalAzul, brilho);
    }else if(retornarHoraSemSegundos().equalsIgnoreCase(c13)){
      int brilho = map(b13, 0, 100, 0, 255);
      analogWrite(canalAzul, brilho);
    }else if(retornarHoraSemSegundos().equalsIgnoreCase(c14)){
      int brilho = map(b14, 0, 100, 0, 255);
      analogWrite(canalAzul, brilho);
    }else if(retornarHoraSemSegundos().equalsIgnoreCase(c15)){
      int brilho = map(b15, 0, 100, 0, 255);
      analogWrite(canalAzul, brilho);
    }else if(retornarHoraSemSegundos().equalsIgnoreCase(c16)){
      int brilho = map(b16, 0, 100, 0, 255);
      analogWrite(canalAzul, brilho);
    }else if(retornarHoraSemSegundos().equalsIgnoreCase(c17)){
      int brilho = map(b17, 0, 100, 0, 255);
      analogWrite(canalAzul, brilho);
    }else if(retornarHoraSemSegundos().equalsIgnoreCase(c18)){
      int brilho = map(b18, 0, 100, 0, 255);
      analogWrite(canalAzul, brilho);
    }else if(retornarHoraSemSegundos().equalsIgnoreCase(c19)){
      int brilho = map(b19, 0, 100, 0, 255);
      analogWrite(canalAzul, brilho);
    }
  }
}

void verificaCanalBranco(){
  if(!c20.equalsIgnoreCase("") || !c21.equalsIgnoreCase("") || !c22.equalsIgnoreCase("") || !c23.equalsIgnoreCase("") || !c24.equalsIgnoreCase("")
      || !c25.equalsIgnoreCase("") || !c26.equalsIgnoreCase("") || !c27.equalsIgnoreCase("") || !c28.equalsIgnoreCase("") || !c29.equalsIgnoreCase("")){
    if(retornarHoraSemSegundos().equalsIgnoreCase(c20)){
      int brilho = map(b20, 0, 100, 0, 255);
      analogWrite(canalBranco, brilho);
    }else if(retornarHoraSemSegundos().equalsIgnoreCase(c21)){
      int brilho = map(b21, 0, 100, 0, 255);
      analogWrite(canalBranco, brilho);
    }else if(retornarHoraSemSegundos().equalsIgnoreCase(c22)){
      int brilho = map(b22, 0, 100, 0, 255);
      analogWrite(canalBranco, brilho);
    }else if(retornarHoraSemSegundos().equalsIgnoreCase(c23)){
      int brilho = map(b23, 0, 100, 0, 255);
      analogWrite(canalBranco, brilho);
    }else if(retornarHoraSemSegundos().equalsIgnoreCase(c24)){
      int brilho = map(b24, 0, 100, 0, 255);
      analogWrite(canalBranco, brilho);
    }else if(retornarHoraSemSegundos().equalsIgnoreCase(c25)){
      int brilho = map(b25, 0, 100, 0, 255);
      analogWrite(canalBranco, brilho);
    }else if(retornarHoraSemSegundos().equalsIgnoreCase(c26)){
      int brilho = map(b26, 0, 100, 0, 255);
      analogWrite(canalBranco, brilho);
    }else if(retornarHoraSemSegundos().equalsIgnoreCase(c27)){
      int brilho = map(b27, 0, 100, 0, 255);
      analogWrite(canalBranco, brilho);
    }else if(retornarHoraSemSegundos().equalsIgnoreCase(c28)){
      int brilho = map(b28, 0, 100, 0, 255);
      analogWrite(canalBranco, brilho);
    }else if(retornarHoraSemSegundos().equalsIgnoreCase(c29)){
      int brilho = map(b29, 0, 100, 0, 255);
      analogWrite(canalBranco, brilho);
    }
  }
}
