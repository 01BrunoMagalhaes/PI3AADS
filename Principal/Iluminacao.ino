void inicializarIluminacao(){
  pinMode(p1, OUTPUT); pinMode(p2, OUTPUT);
}  

void verificaIluminacao(){
  canalAzul();
}

void canalAzul(){
  if(!c10.equalsIgnoreCase("") || !c11.equalsIgnoreCase("") || !c12.equalsIgnoreCase("") || !c13.equalsIgnoreCase("") || !c14.equalsIgnoreCase("")
      || !c15.equalsIgnoreCase("") || !c16.equalsIgnoreCase("") || !c17.equalsIgnoreCase("") || !c18.equalsIgnoreCase("") || !c19.equalsIgnoreCase("")){
    if(retornarHoraSemSegundos().equalsIgnoreCase(c10)){
      int brilho = map(b10, 0, 100, 0, 255);
      analogWrite(p1, brilho);
    }else if(retornarHoraSemSegundos().equalsIgnoreCase(c11)){
      int brilho = map(b11, 0, 100, 0, 255);
      analogWrite(p1, brilho);
    }else if(retornarHoraSemSegundos().equalsIgnoreCase(c12)){
      int brilho = map(b12, 0, 100, 0, 255);
      analogWrite(p1, brilho);
    }else if(retornarHoraSemSegundos().equalsIgnoreCase(c13)){
      int brilho = map(b13, 0, 100, 0, 255);
      analogWrite(p1, brilho);
    }else if(retornarHoraSemSegundos().equalsIgnoreCase(c14)){
      int brilho = map(b14, 0, 100, 0, 255);
      analogWrite(p1, brilho);
    }else if(retornarHoraSemSegundos().equalsIgnoreCase(c15)){
      int brilho = map(b15, 0, 100, 0, 255);
      analogWrite(p1, brilho);
    }else if(retornarHoraSemSegundos().equalsIgnoreCase(c16)){
      int brilho = map(b16, 0, 100, 0, 255);
      analogWrite(p1, brilho);
    }else if(retornarHoraSemSegundos().equalsIgnoreCase(c17)){
      int brilho = map(b17, 0, 100, 0, 255);
      analogWrite(p1, brilho);
    }else if(retornarHoraSemSegundos().equalsIgnoreCase(c18)){
      int brilho = map(b18, 0, 100, 0, 255);
      analogWrite(p1, brilho);
    }else if(retornarHoraSemSegundos().equalsIgnoreCase(c19)){
      int brilho = map(b19, 0, 100, 0, 255);
      analogWrite(p1, brilho);
    }
  }
}

