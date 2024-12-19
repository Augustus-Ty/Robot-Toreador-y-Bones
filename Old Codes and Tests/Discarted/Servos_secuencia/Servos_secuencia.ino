#include <Servo.h>
Servo Servo15kg;
Servo Servo1kg;
Servo Servo215kg;
Servo Servo21kg;
char ops;
void arriba();
void abajo();
void guardado();

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Servo15kg.attach(4);
Servo1kg.attach(5);
Servo215kg.attach(6);
Servo21kg.attach(7);
Servo215kg.write(90);
Servo15kg.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0){
ops=Serial.read();
if(ops=='A'){
Servo15kg.write(90);
Servo1kg.write(80);
Servo215kg.write(85);
Servo21kg.write(80);
Serial.println(Servo15kg.read());
Serial.println(Servo215kg.read());
}
if(ops=='B'){
Servo15kg.write(0);
Servo1kg.write(0);
Servo215kg.write(180);
Servo21kg.write(0);
Serial.println(Servo15kg.read());
Serial.println(Servo215kg.read());
}
if(ops=='C'){
Servo15kg.write(10);
Servo1kg.write(60);
Servo215kg.write(10);
Servo21kg.write(60);
Serial.println(Servo15kg.read());
Serial.println(Servo215kg.read());
}
}


}




