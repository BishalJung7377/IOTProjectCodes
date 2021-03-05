#include <Servo.h>

#define relay 10
int LED = 7; //define led pin
int LDR = A1;//Set A1(Analog Input) for LDR.


Servo myservo; 
int pos = 0;  

const int sensorMin = 0; 
const int sensorMax = 1024; 


void setup() {
  myservo.attach(5); 
  Serial.begin(9600); 
  pinMode(LED, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(LDR, INPUT); 
}

void loop()
{
  int sensorReading = analogRead(A0);
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);

  int LDRValue = analogRead(LDR); //Reads the Value of LDR(light).
//  Serial.print("sensor = "); //Prints the value of LDR to Serial Monitor.
//  Serial.print(LDRValue);

  switch (range)
    {
      case 0:
         Serial.println("RAINING");
  for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
  }              
                     

        break;

case 1:
// Serial.println("NOT RAINING");
 for (pos = 90; pos <= 90; pos += 1) {
    myservo.write(pos);             
                     
 }    
       
if (LDRValue <=400) 
{
digitalWrite(LED, HIGH);
digitalWrite(relay, HIGH);
//Serial.println("It's Dark Outside; Lights status: ON");
  for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
else 
{
digitalWrite(LED, LOW);
digitalWrite(relay, LOW);
//Serial.println("It's Bright Outside; Lights status: OFF");
 for (pos = 90; pos <= 90; pos += 1) {
    myservo.write(pos);             
    delay(15);                       
  }
}
  break;
    }

  delay(1000); 
 
}
