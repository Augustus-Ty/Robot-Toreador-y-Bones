#include <SoftwareSerial.h>
SoftwareSerial HC12(11, 12); // HC-12 TX Pin, HC-12 RX Pin
//Variable decodificadora
int joyX;
int joyY;
int A;
int B;
int C;
int D;
int Val[6];
long Rep;
//Velocidad
int VD=6;
int VI=5;
//Lado Derecho
int Din1=2;
int Din2=3;
//Lado Izquierdo
int iin3=7;
int iin4=8;
//Servos
int Servo1=9;
int Servo2=12;
int Servo3=A1;
int Servo4=A2;
void setup() {
  Serial.begin(9600);
  HC12.begin(9600);               
//Salidas
pinMode(Din1, OUTPUT);
pinMode(Din2, OUTPUT);
pinMode(iin3, OUTPUT);
pinMode(iin4, OUTPUT);
pinMode(VD, OUTPUT);
pinMode(VI, OUTPUT);
pinMode(Servo1, OUTPUT);
pinMode(Servo2, OUTPUT);
pinMode(Servo3, OUTPUT);
pinMode(Servo4, OUTPUT);
}
void loop() {
  while (HC12.available()>0) {
    Serial.println(HC12.readString().toInt());
    Rep= HC12.readString().toInt();
     Val[0]= Rep%100;
     Rep/=100;
     Val[1]=Rep%100;
      Rep/=100;
     Val[2]=Rep%10;
      Rep/=10;
     Val[3]=Rep%10;
      Rep/=10;
     Val[4]=Rep%10;
      Rep/=10;
     Val[5]=Rep;
     joyX=Val[0]*1023/99;
     joyY=Val[1]*1023/99;
     Serial.print(Val[0]);
 /* //data X
    if (joyX > 550) {
    digitalWrite(Din1,HIGH);
    digitalWrite(Din2,LOW);

    digitalWrite(iin3,HIGH);
    digitalWrite(iin4,LOW);
         Serial.println("Dato en X");
         Serial.println (joyX);
   // Serial.println("Yendo hacia ADELANTE");
      
    }

    //data X
    if (joyX < 400 && joyX >0) {
    digitalWrite(Din1,LOW);
    digitalWrite(Din2,HIGH);

    digitalWrite(iin3,LOW);
    digitalWrite(iin4,HIGH);

         Serial.println("Dato en X");
         Serial.println (joyX);
    //Serial.println("Yendo hacia atras");
    }

    //data Y
    if (joyY > 550 ) {

    digitalWrite(Din1,HIGH);
    digitalWrite(Din2,LOW);

    digitalWrite(iin3,LOW);
    digitalWrite(iin4,HIGH);

     Serial.println("Dato en Y:");
             Serial.println (joyY);
    //Serial.println("Yendo hacia la derecha");
    }

    //data Y
    if (joyY < 400 && joyY > 0 ) {

    digitalWrite(Din1,LOW);
    digitalWrite(Din2,HIGH);

    digitalWrite(iin3,HIGH);
    digitalWrite(iin4,LOW);

     Serial.println("Dato en Y:");
             Serial.println (joyY);
   // Serial.println("Yendo hacia la izquierda");
    }

    if (joyX < 550 && joyX > 400 && joyY < 550 && joyY > 400) {
    digitalWrite(Din1,LOW);
    digitalWrite(Din2,LOW);

    digitalWrite(iin3,LOW);
    digitalWrite(iin4,LOW);

    Serial.println("Parado");
    }
*/

  }
  delay(110);
}






