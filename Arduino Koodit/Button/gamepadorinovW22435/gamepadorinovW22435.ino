

#include <Bounce2.h> // bounce library for keboard functionality
#include <math.h>

#include <HID-Project.h>

const int key3  = 8; // left
const int key4  = 9; // down
const int key5  = 5; // Start
const int key1  = 6; // right
const int key2  = 7; // up
const int key6  = 4; // A
const int key7  = 3; // B
const int key8  = 2; // C
const int key9  = 19; // Ltrigger
const int key10 = 20; // Rtrigger
const int nappula = 18































; // nappula
// LEDs
const int ledi1     = 15;
const int ledi2     = 14;
const int ledi3     = 16;
const int ledi4     = 10;

// counters

int interval = 5;
int interval2 = 50;
int interval3 = 10000;

int buttonState     = 0;
int lastButtonState = 0;
int stateNum        = 0;

Bounce button1 = Bounce();
Bounce button2 = Bounce();
Bounce button3 = Bounce();
Bounce button4 = Bounce();
Bounce button5 = Bounce();
Bounce button6 = Bounce();
Bounce button7 = Bounce();
Bounce button8 = Bounce();
Bounce button9 = Bounce();
Bounce button10 = Bounce();
Bounce buttonPR = Bounce();

void setup()
{
  pinMode(key1, INPUT_PULLUP);
  button1.attach(key1);
  button1.interval(8);
  
  pinMode(key3, INPUT_PULLUP);
  button3.attach(key3);
  button3.interval(8);
  
  pinMode(key2, INPUT_PULLUP);
  button2.attach(key2);
  button2.interval(8);
  
  pinMode(key4, INPUT_PULLUP);
  button4.attach(key4);
  button4.interval(8);

  pinMode(key5, INPUT_PULLUP);
  button5.attach(key5);
  button5.interval(8);
  
  pinMode(key6, INPUT_PULLUP);
  button6.attach(key6);
  button6.interval(8);
  
  pinMode(key7, INPUT_PULLUP);
  button7.attach(key7);
  button7.interval(8);

  pinMode(key8, INPUT_PULLUP);
  button8.attach(key8);
  button8.interval(8);

  pinMode(key9, INPUT_PULLUP);
  button9.attach(key9);
  button9.interval(8);

  pinMode(key10, INPUT_PULLUP);
  button10.attach(key10);
  button10.interval(8);

  pinMode(18, INPUT_PULLUP);
  buttonPR.attach(nappula);
  buttonPR.interval(8);

    //leds
  
  pinMode(15, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(10, OUTPUT);
Serial.begin(9600);

  
}

void loop(){ 



   buttonPR.update();
    delay, 200; 

    if (buttonPR.read() == LOW) {
    buttonState = 0;
   }
    if (buttonPR.read() == HIGH) {
    buttonState = 1;
    }

    if (buttonState != lastButtonState) {
    
    if (buttonState == 1) { 
      stateNum++;        
    }
       
    lastButtonState = buttonState;
     delay, 20; 
  }
    if(stateNum> 4) stateNum = 0;
    Serial.println(stateNum);

  

switch (stateNum){

case 1:
// button mapping
 digitalWrite (ledi1, HIGH);
 digitalWrite (ledi2, LOW);
 digitalWrite (ledi3, LOW);
 digitalWrite (ledi4, LOW);
#define key1p KEY_RIGHT_ARROW //right
#define key2p KEY_UP_ARROW    //up
#define key3p KEY_LEFT_ARROW  //left
#define key4p KEY_DOWN_ARROW  //down
#define key5p KEY_ESC         //punanen
#define key6p 32              //iso action
#define key7p KEY_LEFT_SHIFT  //alempi sininen
#define key8p KEY_RETURN      //ylempi sininen
#define key9p KEY_RETURN      //LTrigger
#define key10p KEY_RETURN     //RTrigger
break;
case 2:

 digitalWrite (ledi1, LOW);
 digitalWrite (ledi2, HIGH);
 digitalWrite (ledi3, LOW);
 digitalWrite (ledi4, LOW);  
#define key1p KEY_RIGHT_ARROW //right
#define key2p KEY_UP_ARROW    //up
#define key3p KEY_LEFT_ARROW  //left
#define key4p KEY_DOWN_ARROW  //down
#define key5p KEY_ESC         //punanen
#define key6p 32              //iso action
#define key7p KEY_LEFT_SHIFT  //alempi sininen
#define key8p KEY_RETURN      //ylempi sininen
#define key9p KEY_RETURN      //LTrigger
#define key10p KEY_RETURN     //RTrigger
break;

case 3:
 digitalWrite (ledi1, LOW);
 digitalWrite (ledi2, LOW);
 digitalWrite (ledi3, HIGH);
 digitalWrite (ledi4, LOW);
break;

case 4:
 digitalWrite (ledi1, LOW);
 digitalWrite (ledi2, LOW);
 digitalWrite (ledi3, LOW);
 digitalWrite (ledi4, HIGH);
break;
 }


// keyboard section


  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  button6.update();
  button7.update();
  button8.update();
  button9.update();
  button10.update();
  
  if (button1.read() == LOW) {
    Keyboard.press(key1p);
  }
  if (button1.read() == HIGH) {
    Keyboard.release(key1p);
  }
  if (button2.read() == LOW) {
    Keyboard.press(key2p);
  }
  if (button2.read() == HIGH) {
    Keyboard.release(key2p);
  }
  if (button3.read() == LOW) {
    Keyboard.press(key3p);
  }
  if (button3.read() == HIGH) {
    Keyboard.release(key3p);
  }
  if (button4.read() == LOW) {
    Keyboard.press (key4p);
  }
  if (button4.read() == HIGH) {
    Keyboard.release (key4p);
  }

  
    if (button5.read() == LOW) {
    Keyboard.press(key5p);
  }
  if (button5.read() == HIGH) {
    Keyboard.release(key5p);
  }
  if (button6.read() == LOW) {
    Keyboard.press(key6p);
  }
  if (button6.read() == HIGH) {
    Keyboard.release(key6p);
  }
  if (button7.read() == LOW) {
    Keyboard.press(key7p);
  }
  if (button7.read() == HIGH) {
    Keyboard.release(key7p);
  }
  if (button8.read() == LOW) {
    Keyboard.press (key8p);
  }
  if (button8.read() == HIGH) {
    Keyboard.release (key8p);
  }
    if (button9.read() == LOW) {
    Keyboard.press(key9p);
  }
  if (button9.read() == HIGH) {
    Keyboard.release(key9p);
  }
  if (button10.read() == LOW) {
    Keyboard.press (key10p);
  }
  if (button10.read() == HIGH) {
    Keyboard.release (key10p);
  }

}

