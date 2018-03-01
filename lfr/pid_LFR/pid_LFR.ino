

//CREDIT to JS for the path Solving Code

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
int chk=0;
#define lm1  2   
#define lm2  3   
int pre=0;
#define rm1 4  
#define rm2 7   


char path[30] = {};
int pathlength=0;
int readLength;
int replaystage=0;

int count=0;
float Kp = 72;   // Max deviation = 8-4.5 = 3.5 ||  255/3.5 = 72
float Ki = 0.00015;
float Kd = 5;

float error = 0;
float previousError = 0;
float totalError = 0;

float power = 0;

int PWM_Right, PWM_Left;

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
readsense();

}

void right()
{
Serial.println("rttttttttttt");


digitalWrite(lm1,HIGH);
digitalWrite(lm2,LOW);
digitalWrite(rm1,LOW);
digitalWrite(rm2,HIGH);
readsense();
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

}

void PID_program()
{ 
    readSensor();
    
    previousError = error; // save previous error for differential 
    error = avgSensor - 4.5; // Count how much robot deviate from center
    totalError += error; // Accumulate error for integral
    
    power = (Kp*error) + (Kd*(error-previousError)) + (Ki*totalError);
    
    if( power>255 ) { power = 255.0; }
    if( power<-255.0 ) { power = -255.0; }
    
    if(power<0) // Turn left
    {
      PWM_Right = 255;
      PWM_Left = 255 - abs(int(power));
    }
    
    else // Turn right
    {
      PWM_Right = 255 - int(power);
      PWM_Left = 255;
    }
   
}

void readSensors()
{
  readsense();
 


//000011
 if(l1==0&&l2==0&&l3==0&&r1==0&&r2==1&&r3==1)
{ 
  left();
  delay(50);
   
}
//000001
else if(l1==0&&l2==0&&l3==0&&r1==0&&r2==0&&r3==1)
{ int a=millis()-premilli;
  
  left();
  delay(50);
   
   
}

//001111
else if(l1==0&&l2==0&&l3==1&&r1==1&&r2==1&&r3==1)
{ 
  left();
  delay(50);
 
}

//000111
else if(l1==0&&l2==0&&l3==0&&r1==1&&r2==1&&r3==1)
{ 
  
  left();
  delay(50);
  
}

//111000
else if((r1==0)&&(r2==0)&&(r3==0)&&(l1==1)&&(l2==1)&&(l3==1))
{

  right();
  delay(50);
 }

//110000
else if((r3==0)&&(r2==0)&&(l2==1)&&(l1==1)&&(l3==0)&&(r1==0))
{ right();
  delay(50);
 
}
//100000
else if(((r3==0)&&(r2==0))&&(l2==0)&&(l1==1)&&(l3==0)&&(r1==0))
{ right();
  delay(50);
 
}
//111100
else if(l1==1&&l2==1&&l3==1&&r1==1&&r2==0&&r3==0)
{  right();
  delay(50);
 
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
{sright();}

//111111
else if(l1==1&&l2==1&&l3==1&&r1==1&&r2==1&&r3==1)
{ int chh=0;
  int a=millis()-premilli;
  
   
  forward();
  delay(2);
  
  }



//11(0/0)11
else if(((l3==0)||(r1==0  ))&&(l2==1)&&(l1==1)&&(r3==1)&&(r2==1))
{forward();
pre=millis();
delay(3);} 




else if(((l3==0)&&(r1==0  ))&&(l2==0)&&(l1==0)&&(r3==0)&&(r2==0))
{forward();
delay(100);
} 
else readsense();
}






















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
analogWrite(5,250);
analogWrite(6,247);
 
 
 readSensors();    
//forward();
}





