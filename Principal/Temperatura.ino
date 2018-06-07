OneWire  sensorTemp(t);

void verificaAquecerResfriar(String a){
  if(!a.equalsIgnoreCase("")){
    tMin = a.substring(0, a.indexOf("&")).toFloat();
    tMax = a.substring(a.indexOf("&")+1, a.length()).toFloat();
  }
}

void verificaTemperatura(float baixa, float alta){
  if(baixa == 0 && alta == 0){
    ligarDesligarRele(r1, 0);
    ligarDesligarRele(r2, 0);
  }else{
    if(temperaturaAtual() >= alta){
      Serial.println(F("Ligando resfriamento."));
      ligarDesligarRele(r1, 1);
    }else if(temperaturaAtual() <= baixa){
      Serial.println(F("Ligando aquecimento."));
      ligarDesligarRele(r2, 1);
    }else{
      ligarDesligarRele(r1, 0);
      ligarDesligarRele(r2, 0);
    }
  }
}

float temperaturaAtual(){
  byte i;
  byte present = 0;
  byte type_s;
  byte data[12];
  byte addr[8];
  float celsius, fahrenheit;
 
  if ( !sensorTemp.search(addr)) {
    sensorTemp.reset_search();
    delay(250);
  }

  sensorTemp.reset();
  sensorTemp.select(addr);
  sensorTemp.write(0x44,1);
 
  delay(1000);
 
  present = sensorTemp.reset();
  sensorTemp.select(addr);  
  sensorTemp.write(0xBE);

  for ( i = 0; i < 9; i++) { 
    data[i] = sensorTemp.read();
  }
  unsigned int raw = (data[1] << 8) | data[0];
  if (type_s) {
    raw = raw << 3; // 9 bit resolution default
    if (data[7] == 0x10) {
      // count remain gives full 12 bit resolution
      raw = (raw & 0xFFF0) + 12 - data[6];
    }
  } else {
    byte cfg = (data[4] & 0x60);
    if (cfg == 0x00) raw = raw << 3;
    else if (cfg == 0x20) raw = raw << 2;
    else if (cfg == 0x40) raw = raw << 1;
  }
  celsius = (float)raw / 16.0;
  
  return celsius; 
}
