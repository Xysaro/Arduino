#include <Servo.h>

Servo Steer;

int left=7;
int right=8;

void setup() {
Steer.attach(9);
pinMode(left, INPUT);
pinMode(right, INPUT);  
}

void loop() {

  if (left == HIGH){Steer.write(135);}
  if (right == HIGH){Steer.write(45);}
  else { Steer.write(90);}
  // put your main code here, to run repeatedly:

}
