#include <Bounce2.h> // bounce library for keboard functionality
#include <EEPROM.h> // EEPROM library for saving

// button mapping
#define key1p 122
#define key2p 120
#define key3p KEY_ESC

// button pins
const int key1 = 2; // left keyswitch
const int key2 = 3; // right keyswitch
const int key3 = 18; // side button

// LED pins

const int LED1 = 5;
const int LED2 = 6;

// counters
unsigned long previousMillis=0;
unsigned long previousMillis2=0;
unsigned long pmbs=0;
unsigned long pmbn=0;
unsigned long previousMillisCD = 0;
unsigned long cooldown = 200;
int interval = 5;
int interval2 = 50;
int interval3 = 10000;
int intbs = 500;
int swbs = 0;
int bncn = 0;
int intbn = 75;
int b3cooldown = 0;

const int ledfade = 1;

int buttonState = 0;
int led1 = 0;
int led2 = 0;
int ledmax = 50;
int ledmin = 0;
int b3 = 0;

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

//LEDS
  if (buttonState == ledfade) {
    if (!digitalRead(key1)){
      led1 = ledmax;
    }
    if (!digitalRead(key2)){
      led2 = ledmax;
    }
    if (b3 == 1){
      led1 = ledmax;
      led2 = ledmax;
    }
    if ((unsigned long)(currentMillis - previousMillis) >= interval) {
      if (led1 > 0){        
        led1--;          
      }
      if (led2 > 0){
        led2--;
      }
      previousMillis = currentMillis;      
    }
   }
  
  
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

  }
}

