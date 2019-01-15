int input1 = 8;
int input2 = 9;

int i1 = 0;
int i2 = 0;

void setup() {
  pinMode(input1, INPUT);
  pinMode(input2, INPUT);
  Serial.begin(9600);
}

void loop() {

  i1 = digitalRead(input1);
  i2 = digitalRead(input2);

  Serial.print("input1--");
  Serial.print(i1);
  Serial.print("--input2--");
  Serial.println(i2);
  delay(1);
}
