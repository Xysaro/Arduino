
int led = 3;
int ldrA = A0;
int ldrB = 4;

void setup() {
  pinMode(led, OUTPUT);
  
  pinMode(ldrB, INPUT);
  Serial.begin(9600);

}

void loop() {
  
  for(int i=0; i<=255; i++){
    analogWrite(led, i);
    delay(100);
    if (digitalRead(ldrB)== HIGH){
      Serial.println("HIGH");
      Serial.println(analogRead(ldrA));
      Serial.println(i);
      break;
    }
  }

}
