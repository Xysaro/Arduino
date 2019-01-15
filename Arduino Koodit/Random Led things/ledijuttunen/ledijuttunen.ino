
int led1 = 2 ;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 8;
int led8 = 9;
int led9 = 10;
int led10 = 11;
int led11 = 12;
int led12 = 13;


void setup() {
 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(led11, OUTPUT);
  pinMode(led12, OUTPUT);
   Serial.begin(9600);
  
}

// the loop routine runs over and over again forever:
void loop() {
  
int viive = analogRead(A0);
delay(1);
  
digitalWrite(led1, HIGH);
  delay(viive);
digitalWrite(led1, LOW);
  
  
digitalWrite(led2, HIGH);
  delay(viive);
digitalWrite(led2, LOW);
    
  
digitalWrite(led3, HIGH);
  delay(viive);
digitalWrite(led3, LOW);
  
  
digitalWrite(led4, HIGH);
  delay(viive);
digitalWrite(led4, LOW);
   
  
digitalWrite(led5, HIGH);
  delay(viive);
digitalWrite(led5, LOW);
 
  
digitalWrite(led6, HIGH);
  delay(viive);  
digitalWrite(led6, LOW);
  
  
digitalWrite(led7, HIGH);
  delay(viive);
digitalWrite(led7, LOW);

  
digitalWrite(led8, HIGH);
  delay(viive);
digitalWrite(led8, LOW);


digitalWrite(led9, HIGH);
  delay(viive);
digitalWrite(led9, LOW);
 
  
digitalWrite(led10, HIGH);
  delay(viive);
digitalWrite(led10, LOW);
 
  
digitalWrite(led11, HIGH);
  delay(viive);
digitalWrite(led11, LOW);

  
digitalWrite(led12, HIGH);
  delay(viive);
digitalWrite(led12, LOW);
           
  

}  
