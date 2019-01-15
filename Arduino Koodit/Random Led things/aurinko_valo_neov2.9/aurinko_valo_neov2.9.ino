#include <Adafruit_NeoPixel.h>
#include <SevSeg.h>


int NP = 60;
int PIN = A0;
float r = 0;
float b = 0;
float g = 0;
int t = 2000;
int tt = 2000;
int i = 0;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NP, PIN, NEO_GRB + NEO_KHZ800);
SevSeg sevseg; //Instantiate a seven segment controller object


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

  while (r<255){
    r++;  
    b=b+0.22;
    g=g+0.61;
    sevseg.setNumber(r, -1);  
    sevseg.refreshDisplay();
    pixol();};
  


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
  sevseg.setNumber(r, -1);  
  sevseg.refreshDisplay();
  delay(tt);
}

void dig(){
sevseg.setNumber(r, -1);  
sevseg.refreshDisplay(); // Must run repeatedly 
}

