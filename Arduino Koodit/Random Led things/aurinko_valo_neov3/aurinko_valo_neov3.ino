#include <Adafruit_NeoPixel.h>


int NP = 2;
int PIN = A0;
float r = 0;
float b = 0;
float g = 0;
int t = 2000;
int tt = 2000;
int i = 0;
unsigned long previousMillis = 0;
const long interval = 2000;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NP, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
 pixels.begin();
 pixels.show();
 Serial.begin(9600);
 Serial.println("start");
 

}

void loop() {

  while (r<255){
    unsigned long currentMillis = millis();
    

   if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    r++;  
    b=b+0.22;
    g=g+0.61;
    pixol();};
  
}

}
void pixol() {
  while (i <NP){
    pixels.setPixelColor(i, r,g, b);
    pixels.show();
    i++;
  }
  i=0;
  Serial.print("Red--");
  Serial.print(r);
  Serial.print("--Blue--");
  Serial.print(b);
  Serial.print("--Green--");
  Serial.print(g);
  Serial.print("--AO--");
  Serial.println();
}


