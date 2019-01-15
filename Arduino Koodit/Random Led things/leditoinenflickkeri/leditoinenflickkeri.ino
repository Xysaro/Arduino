// LED Fire Effect

int ledPin1 = 10;
int ledPin2 = 11;
int ledPin3 = 9;
int ledPin4 = 6;
int Photores = A5;
int value;

void setup()
{
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(ledPin4, OUTPUT);
Serial.begin(9600);

}

void loop() {
  value = analogRead(Photores);
  Serial.println(value);

  if(value < 100){
    analogWrite(ledPin1, random(120)+135);
    analogWrite(ledPin2, random(120)+135);
    analogWrite(ledPin3, random(120)+135);
    analogWrite(ledPin4, random(120)+135);
    delay(random(100));
  }else{
    analogWrite(ledPin1, 0);
    analogWrite(ledPin2, 0);
    analogWrite(ledPin3, 0);
    analogWrite(ledPin4, 0);
    }
  
}

