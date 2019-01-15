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


Serial.begin(9600);
}

void loop() {

  Db1.update();
  Db2.update();
  

  if (Db2.fell()){
    Keyboard.press('z');
    for(int i=0;i<5;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    np1.setPixelColor(i, np1.Color(0,150,0)); // Moderately bright green color.

    np1.show();
    }   
  }
if (Db2.rose()){
  Keyboard.release('z');
    for(int i=0;i<5;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    np1.setPixelColor(i, np1.Color(150,0,0)); // Moderately bright green color.

    np1.show();
    }   
  }

 // #----------------------------------------

    if (Db1.fell()){
      Keyboard.press('x');
    for(int i=6;i<10;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    np1.setPixelColor(i, np1.Color(0,150,0)); // Moderately bright green color.

    np1.show();
    }   
  }
if (Db1.rose()){
  Keyboard.release('x');
    for(int i=6;i<10;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    np1.setPixelColor(i, np1.Color(150,0,0)); // Moderately bright green color.

    np1.show();
    }   
  }

  Serial.print(" B1:");
  Serial.print(Db1.read());
  Serial.print(" B2:");
  Serial.println(Db2.read());
  delay(1);
}
