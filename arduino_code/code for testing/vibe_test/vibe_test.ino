
//int always_low = 2;
//
//int motor1pin2 = 3;
//
//int motor2pin1 = 4;
//int motor2pin2 = 5;

int pin2 = 2;
int pin3 = 3;
int pin4 = 4;
int pin5 = 5;
int pin6 = 6;
int pin7 = 7;
int pin8 = 8;
int pin9 = 9;



void setup(){

  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
  pinMode(pin4,OUTPUT);
  pinMode(pin5,OUTPUT);
  pinMode(pin6,OUTPUT);
  pinMode(pin7,OUTPUT);
  pinMode(pin8,OUTPUT);
  pinMode(pin9,OUTPUT);  
}

void loop(){

  int del = 500; // fastest is 75ms
  int longer = 75;
  digitalWrite(pin8,HIGH);
  digitalWrite(pin9,HIGH);
  delay(del);
  digitalWrite(pin7,HIGH);
  digitalWrite(pin9,LOW);
  
  digitalWrite(pin6,HIGH);
  digitalWrite(pin8,LOW);
  
  delay(del);
  digitalWrite(pin5,HIGH);
  digitalWrite(pin7,LOW);
  digitalWrite(pin4,HIGH);
  digitalWrite(pin6,LOW);
  
  delay(del);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin5,LOW);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin4,LOW);
  
  delay(del);
  digitalWrite(pin5,HIGH);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,HIGH);
  digitalWrite(pin2,LOW);
  
  delay(del);
  digitalWrite(pin7,HIGH);
  digitalWrite(pin5,LOW);
  digitalWrite(pin6,HIGH);
  digitalWrite(pin4,LOW);
  
  delay(del);
  digitalWrite(pin9,HIGH);
  digitalWrite(pin7,LOW);
  digitalWrite(pin8,HIGH);
  digitalWrite(pin6,LOW);
 
//  digitalWrite(pin8,HIGH);
//  delay(del);
//  digitalWrite(pin8,LOW);
//  digitalWrite(pin6,HIGH);
//  delay(del);
//  digitalWrite(pin6,LOW);
//  digitalWrite(pin4,HIGH);
//  delay(del);
//  digitalWrite(pin4,LOW);
//  digitalWrite(pin2,HIGH);
//  delay(longer);
//  digitalWrite(pin2,LOW);
//  digitalWrite(pin3,HIGH);
//  delay(del);
//  digitalWrite(pin3,LOW);
//  digitalWrite(pin5,HIGH);
//  delay(del);
//  digitalWrite(pin5,LOW);
//  digitalWrite(pin7,HIGH);
//  delay(del);
//  digitalWrite(pin7,LOW);
//  digitalWrite(pin9,HIGH);
//  delay(longer);
//  digitalWrite(pin9,LOW);


//  digitalWrite(pin2,HIGH);
//  delay(del);
//  digitalWrite(pin2,LOW);
//  digitalWrite(pin3,HIGH);
//  delay(del);
//  digitalWrite(pin3,LOW);
//  digitalWrite(pin4,HIGH);
//  delay(del);
//  digitalWrite(pin4,LOW);
//  digitalWrite(pin5,HIGH);
//  delay(del);
//  digitalWrite(pin5,LOW);
//  digitalWrite(pin6,HIGH);
//  delay(del);
//  digitalWrite(pin6,LOW);
//  digitalWrite(pin7,HIGH);
//  delay(del);
//  digitalWrite(pin7,LOW);
//  digitalWrite(pin8,HIGH);
//  delay(del);
//  digitalWrite(pin8,LOW);
//  digitalWrite(pin9,HIGH);
//  delay(del);
//  digitalWrite(pin9,LOW);
//  digitalWrite(pin2,HIGH);
  
  
}
