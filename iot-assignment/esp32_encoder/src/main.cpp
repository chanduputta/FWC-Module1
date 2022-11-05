#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#ifndef STASSID
#define STASSID "motorola"  // Replace with your network credentials
#define STAPSK  "77777777"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;
int x,y,z,w,a,b;

void OTAsetup() 
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }
  ArduinoOTA.begin();
}

void OTAloop() {
  ArduinoOTA.handle();
}

//-------------------------------------------------------//

void setup(){
  OTAsetup();

  //-------------------//
  // Custom setup code //
  //-------------------//
	pinMode(2, INPUT);
	pinMode(4, INPUT);
	pinMode(5, INPUT);
	pinMode(10, INPUT);
	pinMode(33, OUTPUT);
	pinMode(32, OUTPUT);


}

void loop() {
  OTAloop();
  delay(10);  // If no custom loop code ensure to have a delay in loop
  //-------------------//
  // Custom loop code  //
  //-------------------//
x=digitalRead(2);
y=digitalRead(4);
z=digitalRead(5);
w=digitalRead(10);
a=x|z;
b=y|z;
digitalWrite(33,a);
digitalWrite(32,b);

}


