
const int buttonPin = 2;
const int motorCW = 9;
const int led = 10;
int buttonState = 0;





void setup() {
 
pinMode(motorCW, OUTPUT);
pinMode(led, OUTPUT);
pinMode(buttonPin, INPUT);
}

void loop() {

  
 buttonState = digitalRead(buttonPin);
 
 if (buttonState == HIGH) {
   digitalWrite(motorCW, HIGH);
   analogWrite(led, HIGH);
   
 }else{
   digitalWrite(motorCW, LOW);
   analogWrite(led, LOW);
   }

}
