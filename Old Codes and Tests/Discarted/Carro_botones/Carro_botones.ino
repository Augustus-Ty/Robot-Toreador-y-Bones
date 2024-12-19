#include <SoftwareSerial.h>   
#include <Servo.h>
SoftwareSerial BT(8,7);   
//Servos
Servo Servo15kg;
Servo Servo1kg;
Servo Servo215kg;
Servo Servo21kg;

//Lado Derecho
int Din1=2;
int Din2=3;

//Lado Izquierdo
int iin3=9;
int iin4=10;
//Velocidad
int Vel1=5;
int Vel2=6;
//
int roll,pitch; //roll and pitch sent from Android device
int fx,fy; //control pad values sent from Andorid device
char ops; // the Bluetooth data received
//MOTOR PASO A PASO
int Paso1=15;
int Paso2=16;
int Paso3=17;
int Paso4=18;
int pasos [8][4] =
{
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};
int pasos2 [8][4] =
{
  {1, 0, 0, 1},
  {0, 0, 0, 1},
  {0, 0, 1, 1},
  {0, 0, 1, 0},
  {0, 1, 1, 0},
  {0, 1, 0, 0},
  {1, 1, 0, 0},
  {1, 0, 0, 0}
};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 BT.begin(9600);
 delay(1500);
 //Sentido
 pinMode(Din1, OUTPUT);
 pinMode(Din2, OUTPUT);
 pinMode(iin3, OUTPUT);
 pinMode(iin4, OUTPUT);
 //Velocidades
 pinMode(Vel1,OUTPUT);
 pinMode(Vel2,OUTPUT);
 //Servos
 Servo15kg.attach(11);
 Servo1kg.attach(12);
 Servo215kg.attach(4);
 Servo21kg.attach(13);
 //Iniciar Drivers
analogWrite(Vel1,0);
analogWrite(Vel2,0);
//Motor paso a Paso
pinMode(Paso1,OUTPUT);
pinMode(Paso2,OUTPUT);
pinMode(Paso3,OUTPUT);
pinMode(Paso4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 if(BT.available()>0){
 ops = BT.read();

      //data X
     if (ops=='A') {
     digitalWrite(Din1,HIGH);
     digitalWrite(Din2,LOW);

     digitalWrite(iin3,HIGH);
     digitalWrite(iin4,LOW);
     analogWrite(Vel1,255);
     analogWrite(Vel2,255);
         Serial.println("Dato en X");
         Serial.println (fx);
     Serial.println("Yendo hacia ADELANTE");
      
    }

    //data X
    if (ops=='B') {
     digitalWrite(Din1,LOW);
     digitalWrite(Din2,HIGH);

     digitalWrite(iin3,LOW);
     digitalWrite(iin4,HIGH);
     delay(10);
     analogWrite(Vel1,255);
     analogWrite(Vel2,255);
         Serial.println("Dato en X");
         Serial.println (fx);
    Serial.println("Yendo hacia atras");
    }

    //data Y
    if (ops=='C' ) {

     digitalWrite(Din1,HIGH);
     digitalWrite(Din2,LOW);

     digitalWrite(iin3,LOW);
     digitalWrite(iin4,HIGH);
     delay(10);
     analogWrite(Vel1,255);
     analogWrite(Vel2,255);
     Serial.println("Dato en Y:");
             Serial.println (fy);
    Serial.println("Yendo hacia la derecha");
    }

    //data Y
    if (ops=='D') {

     digitalWrite(Din1,LOW);
     digitalWrite(Din2,HIGH);

     digitalWrite(iin3,HIGH);
     digitalWrite(iin4,LOW);
     delay(10);
     analogWrite(Vel1,255);
     analogWrite(Vel2,255);
     Serial.println("Dato en Y:");
      Serial.println (fy);
     Serial.println("Yendo hacia la izquierda");
    }

  if (ops=='Z'){
   Servo15kg.write(90);
   Servo1kg.write(90);
   Servo215kg.write(90);
   Servo21kg.write(90);
  }
  if (ops=='N'){
   Servo15kg.write(10);
   Servo1kg.write(82);
   Servo215kg.write(170);
   Servo21kg.write(102);
   }
  if (ops=='V'){
   Servo15kg.write(10);
   Servo1kg.write(80);
   Servo215kg.write(160);
   Servo21kg.write(100);
  }
  
  
  if ( ops=='S') {
     digitalWrite(Din1,LOW);
     digitalWrite(Din2,LOW);
 
     digitalWrite(iin3,LOW);
     digitalWrite(iin4,LOW);

     analogWrite(Vel1,0);
     analogWrite(Vel2,0);
     delay(10);
     Serial.println("Parado");
    }
   if(ops=='H'){
    for (int i = 0; i < 8; i++)
    {
      digitalWrite(Paso1, pasos[i][0]);
      digitalWrite(Paso2, pasos[i][1]);
      digitalWrite(Paso3, pasos[i][2]);
      digitalWrite(Paso4, pasos[i][3]);
      delay(10);
    }
              }
   if(ops=='O'){
    for (int i = 0; i < 8; i++)    
    {
      digitalWrite(Paso4, pasos2[i][0]);
      digitalWrite(Paso3, pasos2[i][1]);
      digitalWrite(Paso2, pasos2[i][2]);
      digitalWrite(Paso1, pasos2[i][3]);
      delay(10);
    }
              }
  }
  
  }

  
   