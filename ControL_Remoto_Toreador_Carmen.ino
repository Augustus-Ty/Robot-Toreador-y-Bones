#include <SoftwareSerial.h>
SoftwareSerial HC12(12, 13);              // D11 is HC-12 RX Pin, D10 is HC-12 TX Pin

int Joy_x = A0;
int Joy_y = A1;
long int valor= 12341023;
int Boton_Arriba = 4;
int Boton_Abajo = 2;
int Boton_Derecha = 5;
int Boton_Izquierda = 3;
int Boton_F = 6;
int Boton_E = 7;
int Boton_Joystick = 8;
//Data to send
int pA, pAB, pD, pI, pE, pF, pJ, joy_x_send, joy_y_send ;

void setup() {
  pinMode(Joy_x,INPUT);
  pinMode(Joy_y,INPUT);
  pinMode(Boton_Arriba,INPUT_PULLUP);
  pinMode(Boton_Abajo,INPUT_PULLUP);
  pinMode(Boton_Derecha,INPUT_PULLUP);
  pinMode(Boton_Izquierda,INPUT_PULLUP);
  pinMode(Boton_F,INPUT_PULLUP);
  pinMode(Boton_E,INPUT_PULLUP);
  pinMode(Boton_Joystick,INPUT_PULLUP);
  Serial.begin(9600);                     //Start serial com in order to print valeus on monitor
  HC12.begin(9600);                       //Start the HC12 serial communication at 9600 bauds. Change bauds if needed
}//end of setup void

void loop() {  
  joy_x_send = map(analogRead(Joy_x),0,1023,0,999);
  joy_y_send = map(analogRead(Joy_y),0,1023,0,999);
 if(digitalRead(Boton_Arriba)==0){
   pA=2;
 }
 else{
   pA=1;
 } 
  pAB = digitalRead(Boton_Abajo);   
  pD = digitalRead(Boton_Derecha);
  pI = digitalRead(Boton_Izquierda);


  ///////
  // Serial.print("X: ");
  // Serial.print(joy_x_send);
  // Serial.print("   |   ");
  // Serial.print("Y: ");
  // Serial.print(joy_y_send);
  // Serial.print("   |   ");
  // Serial.print("W: ");
  // Serial.print(x_send);
  // Serial.print("   |   ");
  // Serial.print("T: ");
  // Serial.print(y_send);
  // Serial.println(" ");
  ///////
  char mensaje[12];
    if (joy_x_send<0) joy_x_send =0;
    if (joy_y_send<0) joy_y_send =0;
    sprintf(mensaje,"V %d%d%d%d%03d%03d", pA, pAB, pD, pI, joy_x_send, joy_y_send);
    //sprintf(mensaje,"V %d%d%04d%04d", pA, pAB, joy_x_send, joy_y_send);
  Serial.println(String(mensaje));
  HC12.println(String(mensaje));//HC12.write("T"); //Send the y angle value and then the "Y" character
  delay(20); //Add a delay of 50. This might affect the transmission 
}//End of void loop