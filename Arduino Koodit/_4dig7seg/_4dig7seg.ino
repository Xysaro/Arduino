
#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment controller object


void setup() {

  byte numDigits = 2;   
  byte digitPins[] = {3, 2};
  byte segmentPins[] = {4, 5, 6, 7, 8, 9, 10, 14};
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(100);
  Serial.begin(9600);
}

void loop() {
  
  
  sevseg.setNumber(1, 0);
  sevseg.refreshDisplay(); // Must run repeatedly
}

