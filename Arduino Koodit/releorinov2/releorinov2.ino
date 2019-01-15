/*
 Some Sample code of how to use your IR remote
 
 * Lets get started:
 
 The IR sensor's pins are attached to Arduino as so:
 Pin 1 to Vout (pin 11 on Arduino)
 Pin 2 to GND
 Pin 3 to Vcc (+5v from Arduino)

*/

#include <IRremote.h>

double power = 16769565;
double Aota = 16720605;
double Bota = 16769055;
double Cota = 16738455;
double Dota = 16724175;

int IRpin = 11;  // pin for the IR sensor
int rele1 = 10; 
int rele2 = 9; // LED pin 
int rele3 = 8; 
int rele4 = 7; // LED pin 

IRrecv irrecv(IRpin);
decode_results results;

boolean releon1 = true; // initializing LEDon as true
boolean releon2 = true; 
boolean releon3 = true;
boolean releon4 = true;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(rele1, OUTPUT);
  pinMode(rele2, OUTPUT);
  pinMode(rele3, OUTPUT);
  pinMode(rele4, OUTPUT);
}

void loop() 


{
  results.value=0;
  if (irrecv.decode(&results)) 
    {
      
      irrecv.resume();   // Receive the next value
    }
    //rele1
   if (results.value == Aota || results.value == power) // this is where you put in your IR remote button #
   
     {
       if (releon1 == true)   // is LEDon equal to true? 
         {
           releon1 = false;   
           digitalWrite(rele1, HIGH);
           delay(100);      // keeps the transistion smooth
            
         }
         
        else
          {
            releon1 = true;
            digitalWrite(rele1, LOW);
            delay(100);
            
          }
          
      }  
    
      //rele2
      if (results.value == Bota || results.value == power)  // this is where you put in your IR remote button #
   
     {
       if (releon2 == true)   // is LEDon equal to true? 
         {
           releon2 = false;   
           digitalWrite(rele2, HIGH);
           delay(100);      // keeps the transistion smooth
            
         }
         
        else
          {
            releon2 = true;
            digitalWrite(rele2, LOW);
            delay(100);
                   }
          
      }    
      //rele3
      if (results.value == Cota || results.value == power)  // this is where you put in your IR remote button #
   
     {
       if (releon3 == true)   // is LEDon equal to true? 
         {
           releon3 = false;   
           digitalWrite(rele3, HIGH);
           delay(100);      // keeps the transistion smooth
            
         }
         
        else
          {
            releon3 = true;
            digitalWrite(rele3, LOW);
            delay(100);
                   }
          
      }    
      //rele4
      if (results.value == Dota || results.value == power)  // this is where you put in your IR remote button #
   
     {
       if (releon4 == true)   // is LEDon equal to true? 
         {
           releon4 = false;   
           digitalWrite(rele4, HIGH);
           delay(100);      // keeps the transistion smooth
            
         }
         
        else
          {
            releon4 = true;
            digitalWrite(rele4, LOW);
            delay(100);
            
            
          
     }
  
    }
    
}
