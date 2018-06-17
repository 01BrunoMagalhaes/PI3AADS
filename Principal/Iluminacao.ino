void inicializarIluminacao(){
  pinMode(canalAzul, OUTPUT); pinMode(canalBranco, OUTPUT);
}  

void verificaIluminacao(){
  verificaCanalAzul();
  verificaCanalBranco();
}

void testarIluminacao(String a){
  if(!a.equalsIgnoreCase("")){
    analogWrite(canalAzul, map(a.substring(0, a.indexOf("&")).toFloat(), 0, 100, 0, 255));
    analogWrite(canalBranco, map(a.substring(a.indexOf("&")+1, a.length()).toFloat(), 0, 100, 0, 255));
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
