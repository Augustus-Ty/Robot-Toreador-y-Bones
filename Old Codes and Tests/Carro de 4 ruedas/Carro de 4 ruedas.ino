char Adelante='A';
char Atras='B';
char LadoDerecho='C';
char LadoIzquierdo='D';
char STOP='P';
char ops;
//Lado Derecho
int Din1=5;
int Din2=4;
int Din3=0;
int Din4=2;
//Lado Izquierdo
int iin1=14;
int iin2=12;
int iin3=13;
int iin4=15;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(Din1, OUTPUT);
pinMode(Din2, OUTPUT);
pinMode(Din3, OUTPUT);
pinMode(Din4, OUTPUT);
pinMode(iin1, OUTPUT);
pinMode(iin2, OUTPUT);
pinMode(iin3, OUTPUT);
pinMode(iin4, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0){
ops=Serial.read();

if(Adelante==ops){
digitalWrite(Din1,HIGH);
digitalWrite(Din2,LOW);
digitalWrite(Din3,HIGH);
digitalWrite(Din4,LOW);

digitalWrite(iin1,HIGH);
digitalWrite(iin2,LOW);
digitalWrite(iin3,HIGH);
digitalWrite(iin4,LOW);
}
if(Atras==ops){
digitalWrite(Din1,LOW);
digitalWrite(Din2,HIGH);
digitalWrite(Din3,LOW);
digitalWrite(Din4,HIGH);

digitalWrite(iin1,LOW);
digitalWrite(iin2,HIGH);
digitalWrite(iin3,LOW);
digitalWrite(iin4,HIGH);
}
if(LadoDerecho==ops){
digitalWrite(Din1,HIGH);
digitalWrite(Din2,LOW);
digitalWrite(Din3,LOW);
digitalWrite(Din4,HIGH);

digitalWrite(iin1,HIGH);
digitalWrite(iin2,LOW);
digitalWrite(iin3,LOW);
digitalWrite(iin4,HIGH);
}
if(LadoIzquierdo==ops){
digitalWrite(Din1,LOW);
digitalWrite(Din2,HIGH);
digitalWrite(Din3,HIGH);
digitalWrite(Din4,LOW);

digitalWrite(iin1,LOW);
digitalWrite(iin2,HIGH);
digitalWrite(iin3,HIGH);
digitalWrite(iin4,LOW);
}
if(STOP==ops){
digitalWrite(Din1,LOW);
digitalWrite(Din2,LOW);
digitalWrite(Din3,LOW);
digitalWrite(Din4,LOW);

digitalWrite(iin1,LOW);
digitalWrite(iin2,LOW);
digitalWrite(iin3,LOW);
digitalWrite(iin4,LOW);
}
}
}
