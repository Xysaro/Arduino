#include <ESP32Servo.h>

Servo Lefts; //stoppeda at pos 111
Servo Rights; // stoppeda at pos 132-136

int Leftsp = 13;
int Rightsp = 12;
int pos= 0;

void setup() {
 
 Serial.begin(115200);
 
 Lefts.setPeriodHertz(50);    // standard 50 hz servo
 Lefts.attach(Leftsp, 1000, 2000);
 Rights.setPeriodHertz(50);    // standard 50 hz servo
 Rights.attach(Rightsp, 1000, 2000);

}

void loop() {
  
/*
for(pos = 0;pos < 180; pos++){
    Serial.println(pos);
    Rights.write(pos);
    delay(100);
}
*/
Lefts.write(115);
}
