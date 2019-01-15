#include <Bounce2.h> // bounce library for keboard functionality
#include <math.h>

// button mapping
#define key1p 122
#define key2p 120
#define key3p KEY_ESC
#define key123p KEY_F2

// button pins
const int key1 = 2; // left keyswitch
const int key2 = 3; // right keyswitch
const int key3 = 18; // side button

// LED pins

const int LED1 = 5;
const int LED2 = 6;

// counters

int interval = 5;
int interval2 = 50;
int interval3 = 10000;

int mod = 0;
int buttonState = 0;
int buttonState2 = 0;

Bounce button1 = Bounce();
Bounce button2 = Bounce();
Bounce button3 = Bounce();

void setup()
{
  pinMode(key1, INPUT_PULLUP);
  button1.attach(key1);
  button1.interval(8);
  
  pinMode(key2, INPUT_PULLUP);
  button2.attach(key2);
  button2.interval(8);
  
  pinMode(key3, INPUT_PULLUP);
  button3.attach(key3);
  button3.interval(8);
  
  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);
  
}

void loop()
{ 

// keyboard section
  button1.update();
  button2.update();
  button3.update();
  
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
  if (button3.read() == LOW && button1.read() == LOW) {
    Keyboard.press (key123p);
  }
  if (button3.read() == HIGH && button1.read() == HIGH) {
    Keyboard.release (key123p);
  }


//LEDS
  buttonState = digitalRead(key2);
  buttonState2 = digitalRead(key1);
  
  if ((buttonState == LOW) || (buttonState2 == LOW)) {
      mod = 1;
      delay, 2000;
      }
  if ((buttonState == HIGH) || (buttonState2 == HIGH)) {
       mod = 0;
      }
  
 
  while (mod == 0) {     
    float val = (exp(sin(millis()/2000.0*PI)) - 0.36787944)*108.0;
    analogWrite(6, val);
    analogWrite(5, val);
    }
  while (mod == 1) {
      if (buttonState == HIGH) {
      // turn LED on:
      digitalWrite(LED2, HIGH);
    }
    if (buttonState == LOW) {
      // turn LED off:
      digitalWrite(LED2, LOW);
    }
    
    if (buttonState2 == HIGH) {
      // turn LED on:
      digitalWrite(LED1, HIGH);
    }
    if (buttonState2 == LOW) {
      // turn LED off:
      digitalWrite(LED1, LOW);
    } 
  }
  }
  
