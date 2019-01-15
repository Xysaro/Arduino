/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

#include <Encoder.h>

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder myEnc(5, 6);
//   avoid using pins with LEDs attached
int maxpos = 200;
int minpos = 0;
long newPosition;
long oldPosition  = -999;


void setup() {
  Serial.begin(9600);
  Serial.println("Basic Encoder Test:");
}


void loop() {
  newPosition = myEnc.read();
  if (newPosition != oldPosition) {
    if (newPosition > maxpos){newPosition = maxpos;}
    if (newPosition < minpos){newPosition = minpos;}
    newPosition = constrain(newPosition,0,200);
    oldPosition = newPosition;
    Serial.println(newPosition);
  } 
    
  
}
