/*
Version: 0.1
This code was written by Grook.net
Please feel free to edit/add any thing to the code but email it back to us for sharing it 
www.grook.net
http://www.youtube.com/GROOKnet
https://www.facebook.com/GROOKnet
*/


#define ECHOPIN 7        // Pin to receive echo pulse 
#define TRIGPIN 8
#include <Servo.h>

Servo myservo; // create servo object to control a servo
int pos = 0; // variable to store the servo position
void setup() {
 Serial.begin(9600); 

  myservo.attach(9); // attaches the servo on pin 9 to the servo object
  pinMode(3,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,INPUT);
  pinMode(ECHOPIN, INPUT); 
  pinMode(TRIGPIN, OUTPUT); 
}

void Print (int R , int T)
{
   Serial.print(R);Serial.print(", ");
   Serial.print(T);Serial.println(".");
   delay(100);
}

float Distance () {
  
  digitalWrite(TRIGPIN, LOW); 
  delayMicroseconds(2); 
  digitalWrite(TRIGPIN, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(TRIGPIN, LOW);
  // Distance Calculation
  
  float distance = pulseIn(ECHOPIN, HIGH,30000); 
  //Serial.println(distance);
  distance= distance/(58.138); 
  return(distance);
}

void loop() {
  
   myservo.write(30); // tell servo to go to position in variable 'pos'
  
 
  delay(200);
  
  
  for(pos = 30; pos <= 160; pos += 1) // goes from 45 degrees to 135 degrees
  { // in steps of 1 degree
    myservo.write(pos); // tell servo to go to position in variable 'pos'
    
  Print(Distance() , pos);    
    delay(5); // waits 15ms for the servo to reach the position
  }
  delay(100);
    
    
  for(pos = 160; pos>=30; pos-=1) // goes from 135 degrees to 45 degrees
  {
    myservo.write(pos); // tell servo to go to position in variable 'pos'
      Print(Distance() , pos);    

    delay(5); // waits 15ms for the servo to reach the position
  }  
  

  
}


