int del = 1000;

int rh = 2;     // right hand
int rfw = 3;    // right front wrist
int rfa = 5;    // right front arm
int rba = 6;    // right back arm
int rbw = 4;    // right back wrist

int lh = 8;     // left hand
int lfw = 9;    // left front wrist
int lfa = 11;   // left front arm 
int lba = 12;   // left back arm
int lbw = 10;   // left back wrist

void setup() {
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);  
  pinMode(10,OUTPUT);  
  pinMode(11,OUTPUT);  
  pinMode(12,OUTPUT);  
  pinMode(13,OUTPUT);  

}


void loop() {
  

//  for (int pulse = 100; pulse >= 10 ; pulse=pulse-5){
//    digitalWrite(lfa,LOW);
//    digitalWrite(lba,HIGH);
//    delay(pulse);
//    digitalWrite(lfa,HIGH);
//    digitalWrite(lba,LOW);
//    delay(pulse);
////    if (pulse < window and pulse > loWindow){
////      digitalWrite(lh,HIGH);
////      delay(pulse);
////      digitalWrite(lh,LOW);
////    }
//  }
  delay(1000);
  digitalWrite(lba,HIGH);
  digitalWrite(lfa,HIGH);
  digitalWrite(lbw,HIGH);
  digitalWrite(lfw,HIGH);
  delay(1000);
  

//  digitalWrite(lh,LOW);
  digitalWrite(lfa,LOW);
  digitalWrite(lba,LOW);
  digitalWrite(lfw,LOW);
  digitalWrite(lbw,LOW);

//  digitalWrite(rbw,HIGH);
//  digitalWrite(rfw,HIGH);
//  delay(200);
//  digitalWrite(rbw,LOW);
//  digitalWrite(rfw,LOW);

//  digitalWrite(prevpin,LOW);
  delay(2000);
//  prevState = state;
 


}
