#include <IRremote.h>
#include <IRremoteInt.h>
#include <Servo.h>
//////////////////////
//Remote ids for arrows
//up    12758, 2758 //10072, 75608 
//down  12759, 2759 //10073, 75609
//left  1276A, 276A //10074, 75610
//right 1276B, 276B //10075, 75611
//////////////////////
//servo centers
//Right:122" "
//Left:109"
//////////////////////
int RECV_PIN = 9;
Servo right;
Servo left;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() 
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  right.attach(10);
  left.attach(11);
 }

void loop(){

  if (irrecv.decode(&results)) 
    {
      Serial.println(results.value);
      irrecv.resume();   // Receive the next value
    } 


switch (results.value) {
    case 10072 : //up
    left.write(180); 
    right.write(0);    
    break;
    
    case 10073 : //down
    left.write(0); 
    right.write(180);      
    break;
    
    case 10074 : //left
    left.write(180); 
    right.write(180);    
    break;
    
    case 10075 : //right
    left.write(0); 
    right.write(0);
    break;
    
    default: 
    left.write(107); 
    right.write(121);
    break;
  }
  
}
