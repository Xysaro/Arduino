int potPin = A0;
int motorPin = 6;
int potValue = 20;
int motorValue = 20;
void setup() {
 Serial.begin(9600);
}
void loop() {

// send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                motorValue = Serial.parseInt();

                // say what you got:
              
                Serial.println(motorValue);

 analogWrite(motorPin, motorValue);  
        }
}

