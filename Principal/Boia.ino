boolean isBoiaAcionada(){
  int estado = digitalRead(bo);
//  Serial.println("Estado = " + String(estado));
  if(estado >= 1){
    return true;
  }else if(estado < 1){
    return false;
  }
  delay(1000);
}


