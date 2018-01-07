int pin[]={11,10,9,8,7};
void setup() {
  // put your setup code here, to run once:

 Serial.begin(57600);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int j;
int ii=map(analogRead(A1),0,1023,0,5);
for(j=0;j<ii;j++)
digitalWrite(pin[j], HIGH);
  j=ii;
  for(;j<5;j++)
  digitalWrite(pin[j],LOW);



}
void showled(byte num)
{
  
  byte i = 1;
  for (int j = 0; j < 5; j++)
  { 
    //Serial.println(num,BIN);
    if (num & i)
      digitalWrite(pin[j], HIGH);
    else
      digitalWrite(pin[j], LOW);
    i = i << 1;
  }
}
