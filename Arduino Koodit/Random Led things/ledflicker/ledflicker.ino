
int ledPin1 = 9; //Set the number of LEDs you use.
int ledPin2 = 10;
int ledPin3 = 11;
//You can use up to 6 LED pins

void setup()
{
pinMode(ledPin1, OUTPUT); //Sets the LED pins as output pins.
pinMode(ledPin2, OUTPUT); //Use the same pins used above
pinMode(ledPin3, OUTPUT);
}

void loop()
{ //Sets a random value of LED voltage in the range of 0V - 5V with PWM
analogWrite(ledPin1, 165);
analogWrite(ledPin2, 42);
analogWrite(ledPin3, 42);
delay(1);

}

