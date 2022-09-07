
int state = 255;
int prevState = 0;
int del = 100;
int prevpin1 = 0;
int prevpin2 = 0;
int prevpin3 = 0;
int prevpin4 = 0;
int pulse = 100;
int timeout = 0;

const int window = 90;
const int loWindow = 80;
const int mindel = 0;

bool leftSide = false; // left side true right side false 
bool readypulse = false;

int rh = 2;     // right hand
int rfw = 3;    // right front wrist
int rfa = 6;    // right front arm
int rba = 4;    // right back arm
int rbw = 5;    // right back wrist

int lh = 8;     // left hand
int lfw = 9;    // left front wrist
int lfa = 12;   // left front arm 
int lba = 10;   // left back arm
int lbw = 11;   // left back wrist

// OLD
//int rh = 2;     // right hand
//int rfw = 3;    // right front wrist
//int rfa = 5;    // right front arm
//int rba = 6;    // right back arm
//int rbw = 4;    // right back wrist
//
//
//int lh = 8;     // left hand
//int lfw = 9;    // left front wrist
//int lfa = 11;   // left front arm 
//int lba = 12;   // left back arm
//int lbw = 10;   // left back wrist

int led = 13;

void setup(){
  Serial.begin(9600);
//  inputString.reserve(200);
//  Serial.setTimeout(100);
  
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

// 10s are for right arm walking
// 20s are for left arm walking
// 30s are for low power cop
// 40s are for high power cop
// 50s are for boundary cop

// 60-80 sideways cop
// 60s are for low power cop
// 70s are for high power cop
// 80s are for boundary cop


void loop(){

  if (Serial.available()) {
    byte incomingByte = Serial.read();
    if (incomingByte != -1){
      state = incomingByte;
      digitalWrite(led,HIGH);
      prevpin4 = led;
    }
    timeout = 0;
  }else{
    timeout++;
    if(timeout > 100000){
      state = 0;
    }
  }


  if(state == 0){ // turn off motors
    if (state != prevState){
      buzz(led,0,0,0);
    }
  }else if(state == 1){ // standby
  
    digitalWrite(prevpin1,LOW);
    digitalWrite(prevpin2,LOW);
    digitalWrite(prevpin3,LOW);
    digitalWrite(prevpin4,LOW);
    
    delay(mindel);
    if (prevState < 20 ){
      leftSide = true;
    } else{
      leftSide = false;
    }
//    prevState = state;
    if (leftSide == true){
      if(readypulse == true){
        digitalWrite(lh,HIGH);
        delay(del);
        readypulse = false;
        prevpin1 = lh;
      }else{
        delay(del);
        readypulse = true;
      }
    } else {
      if(readypulse == true){
        digitalWrite(rh,HIGH);
        delay(del);
        readypulse = false;
        prevpin1 = rh;
      }else{
        delay(del);
        readypulse = true;
      }
    }
  }else if(state == 10){ // right hand: buzz
    if (state != prevState){
      buzz(rh,0,0,0);
    }
  }else if(state == 11){ // right front wrist: right toe-off
    if (state != prevState){
      buzz(rfw,0,0,0);
    }
  }else if(state == 12){ // right front arm
    if (state != prevState){
      buzz(rfa,0,0,0);
    }
  }else if(state == 13){ // right back arm
    if (state != prevState){
      buzz(rba,0,0,0);
    }
  }else if(state == 14){ // right back wrist
    if (state != prevState){
      buzz(rbw,0,0,0);
    }
  }else if(state == 20){ // left hand: left ready
    if (state != prevState){
      buzz(lh,0,0,0);
    }
  }else if(state == 21){ // left front wrist: left toe-off
    if (state != prevState){
      buzz(lfw,0,0,0);
    }
  }else if(state == 22){ // left front arm
    if (state != prevState){
      buzz(lfa,0,0,0);
    }
  }else if(state == 23){ // left back arm
    if (state != prevState){
      buzz(lba,0,0,0);
    }
  }else if(state == 24){ // left back wrist
    if (state != prevState){
      buzz(lbw,0,0,0);
    }                                                             //SWING
  }else if(state == 15){ // hybrid walking right swing
    if (state != prevState){
      swingPulse(rfa,rba,rbw,rfw,lh);
    }
  }else if(state == 25){ // // hybrid walking left swing
    if (state != prevState){
      swingPulse(lfa,lba,lbw,lfw,rh);      
    }
  }else if(state == 16){ // stairs right swing
    if (state != prevState){
      swingPulse(rfa,rba,rbw,rfw,lh);
    }
  }else if(state == 26){ // stairs left swing
    if (state != prevState){
      swingPulse(lfa,lba,lbw,lfw,rh);   
    }
                                                                   // COP
  }else if(state == 30){ // low COP 0-45
    if (state != prevState){
      buzz(rfw,0,0,0);
    }
  }else if(state == 31){ // low COP 45-90
    if (state != prevState){
      buzz(rfw,lfw,0,0);  
    }
  }else if(state == 32){ // low COP 90-135
    if (state != prevState){
      buzz(rfw,lfw,0,0);   
    }
  }else if(state == 33){ // low COP 135-180
    if (state != prevState){
      buzz(lfw,0,0,0);
    }
  }else if(state == 34){ // low COP 180-225
    if (state != prevState){
      buzz(lbw,0,0,0);  
    }
  }else if(state == 35){ // low COP 225-270
    if (state != prevState){
      buzz(rbw,lbw,0,0);
    }
  }else if(state == 36){ // low COP 270-315
    if (state != prevState){
      buzz(rbw,lbw,0,0);
    }
  }else if(state == 37){ // low COP 315-360
    if (state != prevState){
      buzz(rfw,0,0,0);  
    }
  }else if(state == 40){ // high COP 0-45
    if (state != prevState){
      buzz(rfa,rfw,0,0); 
    }
  }else if(state == 41){ // high COP 45-90
    if (state != prevState){
      buzz(rfa,lfw,rfw,0);     
    }
  }else if(state == 42){ // // high COP 90-135
    if (state != prevState){
      buzz(lfa,rfw,lfw,0);
    }
  }else if(state == 43){ // high COP 135-180
    if (state != prevState){
      buzz(lfa,lfw,0,0);
    }
  }else if(state == 44){ // high COP 180-225
    if (state != prevState){
      buzz(lbw,lba,0,0);     
    }
  }else if(state == 45){ // high COP 225-270
    if (state != prevState){
      buzz(lba,rbw,lbw,0); 
    }
  }else if(state == 46){ // high COP 270-315
    if (state != prevState){
      buzz(rba,lbw,rbw,0);
    }
  }else if(state == 47){ // high COP 315-360
    if (state != prevState){
      buzz(rfa,rbw,0,0);
    }
  }else if(state == 50){ // boundary COP 0-45
    if (state != prevState){
      buzz(rfa,rfw,rh,0);
    }
  }else if(state == 51){ // boundary COP 45-90
    if (state != prevState){
      buzz(rfa,lfw,rh,0);
    }
  }else if(state == 52){ // // boundary COP 90-135
    if (state != prevState){
      buzz(lfa,rfw,lh,0);
    }
  }else if(state == 53){ // boundary COP 135-180
    if (state != prevState){
      buzz(lfa,lfw,lh,0);
    }
  }else if(state == 54){ // boundary COP 180-225
    if (state != prevState){
      buzz(lbw,lba,lh,0);
    }
  }else if(state == 55){ // boundary COP 225-270
    if (state != prevState){
      buzz(lba,rbw,lh,0);
    }
  }else if(state == 56){ // boundary COP 270-315
    if (state != prevState){
      buzz(rba,lbw,rh,0);
    }
  }else if(state == 57){ // boundary COP 315-360
    if (state != prevState){
      buzz(rfa,rbw,rh,0);
    }
  }else if(state == 60){ // low COP 0-45
    if (state != prevState){
      buzz(rbw,0,0,0);
    }
  }else if(state == 61){ // low COP 45-90
    if (state != prevState){
      buzz(rbw,lbw,0,0);
    }
  }else if(state == 62){ // low COP 90-135
    if (state != prevState){
      buzz(rbw,lbw,0,0);
    }
  }else if(state == 63){ // low COP 135-180
    if (state != prevState){
      buzz(lbw,0,0,0);
    }
  }else if(state == 64){ // low COP 180-225
    if (state != prevState){
      buzz(lba,0,0,0);
    }
  }else if(state == 65){ // low COP 225-270
    if (state != prevState){
      buzz(rba,lba,0,0);
    }
  }else if(state == 66){ // low COP 270-315
    if (state != prevState){
      buzz(rba,lba,0,0);
    }
  }else if(state == 67){ // low COP 315-360
    if (state != prevState){
      buzz(rba,0,0,0);
    }
  }else if(state == 70){ // high COP 0-45
    if (state != prevState){
      buzz(rfw,rbw,0,0);
    }
  }else if(state == 71){ // high COP 45-90
    if (state != prevState){
      buzz(rbw,lbw,rfw,0);
    }
  }else if(state == 72){ // high COP 90-135
    if (state != prevState){
      buzz(rbw,lbw,lfw,0);
    }
  }else if(state == 73){ // high COP 135-180
    if (state != prevState){
      buzz(lbw,lfw,0,0);
    }
  }else if(state == 74){ // high COP 180-225
    if (state != prevState){
      buzz(lfa,lbw,0,0);
    }
  }else if(state == 75){ // high COP 225-270
    if (state != prevState){
      buzz(rba,lba,lfa,0);
    }
  }else if(state == 76){ // high COP 270-315
    if (state != prevState){
      buzz(rba,lba,rfa,0);
    }
  }else if(state == 77){ // high COP 315-360
    if (state != prevState){
      buzz(rfa,rba,0,0);
    }
  }else if(state == 80){ // boundary COP 0-45
    if (state != prevState){
      buzz(rbw,rfw,rh,0);
    }

  }else if(state == 81){ // boundary COP 45-90
    if (state != prevState){
      buzz(rbw,lfw,rh,0);
    }
  }else if(state == 82){ // // boundary COP 90-135
    if (state != prevState){
      buzz(lbw,rfw,lh,0);
    }
  }else if(state == 83){ // boundary COP 135-180
    if (state != prevState){
      buzz(lbw,lfw,lh,0);
    }
  }else if(state == 84){ // boundary COP 180-225
    if (state != prevState){
      buzz(lfa,lba,lh,0);
    }
  }else if(state == 85){ // boundary COP 225-270
    if (state != prevState){
      buzz(lba,rfa,lh,0);
    }
  }else if(state == 86){ // boundary COP 270-315
    if (state != prevState){
      buzz(rba,lfa,rh,0);
    }
  }else if(state == 87){ // boundary COP 315-360
    if (state != prevState){
      buzz(rfa,rba,rh,0);
    }
  }else { // error state
    digitalWrite(prevpin1,LOW);
    digitalWrite(prevpin2,LOW);
    digitalWrite(prevpin3,LOW);
    
    delay(mindel);
    digitalWrite(led,HIGH);
    prevpin4 = led;
  }
}
