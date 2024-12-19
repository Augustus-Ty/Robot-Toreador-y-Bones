#include <SoftwareSerial.h>
SoftwareSerial HC12(12, 13); // HC-12 TX Pin, HC-12 RX Pin

//define the data pins
float joyX = A0;
float joyY = A1;
int A=7;
int B=6;
int C=5;
int D=4;
//define variable values
float dataX;
float dataY;
int dataA;
int dataB;
int dataC;
int dataD;
//Valores de los botones y joystick convertidos a 0-99
int dataCX;
int dataCY;
int dataCA;
int dataCB;
int dataCC;
int dataCD;
//Valor codificado
long val;
void setup(){
  Serial.begin(9600);
  HC12.begin(9600);
  pinMode(joyX,INPUT);
  pinMode(joyY,INPUT);
  pinMode(A,INPUT_PULLUP);
  pinMode(B,INPUT_PULLUP);
  pinMode(C,INPUT_PULLUP);
  pinMode(D,INPUT_PULLUP);

}

void loop(){
  //leemos los joysticks y los botones
  dataX = analogRead(joyX);
  dataY = analogRead(joyY);
  dataA = digitalRead(A);
  dataB = digitalRead(B);
  dataC = digitalRead(C);
  dataD = digitalRead(D);
  //convertimos valores 
  dataCX=(dataX*99)/1023;
  dataCY=(dataY*99)/1023;
  dataCA=(dataA*1)/1;
  dataCB=(dataB*1)/1;
  dataCC=(dataC*1)/1;
  dataCD=(dataD*1)/1;
  //codificamos
  val= dataCX+dataCY*10z0+dataCA*10000+dataCB*100000+dataCC*1000000+dataCD*10000000;
  HC12.print(val);
  Serial.println(val);
  delay(100);

}