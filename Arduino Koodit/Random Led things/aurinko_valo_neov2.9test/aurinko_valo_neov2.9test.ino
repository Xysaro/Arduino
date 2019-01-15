#include <Adafruit_NeoPixel.h>
#include <SevSeg.h>


int NP = 2;
int PIN = A0;
float r = 0;
float b = 0;
float g = 0;
int t = 2000;
int tt = 2000;
int i = 0;
int c = 0;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NP, PIN, NEO_GRB + NEO_KHZ800);
SevSeg sevseg; //Instantiate a seven segment controller object
unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
 pixels.begin();
 pixels.show();
 Serial.begin(9600);
 Serial.println("start");
 
 

 byte numDigits = 4;   
 byte digitPins[] = {2, 3, 4, 5};
 byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
 sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
 sevseg.setBrightness(100);

}

void loop() {
sevseg.refreshDisplay();

  while (r<255){
    unsigned long currentMillis = millis();
    
    sevseg.setNumber(c , 0);
    sevseg.refreshDisplay(); // Must run repeatedly
if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    r++;  
    b=b+0.22;
    g=g+0.61;
    c=interval/1000+c;
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
  Serial.println();
  sevseg.refreshDisplay();
  
}


