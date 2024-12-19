//BONES_ROBOT_FIRST_GLOBAL_CHALLENGE_V008_ESP32PS4
//2024
//1.LIBRERIAS
#include<math.h>
#include <ESP32Servo.h>
#include <PS4Controller.h>
//2.PINES DE MOTORES 
  //2.1Motores Derechos
  #define INA1 27
  #define INA2 26
  //2.2Motores Izquierdos
  #define INB1 25
  #define INB2 33
  //2.3Motores recolectores
    //2.3.1Direcciones
      
    //2.3.2Velocidades

//3.SERVOMOTORES
  //3.1 Servomotor Objectos
    Servo servomotorderecho;   
    Servo servomotorizquierdo;
    Servo servomotorgripper;
    Servo servomotorclasificador;
    Servo servomotorclasificador2;    
  //3.2 Servomotor Pines
    int SMDP=21; 
    int SMIP=19;
    int SMGP=18;
    int SMRP=23;
    int SMEP=22;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//SETUP
void setup() 
  {
  //1.COMUNICACION
    //1.1Comunicacion Serial
      Serial.begin(115200);
    //1.2Comunicacion con el control PS4
      PS4.begin();//En este caso la direcion MAC del control se dirige a la del ESP32
  //2.MOTORES
    analogWrite(INA1,0); //Evitar encendidos indeseados
    analogWrite(INA2,0);
    analogWrite(INB1,0);
    analogWrite(INB2,0);
  //3.SERVOMOTORES
  //3.1 Timers 
    ESP32PWM::allocateTimer(0);
	  ESP32PWM::allocateTimer(1);
	  ESP32PWM::allocateTimer(2);
	  ESP32PWM::allocateTimer(3);
    ESP32PWM::timerCount[0]=4;
    servomotorderecho.setPeriodHertz(50); //Colocar la frecuencia requerida por el pwm del servomotor
    servomotorizquierdo.setPeriodHertz(50); //Colocar la frecuencia requerida por el pwm del servomotor 
    servomotorgripper.setPeriodHertz(50); //Colocar la frecuencia requerida por el pwm del servomotor 
    servomotorclasificador.setPeriodHertz(50); //Colocar la frecuencia requerida por el pwm del servomotor 
    servomotorclasificador2.setPeriodHertz(50); //Colocar la frecuencia requerida por el pwm del servomotor 
  //3.2 Pines y sus minimos y maximos
    servomotorderecho.attach(SMDP, 1000, 2000); //Usar el servomotor MG995 de valores 1000us y 2000us conectado al D21
    servomotorizquierdo.attach(SMIP, 1000, 2000); //Usar el servomotor MG995 de valores 1000us y 2000us conectado al D19
    servomotorgripper.attach(SMGP, 1000, 2000); //Usar el servomotor MG995 de valores 1000us y 2000us conectado al D18
    servomotorclasificador.attach(SMRP, 1000, 2000); //Usar el servomotor MG995 de valores 1000us y 2000us conectado al D4
    servomotorclasificador2.attach(SMEP, 1000, 2000); //Usar el servomotor MG995 de valores 1000us y 2000us conectado al D4
  }  //Fin del Void setup

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//LOOP
void loop() {
//1.RECIBIR CONSTANTEMENTE AL CONTROL DE PS4
  if (PS4.isConnected()){
//2.CASOS
    if (PS4.LStickY()<=10 && PS4.LStickY()>=-10  ) {
        if(PS4.RStickY()<=10 && PS4.RStickY()>=-10){
       PARADO();
        }
                                  } //FIN DEL CASO 1
    else{
    if (PS4.LStickY()>=100 && PS4.RStickY()<=-100 ){
      //Poner una interrupcion a parado 
       Caso14();
                           } //FIN DEL CASO 4
    if (PS4.LStickY()<=-100 && PS4.RStickY()>=100  ) {
       Caso15();
                           } //FIN DEL CASO 5
    if (PS4.LStickY()>=100 && PS4.RStickY()>=100) {
       Caso12();
                           } //FIN DEL CASO 2
    if (PS4.LStickY()<=-100 && PS4.RStickY()<=-100) {
       Caso13();
                           } //FIN DEL CASO 3
    }
    if(PS4.R2()){
      ARRIBA();
    }
    if(PS4.L2()){
      ABAJO();
    }
    if(PS4.Circle()){
      ABIERTO();
    }
    if(PS4.Triangle()){
      CERRADO();
    }
    if(PS4.Square()){
      ABIERTO2();
    }
    if(PS4.Cross()){
      CERRADO2();
    }    
  }//LLAVE DEL CONTROL PS4
}//Llave del void loop

///////////////////////////////////////////////////////////////////////////////////////////////////////
//CASOS 
//1.Casos motores
//1.1.Caso Parado
void PARADO(){
  analogWrite(INB1,0);
  analogWrite(INB2,0);
  analogWrite(INA1,0);
  analogWrite(INA2,0);
  Serial.println("ESTA PARADO");
             }
//1.2.Caso Adelante Maximo     
void Caso12(){
  analogWrite(INB1,255);
  analogWrite(INB2,0);
  analogWrite(INA1,255);
  analogWrite(INA2,0);
  Serial.println("ESTA ADELANTE");
              }
//1.3.Caso Atras Maximo
void Caso13(){
  analogWrite(INB1,0);
  analogWrite(INB2,255);
  analogWrite(INA1,0);
  analogWrite(INA2,255);
  Serial.println("ESTA ATRAS");
             }
//1.4.Caso Derecha Maximo
void Caso14(){
  analogWrite(INB1,0);
  analogWrite(INB2,255);
  analogWrite(INA1,255);
  analogWrite(INA2,0);
  Serial.println("ESTA Derecha");
             }
//1.5.Caso Izquierda Maximo
void Caso15(){
  analogWrite(INB1,255);
  analogWrite(INB2,0);
  analogWrite(INA1,0);
  analogWrite(INA2,255);
  Serial.println("ESTA Izquierda");
             } 
//1.6.Caso Adelante Variable

//1.7.Caso Atras Variable

//1.8.Caso Derecha Variable

//1.9.Caso  Izquierda Variable

//2.Posiciones de Servomotores
//2.1.Caso arriba
void ARRIBA(){
servomotorderecho.write(180);
servomotorizquierdo.write(0);
  Serial.println("ESTA ARRIBA");
}
//2.2.Caso abajo
void ABAJO(){
servomotorderecho.write(0);
servomotorizquierdo.write(180);
  Serial.println("ESTA ABAJO");
}
//2.3.Caso abierto
void ABIERTO(){
servomotorgripper.write(160);
  Serial.println("ESTA ABIERTO");
}
//2.4.Caso cerrado
void CERRADO(){
servomotorgripper.write(30);
  Serial.println("ESTA CERRADO");
}
//2.3.Caso abierto
void ABIERTO2(){
servomotorclasificador.write(160);
servomotorclasificador2.write(30);
  Serial.println("ESTA ABIERTO33");
}
//2.4.Caso cerrado
void CERRADO2(){
servomotorclasificador.write(30);
servomotorclasificador2.write(160);
  Serial.println("ESTA CERRADO33");
}