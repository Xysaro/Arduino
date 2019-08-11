#include <FastLED.h>

#define NUM_LEDS 8
#define DATA_PIN 10
extern const TProgmemRGBPalette16 CloudColors_p FL_PROGMEM;
extern const TProgmemRGBPalette16 LavaColors_p FL_PROGMEM;
int state;

CRGB valot[NUM_LEDS];


void setup() {
  Serial1.begin(57600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(valot, NUM_LEDS);

}

void loop() {


static uint8_t Pmillis=0;
uint8_t Cmillis=millis();
int indexadd = 255/NUM_LEDS;


lavalamp ();
        
    

}

void lavaroll() {
	int indexadd = 255 / NUM_LEDS;
	uint8_t colorIndex = 10;
	uint8_t brightness = 1;
	
	for (int dot = 0; dot < NUM_LEDS; dot++) {
		valot[dot] = ColorFromPalette(LavaColors_p, colorIndex, brightness, NOBLEND);
	}
}

void lavalamp (){

int indexadd = 255/NUM_LEDS;
uint8_t colorIndex = 10;
uint8_t brightness=1;
  
  for(int dot = 0; dot < NUM_LEDS; dot++) { 
     for(brightness= 0;brightness <255;brightness++){
     
     valot[dot] = ColorFromPalette( LavaColors_p, colorIndex, brightness, NOBLEND);
     Serial1.print(dot,DEC);
     Serial1.print(",");
     Serial1.print(colorIndex,DEC);
     Serial1.print(",");
     Serial1.print(brightness,DEC);
     Serial1.print(",");
     Serial1.println(state,DEC);
     
    FastLED.show();
    FastLED.delay(10);
    }
    colorIndex += indexadd;
    if (dot == 7){
      state=1;
      return(state);
    }
    FastLED.show();
  }
}

