#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

int Xin=A0;
int Yin=A1;
int Bin=3;

int pos = 0;
int pos2 = 0;
int bmod = 0;
int lastState = 0;
int bstate =0;

void setup() {

pinMode(Bin,INPUT);

servo1.attach(11);
servo2.attach(10);
servo3.attach(9);
servo4.attach(8);
servo5.attach(7);
anglereset();

Serial.begin(9600);
}

void anglereset(){
  
  servo1.write(90);
  delay(1000);
  servo2.write(90);
  delay(1000);
  servo3.write(90);
  delay(1000);
  servo4.write(90);
  delay(1000);
  servo5.write(90);
  delay(1000);
}

void Angle(){
  pos = analogRead(Xin);
  pos = map(pos, 0, 1023, 0, 180);
  pos2 = analogRead(Yin);
  pos2 = map(pos2, 0, 1023, 0, 180);
  
}

  
void loop() {
  Angle();

bstate = digitalRead(Bin);

  if (bstate == HIGH && bstate != lastState){
   lastState = 1; 
    bmod++;
  
  }
  if (bstate == LOW) {
    lastState = 0 ;
  }
  
  
  if (bmod >4){
    bmod = 0;
  }

  switch(bmod) {
    default:
    servo1.write(pos2);
    break;
    case 1:
    servo2.write(pos2);
    break;
    case 2:
    servo3.write(pos2);
    break;
    case 3:
    servo4.write(pos2);
    break;
    case 4:
    servo5.write(pos2);
    break;

  }
  
  Serial.print(pos);
  Serial.print("  ");
  Serial.print(pos2);
  Serial.print("  ");
  Serial.print(bmod);
  Serial.print("  ");
  Serial.println(bstate);



}
