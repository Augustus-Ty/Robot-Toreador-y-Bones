//Librerias

#include <Servo.h>

//Direccion Derecha   
#define INA1 2
#define INA2 3
//Direccion Izquierda
#define INB1 9
#define INB2 10
//Velocidades
#define VelDerecha 5
#define VelIzquierda 6
//Servos
Servo ServoDerecho15kg;
Servo ServoIzquierdo15kg;
Servo ServoDerecho1kg;
Servo ServoIzquierdo1kg;
Servo Gripper;
//Variables
int mot[6];
int VelocidadDerecho=0;
int VelocidadIzquierdo=0;
int dir=0;
//Variables de Gripper
int BotonPrendidoApagado;
int BotonPrendidoApagado2;
int BotonPrendidoApagado3;
//Variables Servos
int ArribayAbajo;

void setup() {
  
  Serial.begin(9600);                     // Iniciar serial port 

  //Direcciones Derecha
  pinMode(INA1,OUTPUT);
  pinMode(INA2,OUTPUT);
  //Direcciones Izquierda
  pinMode(INB1,OUTPUT);
  pinMode(INB2,OUTPUT);
  //Velocidad
  pinMode(VelDerecha,OUTPUT);
  pinMode(VelIzquierda,OUTPUT);
  //Servos
 ServoDerecho15kg.attach(11);
 ServoDerecho1kg.attach(12);
 ServoIzquierdo15kg.attach(4);
 ServoIzquierdo1kg.attach(13);
 Gripper.attach(14);
        ServoDerecho15kg.write(140);
       ServoDerecho1kg.write(180);
       ServoIzquierdo15kg.write(40);
       ServoIzquierdo1kg.write(0);

  }

 
void loop() {
  //RecibirValores
  while (Serial.available()> 0) {             
    String mensaje = Serial.readStringUntil('\n');          
    
    int indiceEspacio = mensaje.indexOf(' ');
    if(indiceEspacio != -1) {
      String valorSubcadena = mensaje.substring(indiceEspacio + 1);
      long int valor = valorSubcadena.toInt();
      Serial.println(valor);
      //Decodificacion
      mot[0]=valor%1000;
      mot[1]=(valor/1000)%1000;
      mot[2]=(valor/1000000)%10;
      mot[3]=(valor/10000000)%10;
      mot[4]=(valor/100000000)%10;
      mot[5]=(valor/1000000000)%10;

      map(mot[0],0,999,0,1023);
      map(mot[1],0,999,0,1023);
    }

  }
  delay(22); 
 

 if(mot[5]!=0){
  //Mover hacia Adelante
  if(mot[0]<470){
   //dir=1;
   digitalWrite(INA1,HIGH);
   digitalWrite(INA2,LOW);
   digitalWrite(INB1,HIGH);
   digitalWrite(INB2,LOW);
   VelocidadDerecho=map(mot[0],470,0,0,255);
   VelocidadIzquierdo=map(mot[0],470,0,0,255);
   }
   //Mover hacia Atras
   else if(mot[0]>550){
   //dir=0;
   digitalWrite(INA1,LOW);
   digitalWrite(INA2,HIGH);
   digitalWrite(INB1,LOW);
   digitalWrite(INB2,HIGH);
   VelocidadDerecho=map(mot[0],550,1023,0,255);
   VelocidadIzquierdo=map(mot[0],550,1023,0,255);
   }
   
        else {
        VelocidadDerecho=0;
        VelocidadIzquierdo=0;
             }
   
   if(mot[1]<470){
   int xMap=map(mot[1],470,0,0,255);
   VelocidadDerecho+= xMap;
   VelocidadIzquierdo-= xMap;
   if(VelocidadDerecho<0) VelocidadDerecho=0;
   if(VelocidadIzquierdo>255) VelocidadIzquierdo=255;
   
   if(mot[0]>470 && mot[0]<550){
   //dir=1;
   digitalWrite(INA1,HIGH);
   digitalWrite(INA2,LOW);
   digitalWrite(INB1,LOW);
   digitalWrite(INB2,HIGH);
   VelocidadIzquierdo=VelocidadDerecho;
  
   }
   }
   if(mot[1]>550){
   int xMap=map(mot[1],550,1023,0,255);
   VelocidadDerecho-= xMap;
   VelocidadIzquierdo+= xMap;
   if(VelocidadIzquierdo<0) VelocidadIzquierdo=0;
   if(VelocidadDerecho>255) VelocidadDerecho=255;
   if(mot[0]>470 && mot[0]<550){
   //dir=1;
  digitalWrite(INA1,LOW);
   digitalWrite(INA2,HIGH);
   digitalWrite(INB1,HIGH);
   digitalWrite(INB2,LOW);
   VelocidadDerecho=VelocidadIzquierdo;
  
   }
   }
   if(VelocidadDerecho<70){
   VelocidadDerecho=0;
    } 
   if(VelocidadIzquierdo<70){
   VelocidadIzquierdo=0;
   } 



   //Mover Servos Guardado
     if(mot[3]==0 && BotonPrendidoApagado3==0){
        ServoDerecho15kg.write(140);
       ServoDerecho1kg.write(180);
       ServoIzquierdo15kg.write(40);
       ServoIzquierdo1kg.write(0);
          BotonPrendidoApagado3 = 1 ;

                  }
      else if (mot[3]==0 && BotonPrendidoApagado3==1) {
       ServoDerecho15kg.write(90);
       ServoDerecho1kg.write(91);
       ServoIzquierdo15kg.write(90);
       ServoIzquierdo1kg.write(89);
           delay(500);
          BotonPrendidoApagado3 = 0 ;
      }

    



   //ServoGripper
        if(mot[2]==0 && BotonPrendidoApagado==0){
           Gripper.write(160);
           delay(500);
           BotonPrendidoApagado= 1 ;
                // Serial.println("mot2");
                  }
        else if(mot[2]==0 && BotonPrendidoApagado==1){
           Gripper.write(40);
           delay(500);
           BotonPrendidoApagado= 0 ;
                 //Serial.println("mot2");
                  }
                     //Mover Servos Guardado
  //ServoGripper
        if(mot[4]==0 && BotonPrendidoApagado2==0){
           Gripper.write(160);
           delay(500);
           BotonPrendidoApagado2= 1 ;
                // Serial.println("mot2");
                  }
        else if(mot[4]==0 && BotonPrendidoApagado2==1){
           Gripper.write(100);
           delay(500);
           BotonPrendidoApagado2= 0 ;
                 //Serial.println("mot2");
                  }

   //Arriba y Abajo
        if(mot[5]==2 && ArribayAbajo==0){
       ServoDerecho15kg.write(20);
       ServoDerecho1kg.write(90);
       ServoIzquierdo15kg.write(160);
       ServoIzquierdo1kg.write(90);
           delay(500);
           ArribayAbajo= 1 ;
                // Serial.println("mot2");
                  }
        else if(mot[5]==2 && ArribayAbajo==1){
        ServoDerecho15kg.write(90);
       ServoDerecho1kg.write(90);
       ServoIzquierdo15kg.write(90);
       ServoIzquierdo1kg.write(90);
           delay(500);
           ArribayAbajo= 0 ;
                 //Serial.println("mot2");
                  }


   analogWrite(VelDerecha,VelocidadDerecho);
   analogWrite(VelIzquierda,VelocidadIzquierdo);
   //Serial.print(String(VelocidadDerecho));
   //Serial.print("\t");
   //Serial.println(String(VelocidadIzquierdo));  
               }
  
                         }