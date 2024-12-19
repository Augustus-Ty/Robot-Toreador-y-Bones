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
boolean acc_on=false; //Flag to inidicate if to use accelerometer values

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
analogWrite(Vel1,0);
analogWrite(Vel2,0);
}

void loop() {
  // put your main code here, to run repeatedly:
 if(BT.available()>0){
 ops = BT.read();
   if(ops=='X'){  fx=BT.parseInt();
      while (ops!='*'){
        if (BT.available()){
          ops=BT.read(); //Get next character from bluetooth
          if(ops=='Y') fy= BT.parseInt();
        }}
             Serial.println(fx) ; 
             Serial.println(fy); 
     }


    if ( fx < 550 && fx > 400 && fy < 550 && fy > 400) {
     digitalWrite(Din1,LOW);
     digitalWrite(Din2,LOW);
 
     digitalWrite(iin3,LOW);
     digitalWrite(iin4,LOW);

     analogWrite(Vel1,0);
     analogWrite(Vel2,0);
     delay(10);
     Serial.println("Parado");
    }
      //data X
     if (fx > 550) {
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
    if (fx < 400 && fx > 0) {
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
    if (fy > 550 ) {

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
    if (fy < 450 && fy > 0 ) {

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
    if (ops=='V'){
   Servo15kg.write(10);
   Servo1kg.write(90);
   Servo215kg.write(170);
   Servo21kg.write(90);

  if (ops=='Z'){
   Servo15kg.write(90);
   Servo1kg.write(90);
   Servo215kg.write(90);
   Servo21kg.write(90);
  }
  if (ops=='N'){
   Servo15kg.write(20);
   Servo1kg.write(90);
   Servo215kg.write(160);
   Servo21kg.write(90);
  }
    if (ops=='R'){
   }
  }
  
  }

  }
   


