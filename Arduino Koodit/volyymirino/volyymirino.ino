#include <HID-Project.h>
#include <HID-Settings.h>
#include <Bounce2.h>
#include <Encoder.h>
#define key1p KEY_RIGHT_ARROW

int pause = 7;


Bounce pb = Bounce();
Encoder myEnc(5, 6);

void setup() {
  pinMode(pause, INPUT_PULLUP);
  pb.attach(pause);
  pb.interval(8);
  Serial.begin(9600);
  Consumer.begin();
}

long op  = -999;

void loop() {
 pb.update();

  if (pb.read() == LOW) {
    Consumer.write(MEDIA_VOLUME_MUTE);
    delay(50);
  }


  long np = myEnc.read();
  while (np != op) {
    if (np < op){
     Consumer.write(MEDIA_VOLUME_UP);
     Serial.println(np);
      op = np;
    }
     else{
     Consumer.write(MEDIA_VOLUME_DOWN);
     op = np;
   }                                                                                        
  
  
  
  
  }
}
