#include <DNSServer.h>
#include <ESPUI.h>

const byte DNS_PORT = 53;
IPAddress apIP(192, 168, 1, 1);
DNSServer dnsServer;

#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>


const char *ssid = "HUAWEI";
const char *password = "Vanhatalo";

long oldTime = 0;
bool switchi = false;

void numberCall(Control sender, int type) { Serial.println(sender.value); }
void textCall(Control sender, int type) { Serial.println(sender.value); }
void slider(Control sender, int type) { Serial.println(sender.value); }


void setup(void) {

  Serial.println(WiFi.softAPIP());

  // change the beginning to this if you want to join an existing network
  
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
  
 ArduinoOTA.setHostname("myesp32");
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
 

  ESPUI.slider("Slider one", &slider, COLOR_ALIZARIN, "30");
  ESPUI.slider("Slider two", &slider, COLOR_NONE, "100");


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
