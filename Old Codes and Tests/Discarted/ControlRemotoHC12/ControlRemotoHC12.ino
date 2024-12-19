#include <SoftwareSerial.h>
SoftwareSerial HC12(10, 11); // HC-12 TX Pin, HC-12 RX Pin
int pot = A5;
void setup() {
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12
  pinMode(pot,INPUT);
}
void loop() {  
  int val = map(analogRead(pot),0,1024,0,255);
  HC12.write(val);      // Send that data to HC-12  
  Serial.println(val);
}