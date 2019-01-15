/*
 Fading

 This example shows how to fade an LED using the analogWrite() function.

 The circuit:
 * LED attached from digital pin 9 to ground.

 Created 1 Nov 2008
 By David A. Mellis
 modified 30 Aug 2011
 By Tom Igoe

 http://arduino.cc/en/Tutorial/Fading

 This example code is in the public domain.

 */


int ledPin = 9;    // LED connected to digital pin 9
int buttonPin = 2;
int buttonState = 0;
int fadeValue2 = 0;
void setup() {

 pinMode(ledPin, OUTPUT);
 pinMode(buttonPin, INPUT);

}

void loop() {
  
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH) {
  // fade in from min to max in increments of 5 points:
    for (int fadeValue = 0 ; fadeValue <= 200; fadeValue += 200) {
    // sets the value (range from 0 to 200):
      analogWrite(ledPin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
      delay(30);
    }
 
 
     for (int fadeValue = 200 ; fadeValue >= 0; fadeValue -= 100) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30); 
  }
    buttonState = digitalRead(buttonPin);
    
    if (buttonState == LOW);
      analogWrite(ledPin, fadeValue2); 
     
   }
  
}


