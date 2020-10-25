/** Voice controlled house lights with Google Assitant
 *  Instructable contest
 *  Mridul Mahajan
 */
/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

 */
#define BLYNK_PRINT Serial
#define EspSerial Serial1

#include <SoftwareSerial.h>
#include<SPI.h>
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

// You should get Auth Token in the Blynk App.
char auth[] = "Your auth code";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "your wifi ssid";
char pass[] = "password of your wifi";


SoftwareSerial EspSerial(2, 3); // RX, TX of ESP8266

String s;    //to store incoming text ingredient

BLYNK_WRITE(V0)     // it will run every time a string is sent by Blynk app
{
  s=param.asStr();
  Serial.print(s); //string sent by Blynk app will be printed on Serial Monitor
   if(s=="on")
  {
    digitalWrite(7, LOW);       //Pin 7 has been set in setup()
  }
  else if(s=="off")
  {
    digitalWrite(7, HIGH);
  }
  else{
    Serial.print("Say on or off");
  }
}
// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600

ESP8266 wifi(&EspSerial);

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(7,OUTPUT);       //Pin 7 is set to output
  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);
 
  Blynk.begin(auth, wifi, ssid, pass);
}

void loop()
{
  Blynk.run();
}

