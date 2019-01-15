/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>
#include <SoftwareSerial.h>
#include <Encoder.h>

SoftwareSerial BT(10, 11); 
Servo myservo;  // create servo object to control a servo
Encoder myEnc(5, 6);

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
int maxpos = 200;
int minpos = 0;
long newPosition;
long oldPosition  = -999;


void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  BT.begin(9600);
  BT.println("Hello from Arduino");
  Serial.begin(9600);
  Serial.println("Basic Encoder Test:");
  

}

void loop() {
  newPosition = myEnc.read();
  if (newPosition != oldPosition) {
    if (newPosition > maxpos){newPosition = maxpos;}
    if (newPosition < minpos){newPosition = minpos;}
    newPosition = constrain(newPosition,0,200);
    oldPosition = newPosition;
    Serial.println(newPosition);
  } 
  BT.print("encoder=");
  BT.print(newPosition);
  newPosition = map(newPosition, 0, 200, 0, 180);
  BT.print("--uS=");
  BT.println(newPosition);
  myservo.write(newPosition);
  delay(15);
}

