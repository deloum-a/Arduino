/*
** This code is fork from Thomas Conté's Blog :
** See the original article here: http://hypernephelist.com/2014/07/11/arduino-uno-azure-mobile-services.html
**
** Antoine Deloume, Alexandre Ghiazza, Victor Solevic
** CSULB 2015
*/
 
#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDC, 0xAB, 0xBA, 0xE9, 0xF8, 0x7D };      // CHANGE THIS
const char *server = "arduino-uno-test.azure-mobile.net"; // CHANGE THIS
const char *table_name1 = "temperature";  // A0
const char *table_name2 = "sound";        // A1
const char *table_name3 = "telemetry";    // A2
const char *ams_key = "FTlxxxxIvTdWxxxxxxICXIxxxxxx94";   // CHANGE THIS

EthernetClient client;
char buffer[64];
 
/*
** Send an HTTP POST request to the Azure Mobile Service data API
*/
 
void send_request(int value, const char *table_name)
{
  Serial.println("\nconnecting...");
 
  if (client.connect(server, 80)) {
 
    Serial.print("sending ");
    Serial.print(value);
    Serial.print(" to ");
    Serial.println(table_name);
    
 
    // POST URI
    sprintf(buffer, "POST /tables/%s HTTP/1.1", table_name);
    client.println(buffer);
 
    // Host header
    sprintf(buffer, "Host: %s", server);
    client.println(buffer);
 
    // Azure Mobile Services application key
    sprintf(buffer, "X-ZUMO-APPLICATION: %s", ams_key);
    client.println(buffer);
 
    // JSON content type
    client.println("Content-Type: application/json");
 
    // POST body
    sprintf(buffer, "{\"value\": %d}", value);
 
    // Content length
    client.print("Content-Length: ");
    client.println(strlen(buffer));
 
    // End of headers
    client.println();
 
    // Request body
    client.println(buffer);
    
  } else {
    Serial.println("connection failed");
  }
}
 
/*
** Wait for response
*/
 
void wait_response()
{
  while (!client.available()) {
    if (!client.connected()) {
      return;
    }
  }
}
 
/*
** Read the response and dump to serial
*/
 
void read_response()
{
  bool print = true;
  
  while (client.available()) {
    char c = client.read();
    // Print only until the first carriage return
    if (c == '\n')
      print = false;
    if (print)
      Serial.print(c);
  }
}
 
/*
** Close the connection
*/
 
void end_request()
{
  client.stop();
}
 
/*
** Arduino Setup
*/
 
void setup()
{
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect.
  }
 
  Serial.println("ethernet");
 
  if (Ethernet.begin(mac) == 0) {
    Serial.println("ethernet failed");
    for (;;) ;
  }
  // give the Ethernet shield a second to initialize:
  delay(1000);
}
 
/*
** Arduino Loop
*/
 
void loop()
{
  digitalWrite(7, HIGH);

  // temperature
  int val1 = analogRead(A0);
  send_request(val1, table_name1);
  wait_response();
  read_response();
  end_request();

  // sound
  int val2 = analogRead(A1);
  send_request(val2, table_name2);
  wait_response();
  read_response();
  end_request();

  // telemetry
  int val3 = analogRead(A2);
  send_request(val3, table_name3);
  wait_response();
  read_response();
  end_request();
 
  Serial.println("   ");
  digitalWrite(7, LOW);
  delay(1000);
}
