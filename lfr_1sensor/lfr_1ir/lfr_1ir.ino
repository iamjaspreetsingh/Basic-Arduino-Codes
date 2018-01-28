int in1=10,in2=4,in11=11,in22=5,i=3;
unsigned int premilli=0;
int w1;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in11,OUTPUT);
pinMode(in22,OUTPUT);
pinMode(i,INPUT);
}
int z;
void loop() {
  z=digitalRead(i);
  


if(z==1){
  
  while(z==1)
  {z=digitalRead(i);
  
  int a=millis()-premilli;
  if(a<1000)
  {
    left();
  
  Serial.println(a);
  }
  else {
    right();
 
  }
  }
}
else 
if(z==0)
{ 
  while(z==0){
    z=digitalRead(i);
    forward();
    delay(50);
    premilli=millis();
}
} 


}
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



