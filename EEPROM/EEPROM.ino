#include"EEPROM.h"


void setup() {
  Serial.begin(9600);
  Serial.println("Enter your command: read or write");
  
}

void loop() {
  while(Serial.available()>0) {
  String com= Serial.readString();
  Serial.println(com);
  if(com.indexOf("read")>=0){
  Serial.setTimeout(10000);
  Serial.println("Enter read 'address' ");
  int address;
  EEPROM.write(3,10);
  while(address= Serial.parseInt()){
  byte b= EEPROM.read(address);
  Serial.println(b);
  }
  }
  if(com.indexOf("write")>=0){
    Serial.setTimeout(10000);
    Serial.println("First enter write 'address' ");
    int address;
    Serial.println("Enter data to be placed");
    int data;
    delay(10000);
    address= Serial.parseInt();
    data= Serial.parseInt();
    EEPROM.write(address,data);
    Serial.print("Successfully placed ");
    Serial.print(data);
    Serial.print(" on ");
    Serial.print(address);
  }
  }
}
