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
              StaticJsonBuffer<1500> jsonBuffer; JsonObject& root = jsonBuffer.createObject(); 
              JsonArray& aquarioArray = root.createNestedArray("aquario");
              JsonObject& aquarioObject = jsonBuffer.createObject();
              aquarioArray.add(aquarioObject);
              
              JsonArray& tempArray = aquarioObject.createNestedArray("temperatura");
              JsonObject& tempObject = jsonBuffer.createObject();
              tempArray.add(tempObject);
              tempObject["atual"] = temperaturaAtual();
              tempObject["ideal"] = tIdeal;
              tempObject["minima"] = tMin;
              tempObject["maxima"] = tMax;

              JsonArray& relesArray = aquarioObject.createNestedArray("tomadas");
              JsonObject& relesObject = jsonBuffer.createObject();
              relesArray.add(relesObject);
              relesObject["t1"] = statusRele(r4);
              relesObject["t2"] = statusRele(r5);
              relesObject["t3"] = statusRele(r6);
              relesObject["t4"] = statusRele(r7);
              relesObject["t5"] = statusRele(r8);

              JsonArray& controlsArray = aquarioObject.createNestedArray("controles");
              JsonObject& controlsObject = jsonBuffer.createObject();
              controlsArray.add(controlsObject);
              controlsObject["nivel"] = retornaStatusBoia();
              controlsObject["qtdReposicoes"] = qtdReposicoes;
              controlsObject["temperatura"] = retornaStatusTemperatura();
              controlsObject["iluminacao"] = retornaStatusIluminacao();

              JsonArray& dataArray = aquarioObject.createNestedArray("dateTime");
              JsonObject& dataObject = jsonBuffer.createObject();
              dataArray.add(dataObject);
              dataObject["data"] = retornarData();
              dataObject["hora"] = retornarHora();

              JsonArray& pAtualArray = aquarioObject.createNestedArray("potenciaAtual");
              JsonObject& pAtualObject = jsonBuffer.createObject();
              pAtualArray.add(pAtualObject);
              pAtualObject["azul"] = potenciaAzulAtual;
              pAtualObject["branco"] = potenciaBrancaAtual;
              
              JsonArray& potenciaAzulArray = aquarioObject.createNestedArray("potenciaAzul");
              JsonObject& potenciaAzulObject = jsonBuffer.createObject();
              potenciaAzulArray.add(potenciaAzulObject);
              potenciaAzulObject["p0"] = b10;
              potenciaAzulObject["p1"] = b11;
              potenciaAzulObject["p2"] = b12;
              potenciaAzulObject["p3"] = b13;
              potenciaAzulObject["p4"] = b14;
              potenciaAzulObject["p5"] = b15;
              potenciaAzulObject["p6"] = b16;
              potenciaAzulObject["p7"] = b17;
              potenciaAzulObject["p8"] = b18;
              potenciaAzulObject["p9"] = b19;

              JsonArray& horaAzulArray = aquarioObject.createNestedArray("horaAzul");
              JsonObject& horaAzulObject = jsonBuffer.createObject();
              horaAzulArray.add(horaAzulObject);
              horaAzulObject["h0"] = c10;
              horaAzulObject["h1"] = c11;
              horaAzulObject["h2"] = c12;
              horaAzulObject["h3"] = c13;
              horaAzulObject["h4"] = c14;
              horaAzulObject["h5"] = c15;
              horaAzulObject["h6"] = c16;
              horaAzulObject["h7"] = c17;
              horaAzulObject["h8"] = c18;
              horaAzulObject["h9"] = c19;
              
              JsonArray& potenciaBrancoArray = aquarioObject.createNestedArray("potenciaBranco");
              JsonObject& potenciaBrancoObject = jsonBuffer.createObject();
              potenciaBrancoArray.add(potenciaBrancoObject);
              potenciaBrancoObject["p0"] = b20;
              potenciaBrancoObject["p1"] = b21;
              potenciaBrancoObject["p2"] = b22;
              potenciaBrancoObject["p3"] = b23;
              potenciaBrancoObject["p4"] = b24;
              potenciaBrancoObject["p5"] = b25;
              potenciaBrancoObject["p6"] = b26;
              potenciaBrancoObject["p7"] = b27;
              potenciaBrancoObject["p8"] = b28;
              potenciaBrancoObject["p9"] = b29;
              
              JsonArray& horaBrancoArray = aquarioObject.createNestedArray("horaBranco");
              JsonObject& horaBrancoObject = jsonBuffer.createObject();
              horaBrancoArray.add(horaBrancoObject);
              horaBrancoObject["h0"] = c20;
              horaBrancoObject["h1"] = c21;
              horaBrancoObject["h2"] = c22;
              horaBrancoObject["h3"] = c23;
              horaBrancoObject["h4"] = c24;
              horaBrancoObject["h5"] = c25;
              horaBrancoObject["h6"] = c26;
              horaBrancoObject["h7"] = c27;
              horaBrancoObject["h8"] = c28;
              horaBrancoObject["h9"] = c29;
              
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
