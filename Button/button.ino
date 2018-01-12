void setup() {
  // put your setup code here, to run once:
Serial.begin(57600);
pinMode(4, OUTPUT);
pinMode(2, INPUT_PULLUP);

  
}

void loop() {
  // put your main code here, to run repeatedly:
 if(digitalRead(2))
  digitalWrite(4,LOW);
  else
  digitalWrite(4,HIGH);
// floating state of Serial.println(analogRead(A1));
}
