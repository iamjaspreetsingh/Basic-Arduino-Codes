#include <SPI.h> 
#include <Servo.h>
#include "nRF24L01.h"
#include "RF24.h"
int in1=2,in2=3,in11=6,in22=7;
Servo s;
char aa;
byte msg[1];

RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E420;

void setup(void){

pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in11,OUTPUT);
pinMode(in22,OUTPUT);

  s.attach(5);
  s.write(78);
 Serial.begin(115200);
 delay(100);
 radio.begin();
 radio.openReadingPipe(1,pipe);
 radio.startListening();
  delay(10);
 }
 void loop(){
  
  if (radio.available()){
    bool done = radio.read(msg, 1);  
    byte a=msg[0];
  
    Serial.write(a);
aa=a;




 if(aa=='f')
forward();
else if(aa=='b')
back();
else if(aa=='r')
left();
else if(aa=='l')
right();
else if(aa=='s')
stopp();






}}

void forward()
{
  digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
digitalWrite(in11,HIGH);
digitalWrite(in22,LOW);
}

void back()
{
  digitalWrite(in2,HIGH);
digitalWrite(in1,LOW);
digitalWrite(in22,HIGH);
digitalWrite(in11,LOW);
}

void left()
{
  digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
digitalWrite(in11,LOW);
digitalWrite(in22,HIGH);
}

void right()
{
  digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
digitalWrite(in11,HIGH);
digitalWrite(in22,LOW);
}
void stopp()
{
digitalWrite(in1,LOW);
digitalWrite(in2,LOW);
digitalWrite(in22,LOW);
digitalWrite(in11,LOW);
}






   
 
    
 

