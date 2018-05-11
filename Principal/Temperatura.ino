OneWire  sensorTemp(portaTemperatura);

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

