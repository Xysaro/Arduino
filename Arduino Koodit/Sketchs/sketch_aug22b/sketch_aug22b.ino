int prevR = 0, prevG = 0, prevB = 0; // all of the previous RGB values
int const Red = 11; //pin 11 
int const Blue = 9; // pin 9
int const Green = 10; // pin 10

void setup(){} // sets up the program
void loop() { //main loop of the program
  RGB(255, 255, 255); // this calls the RGB function
  delay(1000); //stays on white for one second
  RGB(0, 0, 255); 
   delay(1000);
   RGB(0,120,255);
  delay(1000);
    RGB(0, 255, 0);
  delay(1000);
    RGB(255, 0, 255);
  delay(10);
    RGB(0,0,0);
  delay(1000);
 
}


void RGB(int R, int G, int B) {
for (int i = 0; i <= 255; i++)
{
if (i >=  prevR - R && prevR < R) {
 
  analogWrite(Red, prevR + i);
}
if (i >= prevG - G && prevG < G) {
 
  analogWrite(Green, prevG + i);
 
}
if (i >= prevB - B && prevB < B) {
 
  analogWrite(Blue, prevB + i);
 
}
//delay(10);
//}
//for (int i = 0; i <= 255; i++)
//{
if (i >= R - prevR && prevR > R) {
 
  analogWrite(Red, prevR - i);
}
if (i >= G - prevG && prevG > G) {
 
  analogWrite(Green, prevG - i);
 
}
if (i >= B - prevB && prevB > B) {
 
  analogWrite(Blue, prevB - i);
 
}
delay(10);
}
delay(10);
analogWrite(Red, R);
analogWrite(Green, G);
analogWrite(Blue, B);
prevR = R;
prevG = G;
prevB = B;
}
