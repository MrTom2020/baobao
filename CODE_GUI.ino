#include <DHT.h>
#include <MQ135.h> 
#include <SharpGP2Y10.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(6, 7); // 6 là Tx, 7 là Rx
String myStr1, myStr2, myStr3, myStr4; 

const int DHTPIN = A3;      
const int DHTTYPE = DHT22;
DHT dht(DHTPIN, DHTTYPE);
#define PIN_MQ135 A2
MQ135 mq135_sensor = MQ135(PIN_MQ135);
int measurePin = A0;          
int ledPower = 2;            
int samplingTime = 280; 
int deltaTime = 40;
int sleepTime = 9680;
float voMeasured = 0;            
float calcVoltage = 0;      
float dustDensity = 0;  

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  dht.begin();
  pinMode(ledPower,OUTPUT);
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  float ppm = mq135_sensor.getPPM();
  digitalWrite(ledPower,LOW);        
  delayMicroseconds(samplingTime);   
  voMeasured = analogRead(measurePin); 
  delayMicroseconds(deltaTime);         
  digitalWrite(ledPower,HIGH);          
  delayMicroseconds(sleepTime);       
  calcVoltage = voMeasured*(5.0/1024);  
  dustDensity = 0.17*calcVoltage+0.1;  

  myStr1 = String(t); 
  myStr2 = String(h);
  myStr3 = String(ppm); 
  myStr4 = String(dustDensity);
  myStr1 = myStr1 += " " + myStr2 += " " + myStr3 += " " + myStr4;
  Serial.println(t);
  Serial.println();
  Serial.println(h);
  Serial.println();
  Serial.println(ppm);
  Serial.println();
  Serial.println(dustDensity);
  Serial.println();
  Serial.println(myStr1);
  mySerial.println(myStr1);
  delay(5000);
  
}
