#include <Adafruit_NeoPixel.h>

int PIN = 4;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(8, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  pixels.begin();
  pixels.show();
  pixels.setBrightness(50);

}

void loop() {
  pixels.setPixelColor(0,255,255,0);
  pixels.setPixelColor(1,255,255,0);
  pixels.setPixelColor(2,0,255,0);
  pixels.setPixelColor(3,0,255,0);
  pixels.setPixelColor(4,0,0,155);
  pixels.setPixelColor(5,0,0,155);
  pixels.setPixelColor(6,155,0,0);
  pixels.setPixelColor(7,0155,0,0);
  pixels.show();
}
