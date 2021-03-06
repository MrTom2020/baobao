#include <SoftwareSerial.h>
SoftwareSerial mySerial(1, 3);    // 1 là TX, 3 là RX
#include <string.h>
String myStr1, myStr2, myStr3, myStr4; 
float t, h, ppm, dustDensity;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
 if (Serial.available()>0) { 
    myStr1 = Serial.readString();
    Serial.println(myStr1);
 }
  t = myStr1.toInt();
  h = myStr2.toInt();
  ppm = myStr3.toInt();
  dustDensity = myStr4.toInt();
  Serial.println(t);
  Serial.println();
  Serial.println(h);
  Serial.println();
  Serial.println(ppm);
  Serial.println();
  Serial.println(dustDensity);
  Serial.println();
  delay(5000);
}
