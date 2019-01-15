
int led = 3;
int ldrA = A0;
int ldrB = 4;

void setup() {
  pinMode(led, OUTPUT);
  
  pinMode(ldrB, INPUT);
  Serial.begin(9600);

}

void loop() {
  

    analogWrite(led, 3);
    Serial.println(analogRead(ldrA));
    delay(100);
    
}
