#include <SPI.h>      //the communication interface with the modem
#include <RF24.h>     //the library which helps us to control the radio modem (nRF24L)
#include <nRF24L01.h>

//Velocidad
int VD=6;
int VI=5;

//Lado Derecho
int Din1=2;
int Din2=3;

//Lado Izquierdo
int iin3=7;
int iin4=8;

float data[4];

RF24 radio(9, 10); //10 and 9 are a digital pin numbers to which signals CE and CSN are connected

const byte pipe[6] = {'c','a','n','a','l'}; // Radio pipe address for the 2 nodes to communicate.


void setup() {
  Serial.begin(9600);
pinMode(Din1, OUTPUT);
pinMode(Din2, OUTPUT);
pinMode(iin3, OUTPUT);
pinMode(iin4, OUTPUT);

  radio.begin();                    //it activates the modem
  radio.openReadingPipe(1, pipe);   //determines the address of our modem which receive data
  radio.startListening();           //enable receiving data via modem
}

void loop() {
  if (radio.available()>0) {
    radio.read(&data, sizeof(data));
    
    if (data[0] < 550 && data[0] > 400 && data[1] < 550 && data[1] > 400) {
    digitalWrite(Din1,LOW);
    digitalWrite(Din2,LOW);

    digitalWrite(iin3,LOW);
    digitalWrite(iin4,LOW);
     delay(500);
    Serial.println("Parado");
    }
    else{    
      //data X
    if (data[0] > 550) {
    digitalWrite(Din1,HIGH);
    digitalWrite(Din2,LOW);

    digitalWrite(iin3,HIGH);
    digitalWrite(iin4,LOW);
         Serial.println("Dato en X");
         Serial.println (data[0]);
    Serial.println("Yendo hacia ADELANTE");
      
    }

    //data X
    if (data[0] < 400 && data[0]>0) {
    digitalWrite(Din1,LOW);
    digitalWrite(Din2,HIGH);

    digitalWrite(iin3,LOW);
    digitalWrite(iin4,HIGH);
     delay(500);
         Serial.println("Dato en X");
         Serial.println (data[0]);
    Serial.println("Yendo hacia atras");
    }

    //data Y
    if (data[1] > 550 ) {

    digitalWrite(Din1,HIGH);
    digitalWrite(Din2,LOW);

    digitalWrite(iin3,LOW);
    digitalWrite(iin4,HIGH);
     delay(500);
     Serial.println("Dato en Y:");
             Serial.println (data[1]);
    Serial.println("Yendo hacia la derecha");
    }

    //data Y
    if (data[1] < 450 && data[1]>0 ) {

    digitalWrite(Din1,LOW);
    digitalWrite(Din2,HIGH);

    digitalWrite(iin3,HIGH);
    digitalWrite(iin4,LOW);
     delay(500);
     Serial.println("Dato en Y:");
             Serial.println (data[1]);
    Serial.println("Yendo hacia la izquierda");
    }}
    

  }
}