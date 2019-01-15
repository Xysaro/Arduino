int led = 13;
int relay = 4;
int photo = A0;
int Button = 7;
int var = 0;
int var2 = 0;



void setup() {
  pinMode (led, OUTPUT);
  pinMode (relay, OUTPUT);
  pinMode (photo, INPUT);
  pinMode (Button, INPUT);
  Serial.begin(38400);
}

void loop() {
  
   
   var = analogRead(photo);
   var2 = digitalRead(Button);
   delay(10);
   Serial.println(var);
  

 if(var2 == 1){
  digitalWrite(relay, HIGH);
  digitalWrite(led, HIGH);
 }
  
 if(var >20){
  digitalWrite(relay, LOW);
  digitalWrite(led, LOW);
  delay(2000);
 }

}
