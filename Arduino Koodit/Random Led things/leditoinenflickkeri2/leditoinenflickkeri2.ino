// LED Fire Effect

int ledPin1 = 10;
int ledPin2 = 11;
int ledPin3 = 9;
int ledPin4 = 6;
int ledPin5 = 5;
int ledPin6 = 3;
int ledPin7 = 2;
int ledPin8 = 4;
int ledPin9 = 7;
int ledPin10 = 8;
int ledPin11 = 13;
int ledPin12 = 12;
int viive = 100;
int mod = 1;


void setup()
{
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(ledPin4, OUTPUT);
pinMode(ledPin5, OUTPUT);
pinMode(ledPin6, OUTPUT);
pinMode(ledPin7, OUTPUT);
pinMode(ledPin8, OUTPUT);
pinMode(ledPin9, OUTPUT);
pinMode(ledPin10, OUTPUT);
pinMode(ledPin11, OUTPUT);
pinMode(ledPin12, OUTPUT);
Serial.begin(9600);


}

void loop() {
  
  int res = analogRead(A0);
  delay(1);
  
  if (res < 100) {
    
    mod = 0;
    }
  if (res > 100) { 
     mod = 1;
    }
  
  
  
  if (mod == 0) {

    analogWrite(ledPin1, random(120)+135);
    analogWrite(ledPin2, random(120)+135);
    analogWrite(ledPin3, random(120)+135);
    analogWrite(ledPin4, random(120)+135);
    analogWrite(ledPin5, random(120)+135);
    analogWrite(ledPin6, random(120)+135);
    digitalWrite(ledPin7, HIGH);
    digitalWrite(ledPin8, HIGH);
    digitalWrite(ledPin9, HIGH);
    digitalWrite(ledPin10, HIGH);
    digitalWrite(ledPin11, HIGH);
    digitalWrite(ledPin12, HIGH);
    delay(random(100));
    
    }else{
 digitalWrite(ledPin1, HIGH);
  delay(viive);
digitalWrite(ledPin1, LOW);
  
  
digitalWrite(ledPin2, HIGH);
  delay(viive);
digitalWrite(ledPin2, LOW);
    
  
digitalWrite(ledPin3, HIGH);
  delay(viive);
digitalWrite(ledPin3, LOW);
  
  
digitalWrite(ledPin4, HIGH);
  delay(viive);
digitalWrite(ledPin4, LOW);
   
  
digitalWrite(ledPin5, HIGH);
  delay(viive);
digitalWrite(ledPin5, LOW);
 
  
digitalWrite(ledPin6, HIGH);
  delay(viive);  
digitalWrite(ledPin6, LOW);
  
  
digitalWrite(ledPin7, HIGH);
  delay(viive);
digitalWrite(ledPin7, LOW);

  
digitalWrite(ledPin8, HIGH);
  delay(viive);
digitalWrite(ledPin8, LOW);


digitalWrite(ledPin9, HIGH);
  delay(viive);
digitalWrite(ledPin9, LOW);
 
  
digitalWrite(ledPin10, HIGH);
  delay(viive);
digitalWrite(ledPin10, LOW);
 
  
digitalWrite(ledPin11, HIGH);
  delay(viive);
digitalWrite(ledPin11, LOW);

  
digitalWrite(ledPin12, HIGH);
  delay(viive);
digitalWrite(ledPin12, LOW);
      
      
      }
}
