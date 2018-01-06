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
    // put your main code here, to run repeatedly:
    for (int j = 0; j < 32; j++)
    { 
      showled(j);
      delay(100);
    }
   
  }


