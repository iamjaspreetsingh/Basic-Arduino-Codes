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
    int t=0,z;
    // put your main code here, to run repeatedly:
   for (int i = 1; i <= 4;i++)
    { z=1;
    for (int j=i; j<=4 ;j++)
    { 
    showled(t|z);
    z=z<<1;
    }
    
    z=z>>1;
    t=t|z;
    }
     
  }

  
