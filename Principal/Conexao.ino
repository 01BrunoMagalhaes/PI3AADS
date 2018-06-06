#include <ArduinoJson.h>
#include <SPI.h>
#include <Ethernet.h>

//Definicoes de IP, mascara de rede e gateway
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(192,168,15,11);          //Define o endereco IP
IPAddress gateway(192,168,15,10);      //Define o gateway
IPAddress subnet(255, 255, 255, 0); //Define a máscara de rede

String conteudo = "";
char c;

EthernetServer server(80);

void  inicializarEthernet(){
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
}

void verificaClients() {
  
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
          int f = i + 3;
        
          Serial.print(F("Conteúdo da URL: ")); Serial.println(conteudo);
          acao = conteudo.substring(i,f);
          Serial.print(F("Conteúdo ação: ")); Serial.println(acao);
          if(!acao.equalsIgnoreCase("")){
            if(acao.equalsIgnoreCase("01/")){
              int i = conteudo.indexOf("01/") +3;
              int f = conteudo.indexOf(" HTTP");
              verificaReles(conteudo.substring(i,f));
            }
          }  
          StaticJsonBuffer<500> jsonBuffer; JsonObject& root = jsonBuffer.createObject(); 
          JsonArray& valorTemperatura = root.createNestedArray("temperatura"); valorTemperatura.add(temperaturaAtual()); 
          //JsonArray& data = root.createNestedArray("data"); data.add(retornarData());
          //JsonArray& hora = root.createNestedArray("hora"); hora.add(retornarHora());
          //JsonArray& reles = root.createNestedArray("tomadas"); 
          //reles.add(statusRele(r1)); reles.add(statusRele(r2)); reles.add(statusRele(r3)); reles.add(statusRele(r4)); 
          //reles.add(statusRele(r5)); reles.add(statusRele(r6)); reles.add(statusRele(r7)); reles.add(statusRele(r8));
          //Serial.print(F("Sending: ")); 
          root.printTo(Serial); 
          Serial.println(); client.println("HTTP/1.0 200 OK"); client.println("Content-Type: application/json"); client.println("Connection: close"); client.println("charset: utf-8");
          //client.println("Refresh: 5"); 
          client.println(); root.prettyPrintTo(client);  
        
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
