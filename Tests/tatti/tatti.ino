
int Xin=A1;
int Yin=A0;
int Bin=3;

void setup() {
 pinMode(Bin,INPUT);
  
  Serial.begin (9600);
}

void loop() {


  Serial.print(analogRead(Xin));
  Serial.print("  ");
  Serial.print(analogRead(Yin));
   Serial.print("  ");
  Serial.println(digitalRead(Bin));

  delay(10);

}
