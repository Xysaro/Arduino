/*
Library Originally added by David A Mellis
Library Modified by Limor Fried
Example added by Tom Igoe
Modified by Tom Igoe
This example is in the public domain. http://www.arduino.cc.en/Tutorial/LiquidCrystal
Contrast modification by Ahmed Murtaza Qureshi (www.engineeringlearning.blogspot.com)
*/
#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>


#define ONE_WIRE_BUS 10
OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

int Contrast=15;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte customChar1[] = {
  
  B01010,
  B00000,
  B01110,
  B00001,
  B01111,
  B10001,
  B01111,
  B00000
};

byte customChar2[] = {
  
  B01010,
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,
  B00000
};
void setup() 
{
  Serial.begin(9600);
  Serial.println("LCD test with PWM contrast adjustment");
  pinMode(13,OUTPUT);
  analogWrite(6,Contrast);

  sensors.begin();
  // set up the LCD's number of columns and rows: 
 lcd.createChar(0, customChar1);
  lcd.createChar(1, customChar2);
  lcd.begin(16, 2);
  
  // Print a message to the LCD.
 lcd.print("L");
  lcd.write(byte(0));
  lcd.print("mp");
    lcd.write(byte(1));
      lcd.print("tila!!");
}

void loop() 
{

  sensors.requestTemperatures(); 
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(sensors.getTempCByIndex(0));
}
