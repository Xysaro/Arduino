#include <TFT.h> // Hardware-specific library
#include <SPI.h>

#define CS   10
#define DC   9
#define RESET  8  

// pin definition for the Leonardo
// #define CS   7
// #define DC   0
// #define RESET  1 

TFT myScreen = TFT(CS, DC, RESET);

void setup(){
  myScreen.begin();  
  myScreen.background(0,0,0);  // clear the screen with black
  delay(1000);  // pause for dramatic effect
}

void loop(){
  
  myScreen.background(255,0,0); // clear the screen before starting again
  delay(1000); 
}

