#include<SoftwareSerial.h>
SoftwareSerial mat(2, 3);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  mat.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (mat.available()>=3)
  { 
    int i = mat.parseInt();
    int j = mat.parseInt();
    int k = mat.parseInt();
    Serial.print(i);
    Serial.print(" ");
    Serial.print(j);
    Serial.print(" ");
    Serial.println(k);
    analogWrite(11, i);
    analogWrite(9, j);
    analogWrite(10, k);
  }
}
