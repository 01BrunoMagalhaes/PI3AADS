#include <ArduinoJson.h>
#include <SPI.h>
#include <Ethernet.h>

//Definicoes de IP, mascara de rede e gateway
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(192,168,15,11);          //Define o endereco IP
IPAddress gateway(192,168,15,10);      //Define o gateway
IPAddress subnet(255, 255, 255, 0); //Define a máscara de rede

String conteudo = "", acao = "";
char c;

EthernetServer server(80);

void  inicializarEthernet(){
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
}

void verificaClients() {
  
  EthernetClient client = server.available(); //Aguarda conexao do browser

  if (client) {
    Serial.println("Novo cliente");
    boolean currentLineIsBlank = true;
     
    while (client.connected()) {
      if (client.available()) {
        c = client.read();
        //Serial.write(c);
          
        if(conteudo.length() < 50){            
          conteudo += c;
        }

        if (c == 'n' && currentLineIsBlank) {
          
          verificarComandos(conteudo);  

            StaticJsonBuffer<500> jsonBuffer; JsonObject& root = jsonBuffer.createObject(); JsonArray& valorTemperatura = root.createNestedArray("temperatura");
            valorTemperatura.add(temperaturaAtual()); Serial.print(F("Sending: ")); root.printTo(Serial); Serial.println(); client.println("HTTP/1.0 200 OK");
            client.println("Content-Type: application/json"); client.println("Connection: close"); client.println("Refresh: 5"); client.println(); root.prettyPrintTo(client);  
          
          break;
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
    acao = "";
  }
}


