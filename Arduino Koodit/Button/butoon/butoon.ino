
#include <Adafruit_NeoPixel.h>
#include <Bounce2.h>
int b1 = 2;
int b2 = 3;

Bounce Db1 = Bounce();
Bounce Db2 = Bounce();

void setup() {
  
pinMode(b1, INPUT_PULLUP);
Db1.attach(b1);
Db1.interval(5);

pinMode(b2, INPUT_PULLUP);
Db2.attach(b2);
Db2.interval(5);

Serial.begin(9600);
}

void loop() {
  Db1.update();
  Db2.update();
  
 

  Serial.print(" B1:");
  Serial.print(Db1.read());
  Serial.print(" B2:");
  Serial.println(Db2.read());
  delay(1);
}
