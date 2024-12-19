
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
// Hardware configuration
// Set up nRF24L01 radio on pins D4 & D2 of Nodemcu
RF24 radio(9, 10);//CE, CSN
const byte pipe[6] = "00001";// Radio pipe address for the 2 nodes to communicate.
float data[4];
float vel;
 
void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);
 


  radio.begin();
  radio.openReadingPipe(0, pipe);
  radio.startListening();
}
 
void loop() {

  // Your code here
  if (radio.available()) {
    radio.read(&data, sizeof(data));
    vel = data[0];
    Serial.println("Velocidad: ");
    Serial.println (vel);

    delay(1000);
  }
 
}
