#include <TrueRandom.h>

const int ledPin =  13;      // the number of the LED pin


int ledState = LOW;             // ledState used to set the LED

unsigned long previousMillis = 0;        // will store last time LED was updated

long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
  pinMode(ledPin, OUTPUT);
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
}

