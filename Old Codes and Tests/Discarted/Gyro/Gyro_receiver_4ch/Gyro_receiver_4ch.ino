
#include <SoftwareSerial.h>
SoftwareSerial HC12(12,13);              // D11 is HC-12 TX Pin, D10 is HC-12 RX Pin
#include <Servo.h>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Inputs and outputs
Servo throttle;
Servo yaw;
Servo pitch;
Servo roll;

//Used variables for receive data and control motors
byte incomingByte;
String readBuffer = "";
String readBufferX = "";
String readBufferY = "";
String readBufferW = "";
String readBufferT = "";
int X_val = 0;
int Y_val = 0;
int Yaw_val = 0;
int Throttle_val = 0;
int i = 0;
bool x_ready = false;
bool y_ready = false;
bool yaw_ready = false;
bool throttle_ready = false;
bool x_passed = false;
bool y_passed = false;
bool yaw_passed = false;
bool data_received = false;
int pwm_x = 0;
int pwm_y = 0;
int pwm_throttle = 0;
int pwm_yaw = 1500;
int pwm_roll = 1500;
int pwm_pitch = 1500;
bool first = false;

void setup() {
  throttle.attach(3);
  yaw.attach(5);
  pitch.attach(6);
  roll.attach(9);
  
  Serial.begin(9600);                     // Open serial port 
  HC12.begin(9600);                     // Open serial port to HC12

  throttle.writeMicroseconds(1000); 
  yaw.writeMicroseconds(1500); 
  pitch.writeMicroseconds(1500); 
  roll.writeMicroseconds(1500); 
  }

 
void loop() {
  //First we store the entire incoming data into "readBuffer"
  while (HC12.available()> 0) {             // If the HC-12 has data in
    incomingByte = HC12.read();             // Store the data byte by byte
    readBuffer += char(incomingByte);       // Add each byte to ReadBuffer total string variable
  }
  delay(22); //This delay has to be equal or higher than the delay in transmitter
  
  /*
  We know we first send the X angle data then the Y. So we store the number till
  we receive an "X". If "X" is received we stop adn we then get the x angle data
  till we receive an "Y".
  */
  while (i <= sizeof(readBuffer))
  {
    if(readBuffer[i] == 'X')
    {      
      x_ready = true;
    }
    if(readBuffer[i] == 'Y')
    {      
      y_ready = true;
    } 
    if(readBuffer[i] == 'W')
    {      
      yaw_ready = true;
      
    } 
    if(readBuffer[i] == 'T')
    {      
      throttle_ready = true;
      
    } 
    
    if(!x_ready)
    {      
      readBufferX = readBufferX + (readBuffer[i] );
    }
    if(x_passed && !y_ready)
    {      
      readBufferY = readBufferY + (readBuffer[i] );
    }
    if(y_passed && !yaw_ready)
    {      
      readBufferW = readBufferW + (readBuffer[i] );
    }
    if(yaw_passed && !throttle_ready)
    {      
      readBufferT = readBufferT + (readBuffer[i] );
    }

    
    if(x_ready)
    {      
      x_passed = true;
    }
    if(y_ready)
    {      
      y_passed = true;
    }
    if(yaw_ready)
    {      
      yaw_passed = true;
    }
    i=i+1;
  }
  data_received = true;
  
  X_val = readBufferX.toInt(); //Pass the data from string to int so we could use it
  Y_val = readBufferY.toInt();
  Yaw_val = readBufferW.toInt();
  Throttle_val = readBufferT.toInt();
  
  if(data_received)
  {
    ///////////////////////////////////////////////////////////////////////////
    //Uncomment the lines below if you want to print the data on serial monitor   
    //Serial.print(X_val);
    //Serial.print("  ");
    //Serial.println(Y_val);
    ///////////////////////////////////////////////////////////////////////////
    
    //Now we reset all variables
         //Reset the buffer to empty
    readBufferX = "";       //Reset the buffer to empty
    readBufferW = "";       //Reset the buffer to empty
    readBufferT = "";       //Reset the buffer to empty
    x_ready = false;        //Reset the other values
    y_ready = false;  
    yaw_ready = false;        //Reset the other values
    throttle_ready = false;        //Reset the other values
    
    x_passed = false;
    y_passed = false;
    yaw_passed = false;
    readBufferY = "";       //Reset the buffer to empty
    
    i=0;
    data_received = false;
    readBuffer = "";
    }
  

///////////////////////////////////////////////////////////////////////////
////////////////////////////front and back/////////////////////////////////
///////////////////////////////////////////////////////////////////////////
  //Now we control the PWM signal for each output

  pwm_throttle = map (Throttle_val,0,1024,1000,2000);
  pwm_yaw = map (Yaw_val,0,1024,1000,2000);
  pwm_roll = map (X_val,-60,60,1000,2000);    //We give a maximum angle of 60 degrees
  pwm_pitch = map (Y_val,-60,60,1000,2000);

  //Serial.println(pwm_yaw);
///////  
  Serial.print("X: ");
  Serial.print(X_val);
  Serial.print("\t");
  Serial.print("Y: ");
  Serial.print(Y_val);
  Serial.print("\t");
  Serial.print("W: ");
  Serial.print(Yaw_val);
  Serial.print("\t");
  Serial.print("T: ");
  Serial.print(Throttle_val);
  Serial.println(" ");
  ////////
  throttle.writeMicroseconds(pwm_throttle); 
  yaw.writeMicroseconds(pwm_yaw); 
  roll.writeMicroseconds(pwm_roll); 
  pitch.writeMicroseconds(pwm_pitch); 
  delay(1000);
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
}//End of void loop




