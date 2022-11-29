
#include <WiFi.h>
#include <ESPmDNS.h>
#include <ESPAsyncWebServer.h>



#define ENA 15  //en-A
#define A1F 16  //A1 foreward
#define A2B 17  //A2 backward
#define ENB 12  //en-B
#define B1F 13  //B1 foreward
#define B2B 14  //B2 backward


//PROGMEM describes that that particular thing will store in RAM. By Default everything stores in flash memory.

//(raw string literal) R"====()  iF we Not mention This we should write whole html code in single line.

char webpage[] PROGMEM = R"=====(

<!DOCTYPE html>
<html>
<body>

<center>
<h1>UGV unnamed ground vehicle</h1>
<button onclick="window.location = 'http://'+location.hostname+'/start'">START</button>
<button onclick="window.location = 'http://'+location.hostname+'/stop'">STOP</button>
<h3> 
<button onclick="window.location = 'http://'+location.hostname+'/front'">&#8593</button>
</h3>
<button onclick="window.location = 'http://'+location.hostname+'/left'">&#8592</button>
<button onclick="window.location = 'http://'+location.hostname+'/right'">&#8594</button>
<h3>
<button onclick="window.location = 'http://'+location.hostname+'/back'">&#8595</button>
</h3>

</center>
</body>
</html>

)=====";

     
//instead of giving manually ipaddress we give "+location.hostname+" which returns current ipaddress


AsyncWebServer server(80); // server port 80

void notFound(AsyncWebServerRequest *request)
{
  request->send(404, "text/plain", "Page Not found");
}

void setup(void)
{
  
  pinMode(ENA,OUTPUT);
  pinMode(A1F,OUTPUT);
  pinMode(A2B,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(B1F,OUTPUT);
  pinMode(B2B,OUTPUT);
  
  WiFi.softAP("ugvEsp", "12345678");

  MDNS.begin("ESP"); //esp.local/
    
    
  server.on("/", [](AsyncWebServerRequest * request)
  { 
   
  request->send_P(200, "text/html", webpage);
  });

   server.on("/front", HTTP_GET, [](AsyncWebServerRequest * request)
  { 
    digitalWrite(A1F,HIGH);
    digitalWrite(B1F,HIGH);
    digitalWrite(A2B,LOW);
    digitalWrite(B2B,LOW);
  request->send_P(200, "text/html", webpage);
  });
  
   server.on("/back", HTTP_GET, [](AsyncWebServerRequest * request)
  { 
    digitalWrite(A2B,HIGH);
    digitalWrite(B2B,HIGH);
    digitalWrite(A1F,LOW);
    digitalWrite(B1F,LOW);
  request->send_P(200, "text/html", webpage);
  });
  
   server.on("/left", HTTP_GET, [](AsyncWebServerRequest * request)
  { 
    digitalWrite(A1F,HIGH);
    digitalWrite(B1F,LOW);
    digitalWrite(A2B,LOW);
    digitalWrite(B2B,LOW);
  request->send_P(200, "text/html", webpage);
  });
  
   server.on("/right", HTTP_GET, [](AsyncWebServerRequest * request)
  { 
    digitalWrite(A1F,LOW);
    digitalWrite(B1F,HIGH);
    digitalWrite(A2B,LOW);
    digitalWrite(B2B,LOW);
  request->send_P(200, "text/html", webpage);
  });
  
   server.on("/stop", HTTP_GET, [](AsyncWebServerRequest * request)
  { 
    digitalWrite(A1F,LOW);
    digitalWrite(B1F,LOW);
    digitalWrite(A2B,LOW);
    digitalWrite(B2B,LOW);
  request->send_P(200, "text/html", webpage);
  });

   server.on("/start", HTTP_GET, [](AsyncWebServerRequest * request)
  { 
  
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  request->send_P(200, "text/html", webpage);
  });
  
  server.onNotFound(notFound);

  server.begin();  // it will start webserver
}


void loop(void)
{
}
