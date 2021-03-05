#include <Blynk.h>

#include <SPI.h>
#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>

// WiFi parameters to be configured
const char* ssid = "7577";
const char* password = "12345678";
char auth[]="628XCrjnQjvTX_Z0b1uWfEmz3U6CmGKD";


void setup() {

 Serial.begin(9600);
 while (!Serial){
  ;}

   WiFi.begin(ssid, password);

  // while wifi not connected yet, print '.'
  // then after it connected, get out of the loop
  while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.print(".");
  }
  //print a new line, then print WiFi connected and the IP address
  Serial.println("");
  Serial.println("WiFi connected");
  // Print the IP address
  Serial.println(WiFi.localIP());
  Blynk.begin(auth,ssid,password);
  
}

void loop() {
 
if(Serial.available()){
    Serial.write(Serial.read());
//    Serial.println(Serial.read());
    Blynk.notify( "Raining");
  
  }
//  else   {
//  Blynk.notify("Access Denied");
//   Serial.println(" Access denied");
//       digitalWrite(ledPin, HIGH);
//     ledOn = true; 
//    delay(3000);
//  }
}
