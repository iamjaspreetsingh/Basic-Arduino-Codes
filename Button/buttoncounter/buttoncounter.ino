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
 {if(digitalRead(2)==1) 
  {i++;
Serial.println(i);}
  
  }
}
