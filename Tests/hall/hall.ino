int hes = 9;
int State = 0;

void setup() {
  pinMode(hes, INPUT);
  Serial.begin(9600);
  
  
  // put your setup code here, to run once:

}

void loop() {
State = digitalRead(hes);
Serial.println(State);
   delay(100);
}

