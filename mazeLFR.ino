
//CREDIT to Patrick McCabe for the path Solving Code, visit patrickmccabemakes.com!!

#define ls1    13
#define ls2    12
#define ls3    11
#define rs1    10
#define rs2    9
#define rs3    8


#define lmen    6
#define rmen    5


int l1,l2,l3,r1,r2,r3;
unsigned int premilli=0;

#define lm1  2   //Speed
#define lm2  3   //Direction

#define rm1 4   //Speed
#define rm2 7   //Direction

#define led 5

char path[30] = {};
int pathlength=0;
int readLength;

void setup()
{  
  pinMode(ls1, INPUT);
  pinMode(ls2, INPUT);
  pinMode(ls3, INPUT);
  pinMode(rs1, INPUT);
  pinMode(rs2, INPUT);
  pinMode(rs3, INPUT);

  
  pinMode(lmen, OUTPUT);
  pinMode(rmen, OUTPUT);
  
    
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  }


void loop()
{  
 readSensors();                                                                                      
//analogWrite(5,200);
analogWrite(6,240);

Serial.println("Path : ");
for(int i=0;i<pathlength;i++)
Serial.print(path[i]);
}





void forward()
{
Serial.println("forr");
 digitalWrite(lm1,HIGH);
digitalWrite(lm2,LOW);
digitalWrite(rm1,HIGH);
digitalWrite(rm2,LOW);
}

void back()
{

  digitalWrite(lm2,HIGH);
digitalWrite(lm1,LOW);
digitalWrite(rm2,HIGH);
digitalWrite(rm1,LOW);
}

void sright()
{

Serial.println("rig");
  digitalWrite(lm1,HIGH);
digitalWrite(lm2,LOW);
digitalWrite(rm1,LOW);
digitalWrite(rm2,LOW);
}

void sleft()
{
Serial.println("lef");
digitalWrite(lm1,LOW);
digitalWrite(lm2,LOW);
digitalWrite(rm1,HIGH);
digitalWrite(rm2,LOW);
}









void left()
{
Serial.println("lefttttt");
digitalWrite(lm1,LOW);
digitalWrite(lm2,HIGH);
digitalWrite(rm1,HIGH);
digitalWrite(rm2,LOW);
}

void right()
{
Serial.println("rttttttttttt");


digitalWrite(lm1,HIGH);
digitalWrite(lm2,LOW);
digitalWrite(rm1,LOW);
digitalWrite(rm2,HIGH);

}
void stopp()
{
Serial.println("stop");

digitalWrite(lm1,LOW);
digitalWrite(lm2,LOW);
digitalWrite(rm2,LOW);
digitalWrite(rm1,LOW);
}

























void readSensors()
{
  l1  = digitalRead(ls1);
  l2    = digitalRead(ls2);
  l3     = digitalRead(ls3);
  r1 = digitalRead(rs1);
  r2  = digitalRead(rs2);
  r3   = digitalRead(rs3);  

// serial printing below for debugging purposes

 Serial.print(l1);
 Serial.print(" ");
 Serial.print(l2);
 Serial.print(" ");
 Serial.print(l3);
 Serial.print(" ");
 Serial.print(r1);
 Serial.print(" ");
 Serial.print(r2);
 Serial.print(" ");
 Serial.print(r3);
 

//110011
if(((l3==0)||(r1==0  ))&&(l2==1)&&(l1==1)&&(r3==1)&&(r2==1))
forward();

//10__11
else if(((l1==1)&&(l2==0))&&(r3==1)&&(r2==1))
sleft();

//01__11
else if(((l1==0)&&(l2==1))&&(r3==1)&&(r2==1))
sleft();

//11__01
else if(((r3==1)&&(r2==0))&&(l2==1)&&(l1==1))
sright();
//11__10
else if(((r3==0)&&(r2==1))&&(l2==1)&&(l1==1))
sright();
//110000
else if((r3==0)&&(r2==0)&&(l2==1)&&(l1==1)&&(l3==0)&&(r1==0))
{
   int a=millis()-premilli;
  if(a>1000)
  {
 forward();
delay(200);
  right();
  delay(450);
path[pathlength]='R';
  pathlength++;
premilli=0;}

}
//100000
else if(((r3==0)&&(r2==0))&&(l2==0)&&(l1==1)&&(l3==0)&&(r1==0))
{ int a=millis()-premilli;
  if(a>1000)
  {
 forward();
  delay(200);
  right();
  delay(450);
path[pathlength]='R';
  pathlength++;
premilli=0;}

}

//111100
else if(l1==1&&l2==1&&l3==1&&r1==1&&r2==0&&r3==0)
{ int a=millis()-premilli;
  if(a>1000)
  {
 
  
  forward();
  delay(200); 
  right();
  delay(450);
  path[pathlength]='R';
  pathlength++;

premilli=0;}
}
//000011
else if(l1==0&&l2==0&&l3==0&&r1==0&&r2==1&&r3==1)
{  int a=millis()-premilli;
  if(a>1000)
  {
 forward(); 
  delay(200);
  left();
  delay(450);
  path[pathlength]='L';
  pathlength++;
premilli=0;}

}
//000001
else if(l1==0&&l2==0&&l3==0&&r1==0&&r2==0&&r3==1)
{ int a=millis()-premilli;
  if(a>1000)
  {
  forward();
  delay(200); 
  left();
  delay(450);
  path[pathlength]='L';
  pathlength++;
premilli=0;}

}

//001111
else if(l1==0&&l2==0&&l3==1&&r1==1&&r2==1&&r3==1)
{ int a=millis()-premilli;
  if(a>1000)
  {
  forward();
  delay(200); 
  left();
  delay(450);
  path[pathlength]='L';
  pathlength++;
premilli=0;}

}



else stopp();
  
}

