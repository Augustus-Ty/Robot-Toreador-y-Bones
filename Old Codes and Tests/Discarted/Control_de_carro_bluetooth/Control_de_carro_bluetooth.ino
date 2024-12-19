#include <SoftwareSerial.h>
SoftwareSerial BT(9,10);
//define the data pins
float joyX = A5;
float joyY = A4;

//define variable values
float dataX;
float dataY;

void setup(void){
  Serial.begin(9600);
  BT.begin(9600);
}

void loop(){
  //Send signal data
  dataX = analogRead(joyX);
  dataY = analogRead(joyY);
  
  BT.write(dataX);
  BT.write(dayaY);
 
  Serial.print("Data X:"); Serial.println(dataX);

  Serial.print("Data Y:"); Serial.println(dataY);
  delay(500);
  
}