int pin1= 8;
int pin2= 9;

void setup() {
  pinMode(pin1,INPUT);
  pinMode(pin2,INPUT);
  Serial.begin(9600);
  Serial.println("sup..");
}

void loop() {

  if (pin1 == HIGH){
    Serial.println("Pin 8 is high ");
  }else{Serial.println("Pin 8 is low ");
  }
  if (pin2 == HIGH){
    Serial.println("Pin 9 ");
  }else{Serial.println("Pin 9 is low ");
  }
 delay(10);
}
