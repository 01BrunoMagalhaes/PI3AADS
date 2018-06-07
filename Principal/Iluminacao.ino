void inicializarIluminacao(){
  pinMode(p1, OUTPUT); pinMode(p2, OUTPUT);

  int brilho = map(0, 0, 100, 0, 255);
  analogWrite(p1, brilho);
  analogWrite(p2, brilho);
}
