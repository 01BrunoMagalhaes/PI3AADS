#include <ArduinoJson.h>
#include <SPI.h>
#include <Ethernet.h>

//Definicoes de IP, mascara de rede e gateway
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(10,0,0,2);          //Define o endereco IP
IPAddress gateway(10,0,0,1);      //Define o gateway
IPAddress subnet(255, 255, 255, 0); //Define a máscara de rede

String conteudo = "";
char c;

EthernetServer server(80);

void  inicializarEthernet(){
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
}

void verificaClients() {
  Serial.println(Ethernet.localIP());
  EthernetClient client = server.available(); //Aguarda conexao do browser

  if (client) {
    Serial.println(F("Novo cliente"));
    boolean currentLineIsBlank = true;
     
    while (client.connected()) {
      if (client.available()) {
        c = client.read();
          
        if(conteudo.length() < 50){            
          conteudo += c;
        }

        if (c == 'n' && currentLineIsBlank) {
          String acao =  "";
          int i = conteudo.indexOf("/") +1;
          acao = conteudo.substring(i, i + 3);
        
          //Serial.print(F("Conteúdo da URL: ")); Serial.println(conteudo);
          //Serial.print(F("Conteúdo ação: ")); Serial.println(acao);
          
          if(!acao.equalsIgnoreCase("")){
            if(acao.equalsIgnoreCase("00 ")){
              StaticJsonBuffer<500> jsonBuffer; JsonObject& root = jsonBuffer.createObject(); 
              //JsonArray& valorTemperatura = root.createNestedArray("temperatura"); 
              //root.createNestedArray("temperatura");
              //valorTemperatura.add(temperaturaAtual()); 
              JsonObject& temp = root.createNestedObject("temperatura");
              temp["atual"] = temperaturaAtual();
              temp["minima"] = tMin;
              temp["maxima"] = tMax;
              
              JsonObject& reles = root.createNestedObject("tomadas");
              reles["t1"] = statusRele(r4);
              reles["t2"] = statusRele(r5);
              reles["t3"] = statusRele(r6);
              reles["t4"] = statusRele(r7);
              reles["t5"] = statusRele(r8);
              
              JsonObject& controls = root.createNestedObject("controles");
              controls["nivel"] = retornaStatusBoia();
              controls["temperatura"] = retornaStatusTemperatura();

              JsonObject& data = root.createNestedObject("dateTime");
              data["data"] = retornarData();
              data["hora"] = retornarHora();

              client.println("HTTP/1.0 200 OK"); client.println("Content-Type: application/json"); client.println("Connection: close"); client.println("charset: utf-8");
              //client.println("Refresh: 5"); 
              client.println(); root.prettyPrintTo(client);  
              break;
            }else if(acao.equalsIgnoreCase("01/")){
              int i = conteudo.indexOf("01/") +3;
              int f = conteudo.indexOf(" HTTP");
              verificaReles(conteudo.substring(i,f));
              client.println("HTTP/1.0 200 OK");
            }else if(acao.equalsIgnoreCase("02/")){
              int i = conteudo.indexOf("02/") +3;
              int f = conteudo.indexOf(" HTTP");
              verificaAquecerResfriar(conteudo.substring(i,f));
              client.println("HTTP/1.0 200 OK");                
            }else if(acao.equalsIgnoreCase("03/")){
              int i = conteudo.indexOf("03/") +3;
              int f = conteudo.indexOf(" HTTP");
              verificaNivelAgua(conteudo.substring(i,f));
              client.println("HTTP/1.0 200 OK");
            }else if(acao.equalsIgnoreCase("04/")){
              int i = conteudo.indexOf("04/") +3;
              int f = conteudo.indexOf(" HTTP");
              testarIluminacao(conteudo.substring(i,f));
              client.println("HTTP/1.0 200 OK");
            }else if(acao.equalsIgnoreCase("05/")){
              int i = conteudo.indexOf("05/") +3;
              int f = conteudo.indexOf(" HTTP");
              programarCanalAzul1(conteudo.substring(i,f));
              client.println("HTTP/1.0 200 OK");
            }else if(acao.equalsIgnoreCase("06/")){
              int i = conteudo.indexOf("06/") +3;
              int f = conteudo.indexOf(" HTTP");
              programarCanalAzul2(conteudo.substring(i,f));
              client.println("HTTP/1.0 200 OK");
            }else if(acao.equalsIgnoreCase("07/")){
              int i = conteudo.indexOf("07/") +3;
              int f = conteudo.indexOf(" HTTP");
              programarCanalBranco1(conteudo.substring(i,f));
              client.println("HTTP/1.0 200 OK");
            }else if(acao.equalsIgnoreCase("08/")){
              int i = conteudo.indexOf("08/") +3;
              int f = conteudo.indexOf(" HTTP");
              programarCanalBranco2(conteudo.substring(i,f));
              client.println("HTTP/1.0 200 OK");
            }else if(acao.equalsIgnoreCase("09 ")){
              simularIluminacaoAutomatica();
              client.println("HTTP/1.0 200 OK");
            }else{
              client.println("HTTP/1.0 200 OK");
            }
          }  
          client.println("HTTP/1.0 200 OK");
          break;
        }
      }        
        if (c == 'n') {
          currentLineIsBlank = true;
        } else if (c != 'r') {
          currentLineIsBlank = false;
        }
      }
    }      
    delay(1);
    client.stop();
    conteudo = "";
}
