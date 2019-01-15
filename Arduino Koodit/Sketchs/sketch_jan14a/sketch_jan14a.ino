#include <Servo.h> 

Servo myservo;

void setup() 
{ 
  myservo.attach(8);
  myservo.writeMicroseconds(1000);  // set servo to mid-point
} 

void loop() {} 

