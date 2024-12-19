#include <SoftwareSerial.h>   
#include <Servo.h>
SoftwareSerial BT(7,8);   
//Servos
Servo Servo15kg;
Servo Servo1kg;
Servo Servo215kg;
Servo Servo21kg;
//Ordenes
char adelante='A';
char atras='B';
char ladoDerecho='C';
char ladoIzquierdo='D';
char sTOP='P';
char ops;

//Lado Derecho
int Din1=2;
int Din2=3;

//Lado Izquierdo
int iin3=9;
int iin4=10;
//Velocidad
int Vel1=5;
int Vel2=6;

//Voids

//Void Ruedas
void Adelante();
void Atras();
void Derecha();
void Izquierda();
//Void Servos
void Guardado();
void Arriba();
void Abajo();
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


}

void loop() {
  // put your main code here, to run repeatedly:

if(BT.available()>0){
ops=BT.read();

switch (ops) {
//Adelante
case 'A':
Adelante();
break;
//Atras
case 'B':
Atras();
break;
//Derecha
case 'C':
Derecha();
break;
//Izquierda
case 'D':
Izquierda();
break;

//STOP
case 'S':
STOP();
break;
case 'V':
Guardado();
break;
case 'Z':
Arriba();
break;
case 'N':
Abajo();
break;

}
}
}





void Adelante()
{
digitalWrite(Din1,HIGH);
digitalWrite(Din2,LOW);

digitalWrite(iin3,HIGH);
digitalWrite(iin4,LOW);

Serial.println("Llendo hacia adelante");
}
void Atras()
{
digitalWrite(Din1,LOW);
digitalWrite(Din2,HIGH);

digitalWrite(iin3,LOW);
digitalWrite(iin4,HIGH);

Serial.println("Llendo hacia atras");
}
void Derecha()
{
digitalWrite(Din1,HIGH);
digitalWrite(Din2,LOW);

digitalWrite(iin3,LOW);
digitalWrite(iin4,HIGH);

Serial.println("Llendo hacia la derecha");
}
void Izquierda()
{
digitalWrite(Din1,LOW);
digitalWrite(Din2,HIGH);

digitalWrite(iin3,HIGH);
digitalWrite(iin4,LOW);
Serial.println("Llendo hacia la izquierda");
}
void STOP()
{
digitalWrite(Din1,LOW);
digitalWrite(Din2,LOW);

digitalWrite(iin3,LOW);
digitalWrite(iin4,LOW);
Serial.println("Parado");
}
void Guardado()
{
Servo15kg.write(0);
Servo1kg.write(0);
Servo215kg.write(180);
Servo21kg.write(0);
Serial.println(Servo15kg.read());
Serial.println(Servo215kg.read());
}
void Arriba()
{
Servo15kg.write(0);
Servo1kg.write(0);
Servo215kg.write(180);
Servo21kg.write(0);
Serial.println(Servo15kg.read());
Serial.println(Servo215kg.read());
}
void Abajo(){
Servo15kg.write(0);
Servo1kg.write(0);
Servo215kg.write(180);
Servo21kg.write(180);
Serial.println(Servo15kg.read());
Serial.println(Servo215kg.read());
}

