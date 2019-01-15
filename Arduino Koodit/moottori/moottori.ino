
#include <Bounce2.h>

//pin 4&2 = up/down -- pin3 = modbutton

int up   = 2;
int down = 4;
int modbutton  = 3;
int motor = 5;

int motorspeed = 0;
int mode = 0;



Bounce updb = Bounce(); 
Bounce downdb = Bounce(); 
Bounce modbuttondb = Bounce(); 

void setup() {

  pinMode(up ,INPUT_PULLUP);
  updb.attach(up);
  updb.interval(5); // interval in ms
  
  pinMode(down,INPUT_PULLUP);
  downdb.attach(down);
  downdb.interval(5); // interval in ms

  pinMode(modbutton,INPUT_PULLUP);
  modbuttondb.attach(modbutton);
  modbuttondb.interval(5); // interval in ms

  Serial.begin(9600);

}

void loop() {
  // Update the Bounce instances :
  updb.update();
  downdb.update();
  modbuttondb.update();

if (updb.fell() && motorspeed<255){
  motorspeed = motorspeed + 15;
  }
    
if (downdb.fell() && motorspeed > 0){
  motorspeed = motorspeed - 15;
  }
  
if (modbuttondb.fell()){
  if (mode < 5 ){
    mode++;
  }else{
    mode = 0;
  }
  
  }
analogWrite(motor,motorspeed);

  Serial.print("--motorspeed--");
  Serial.print(motorspeed);
  Serial.print("---mode--");
  Serial.println(mode);
  delay(2);
}
  

