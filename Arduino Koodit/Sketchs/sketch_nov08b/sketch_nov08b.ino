/*
 Some Sample code of how to use your IR remote
 
 * Lets get started:
 
 The IR sensor's pins are attached to Arduino as so:
 Pin 1 to Vout (pin 11 on Arduino)
 Pin 2 to GND
 Pin 3 to Vcc (+5v from Arduino)

*/

#include <IRremote.h>

int IRpin = 11;  // pin for the IR sensor
int LED = 13; 
int LED2 = 5; 
IRrecv irrecv(IRpin);
decode_results results;

boolean LEDon = true; // initializing LEDon as true
boolean LEDon2 = true; // initializing LEDon as true

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() 
{
   
  if (irrecv.decode(&results)) 
    {
      
      irrecv.resume();   // Receive the next value
    }
  
   if (results.value == 16769055)  // change zero to your IR remote button number
     {
       digitalWrite(LED,HIGH);
       
       }else{
    
      digitalWrite(LED,LOW);
      }
      
      
   if (results.value == 16720605)  // change zero to your IR remote button number
     {
       digitalWrite(LED2,HIGH);
       
       }else{
    
      digitalWrite(LED2,LOW);
      }
 }
