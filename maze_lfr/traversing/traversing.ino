
#define ls1    13
#define ls2    12
#define ls3    10
#define rs1    11
#define rs2    9
#define rs3    8

#define lmen    6
#define rmen    5

#define ledR    A1
#define ledG    A2
#define ledB    A3

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
int ch=1;
int sg=0;
int gridno=1;
int sgrid[5]={};
void setup()
{  
  pinMode(ls1, INPUT);
  pinMode(ls2, INPUT);
  pinMode(ls3, INPUT);
  pinMode(rs1, INPUT);
  pinMode(rs2, INPUT);

  
  pinMode(lmen, OUTPUT);
  pinMode(rmen, OUTPUT);
  
    
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);

  analogWrite(5,170);
  analogWrite(6,165);
  
  pinMode(led, OUTPUT);
  Serial.begin(9600);
                      
 
 forward();
 delay(400);
 
blinkled();
  }


void loop()
{                                                                                    

 
 //forward();
 
 readSensors();    
 if(l1==0&&l2==0&&r1==0&&r2==0)
  {if(l3==1)
    {blinkled();
    sgrid[sg]=gridno;
    sg++;}
  gridno++;
  }
 
}





void forward()
{Serial.println("forr");
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























void readsense()
{
  l1  = digitalRead(ls1);
  l2    = digitalRead(ls2);
  l3     = digitalRead(ls3);
  r1 = digitalRead(rs1);
  r2  = digitalRead(rs2);
  r3  = digitalRead(rs3);
}

void rightgo()
{
  do{
    sright();
    readsense();
  }while(!((l3==0)&&(l2==1)&&(l1==1)&&(r1==0)&&(r2==1)&&(r3==1)));
 delay(1);
forward();
delay(150);
  do{
    sright();
    readsense();
  }while(!((l3==0)&&(l2==1)&&(l1==1)&&(r1==0)&&(r2==1)&&(r3==1)));

 
 do{
  forward();
  delay(2);
  if(l2==0)
  sleft();
  else if(r1==0)
  sright();
  if(l1==0&&l2==0&&r2==0&&r3==0)
  {if(l3==1&&r1==1)
    {blinkled();
    sgrid[sg]=gridno;
    sg++;}
  gridno++;
  }

    
    
    readsense();
  }while(!((l3==1)&&(r1==1)&&(l2==1)&&(l1==1)&&(r2==1)&&(r3==1)));

}


void leftgo()
{
  do{
    sleft();
    readsense();
  }while(!(l3==0&&(l2==1)&&(l1==1)&&(r1==0)&&(r2==1)&&(r3==1)));
 delay(1);
forward();
delay(350);
  do{
    sleft();
    readsense();
  }while(!(l3==0&&(l2==1)&&(l1==1)&&(r1==0)&&(r2==1)&&(r3==1)));

 
 
 do{
  forward();
  delay(2);
  if(l2==0)
  sleft();
  else if(r1==0)
  sright();
  if(l1==0&&l2==0&&r2==0&&r3==0)
  {if(l3==1&&r1==1)
    {blinkled();
    sgrid[sg]=gridno;
    sg++;}
  gridno++;
  }
  
    readsense();
  }while(!((l3==1)&&(r1==1)&&(l2==1)&&(l1==1)&&(r2==1)&&(r3==1)));

}



void readSensors()
{
 if(ch==6)
 {
  stopp();
  checkforled();
 }
  
 else if(ch%2==1)
{
  rightgo();
  ch++;}
 else 
 {
  leftgo();
  ch++;
 }
 
}

void checkforled()
{
 if(sg==3)
 {//blue triangle
   digitalWrite(ledB,HIGH);
  
 }
 else if(sg==4)
 {
  if((sgrid[0]==1&&sgrid[1]==2&&sgrid[2]==7&&sgrid[3]==8)||(sgrid[0]==2&&sgrid[1]==3&&sgrid[2]==9&&sgrid[3]==9))
  {//green rectangle
 
 digitalWrite(ledG,HIGH);
  
  }
  else if (sgrid[0]==1&&sgrid[1]==3&&sgrid[2]==7&&sgrid[3]==9)
  {//red square
    
  digitalWrite(ledR,HIGH);
  
  }
 }
}
void blinkled()
{
  digitalWrite(ledB,HIGH);
  delay(500);
  digitalWrite(ledB,LOW);
}

