//Definir el HC12
  #include <SoftwareSerial.h>
  SoftwareSerial HC12(12, 13);              // D11 is HC-12 RX Pin, D10 is HC-12 TX Pin
//Valores del control
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
  //Valores A Enviar
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
   //pinMode(Boton_Joystick,INPUT_PULLUP);
   Serial.begin(9600);                     
   HC12.begin(9600);                       
             }

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


  /*{
   Serial.print("X: ");
   Serial.print(joy_x_send);
   Serial.print("   |   ");
   Serial.print("Y: ");
   Serial.print(joy_y_send);
   Serial.print("   |   ");
   Serial.print("W: ");
   Serial.print(x_send);
   Serial.print("   |   ");
   Serial.print("T: ");
   Serial.print(y_send);
   Serial.println(" ");
  }*/
  char mensaje[12];
    sprintf(mensaje,"V %d%d%d%d%d%03d%03d", pA, pAB, pD, pI, joy_x_send, joy_y_send);
    //sprintf(mensaje,"V %d%d%04d%04d", pA, pAB, joy_x_send, joy_y_send);
  Serial.println(String(analogRead(14)));
  HC12.println(String(mensaje));
  delay(20); 
           }