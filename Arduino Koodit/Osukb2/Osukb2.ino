#include <HID-Project.h>
#include <HID-Settings.h>


#include <Adafruit_FreeTouch.h>

Adafruit_FreeTouch qt2 = Adafruit_FreeTouch(A3, OVERSAMPLE_8, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt1 = Adafruit_FreeTouch(A0, OVERSAMPLE_8, RESISTOR_50K, FREQ_MODE_NONE);

int pt[]={400,600};
int qtd[2];

void setup() {
 
 qt1.begin();
 qt2.begin();
 Serial.begin(9600);

}

void loop() {

qtd[1]=qt1.measure();
qtd[2]=qt2.measure();

Serial.print(qtd[1]);
Serial.print("\t");
Serial.println(qtd[2]);

if (qt[1]>pt[1]){
  
}
 
}
