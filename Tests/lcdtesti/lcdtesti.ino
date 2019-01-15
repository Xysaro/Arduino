#include <nokia110lcd_driver.h>



void setup() {
  lcd_init();
  delay(2000);
  lcd_clear;


 
}

void loop() {
lcd_gotoyx(2,1);
lcd_string("MOI");
delay(2000);
lcd_gotoyx(3,6);
lcd_string("MIRA!");
delay(2000);
lcd_clear();




}
