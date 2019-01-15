#include <TrueRandom.h>

#include <Servo.h> 
int  updateInterval= 1000; 
unsigned long lastUpdate;
int increment = 1;
int pos = 0;
Servo servo;

const int ledPin =  13;      // the number of the LED pin
int ledState = LOW;             // ledState used to set the LED
unsigned long previousMillis = 0;        // will store last time LED was updated
long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
  pinMode(ledPin, OUTPUT);
  servo.attach(9);
  Serial.begin(9600);
}

void loop() {


  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    Serial.println(interval);
    if (ledState == LOW) {
      ledState = HIGH;
      interval = TrueRandom.random(100,3000);
    } else {
      ledState = LOW;
      interval = TrueRandom.random(1,100);
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
  if((millis() - lastUpdate) > updateInterval)  // time to update
    {
      lastUpdate = millis();
      pos += increment;
      servo.write(pos);
      Serial.println(pos);
      if ((pos >= 180) || (pos <= 0)) // end of sweep
      {
        // reverse direction
        increment = -increment;
      }
    }
}

