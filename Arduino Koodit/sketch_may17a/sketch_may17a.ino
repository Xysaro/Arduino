const int en = 11;
const int forw = 4;
const int rev = 5;
int speeds = 0;
void setup() {

pinMode(en,OUTPUT);
pinMode(forw,OUTPUT);
pinMode(rev,OUTPUT);
Serial.begin(9600);
}

void loop() {
  
 digitalWrite(forw, HIGH);

 if(speeds == 0){
  for(; speeds<255;speeds++){
    analogWrite(en,speeds);
    Serial.println(speeds);
    delay(100);
    }
 }
if(speeds == 254){
  for(; speeds<0;speeds--){
    analogWrite(en,speeds);
    Serial.println(speeds);
    delay(100); 
}
}
}
