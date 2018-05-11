RtcDS3231<TwoWire> Rtc(Wire);
void  inicializaRtc(){
  Rtc.Begin();
  if(!Rtc.GetIsRunning()){
    Rtc.SetIsRunning(true);
  }
  Rtc.Enable32kHzPin(false);
  Rtc.SetSquareWavePin(DS3231SquareWavePin_ModeNone);
}
   
   RtcDateTime now = Rtc.GetDateTime();

String formatDate(const RtcDateTime& dt, String format){
  String d = dt.Day() < 10 ? "0" + String(dt.Day()) : String(dt.Day()) ;
  String m = dt.Month() < 10 ? "0" + String(dt.Month()) : String(dt.Month()) ;
  String y = String(dt.Year()) ;
  format.replace("d",d);
  format.replace("m",m);
  format.replace("y",y);
  return format;
}
 
String formatTime(const RtcDateTime& dt, String format){
  String h = dt.Hour() < 10 ? "0" + String(dt.Hour()) : String(dt.Hour()) ;
  String m = dt.Minute() < 10 ? "0" + String(dt.Minute()) : String(dt.Minute()) ;
  String s = dt.Second() < 10 ? "0" + String(dt.Second()) : String(dt.Second()) ;
  format.replace("h",h);
  format.replace("m",m);
  format.replace("s",s);
  return format;
}

String retornaTudo(){
 return String("Data atual: " + formatDate(now,"d/m/y") + " Hora atual: " + formatTime(now,"h:m:s"));
}


