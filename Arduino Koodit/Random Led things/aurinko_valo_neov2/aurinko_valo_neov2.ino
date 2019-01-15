#include <Adafruit_NeoPixel.h>

int NP = 2;
int PIN = 6;
int r = 0;
int b = 0;
int g = 0;
float f = 0;
float l = 0;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NP, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
 pixels.begin();
 pixels.show();
 Serial.begin(9600);
 Serial.println("start");

}

void loop() {

  while (r<255){
    r++;  
    f = f + 0.22;
    b = (int)f;
    l = l + 0.61;
    g = (int)l;
    pixol();};
  


}
void pixol() {
  pixels.setPixelColor(0, r,g, b);
  pixels.setPixelColor(1, r, g, b);
  pixels.show();
  Serial.print("Red--");
  Serial.print(r);
  Serial.print("--Blue--");
  Serial.print(b);
  Serial.print("--Green--");
  Serial.print(g);
   Serial.print("--FLoatn--");
  Serial.print(f);
  Serial.println();
  delay(100);
}


