void setup() {
  // put your setup code here, to run once:
Serial.begin(57600);
pinMode(4, OUTPUT);
pinMode(2, INPUT_PULLUP);

  
}
int i=0;
void loop() {
  
  // put your main code here, to run repeatedly:
 if(digitalRead(2)==0)
 { if((i%2)==0)
 digitalWrite(4,LOW);
  else
 { digitalWrite(4,HIGH);}
  i++;
  }
// floating state of Serial.println(analogRead(A1));
}
