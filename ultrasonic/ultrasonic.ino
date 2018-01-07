void setup() {
  // put your setup code here, to run once:
Serial.begin(57600);
pinMode(3, OUTPUT);
pinMode(11, INPUT);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(3,LOW);
delayMicroseconds(2);
  digitalWrite(3,HIGH);
  delayMicroseconds(10);
  digitalWrite(3,LOW);
Serial.println(340*pulseIn(11,HIGH));

}
