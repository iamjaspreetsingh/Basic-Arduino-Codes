int in1=10,in2=4,in11=11,in22=5;
#include<SoftwareSerial.h>
SoftwareSerial bt(2,3);
int w1;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
bt.begin(9600);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in11,OUTPUT);
pinMode(in22,OUTPUT);
pinMode(6,OUTPUT);
pinMode(9,OUTPUT);
pinMode(2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
 { 
  char w=bt.read();

w1=Serial.parseInt();
 if(w1!=NULL)
{Serial.println(w1);
 analogWrite(6,w1);
analogWrite(9,w1);
}
  if(w=='f')
forward();
else if(w=='b')
back();
else if(w=='l')
left();
else if(w=='r')
right();
else if(w=='s')
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

