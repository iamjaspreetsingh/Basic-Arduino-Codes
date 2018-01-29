int in1=2,in2=3,in11=6,in22=7;

void setup() {
  // put your setup code here, to run once:

pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in11,OUTPUT);
pinMode(in22,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
back();
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

