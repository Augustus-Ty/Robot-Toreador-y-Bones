//Transmitter Side Code for Arduino Nano
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Hardware configuration
// Set up nRF24L01 radio on pins D8 & D10 of  Arduino Nano
float data[4];
RF24 radio(9,10); //CN y CSN
const byte pipe[6] = {"00001"};// Radio pipe address for the 2 nodes to communicate.
float vel;  //Stores humidity value

 
void setup()
{
  Serial.begin(9600);

  radio.begin();
  radio.openWritingPipe(pipe);
  radio.stopListening();
 
}
 
void loop()
{
   vel = analogRead(A0);

  Serial.print("Velocidad: ");
  Serial.println(vel);

  data[0]=vel;

  radio.write(&data, sizeof(data));
  delay(1000);
}