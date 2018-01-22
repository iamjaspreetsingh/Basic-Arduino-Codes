#include<SoftwareSerial.h>
SoftwareSerial esp(2, 3);
void setup() {
  // put your setup code here, to run once:
esp.begin(38400);
Serial.begin(38400);

}
void loop() {
  // put your main code here, to run repeatedly:
esp.print("AT+NAME=JS\r\n");
if(esp.find("OK"))
Serial.println("ok");

}
