#include <HID-Project.h>
#include <HID-Settings.h>
#include <Adafruit_NeoPixel.h>
#include <Bounce2.h>



int b1 = 2;
int b2 = 3;
int s1 = 0;
int neo1 = 15;

int nup = 10;

Adafruit_NeoPixel np1 = Adafruit_NeoPixel(nup, neo1, NEO_GRB + NEO_KHZ800);


Bounce Db1 = Bounce();
Bounce Db2 = Bounce();

void setup() {
  
pinMode(b1, INPUT_PULLUP);
Db1.attach(b1);
Db1.interval(5);

pinMode(b2, INPUT_PULLUP);
Db2.attach(b2);
Db2.interval(5);

 np1.begin();
 np1.show(); // Initialize all pixels to 'off'

Keyboard.begin();
Serial.begin(9600);
}

void loop() {
  
  
  Db1.update();
  Db2.update();
  

  if (Db2.fell()){
    for(int i=0;i<5;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    np1.setPixelColor(i, np1.Color(0,150,0)); // Moderately bright green color.

    np1.show();
    }   
  }
if (Db2.rose()){
    for(int i=0;i<5;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    np1.setPixelColor(i, np1.Color(150,0,0)); // Moderately bright green color.

    np1.show();
    }   
  }

 // #----------------------------------------

    if (Db1.fell()){
    for(int i=6;i<10;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    np1.setPixelColor(i, np1.Color(0,0,150)); // Moderately bright green color.

    np1.show();
    }   
  }
if (Db1.rose()){
    for(int i=6;i<10;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    np1.setPixelColor(i, np1.Color(150,0,150)); // Moderately bright green color.

    np1.show();
    }   
  }
  keyboard();
}

void keyboard() {

if (Db2.fell()){
  Keyboard.press('z');
}
if (Db2.rose()){
  Keyboard.release('z');
  }
if (Db1.fell()){
  Keyboard.press('x');
  }
if (Db1.rose()){
  Keyboard.release('x');
  }

}

