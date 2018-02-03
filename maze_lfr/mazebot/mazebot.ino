
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


#define lm1  2   //Speed
#define lm2  3   //Direction

#define rm1 4   //Speed
#define rm2 7   //Direction

#define led 5

char path[30] = {};
int pathLength;
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
//analogWrite(6,200);

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
 
//00__11
if(((l1==0)&&(l2==0))&&(r3==1)&&(r2==1))
{
  left();
  delay(150);
}

//110011
else if(((l3==0)||(r1==0  ))&&(l2==1)&&(l1==1)&&(r3==1)&&(r2==1))
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
//11__00
else if(((r3==0)&&(r2==0))&&(l2==1)&&(l1==1))
{
  right();
  delay(150);

}

else stopp();
  
}

