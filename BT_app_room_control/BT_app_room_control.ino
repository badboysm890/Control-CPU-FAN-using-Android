
#include <SimpleDHT.h>


int fans=12;
int sys=13;
int pc=7;

int Received=0;
int light_state =0;
int vent_state = 0;
int pc_state = 0;
int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);

void setup(){
  
  Serial.begin(9600);
  
  pinMode(sys,OUTPUT);
  pinMode(pc,OUTPUT);
  
}

void loop(){
 digitalWrite(8,HIGH);
 if(Serial.available()>0)
 { 
    Received = Serial.read();
    
 }
 
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
  
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");
  
  
if (Received == '1')
  {
    digitalWrite(sys,HIGH);
    Received=0;  
    Serial.write("ON");
  }
if (Received == '2')
  {
    digitalWrite(sys,LOW);
    Received=0;
    Serial.write("off");
  }
if (Received == '3')
 {
  Serial.write("Fans Are ramping Up Put on headset");
  digitalWrite(sys,HIGH);
  Received=0;
 }
if (Received == '4')
{
  Serial.write("Silent Mode Activated");
  digitalWrite(sys,LOW);
  Received=0; 
}
if (Received == '5')
{
  if(temperature > 50)
  {
    digitalWrite(sys,HIGH);
    Serial.write("AutoMatic Mode");
  }
  else
  {
    digitalWrite(sys,LOW);
  }
}
delay(1500);
} 
 
