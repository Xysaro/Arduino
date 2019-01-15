

const int ledi1     = 15;
const int ledi2     = 14;
const int ledi3     = 16;
const int ledi4     = 10;
const int nappula   = 18;
int buttonState     = 0;
int lastButtonState = 0;
int stateNum        = 0;

void setup() {
  pinMode(15, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(18, INPUT);
  Serial.begin(9600);
}

void loop() {

   buttonState = digitalRead(nappula);
    delay, 200; 

    if (buttonState != lastButtonState) {
    
    if (buttonState == 1) { 
      stateNum++;        
    }
    

   

    lastButtonState = buttonState;
     delay, 20; 
  }
    if(stateNum> 4) stateNum = 0;
     
  

   Serial.println(stateNum);

switch (stateNum) {
case 0:
 digitalWrite (ledi1, LOW);
 digitalWrite (ledi2, LOW);
 digitalWrite (ledi3, LOW);
 digitalWrite (ledi4, LOW);

case 1:
 digitalWrite (ledi1, HIGH);
 digitalWrite (ledi2, LOW);
 digitalWrite (ledi3, LOW);
 digitalWrite (ledi4, LOW);

case 2:
 digitalWrite (ledi1, LOW);
 digitalWrite (ledi2, HIGH);
 digitalWrite (ledi3, LOW);
 digitalWrite (ledi4, LOW);

case 3:
 digitalWrite (ledi1, LOW);
 digitalWrite (ledi2, LOW);
 digitalWrite (ledi3, HIGH);
 digitalWrite (ledi4, LOW);

case 4:
 digitalWrite (ledi1, LOW);
 digitalWrite (ledi2, LOW);
 digitalWrite (ledi3, LOW);
 digitalWrite (ledi4, HIGH);
}
 delay, 20; 
}

