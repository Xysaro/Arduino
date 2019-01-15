


void setup() {
  Serial.begin(9600);
  Serial.println("<Arduino is ready>");

}

void loop() {
  char rc;
  int pos;
  while (Serial.available() > 0 ) {
    rc = Serial.readBytesUntil(':');
    pos = Serial.readBytesUntil('>');
    Serial.print("i got:");
    Serial.print(rc);
    Serial.print(pos);
}

}
