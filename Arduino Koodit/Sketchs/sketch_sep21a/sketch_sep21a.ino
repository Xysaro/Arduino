
const int kaami = 9;
const int nappula = 2;
int mod = 1;
int tila = 0;

void setup() {
  
 pinMode (kaami, OUTPUT);
 pinMode (nappula, INPUT);

}

void loop() {
  
  tila = digitalRead(nappula);
  if (tila == HIGH){
    digitalWrite(kaami, HIGH);
   }else{
    digitalWrite(kaami, LOW);
    }
  }

