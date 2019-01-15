/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;
Servo myservo2; // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(11);
}

void loop() {

    myservo.write(0);              // tell servo to go to position in variable 'pos'
    myservo2.write(180);
    delay(2000);
    myservo.write(0);              // tell servo to go to position in variable 'pos'
    myservo2.write(0);
    delay,(2000);
    myservo.write(0);              // tell servo to go to position in variable 'pos'
    myservo2.write(180);
    delay,(2000);
    myservo.write(0);              // tell servo to go to position in variable 'pos'
    myservo2.write(0);
    delay(2000);
}

