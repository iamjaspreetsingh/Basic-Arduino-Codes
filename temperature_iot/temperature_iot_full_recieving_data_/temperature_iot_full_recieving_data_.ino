#include<SoftwareSerial.h>
#define baudrate 115200
SoftwareSerial esp(2, 3); // 2 as Rx 3 as Tx
#define SSID "Google"
#define PASS "11111111"
#define IP "184.106.153.149" // thing speak ip address: 184.106.153.149

// GET /update?key=[THINGSPEAK_KEY]&field1=[data 1]&field2=[data 2]...;
String GET = "GET /channels/402782/fields/1.json?api_key=SK4AD2L8YEO9P9LU&results=1";
// channels/402786/fields/1.json?api_key=U6N8EJUE95O21GG5&results=2

void setup() {
  pinMode(A0, INPUT);
  pinMode(12, OUTPUT);
  esp.begin( baudrate );
  Serial.begin( baudrate );
  check:
  sendSerial("AT");
  delay(5000);
  if (esp.find("OK"))
  {
    Serial.println("RECEIVED: OK\nData ready to sent!");
    connectWiFi();
  }
  else
  {
    goto check;
  }
}

void loop()
{
start:
 updatevalues("100");
}
//----- update the  Thingspeak string
void updatevalues( String T)
{
  // ESP8266 Client
  String cmd = "AT+CIPSTART=\"TCP\",\"";// Setup TCP connection
  cmd += IP;
  cmd += "\",80";
  sendSerial(cmd);
  delay(2000);
  if ( esp.find( "Error" ) )
  {
    Serial.print( "RECEIVED: Error\nExit1" );
    return;
  }

  cmd = GET ;//+ "&field1=" + T + "\r\n";
  esp.print( "AT+CIPSEND=" );
  esp.println( cmd.length() );
  if (esp.find( ">" ) )
  {
    Serial.print(">");
    Serial.print(cmd);
    esp.print(cmd);
    if(esp.available())
    Serial.println(Serial.parseInt());

  }
  else
  {
    sendSerial( "AT+CIPCLOSE" );//close TCP connection
  }
  if ( esp.find("OK") )
  {
    Serial.println( "RECEIVED: OK" );
  }
  else
  {
    Serial.println( "RECEIVED: Error\nExit2" );
  }
}

void sendSerial(String cmd)
{
  Serial.print("SEND: ");
  Serial.println(cmd);
  esp.println(cmd);
  }

boolean connectWiFi()
{
  esp.println("AT+CWMODE=1");//WiFi STA mode - if '3' it is both client and AP
  delay(5000);
  //Connect to Router with AT+CWJAP="SSID","Password";
  // Check if connected with AT+CWJAP?
  String cmd = "AT+CWJAP=\""; // Join accespoint
  cmd += SSID;
  cmd += "\",\"";
  cmd += PASS;
  cmd += "\"";
  sendSerial(cmd);
  delay(5000);
  if (esp.find("OK"))
  {
    Serial.println("RECEIVED: OK");
    return true;
  }
  else
  {
    Serial.println("RECEIVED: Error");
    return false;
  }
  cmd = "AT+CIPMUX=0";// mutiplexing off
  sendSerial( cmd );
  if ( esp.find( "Error") )
  {
    Serial.print( "RECEIVED: Error" );
    return false;
  }
}
