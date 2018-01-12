int pin[]={5,6,7,8,9};
void setup() {
  // put your setup code here, to run once:
Serial.begin(57600);
pinMode(3, OUTPUT);
pinMode(11, INPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
}

void loop() {
 
  // put your main code here, to run repeatedly:
 digitalWrite(3,LOW);
 delayMicroseconds(2);
 digitalWrite(3,HIGH);
 delayMicroseconds(10);
 digitalWrite(3,LOW);
  
int x=pulseIn(11,HIGH);
Serial.println(x);
if(x>0&&x<200)
{for(int i=0;i<5;i++)
digitalWrite(pin[i],HIGH);
}
else if((x>=200)&&(x<400))
{for(int i=0;i<4;i++)
digitalWrite(pin[i],HIGH);
for(int j=4;j<5;j++)
digitalWrite(pin[j],LOW);}

else if((x>=400)&&(x<600))
{for(int i=0;i<3;i++)
digitalWrite(pin[i],HIGH);
for(int j=3;j<5;j++)
digitalWrite(pin[j],LOW);}

else if((x>=600)&&(x<800))
{for(int i=0;i<2;i++)
digitalWrite(pin[i],HIGH);
for(int j=2;j<5;j++)
digitalWrite(pin[j],LOW);}

else if((x>=800)&&(x<1000))
{digitalWrite(pin[0],HIGH);
for(int j=1;j<5;j++)
digitalWrite(pin[j],LOW);
}
else 
for(int i=0;i<5;i++)
digitalWrite(pin[i],LOW);
}
