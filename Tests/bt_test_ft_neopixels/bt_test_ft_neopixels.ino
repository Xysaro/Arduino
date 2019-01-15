
#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>
SoftwareSerial BT(8, 9); 
// creates a "virtual" serial port/UART
// connect BT module TX to D10
// connect BT module RX to D11
// connect BT Vcc to 5V, GND to GND

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(8, 4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixel = Adafruit_NeoPixel(1, 3, NEO_GRB + NEO_KHZ800);

char b; // stores incoming character from other device
int a; // stores incoming character from other device


void setup()  
{
  pixels.begin();
  pixel.begin();
  pixels.show();
  pixel.show();
  // set the data rate for the SoftwareSerial port
  BT.begin(9600);
  // Send test message to other device
  BT.println("Hello from Arduino");
  Serial.begin(9600);
}
void loop() 
{
  if (BT.available()) {
    BT.print("received ");
    b=(BT.read());
  
    if(isDigit(b)){  
      a=b;
      BT.println(a);
      Serial.println(a);
    }
  
  }
 
switch(a){

case 49:
solidcolor(255,0,0,8);


break;
case 50:
solidcolor(0,255,0,8);

break;
case 51:
solidcolor(0,0,255,8);

break;
case 52:
rgbFadeInAndOut(255,0,255,50);

break;
case 53:
rainbow(20);

break;
default:
solidcolor(0,0,0,8);

break;
}
}

//for simple solid color
void solidcolor( int red,int green,int blue,int NUM){

for(int i=0;i<NUM;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(red,green,blue)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(1); // Delay for a period of time (in milliseconds).

  }
  
}

//fade in and out effect
void rgbFadeInAndOut(uint8_t red, uint8_t green, uint8_t blue, uint8_t wait) {
  for(uint8_t b = 20; b <200; b++) {
     for(uint8_t i=0; i < pixels.numPixels(); i++) {
        pixels.setPixelColor(i, red * b/255, green * b/255, blue * b/255);
     }

     pixels.show();
     Serial.println(b);
     if (BT.available()) {
        break;
       }
     delay(wait);
  };

  for(uint8_t b=200; b > 20; b--) {
     for(uint8_t i = 0; i < pixels.numPixels(); i++) {
        pixels.setPixelColor(i, red * b/255, green * b/255, blue * b/255);
     }
     pixels.show();
     Serial.println(b);
     if (BT.available()) {
        break;
       }
     delay(wait);
  }
}


void rainbow(uint8_t wait) { //koska sateenkaari
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<pixels.numPixels(); i++) {
      pixels.setPixelColor(i, Wheel((i+j) & 255));
    }
    pixels.show();
    if (BT.available()) { //to break loop if new bluetooth instruction is available
        break;
       }
    delay(wait);
  }
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
