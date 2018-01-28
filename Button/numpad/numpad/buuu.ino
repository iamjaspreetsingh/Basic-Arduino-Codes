int in1=3,in2=4,o1=5,o2=6;
int ch=0;
void setup() {
  // put your setup code here, to run once:
pinMode(3,INPUT_PULLUP);
pinMode(4,INPUT_PULLUP);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
Serial.begin(9600);
}
int cb,lb=0;
void loop() {
  // put your main code here, to run repeatedly:
 cb=button();
if(lb!=cb)
if(cb!=0)
Serial.println(cb);
lb=cb;

}

int button()
{
  digitalWrite(o1,HIGH);
digitalWrite(o2,HIGH);
  
digitalWrite(o1,LOW);
if(digitalRead(in1)==LOW)
{
if(ch!=1)
  return(1);
ch=1;}
else if(digitalRead(in2)==LOW)
{if(ch!=2)
  return(2);
  ch=2;
}
digitalWrite(o1,HIGH);
digitalWrite(o2,LOW);
if(digitalRead(in1)==LOW)
{if(ch!=3)
  return(3);
  ch=3;
}
else if(digitalRead(in2)==LOW)
{if(ch!=4)
  return(4);
  ch=4;
}

return(0);
}

