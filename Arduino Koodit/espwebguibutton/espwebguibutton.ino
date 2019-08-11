#include <ESP32Servo.h>

#include <DNSServer.h>
#include <ESPUI.h>


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
  
  long interval = 10; 
  unsigned long previousMillis = 0;
  unsigned long currentMillis = millis();
  unsigned long previousMillis2 = 0;
  unsigned long currentMillis2 = millis();
  int posL = 0;
  int posR = 180;
  
while (posR != 132 || posL != 111){
  if (currentMillis - previousMillis >= interval && posR!=132){
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    posR++;
    Serial.print(posR);
    Rights.write(posR);
  }

  if (currentMillis2 - previousMillis2 >= interval && posL!=132){
    // save the last time you blinked the LED
    previousMillis2 = currentMillis2;
    posL++;
    Serial.println("/t"); 
    Serial.println(posL); 
    Lefts.write(posL);

  }
 }
}

void padExample(Control sender, int value) {
  switch (value) {
    case P_LEFT_DOWN:
      Serial.print("left down");
      Rights.write(0);
      Lefts.write(0); 
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
     Lefts.write(0);      
      break;
    case P_FOR_UP:
      Serial.print("for up");
      Servostop();

      break;
    case P_BACK_DOWN:
      Serial.print("back down");
      Rights.write(0);
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

  if (millis() - oldTime > 5000) {
    ESPUI.print("Millis:", String(millis()));
    switchi = !switchi;
    ESPUI.updateSwitcher("Switch one", switchi);
    oldTime = millis();
  }
}
