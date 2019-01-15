#include <Encoder.h>
    Encoder enc (5, 6);
    void setup()  
      {
        Serial.begin(9600);
       }
    void loop()
    {
    
      int newenc=enc.read();
      if(newenc<0){enc.write(0);}
      if(newenc>200){enc.write(200);}
      newenc = constrain(newenc,0,200);  
      
      Serial.println(newenc);
    } 
