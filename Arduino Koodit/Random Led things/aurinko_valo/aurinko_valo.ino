int L = 9;  //led pinout
int B = 0;  //brightness

void setup() {
 pinMode(L, OUTPUT);
 Serial.begin(9600);
}

void loop() {
if(B <= 254){
    B = B + 1;
    analogWrite(L, B);
    Serial.println(B);
  }else{
    B = B + 0;
  } 
  delay(100);
}
