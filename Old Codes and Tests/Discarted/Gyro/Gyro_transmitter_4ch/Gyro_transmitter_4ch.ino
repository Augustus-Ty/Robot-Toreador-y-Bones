
//Libraries
#include <SoftwareSerial.h>
SoftwareSerial HC12(12,13);              // D11 is HC-12 TX Pin, D10 is HC-12 RX Pin

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Inputs
int Joy_x = A0;
int Joy_y = A1;

//Data to send
int x_send, y_send, joy_x_send, joy_y_send;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  pinMode(Joy_x,INPUT);
  pinMode(Joy_y,INPUT);
  Serial.begin(9600);                     //Start serial com in order to print valeus on monitor
  HC12.begin(9600);                       //Start the HC12 serial communication at 9600 bauds. Change bauds if needed
}//end of setup void


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() {  
  joy_x_send = analogRead(Joy_x);
  joy_y_send = analogRead(Joy_y);
  x_send = joy_x_send;  //pass from flaot to int in order to send the values, also invert X angle
  y_send = joy_y_send;   //pass from flaot to int in order to send the values
  ///////
  Serial.print("X: ");
  Serial.print(x_send);
  Serial.print("   |   ");
  Serial.print("Y: ");
  Serial.print(y_send);
  Serial.print("   |   ");
  Serial.print("W: ");
  Serial.print(joy_x_send);
  Serial.print("   |   ");
  Serial.print("T: ");
  Serial.print(joy_y_send);
  Serial.println(" ");
  ///////
  HC12.print(x_send);HC12.write("X"); //Send the x angle value and then the "X" character
  HC12.print(y_send);HC12.write("Y"); //Send the y angle value and then the "Y" character
  HC12.print(joy_x_send);HC12.write("W"); //Send the y angle value and then the "Y" character
  HC12.print(joy_y_send);HC12.write("T"); //Send the y angle value and then the "Y" character
  delay(20); //Add a delay of 50. This might affect the transmission 
}//End of void loop


