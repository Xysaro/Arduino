/*
  LED on when you press a button.
  LED off when you release a button.  
  
  created 01-12-2009 by kasperkamperman.com
*/

const int buttonPin = 18;      // the pin that the pushbutton is attached to
const int ledPin    = 14;     // the pin that the LED is attached to

int buttonState     = 0;      // current state of the button

void setup() {
  pinMode(buttonPin, INPUT);  // initialize the button pin as a input
  pinMode(ledPin, OUTPUT);    // initialize the button pin as a output
}

void loop() {
  // read the pushbutton input pin
  buttonState = digitalRead(buttonPin);

  // turns LED on if the buttonState=HIGH or off if the buttonState=LOW
  digitalWrite(ledPin, buttonState);
}
