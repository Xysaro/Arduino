#include <Adafruit_NeoPixel.h>

int NP = 2;
int PIN = 6;
int R = 0;
int B = 0;
int G = 0;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NP, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
 pixels.begin();
 pixels.show();
 Serial.begin(9600);

}

void loop() {
  while (R !=255 ){
  R = R + 1;
  }
  while (R == 255 & B !=255) {
  B = B + 1;
  }
  while (B == 255 & G != 255) {
  G = G + 1;
  }
  
  pixels.setPixelColor(0, R, B, G);
  pixels.setPixelColor(1, R, B, G);
  pixels.show();
  Serial.print("Red--");
  Serial.print(R);
  Serial.print("--Blue--");
  Serial.print(B);
  Serial.print("--Green--");
  Serial.print(G);
  Serial.println();
delay(100);
}
