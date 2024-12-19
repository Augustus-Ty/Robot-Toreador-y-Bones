#include <SPI.h>  //the communication interface with the modem
#include "RF24.h" //the library which helps us to control the radio modem
#include <nRF24L01.h>
//define the data pins
float joyX = A5;
float joyY = A4;

//define variable values
float dataX;
float dataY;

float data[4];

RF24 radio(9,10); //10 and 9 are a digital pin numbers to which signals CE and CSN are connected
                                      
const byte pipe[5] = {'c','a','n','a','l'};//the address of the modem, that will receive data from Arduino


void setup(void){
  Serial.begin(9600);
  radio.begin();                      //it activates the modem
  radio.openWritingPipe(pipe);        //sets the address of the receiver to which the program will send data
  radio.stopListening();
}

void loop(){
  //Send signal data
  dataX = analogRead(joyX);
  dataY = analogRead(joyY);
  
  data[0] = dataX;
  data[1] = dataY;

  Serial.print("Data X:"); Serial.println(dataX);

  Serial.print("Data Y:"); Serial.println(dataY);
  delay(500);
  radio.write(&data, sizeof(data));
  
}
