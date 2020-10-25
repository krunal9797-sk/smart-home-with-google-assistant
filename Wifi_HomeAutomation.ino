//Visit www.roboshala.com for more details on NodeMCU and other projects.

#include <ESP8266WiFi.h>
#define ssid "CPH1613"
#define password  "12345678"

char ssid[] = "CPH1613";
char password[] = "12345678";

 // SSID i.e. Service Set Identifier is the name of your WIFI
 // Your Wifi password, in case you have open network comment the whole statement.
 
int R1=D1; // GPIO13 or for NodeMCU you can directly write D7 
int R2=D2;
int R3=D3;
int R4=D4;
WiFiServer server(80); // Creates a server that listens for incoming connections on the specified port, here in this case port is 80.
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(R4, OUTPUT);
  
  digitalWrite(R1,HIGH);
  digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);
  digitalWrite(R4,HIGH);

  
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP()); //Gets the WiFi shield's IP address and Print the IP address of serial monitor
  Serial.println("/");
 
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
 
 
  if (request.indexOf("/Relay1On") != -1)  {
    digitalWrite(R1,LOW);
     
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("Relay 1 is ON");
      client.println("</html>");
      client.stop();
      delay(1);
  }
  if (request.indexOf("/Relay1Off") != -1)  {
    digitalWrite(R1, HIGH);
   
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("Relay 1 is OFF");
      client.println("</html>");
      client.stop();
      delay(1);
  }


  if (request.indexOf("/Relay2On") != -1)  {
    digitalWrite(R2,LOW);
    
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("Relay 2 is ON");
      client.println("</html>");
      client.stop();
      delay(1);

  }
  if (request.indexOf("/Relay2Off") != -1)  {
    digitalWrite(R2, HIGH);

      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("Relay 2 is OFF");
      client.println("</html>");
      client.stop();
      delay(1);
  }


  if (request.indexOf("/Relay3On") != -1)  {
    digitalWrite(R3,LOW);

      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("Relay 3 is ON");
      client.println("</html>");
      client.stop();
      delay(1);
  }
  if (request.indexOf("/Relay3Off") != -1)  {
    digitalWrite(R3, HIGH);

      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("Relay 3 is OFF");
      client.println("</html>");
      client.stop();
      delay(1);
  }

  if (request.indexOf("/Relay4On") != -1)  {
    digitalWrite(R4,LOW);
    
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("Relay 4 is ON");
      client.println("</html>");
      client.stop();
      delay(1);
  }
  if (request.indexOf("/Relay4Off") != -1)  {
    digitalWrite(R4, HIGH);

      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("Relay 4 is OFF");
      client.println("</html>");
      client.stop();
      delay(1);
  }

}
