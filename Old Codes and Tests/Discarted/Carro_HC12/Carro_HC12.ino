//Libraries
#include <SoftwareSerial.h>
SoftwareSerial HC12(10, 11);              // D11 is HC-12 TX Pin, D10 is HC-12 RX Pin

int ops[15];
void setup() {
  
  Serial.begin(9600);                     // Open serial port 
  HC12.begin(9600);                     // Open serial port to HC12

  }

 
void loop() {
  //First we store the entire incoming data into "readBuffer"
  while (HC12.available()> 0) {             // If the HC-12 has data in
    String mensaje = HC12.readStringUntil('\n');             // Store the data byte by byte
    
    int indiceEspacio = mensaje.indexOf(' ');
    if(indiceEspacio != -1) {
      String valorSubcadena = mensaje.substring(indiceEspacio + 1);
      long int valor = valorSubcadena.toInt();
      Serial.println(mensaje);
      //Serial.println(valor);
      ops[0]=valor%10000;
      ops[1]=(valor/10000)%10000;
      ops[2]=(valor/100000000)%10;
      ops[3]=(valor/1000000000)%10;
      ops[4]=(valor/10000000)%10;
      //Serial.println("Datos= " + String(mot[0]) + "\t" + String(mot[1]) + "\t" + String(mot[2]) + "\t" + String(mot[3]) + "\t" + String(mot[4]));
    }
    //readBuffer += char(incomingByte);       // Add each byte to ReadBuffer total string variable
  }
  delay(22); //This delay has to be equal or higher than the dalay in transmitter
  //X_val = readBufferX.toInt(); //Pass the data from string to int so we could use it
/* if(mot[3]!=0){
   Serial.print(String(mot[0]));
  // Serial.print("\t");
   Serial.println(String(mot[1]));  
 }*/
  
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
}//End of void loop