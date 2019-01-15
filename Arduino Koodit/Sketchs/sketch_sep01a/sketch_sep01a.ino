/*

Code by Michael Hawley
1/4/2013

*/

// LED is in pin 8
int ledPin = 11;
// button is in pin 2
int buttonPin = 3;
// button state is set to numerical value of "LOW"
int buttonState = 0;
// starting LED brightness is 0
int brightness = 0;

void setup() {
  // the LED is an output device
  pinMode(ledPin, OUTPUT);
  // the button is an input device
  pinMode(buttonPin, INPUT);
}

void loop() {
  // find out what the button is doing right now
  buttonState = digitalRead(buttonPin);
  
  // if the button is pressed...
  if (buttonState == HIGH) {
    // increase the brightness value of the LED
    for (int brightness = 0 ; brightness <= 255 ; brightness +=100) {
      // write the brightness value of the LED
      analogWrite(ledPin, brightness);
      // but don't do it too quickly
      delay(5);
    }
    // keep the LED on for 5 seconds
    delay(5000);
  }  
  
  // after you're done with shining the LED, find out what the button is doing
  buttonState = digitalRead(buttonPin);
  
  // if the button isn't being pressed right now...
  if(buttonState == LOW) {
    // decrease the LED brightness' current value...
    for(int brightness = brightness ; brightness >=0; brightness -=5) {
      // and write it to the LED
      analogWrite(ledPin, brightness);
      // but don't do it too quickly
      delay(20);
    }
  }
}
