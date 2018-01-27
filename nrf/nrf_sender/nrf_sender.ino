#include  <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
long msg[1];
RF24 radio(9,10);//CE=9 CSN=10
const uint64_t pipe = 0xE8E8F0F0E1LL;
long i=0;
void setup(void){
 Serial.begin(115200);
 radio.begin();
 radio.stopListening();
 radio.openWritingPipe(pipe);
 delay(10);
 }
 void loop(void){
 
 msg[0] = analogRead(A0);
 if(msg[0]>850){
  msg[0] = map(msg[0],850,1023,80,180);
 }
 else if(msg[0]<650){
  msg[0] = map(msg[0],0,650,0,76);
 }
 else{
  msg[0] = 78;
 }
 bool result = radio.write(msg, 2);//2 is payload (long 2 bytes)
 Serial.println(result);
 
 }
