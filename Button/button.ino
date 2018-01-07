void setup() {
  // put your setup code here, to run once:
Serial.begin(57600);
pinMode(10, OUTPUT);
pinMode(3, INPUT_PULLUP);

  
}

void loop() {
  // put your main code here, to run repeatedly:
 if(digitalRead(3))
  digitalWrite(10,HIGH);
  else
  digitalWrite(10,LOW);
// floating state of Serial.println(analogRead(A1));
}
