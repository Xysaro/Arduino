int servoPin = 9;
int servoPin2 = 10;

int servoPosition = 1000; // position in microseconds
int servoPosition2 = 2000; // position in microseconds

void setup() 
{
  pinMode(servoPin, OUTPUT);
  pinMode(servoPin2, OUTPUT);
}

void loop() 

{
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(servoPosition);
  digitalWrite(servoPin, LOW);
  digitalWrite(servoPin2, HIGH);  
  delayMicroseconds(servoPosition2);
  digitalWrite(servoPin2, LOW);  

  delay(20); // wait 20 milliseconds
}
