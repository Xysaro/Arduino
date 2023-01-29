/*********
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com  
*********/

// Import required libraries
#ifdef ESP32
  #include <WiFi.h>
  #include <ESPAsyncWebServer.h>
#else
  #include <Arduino.h>
  #include <ESP8266WiFi.h>
  #include <Hash.h>
  #include <ESPAsyncTCP.h>
  #include <ESPAsyncWebServer.h>
#endif

#include <ESPmDNS.h>
#include <NewPing.h>

#define TRIGGER_PIN  32  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     33  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

String hostname = "tynnyri";

// Variables to store temperature values

String distanceCM = "";


// Timer variables
unsigned long lastTime = 0;  
unsigned long timerDelay = 30000;

// Replace with your network credentials
const char* ssid = "TP-LINK";
const char* password = "Vanhatalo";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);


String readDistanceCM(){
  int dist = sonar.ping_cm();
  Serial.println(dist);
  return String(dist); 
}


const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    html {
     font-family: Arial;
     display: inline-block;
     margin: 0px auto;
     text-align: center;
    }
    h2 { font-size: 3.0rem; }
    p { font-size: 3.0rem; }
    .units { font-size: 1.2rem; }
    .ds-labels{
      font-size: 1.5rem;
      vertical-align:middle;
      padding-bottom: 15px;
    }
  </style>
</head>
<body>
  <h2>Pellettitynnyrin syvyys</h2>
  <p>
    <span id="distacecm">%DISTANCECM%</span>
    <span class="units">cm</span>
  </p>
</body>
<script>
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("distancecm").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/distancecm", true);
  xhttp.send();
}, 10000) ;

</script>
</html>)rawliteral";

// Replaces placeholder with DS18B20 values
String processor(const String& var){
  //Serial.println(var);

 if(var == "DISTANCECM"){
    return distanceCM;
  }
  return String();
}

void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);
  Serial.println();
  
  
  readDistanceCM();

  // Connect to Wi-Fi
  WiFi.config(INADDR_NONE, INADDR_NONE, INADDR_NONE, INADDR_NONE);
  WiFi.setHostname(hostname.c_str()); //define hostname
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  if(!MDNS.begin(hostname.c_str())) {
     Serial.println("Error starting mDNS");
     return;
  }
  
  Serial.println();
  
  // Print ESP Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
  });
  server.on("/distancecm", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", distanceCM.c_str());
  });
  // Start server
  server.begin();
}
 
void loop(){
  if ((millis() - lastTime) > timerDelay) {
    distanceCM = readDistanceCM();
    lastTime = millis();
  }  
}
