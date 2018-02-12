

//CREDIT to Patrick McCabe for the path Solving Code, visit patrickmccabemakes.com!!

#define ls1    13
#define ls2    12
#define ls3    10
#define rs1    11
#define rs2    9
#define rs3    8

int j=0;

#define lmen    6
#define rmen    5


int l1,l2,l3,r1,r2,r3;
unsigned int premilli=0;

#define lm1  2   
#define lm2  3   

#define rm1 4  
#define rm2 7   


char path[30] = {};
int pathlength=0;
int readLength;
int replaystage=0;

void setup()
{  
  pinMode(ls1, INPUT);
  pinMode(ls2, INPUT);
  pinMode(ls3, INPUT);
  pinMode(rs1, INPUT);
  pinMode(rs2, INPUT);
  pinMode(rs3, INPUT);

  
  pinMode(A5, INPUT_PULLUP);

  pinMode(lmen, OUTPUT);
  pinMode(rmen, OUTPUT);
  
    
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  Serial.begin(9600);
                      
 
   //left();
  //delay(1420);
 //stopp();
  
  
  }


void loop()
{                                                                                    
analogWrite(5,160);
analogWrite(6,156);
 
 
if(!(digitalRead(A5)))
{replaystage=1;
//shorten();
Serial.println("REPLAYYYYYYYYY : ");

}
 readSensors();    

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























void readsense()
{
  l1  = digitalRead(ls1);
  l2    = digitalRead(ls2);
  l3     = digitalRead(ls3);
  r1 = digitalRead(rs1);
  r2  = digitalRead(rs2);
  r3   = digitalRead(rs3);  
Serial.print(l1);
Serial.print(l2);
Serial.print(l3);
Serial.print(r1);
Serial.print(r2);
Serial.print(r3);
Serial.println("a");}

void readSensors()
{
  readsense();
 

//11(0/0)11
if(((l3==0)||(r1==0  ))&&(l2==1)&&(l1==1)&&(r3==1)&&(r2==1))
forward();

//000000
else if(l1==0&&l2==0&&l3==0&&r1==0&&r2==0&&r3==0)
{ 
  if(replaystage==0)
  checkstopp();

  else
  {
    if(path[j]=='L')
    {
      checkstrtforleft();
    }
    else if(path[j]=='S')
    {
      forward();
      delay(300);
    }
    else if(path[j]=='R')
    {
      checkstrtforright();
    }
  j++;
  }

  
}
//000011
else if(l1==0&&l2==0&&l3==0&&r1==0&&r2==1&&r3==1)
{  int a=millis()-premilli;
  do{
  left();
  
  readsense();
  }while(!((l3==0||r1==0)&&l1==1&&l2==1&&r2==1&&r3==1));
   
}
//000001
else if(l1==0&&l2==0&&l3==0&&r1==0&&r2==0&&r3==1)
{ int a=millis()-premilli;
  
  do{
  left();
  
  readsense();
  }while(!((l3==0||r1==0)&&l1==1&&l2==1&&r2==1&&r3==1));
   
   
}

//001111
else if(l1==0&&l2==0&&l3==1&&r1==1&&r2==1&&r3==1)
{ do{
  left();
  
  readsense();
  }while(!((l3==0||r1==0)&&l1==1&&l2==1&&r2==1&&r3==1));
  
}

//000111
else if(l1==0&&l2==0&&l3==0&&r1==1&&r2==1&&r3==1)
{ do{ 
  left();
  readsense();
  }while(!(l1==1&&l2==1&&(l3==0||r1==0)&&r2==1&&r3==1));
  
  
}

//111000
else if((r1==0)&&(r2==0)&&(r3==0)&&(l1==1)&&(l2==1)&&(l3==1))
{
  move1ft();
readsense();
if(((l3==0)||(r1==0  ))&&(l2==1)&&(l1==1)&&(r3==1)&&(r2==1))
{
  
  move1ft();
  
 path[pathlength]='S';
  pathlength++;

}
else if((r3==1)&&(r2==1)&&(l2==1)&&(l1==1)&&(l3==1)&&(r1==1))
{  bck1ft();
  
 path[pathlength]='R';
  pathlength++;

   int a=millis()-premilli;
do{
  right();

  readsense();
  }while(!((l3==0||r1==0)&&l1==1&&l2==1&&r2==1&&r3==1));
}}

//110000
else if((r3==0)&&(r2==0)&&(l2==1)&&(l1==1)&&(l3==0)&&(r1==0))
{ move1ft();
readsense();
if(((l3==0)||(r1==0  ))&&(l2==1)&&(l1==1)&&(r3==1)&&(r2==1))
{
  move1ft();
  
 path[pathlength]='S';
  pathlength++;

}
else if((r3==1)&&(r2==1)&&(l2==1)&&(l1==1)&&(l3==1)&&(r1==1))
{  bck1ft();

 path[pathlength]='R';
  pathlength++;

   int a=millis()-premilli;
 
}
}
//100000
else if(((r3==0)&&(r2==0))&&(l2==0)&&(l1==1)&&(l3==0)&&(r1==0))
{ move1ft();
readsense();
if(((l3==0)||(r1==0  ))&&(l2==1)&&(l1==1)&&(r3==1)&&(r2==1))
{
  move1ft();
 
 path[pathlength]='S';
  pathlength++;
 
}
else if((r3==1)&&(r2==1)&&(l2==1)&&(l1==1)&&(l3==1)&&(r1==1))
{  bck1ft();
 
 path[pathlength]='R';
  pathlength++;
 
  int a=millis()-premilli;
 
}}
//111100
else if(l1==1&&l2==1&&l3==1&&r1==1&&r2==0&&r3==0)
{ move1ft();
readsense();
if(((l3==0)||(r1==0  ))&&(l2==1)&&(l1==1)&&(r3==1)&&(r2==1))
{
  move1ft();
  
 path[pathlength]='S';
  pathlength++;
}
else if((r3==1)&&(r2==1)&&(l2==1)&&(l1==1)&&(l3==1)&&(r1==1))
{  bck1ft();
  int a=millis()-premilli;
  
  
 path[pathlength]='R';
  pathlength++;
 }
}

//01__11
else if(((l1==0)&&(l2==0))&&(r3==1)&&(r2==1))
sleft();

//10__11
else if(((l1==1)&&(l2==0))&&(r3==1)&&(r2==1))
sleft();

//11__01
else if(((r3==1)&&(r2==0))&&(l2==1)&&(l1==1))
sright();

//11__10
else if(((r3==0)&&(r2==1))&&(l2==1)&&(l1==1))
sright();

//111111
else if(l1==1&&l2==1&&l3==1&&r1==1&&r2==1&&r3==1)
{ 
  int a=millis()-premilli;
  
    do{
  left();
  readsense();
  if(((l3==0||r1==0)&&l1==1&&l2==1&&r2==1&&r3==1))
  {forward();
  delay(5);
  break;
  }
  }
while((!((l3==0||r1==0)&&l1==1&&l2==1&&r2==1&&r3==1)));
 
  path[pathlength]='U';
  pathlength++;
  premilli=0;

  
  }




else stopp();

}

void move1ft()
{
  forward();
  delay(100);}

void bck1ft()
{do{
  back();
  readsense();

}while(!(r2==0||r3==0));


delay(2);
  
checkstrtforright();
 
}

void checkstrtforright()
{

  do{
sright();
  readsense();
}while(!((l3==0||r1==0)&&l1==1&&l2==1&&r2==1&&r3==1));

}
void checkstopp()
{
  Serial.println('checkstopp');
  
  readsense();
if((l1==0)&&(l2==0)&&(l3==0)&&(r1==0)&&(r2==0)&&(r3==0))
stopp();
else
{back();
  delay(200);
  
  do{
  back();
  
  readsense();
  }while(!(l3==0||r1==0));

  delay(2);
  checkstrtforleft();
  
  
}
}

void checkstrtforleft()
{
  
  int a=millis()-premilli;
  do{
  sleft();
  readsense();
  }while(!((l3==0||r1==0)&&l1==1&&l2==1&&r2==1&&r3==1)); 
   
  path[pathlength]='L';
  pathlength++;

}






void shorten()
{
  for(int i=1;i<pathlength-1;i++)
  {
    if(path[i]=='U'&&path[i-1]=='L')
    {
      path[i-1]='S';
      for(int j=i;j<pathlength;j++)
      path[j]=path[j+1];
      pathlength--;  
      
    }
    else 
    if(path[i]=='U'&&path[i-1]=='S')
    {
      path[i-1]='R';
      for(int j=i;j<pathlength;j++)
      path[j]=path[j+1];
      pathlength--;  
      
    }
  
  }
}


