#include <SPI.h>
#include <Servo.h>
#include "nRF24L01.h"
#include "RF24.h"

Servo s;

byte msg[1];

RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E420;

void setup(void){
  s.attach(5);
  s.write(78);
 Serial.begin(115200);
 delay(100);
 radio.begin();
 radio.openReadingPipe(1,pipe);
 radio.startListening();
  delay(10);
 }
 void loop(void){
  
  if (radio.available()){
    bool done = radio.read(msg, 1);  
    byte a=msg[0];
  
    Serial.write(a);
   
  }
    
 }

