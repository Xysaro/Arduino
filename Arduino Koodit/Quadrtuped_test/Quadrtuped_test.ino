/***************************************************/
/////////////////////////////////////////////////////
///                                               ///
///    Code for printed Mini 9G Quadruped         ///
///    http://www.thingiverse.com/thing:38159     ///
///    TheCase v.1 Dec2012                        ///
///                                               ///
///    derived from Chopstick Junior 1.0          ///
///    version 1.0.6                              ///
///    by Lutz Michaelis, November 2011           ///  
///    more about this robot and contact form:    ///
///    http://letsmakerobots.com/node/29708       ///
///    powered by                                 ///
///    http://www.roboter-selbstgebaut.com        ///
/////////////////////////////////////////////////////

#include <Servo.h>
// set the names of the servos
/*
 
 .frh = front right hip
 frl = front right leg
 flh = front left hip
 fll = front left leg
 rlh = rear left hip
 rll = rear left leg
 rrh = rear right hip
 rrl = rear right leg
 eye = sevor for sensor
 */
Servo frh;
Servo frl;
Servo flh;
Servo fll;
Servo rlh;
Servo rll;
Servo rrh;
Servo rrl;


// set variables needed for some tasks

//set logical values for physical home position (cheap Chinese servos are cheap!)
int home_frh = 91;
int home_frl = 48;
int home_flh = 66;
int home_fll = 80;
int home_rlh = 93;
int home_rll = 62;
int home_rrh = 77;
int home_rrl = 90;


int pos;
int lastpos;
int val;
int pot=A0;


//////////////////////////////////////
void setup()
{
 
  frh.attach(2);
  frl.attach(3);
  flh.attach(4);
  fll.attach(5);
  rlh.attach(6);
  rll.attach(7);
  rrh.attach(8);
  rrl.attach(9);

  
  Serial.begin(9600);
}      

void loop() {
  
  val=analogRead(pot);
  Serial.print("pot=");
  Serial.print(val);
  val=map(val,0,1023,0,180);
  Serial.print("--Position=");
  Serial.println(val);
  rrl.write(val);
  delay(10 );
    

}
