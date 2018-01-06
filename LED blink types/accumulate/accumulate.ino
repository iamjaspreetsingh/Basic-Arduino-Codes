int pin[] = {8, 9, 10, 11, 12};
int val;
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

  void setup() {
    // put your setup code here, to run once:
    Serial.begin(57600);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
  }

  void loop() {
    int c=1,i=1,next;
    // put your main code here, to run repeatedly:
   for (int j = 1; j <= 4;j++)
    { 
    for (int count=1; i <=31&&count<=6-j ;count++)
    { next=i;
    showled(i);
    Serial.println(i);
    delay(400);
    i=i+c;
    c=c*2;
    }
     i=next+1;
     c=1;
  }

  }
