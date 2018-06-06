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
        //Serial.write(c);
          
        if(conteudo.length() < 50){            
          conteudo += c;
        }

        if (c == 'n' && currentLineIsBlank) {

            //verificarComandos(conteudo);
            String acoes =  "";
  int i = conteudo.indexOf("/") +1;
  int f = conteudo.indexOf(" HTTP");

  Serial.print(F("Conteúdo da URL: ")); Serial.println(conteudo);
  //Serial.print("Inicio: "); Serial.println(i);
  //Serial.print("Fim: "); Serial.println(f);
  acoes = conteudo.substring(i,f);
  Serial.print("Conteúdo ações: "); Serial.println(acoes);

  while(!acoes.equals("")){
    String acaoSeparada = "";
    //acaoSeparada = separaAcao(acoes);
    
    Serial.print(F("Ações URL inicio: ")); Serial.println(acoes);
    
    if(acoes.indexOf("&") != -1){
      int inicio = 0;
      int fim = acoes.indexOf("&") + 1;
        
      acaoSeparada = acoes.substring(inicio, fim);
    }else{
      int inicio = 0;
      int fim = acoes.length();
      acaoSeparada = acoes.substring(inicio, fim);
    }

    acoes.replace(acaoSeparada, "");
    acaoSeparada.replace("&","");
    Serial.print("aaaaaaaaaaaaaa "); Serial.println(acaoSeparada.substring(0,2));
    if(acaoSeparada.equalsIgnoreCase("t1=1")){
      ligarDesligarRele(r1, true);
    }else if(acaoSeparada.equalsIgnoreCase("t1=0")){
      digitalWrite(r1, HIGH);
    }else if(acaoSeparada.equalsIgnoreCase("t2=1")){
      digitalWrite(r2, LOW);
    }else if(acaoSeparada.equalsIgnoreCase("t2=0")){
      digitalWrite(r2, HIGH);
    }else if(acaoSeparada.equalsIgnoreCase("t3=1")){
      digitalWrite(r3, LOW);
    }else if(acaoSeparada.equalsIgnoreCase("t3=0")){
      digitalWrite(r3, HIGH);
    }else if(acaoSeparada.equalsIgnoreCase("t4=1")){
      digitalWrite(r4, LOW);
    }else if(acaoSeparada.equalsIgnoreCase("t4=0")){
      digitalWrite(r4, HIGH);
    }else if(acaoSeparada.equalsIgnoreCase("t5=1")){
      digitalWrite(r5, LOW);
    }else if(acaoSeparada.equalsIgnoreCase("t5=0")){
      digitalWrite(r5, HIGH);
    }else if(acaoSeparada.equalsIgnoreCase("t6=1")){
      digitalWrite(r6, LOW);
    }else if(acaoSeparada.equalsIgnoreCase("t6=0")){
      digitalWrite(r6, HIGH);
    }else if(acaoSeparada.equalsIgnoreCase("t7=1")){
      digitalWrite(r7, LOW);
    }else if(acaoSeparada.equalsIgnoreCase("t7=0")){
      digitalWrite(r7, HIGH);
    }else if(acaoSeparada.equalsIgnoreCase("t8=1")){
      digitalWrite(r8, LOW);
    }else if(acaoSeparada.equalsIgnoreCase("t8=0")){
      digitalWrite(r8, HIGH);
    }
    
    Serial.print(F("Ação separada: ")); Serial.println(acaoSeparada);
    
    Serial.print(F("Ações final: ")); Serial.println(acoes);
  }
            //fim teste
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
}


