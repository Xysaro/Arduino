#include <IRremote.h>
#include <IRremoteInt.h>
#include <Servo.h>
//////////////////////
//Remote ids for arrows
//up    12758, 2758
//down  12759, 2759
//left  1276A, 276A
//right 1276B, 276B
//////////////////////
//servo centers
//Right:122" "
//Left:109"
//////////////////////
int IRpin = 3;
Servo right;
Servo left;

IRrecv irrecv(IRpin);
decode_results results;

void setup() {
  irrecv.enableIRIn(); // Start the receiver
  right.attach(10);
  left.attach(11);
  Serial.begin(9600);
  

}

void loop() {

  if (irrecv.decode(&results)); 
    {
      Serial.println(results.value, HEX);
      irrecv.resume();   // Receive the next value
    } 


switch (results.value) {
    case 12758 : //up
    left.write(180); 
    right.write(0);    
    break;
    
    case 12759 : //down
    left.write(0); 
    right.write(180);      
    break;
    
    case 0x1276A : //left
    left.write(180); 
    right.write(180);    
    break;
    
    case 0x1276B : //right
    left.write(0); 
    right.write(0);
    break;
    
    default: 
    left.write(109); 
    right.write(122);
    break;
  }
  
}
