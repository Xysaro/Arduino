#include <ESP32Servo.h>

#include <DNSServer.h>
#include <ESPUI.h>

#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>


  
const byte DNS_PORT = 53;
IPAddress apIP(192, 168, 1, 1);
DNSServer dnsServer;

#if defined(ESP32)
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif

const char *ssid = "HUAWEI";
const char *password = "Vanhatalo";

long oldTime = 0;
bool switchi = false;

void numberCall(Control sender, int type) { Serial.println(sender.value); }

void textCall(Control sender, int type) { Serial.println(sender.value); }

void slider(Control sender, int type) { Serial.println(sender.value); }

Servo Lefts;  // stops at 111, forward at 0
Servo Rights; // stops at 132, forward at 180

int Leftsp = 13;
int Rightsp = 12;


void Servostop(){
  
 for (int posR = 180;posR > 133;posR--){
    Serial.println(posR);
    Rights.write(posR);
    delay(1);
 }
 for (int posL = 0;posL < 113;posL++){
    Serial.println(posL); 
    Lefts.write(posL);
    delay(1);
  }
 }


void padExample(Control sender, int value) {
  switch (value) {
    case P_LEFT_DOWN:
      Serial.print("left down");
      Rights.write(56);
      Lefts.write(66); 
      break;
    case P_LEFT_UP:
      Serial.print("left up");
      Servostop();
      break;
    case P_RIGHT_DOWN:
      Serial.print("right down");
      Rights.write(180);
      Lefts.write(180);       
      break;
    case P_RIGHT_UP:
      Serial.print("right up");
      Servostop();
      break;
    case P_FOR_DOWN:
      Serial.print("for down");
     Rights.write(180);
     Lefts.write(66);      
      break;
    case P_FOR_UP:
      Serial.print("for up");
      Servostop();

      break;
    case P_BACK_DOWN:
      Serial.print("back down");
      Rights.write(56);
      Lefts.write(180);      
      break;
    case P_BACK_UP:
      Serial.print("back up");
      Servostop();
      break;
    case P_CENTER_DOWN:
      Serial.print("center down");
      
      break;
    case P_CENTER_UP:
      Serial.print("center up");
      
      break;
  }
  Serial.print(" ");
  Serial.println(sender.id);
}


void setup(void) {

     Serial.begin(115200);
     WiFi.begin(ssid, password);
     Serial.println("");
     // Wait for connection
     while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.print(".");
     }
     Serial.println("");
     Serial.print("IP address: ");
     Serial.println(WiFi.localIP());

     ArduinoOTA.setHostname("mopo32");

     ArduinoOTA
    .onStart([]() {
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH)
        type = "sketch";
      else // U_SPIFFS
        type = "filesystem";

      // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
      Serial.println("Start updating " + type);
    })
    .onEnd([]() {
      Serial.println("\nEnd");
    })
    .onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    })
    .onError([](ota_error_t error) {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
      else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
      else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
      else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
      else if (error == OTA_END_ERROR) Serial.println("End Failed");
    });

  ArduinoOTA.begin();

  
 Lefts.setPeriodHertz(50);    // standard 50 hz servo
 Lefts.attach(Leftsp, 1000, 2000);

 Rights.setPeriodHertz(50);    // standard 50 hz servo
 Rights.attach(Rightsp, 1000, 2000);

  ESPUI.pad("Pad without center", false, &padExample, COLOR_CARROT);

  /*
     .begin loads and serves all files from PROGMEM directly.
     If you want to serve the files from SPIFFS use ESPUI.beginSPIFFS
     (.prepareFileSystem has to be run in an empty sketch before)
   */

  dnsServer.start(DNS_PORT, "*", apIP);

  /*
   * Optionally you can use HTTP BasicAuth. Keep in mind that this is NOT a
   SECURE way of limiting access.
   * Anyone who is able to sniff traffic will be able to intercept your password
   since it is transmitted in cleartext ESPUI.begin("ESPUI Control", "myuser",
   "mypassword");
  */
  ESPUI.begin("ESPUI Control");
}

void loop(void) {
  dnsServer.processNextRequest();
  ArduinoOTA.handle();

}
