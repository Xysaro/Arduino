
#define NOFIELD 505L    // Analog output with no applied field, calibrate this

// Uncomment one of the lines below according to device in use A1301 or A1302
// This is used to convert the analog voltage reading to milliGauss
// For A1301: 2.5mV = 1Gauss, and 1024 analog steps = 5V, so 1 step = 1953mG
// For A1302: 1.3mV = 1Gauss, and 1024 analog steps = 5V, so 1 step = 3756mG

#define TOMILLIGAUSS 1.953125
// #define TOMILLIGAUSS 3.756010  

void setup() 
{
  Serial.begin(115200);
}

void loop() 
{
  float gauss = (analogRead(0) - NOFIELD) * TOMILLIGAUSS;

  Serial.print(gauss, 2);
  Serial.print(" Gauss ");

  if (gauss > 0)     Serial.println("(South pole)");
  else if(gauss < 0) Serial.println("(North pole)");
  else               Serial.println();

  delay(1000);
}




 
