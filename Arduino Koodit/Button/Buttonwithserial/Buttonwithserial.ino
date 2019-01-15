
const int buttonPin = 3;     // the number of the pushbutton pin
const int ledPin =  14;      // the number of the LED pin
int analogpin = A0;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  
  pinMode(ledPin, OUTPUT);
  
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
 
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    Serial.println("HIGH");
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    Serial.println("LOW");
  }
  Serial.println(analogRead(analogpin));
  delay(100);
  
}
