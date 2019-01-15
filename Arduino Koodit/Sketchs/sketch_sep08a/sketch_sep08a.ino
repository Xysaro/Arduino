#include <math.h>

void setup()
{
  pinMode(11, OUTPUT);
}

void loop()
{
  float val = (exp(sin(millis()/10000.0*PI)) - 0.36787944)*108.0;
  analogWrite(11, val);
}
