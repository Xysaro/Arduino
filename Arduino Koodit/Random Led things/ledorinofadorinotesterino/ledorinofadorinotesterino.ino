#include <Adafruit_NeoPixel.h>


int PIN = 9;
int totalLEDs = 8;
int ledFadeTime = 50;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(totalLEDs, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  Serial.begin(38400);
}

void loop() {
  rgbFadeInAndOut(255, 0, 255, ledFadeTime); // Blue
  }

void rgbFadeInAndOut(uint8_t red, uint8_t green, uint8_t blue, uint8_t wait) {
  for(uint8_t b = 20; b <200; b++) {
     for(uint8_t i=0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, red * b/255, green * b/255, blue * b/255);
     }

     strip.show();
      Serial.println(b);
     delay(wait);
  };

  for(uint8_t b=200; b > 20; b--) {
     for(uint8_t i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, red * b/255, green * b/255, blue * b/255);
     }
     strip.show();
      Serial.println(b);
     delay(wait);
  };
};
