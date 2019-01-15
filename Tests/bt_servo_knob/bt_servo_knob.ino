/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); 
Servo myservo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  BT.begin(9600);
  BT.println("Hello from Arduino");
}

void loop() {
  val = analogRead(potpin);
  BT.print("pot=");
  BT.print(val);
  val = map(val, 0, 1023, 0, 180);
  BT.print("--Position=");
  BT.println(val );
  myservo.write(val);
  delay(15);
}

