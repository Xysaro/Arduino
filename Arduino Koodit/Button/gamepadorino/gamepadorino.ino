

#include <Bounce2.h> // bounce library for keboard functionality
#include <math.h>
#include <Keyboard.h>

// button mapping
#define key1p KEY_RIGHT_ARROW
#define key2p KEY_UP_ARROW
#define key3p KEY_LEFT_ARROW
#define key4p KEY_DOWN_ARROW
#define key5p KEY_ESC
#define key6p 32
#define key7p KEY_LEFT_SHIFT
#define key8p KEY_RETURN

// button pins
const int key1 = 6; // right
const int key2 = 7; // up
const int key3 = 8; // left
const int key4 = 9; // down
const int key5 = 5; // Start
const int key6 = 4; // A
const int key7 = 3; // B
const int key8 = 2; // C

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
Bounce button4 = Bounce();
Bounce button5 = Bounce();
Bounce button6 = Bounce();
Bounce button7 = Bounce();
Bounce button8 = Bounce();

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
  
}

void loop()
{ 

// keyboard section
  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  button6.update();
  button7.update();
  button8.update();
  
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
}

