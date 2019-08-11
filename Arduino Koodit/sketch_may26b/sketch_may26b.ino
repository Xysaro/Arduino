//project done by www.theorycircuit.com
//code by Crenn from http://thebestcasescenario.com  thank you!
//Varibles used for calculations
int NbTopsFan; int Calc;
 
//The pin location of the sensor
int hallsensor = 2; 

 
unsigned long CT;
unsigned long LT=0;
unsigned long rpmval;

void rpm ()
//This is the function that the interupt calls
{ NbTopsFan++;
  LT=CT;
  CT= millis();

}
 
//This is the setup function where the serial port is initialised,
//and the interrupt is attached
void setup()
{ pinMode(hallsensor, INPUT);
Serial.begin(9600);
attachInterrupt(0, rpm, RISING); }
 
void loop ()
//Set NbTops to 0 ready for calculations
{ NbTopsFan = 0;
 
//Enables interrupts
sei();
 
//Wait 1 second
delay (1000);
 
//Disable interrupts
cli();
 
rpmval = 60000/(CT- LT);

Serial.print(CT); 
Serial.print("\t"); 
Serial.print(LT); 
Serial.print("\t"); 
Serial.print(rpmval); 
Serial.print (" rpm\r\n");
} 
