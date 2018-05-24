void ligarDesligarRele(int posicaoRele, boolean ligar){
  Serial.print("O relé " + String(posicaoRele) + " ");
  if(ligar){  
    digitalWrite(posicaoRele, LOW);  //Liga rele
    Serial.println("ligou.");
  }else{
    Serial.println("desligou.");
    digitalWrite(posicaoRele, HIGH);  //Desliga rele
  }
}
