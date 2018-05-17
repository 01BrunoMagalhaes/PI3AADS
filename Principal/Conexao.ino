#include <ArduinoJson.h>
#include <SPI.h>
#include <Ethernet.h>

//Definicoes de IP, mascara de rede e gateway
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(192,168,15,24);          //Define o endereco IP
IPAddress gateway(192,168,15,1);      //Define o gateway
IPAddress subnet(255, 255, 255, 0); //Define a máscara de rede

  EthernetServer server(80);
void  inicializarEthernet(){
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
}

void teste() {
  //Aguarda conexao do browser
  EthernetClient client = server.available();
  if (client) {
    Serial.println("Novo cliente");
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == 'n' && currentLineIsBlank) {
          //montar aqui o json de acordo
          // Allocate JsonBuffer
  // Use arduinojson.org/assistant to compute the capacity.
  StaticJsonBuffer<500> jsonBuffer;

  // Create the root object
  JsonObject& root = jsonBuffer.createObject();

  // Criando objeto temperatura
  JsonArray& valorTemperatura = root.createNestedArray("temperatura");
    valorTemperatura.add(temperaturaAtual());

  Serial.print(F("Sending: "));
  root.printTo(Serial);
  Serial.println();

  // Write response headers
  client.println("HTTP/1.0 200 OK");
  client.println("Content-Type: application/json");
  client.println();

  // Write JSON document
  root.prettyPrintTo(client);

        }
        if (c == 'n') {
          currentLineIsBlank = true;
        } else if (c != 'r') {
          currentLineIsBlank = false;
        }
        
      }
    }
    // tempo para o browser receber os dados
    delay(1);
    // fecha a conexão
    client.stop();
    }
}
