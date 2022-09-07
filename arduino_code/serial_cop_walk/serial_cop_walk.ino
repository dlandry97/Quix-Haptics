
int state = 255;
int prevState = 0;
int del = 100;
int prevpin1 = 0;
int prevpin2 = 0;
int prevpin3 = 0;
int window = 90;
int loWindow = 80;

int mindel = 0;

bool leftSide = false; // left side true right side false 

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
      delay(mindel);
      digitalWrite(led,LOW);
      
    }
    if (incomingByte == 0){
      digitalWrite(led,LOW);
    } 
  }


  if(state == 0){ // low COP 0-45
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

//      digitalWrite(rfa,HIGH);
//      delay(75);
      prevpin1 = 0;
      prevpin2 = 0;
      prevpin3 = 0;
      
    }

  }else if(state == 1){ // standby
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      if (prevState < 20 ){
        leftSide = true;
      } else{
        leftSide = false;
      }
      prevState = state;

      if (leftSide == true){
        
        digitalWrite(lh,HIGH);
        delay(del);
        digitalWrite(lh,LOW);
        delay(del);
        digitalWrite(lh,HIGH);
        delay(del);
        digitalWrite(lh,LOW);
        delay(del);
        digitalWrite(lh,HIGH);
        delay(del);
        digitalWrite(lh,LOW);
        delay(del);
        digitalWrite(lh,HIGH);
        delay(del);
        digitalWrite(lh,LOW);
        delay(del);
      } else {
        digitalWrite(rh,HIGH);
        delay(del);
        digitalWrite(rh,LOW);
        delay(del);
        digitalWrite(rh,HIGH);
        delay(del);
        digitalWrite(rh,LOW);
        delay(del);
        digitalWrite(rh,HIGH);
        delay(del);
        digitalWrite(rh,LOW);
        delay(del);
        digitalWrite(rh,HIGH);
        delay(del);
        digitalWrite(rh,LOW);
        delay(del);
      }

    }
  }else if(state == 10){ // right hand: right ready
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;
      
      prevpin1 = rh;
      prevpin2 = 0;
      prevpin3 = 0;
      digitalWrite(rh,HIGH);
      delay(mindel);
    }
    
  }else if(state == 11){ // right front wrist: right toe-off
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      prevpin1 = rfw;
      prevpin2 = 0;
      prevpin3 = 0;
      digitalWrite(rfw,HIGH);
      delay(mindel);
    }
    
  }else if(state == 12){ // right front arm
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;
   
      prevpin1 = rfa;
      prevpin2 = 0;
      prevpin3 = 0;
      digitalWrite(rfa,HIGH);
      delay(mindel);
    }
    
  }else if(state == 13){ // right back arm
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      prevpin1 = rba;
      prevpin2 = 0;
      prevpin3 = 0;
      digitalWrite(rba,HIGH);
      delay(mindel);

    }
    
  }else if(state == 14){ // right back wrist
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      prevpin1 = rbw;
      prevpin2 = 0;
      prevpin3 = 0;
      digitalWrite(rbw,HIGH);
      delay(mindel);

    }
    
  }else if(state == 20){ // left hand: left ready
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;
      
      prevpin1 = lh;
      prevpin2 = 0;
      prevpin3 = 0;
      digitalWrite(lh,HIGH);
      delay(mindel);

    }
    
  }else if(state == 21){ // left front wrist: left toe-off
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      prevpin1 = lfw;
      prevpin2 = 0;
      prevpin3 = 0;
      digitalWrite(lfw,HIGH);
      delay(mindel);

    }
    
  }else if(state == 22){ // left front arm
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;
   
      prevpin1 = lfa;
      prevpin2 = 0;
      prevpin3 = 0;
      digitalWrite(lfa,HIGH);
      delay(mindel);
    }
    
  }else if(state == 23){ // left back arm
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      prevpin1 = lba;
      prevpin2 = 0;
      prevpin3 = 0;
      digitalWrite(lba,HIGH);
      delay(mindel);
      
    }
    
  }else if(state == 24){ // left back wrist
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      prevpin1 = lbw;
      prevpin2 = 0;
      prevpin3 = 0;
      digitalWrite(lbw,HIGH);
      delay(mindel);

    }
    
  }else if(state == 15){ // hybrid walking right swing
    if (state != prevState){
      
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;
      
      for (int pulse = 100; pulse >= 10 ; pulse=pulse-7){
        digitalWrite(rfa,LOW);
        digitalWrite(rba,HIGH);
        delay(pulse);
        digitalWrite(rfa,HIGH);
        digitalWrite(rba,LOW);
        delay(pulse);
        if (pulse < window and pulse > loWindow){
          digitalWrite(lh,HIGH);
          delay(pulse);
          digitalWrite(lh,LOW);
        }
      }

      digitalWrite(lh,LOW);
      
      digitalWrite(rfa,LOW);
      digitalWrite(rba,LOW);

      digitalWrite(rbw,HIGH);
      digitalWrite(rfw,HIGH);
      delay(200);
      digitalWrite(rbw,LOW);
      digitalWrite(rfw,LOW);
      
    }
    
  }else if(state == 25){ // // hybrid walking left swing
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      for (int pulse = 100; pulse >= 10 ; pulse=pulse-7){
        digitalWrite(lfa,LOW);
        digitalWrite(lba,HIGH);
        delay(pulse);
        digitalWrite(lfa,HIGH);
        digitalWrite(lba,LOW);
        delay(pulse);
        if (pulse < window and pulse > loWindow){
          digitalWrite(rh,HIGH);
          delay(pulse);
          digitalWrite(rh,LOW);
        }
      }
      
      digitalWrite(rh,LOW);
      
      digitalWrite(lfa,LOW);
      digitalWrite(lba,LOW);

      digitalWrite(lbw,HIGH);
      digitalWrite(lfw,HIGH);
      delay(200);
      digitalWrite(lbw,LOW);
      digitalWrite(lfw,LOW);
      
    }
    
  }else if(state == 16){ // stairs right swing
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;
      
      for (int pulse = 100; pulse >= 10 ; pulse=pulse-5){
        digitalWrite(rfa,LOW);
        digitalWrite(rba,HIGH);
        delay(pulse);
        digitalWrite(rfa,HIGH);
        digitalWrite(rba,LOW);
        delay(pulse);
        if (pulse < window and pulse > loWindow){
          digitalWrite(lh,HIGH);
          delay(pulse);
          digitalWrite(lh,LOW);
        }
      }

      digitalWrite(lh,LOW);
      digitalWrite(rfa,LOW);
      digitalWrite(rba,LOW);

      digitalWrite(rbw,HIGH);
      digitalWrite(rfw,HIGH);
      delay(200);
      digitalWrite(rbw,LOW);
      digitalWrite(rfw,LOW);
      
    }
    
  }else if(state == 26){ // stairs left swing
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      for (int pulse = 100; pulse >= 10 ; pulse=pulse-5){
        digitalWrite(lfa,LOW);
        digitalWrite(lba,HIGH);
        delay(pulse);
        digitalWrite(lfa,HIGH);
        digitalWrite(lba,LOW);
        delay(pulse);
        if (pulse < window and pulse > loWindow){
          digitalWrite(rh,HIGH);
          delay(pulse);
          digitalWrite(rh,LOW);
        }
      }
      
      digitalWrite(rh,LOW);
      
      digitalWrite(lfa,LOW);
      digitalWrite(lba,LOW);

      digitalWrite(lbw,HIGH);
      digitalWrite(lfw,HIGH);
      delay(200);
      digitalWrite(lbw,LOW);
      digitalWrite(lfw,LOW);

    }
    
  }else if(state == 30){ // low COP 0-45
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      digitalWrite(rfw,HIGH);
      delay(mindel);
      prevpin1 = rfw;
      prevpin2 = 0;
      prevpin3 = 0;
      
    }

  }else if(state == 31){ // low COP 45-90
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      digitalWrite(rfw,HIGH);
      digitalWrite(lfw,HIGH);
      delay(mindel);
      prevpin1 = rfw;
      prevpin2 = lfw;
      prevpin3 = 0;
      
    }
  }else if(state == 32){ // low COP 90-135
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      
      digitalWrite(rfw,HIGH);
      digitalWrite(lfw,HIGH);
      delay(mindel);
      prevpin1 = rfw;
      prevpin2 = lfw;
      prevpin3 = 0;
      
    }
  }else if(state == 33){ // low COP 135-180
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

    
//        digitalWrite(rfw,HIGH);
      digitalWrite(lfw,HIGH);
      delay(mindel);
      prevpin1 = 0;
      prevpin2 = lfw;
      prevpin3 = 0;
      
    }
  }else if(state == 34){ // low COP 180-225
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      
//        digitalWrite(rfw,HIGH);
      digitalWrite(lbw,HIGH);
      delay(mindel);
      prevpin1 = 0;
      prevpin2 = lbw;
      prevpin3 = 0;
      
    }
  }else if(state == 35){ // low COP 225-270
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      
      digitalWrite(rbw,HIGH);
      digitalWrite(lbw,HIGH);
      delay(mindel);
      prevpin1 = rbw;
      prevpin2 = lbw;
      prevpin3 = 0;
        
    }
  }else if(state == 36){ // low COP 270-315
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      digitalWrite(rbw,HIGH);
      digitalWrite(lbw,HIGH);
      delay(mindel);
      prevpin1 = rbw;
      prevpin2 = lbw;
      prevpin3 = 0;
        
    }
  }else if(state == 37){ // low COP 315-360
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      digitalWrite(rfw,HIGH);
      delay(mindel);
//        digitalWrite(lfw,HIGH);
      prevpin1 = rfw;
      prevpin2 = 0;
      prevpin3 = 0;
       
    }
  }else if(state == 40){ // high COP 0-45
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;
     
      digitalWrite(rfa,HIGH);
      digitalWrite(rfw,HIGH);
      delay(mindel);
      prevpin1 = rfa;
      prevpin2 = rfw;
      prevpin3 = 0;
      
    }

  }else if(state == 41){ // high COP 45-90
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      digitalWrite(rfa,HIGH);
      digitalWrite(rfw,HIGH);
      digitalWrite(lfw,HIGH);
      delay(mindel);
      prevpin1 = rfa;
      prevpin2 = lfw;
      prevpin3 = rfw;
       
    }
  }else if(state == 42){ // // high COP 90-135
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      
      digitalWrite(lfa,HIGH);
      digitalWrite(lfw,HIGH);
      digitalWrite(rfw,HIGH);
      delay(mindel);
      prevpin1 = lfa;
      prevpin2 = rfw;
      prevpin3 = lfw;
      
    }
  }else if(state == 43){ // high COP 135-180
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      digitalWrite(lfa,HIGH);
      digitalWrite(lfw,HIGH);
      delay(mindel);
//        digitalWrite(lfw,HIGH);
      prevpin1 = lfa;
      prevpin2 = lfw;
      prevpin3 = 0;
      
    }
  }else if(state == 44){ // high COP 180-225
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      
//        digitalWrite(rfa,HIGH);
      digitalWrite(lba,HIGH);
      digitalWrite(lbw,HIGH);
      delay(mindel);
      prevpin1 = lbw;
      prevpin2 = lba;
      prevpin3 = 0;
       
    }
  }else if(state == 45){ // high COP 225-270
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

     
      digitalWrite(lba,HIGH);
      digitalWrite(rbw,HIGH);
      digitalWrite(lbw,HIGH);
      delay(mindel);
      prevpin1 = lba;
      prevpin2 = rbw;
      prevpin3 = lbw;
      
    }
  }else if(state == 46){ // high COP 270-315
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      
      digitalWrite(rba,HIGH);
      digitalWrite(lbw,HIGH);
      digitalWrite(rbw,HIGH);
      delay(mindel);
      prevpin1 = rba;
      prevpin2 = lbw;
      prevpin3 = rbw;
      
    }
  }else if(state == 47){ // high COP 315-360
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      digitalWrite(rfa,HIGH);
      digitalWrite(rbw,HIGH);
      delay(mindel);
//        digitalWrite(lfw,HIGH);
      prevpin1 = rfa;
      prevpin2 = rbw;
      prevpin3 = 0;
      
    }
  }else if(state == 50){ // boundary COP 0-45
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;
     
      digitalWrite(rfa,HIGH);
      digitalWrite(rfw,HIGH);
      digitalWrite(rh,HIGH);
      delay(mindel);
      prevpin1 = rfa;
      prevpin2 = rfw;
      prevpin3 = rh;
      
    }

  }else if(state == 51){ // boundary COP 45-90
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      digitalWrite(rfa,HIGH);
      digitalWrite(rh,HIGH);
      digitalWrite(lfw,HIGH);
      delay(mindel);
      prevpin1 = rfa;
      prevpin2 = lfw;
      prevpin3 = rh;
       
    }
  }else if(state == 52){ // // boundary COP 90-135
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      
      digitalWrite(lfa,HIGH);
      digitalWrite(lh,HIGH);
      digitalWrite(rfw,HIGH);
      delay(mindel);
      prevpin1 = lfa;
      prevpin2 = rfw;
      prevpin3 = lh;
      
    }
  }else if(state == 53){ // boundary COP 135-180
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      digitalWrite(lfa,HIGH);
      digitalWrite(lfw,HIGH);
      digitalWrite(lh,HIGH);
      delay(mindel);
//        digitalWrite(lfw,HIGH);
      prevpin1 = lfa;
      prevpin2 = lfw;
      prevpin3 = lh;
      
    }
  }else if(state == 54){ // boundary COP 180-225
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      
//        digitalWrite(rfa,HIGH);
      digitalWrite(lba,HIGH);
      digitalWrite(lbw,HIGH);
      digitalWrite(lh,HIGH);
      delay(mindel);
      prevpin1 = lbw;
      prevpin2 = lba;
      prevpin3 = lh;
       
    }
  }else if(state == 55){ // boundary COP 225-270
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

     
      digitalWrite(lba,HIGH);
      digitalWrite(rbw,HIGH);
      digitalWrite(lh,HIGH);
      delay(mindel);
      prevpin1 = lba;
      prevpin2 = rbw;
      prevpin3 = lh;
      
    }
  }else if(state == 56){ // boundary COP 270-315
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      
      digitalWrite(rba,HIGH);
      digitalWrite(lbw,HIGH);
      digitalWrite(rh,HIGH);
      delay(mindel);
      prevpin1 = rba;
      prevpin2 = lbw;
      prevpin3 = rh;
      
    }
  }else if(state == 57){ // boundary COP 315-360
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      digitalWrite(rfa,HIGH);
      digitalWrite(rbw,HIGH);
      digitalWrite(rh,HIGH);
      delay(mindel);
//        digitalWrite(lfw,HIGH);
      prevpin1 = rfa;
      prevpin2 = rbw;
      prevpin3 = rh;
      
    }
  }else if(state == 60){ // low COP 0-45
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      digitalWrite(rbw,HIGH);
      delay(mindel);
      prevpin1 = rbw;
      prevpin2 = 0;
      prevpin3 = 0;
      
    }

  }else if(state == 61){ // low COP 45-90
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      digitalWrite(rbw,HIGH);
      digitalWrite(lbw,HIGH);
      delay(mindel);
      prevpin1 = rbw;
      prevpin2 = lbw;
      prevpin3 = 0;
      
    }
  }else if(state == 62){ // low COP 90-135
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      
      digitalWrite(rbw,HIGH);
      digitalWrite(lbw,HIGH);
      delay(mindel);
      prevpin1 = rbw;
      prevpin2 = lbw;
      prevpin3 = 0;
      
    }
  }else if(state == 63){ // low COP 135-180
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

    
//        digitalWrite(rfw,HIGH);
      digitalWrite(lbw,HIGH);
      delay(mindel);
      prevpin1 = 0;
      prevpin2 = lbw;
      prevpin3 = 0;
      
    }
  }else if(state == 64){ // low COP 180-225
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      
//        digitalWrite(rfw,HIGH);
      digitalWrite(lba,HIGH);
      delay(mindel);
      prevpin1 = 0;
      prevpin2 = lba;
      prevpin3 = 0;
      
    }
  }else if(state == 65){ // low COP 225-270
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      
      digitalWrite(rba,HIGH);
      digitalWrite(lba,HIGH);
      delay(75);
      prevpin1 = rba;
      prevpin2 = lba;
      prevpin3 = 0;
        
    }
  }else if(state == 66){ // low COP 270-315
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      digitalWrite(rba,HIGH);
      digitalWrite(lba,HIGH);
      delay(mindel);
      prevpin1 = rba;
      prevpin2 = lba;
      prevpin3 = 0;
        
    }
  }else if(state == 67){ // low COP 315-360
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      digitalWrite(rba,HIGH);
      delay(mindel);
//        digitalWrite(lfw,HIGH);
      prevpin1 = rba;
      prevpin2 = 0;
      prevpin3 = 0;
       
    }
  }else if(state == 70){ // high COP 0-45
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      digitalWrite(rfw,HIGH);
      digitalWrite(rbw,HIGH);
      delay(mindel);
      prevpin1 = rfw;
      prevpin2 = rbw;
      prevpin3 = 0;
      
    }

  }else if(state == 71){ // high COP 45-90
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      digitalWrite(rbw,HIGH);
      digitalWrite(lbw,HIGH);
      digitalWrite(rfw,HIGH);
      delay(mindel);
      prevpin1 = rbw;
      prevpin2 = lbw;
      prevpin3 = rfw;
      
    }
  }else if(state == 72){ // high COP 90-135
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      
      digitalWrite(rbw,HIGH);
      digitalWrite(lbw,HIGH);
      digitalWrite(lfw,HIGH);
      delay(mindel);
      prevpin1 = rbw;
      prevpin2 = lbw;
      prevpin3 = lfw;
      
    }
  }else if(state == 73){ // high COP 135-180
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

    
      digitalWrite(lbw,HIGH);
      digitalWrite(lfw,HIGH);
      delay(mindel);
      prevpin1 = lbw;
      prevpin2 = lfw;
      prevpin3 = 0;
      
    }
  }else if(state == 74){ // high COP 180-225
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      
      digitalWrite(lfa,HIGH);
      digitalWrite(lba,HIGH);
      delay(mindel);
      prevpin1 = lfa;
      prevpin2 = lbw;
      prevpin3 = 0;
      
    }
  }else if(state == 75){ // high COP 225-270
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      
      digitalWrite(rba,HIGH);
      digitalWrite(lba,HIGH);
      digitalWrite(lfa,HIGH);
      delay(mindel);
      prevpin1 = rba;
      prevpin2 = lba;
      prevpin3 = lfa;
        
    }
  }else if(state == 76){ // high COP 270-315
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      digitalWrite(rba,HIGH);
      digitalWrite(lba,HIGH);
      digitalWrite(rfa,HIGH);
      delay(mindel);
      prevpin1 = rba;
      prevpin2 = lba;
      prevpin3 = rfa;
        
    }
  }else if(state == 77){ // high COP 315-360
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      digitalWrite(rfa,HIGH);
      digitalWrite(rba,HIGH);
      delay(mindel);
//        digitalWrite(lfw,HIGH);
      prevpin1 = rfa;
      prevpin2 = rba;
      prevpin3 = 0;
       
    }
  }else if(state == 80){ // boundary COP 0-45
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;
     
      digitalWrite(rbw,HIGH);
      digitalWrite(rfw,HIGH);
      digitalWrite(rh,HIGH);
      delay(mindel);
      prevpin1 = rbw;
      prevpin2 = rfw;
      prevpin3 = rh;
      
    }

  }else if(state == 81){ // boundary COP 45-90
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      digitalWrite(rbw,HIGH);
      digitalWrite(rh,HIGH);
      digitalWrite(lfw,HIGH);
      delay(mindel);
      prevpin1 = rbw;
      prevpin2 = lfw;
      prevpin3 = rh;
       
    }
  }else if(state == 82){ // // boundary COP 90-135
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      
      digitalWrite(lbw,HIGH);
      digitalWrite(lh,HIGH);
      digitalWrite(rfw,HIGH);
      delay(mindel);
      prevpin1 = lbw;
      prevpin2 = rfw;
      prevpin3 = lh;
      
    }
  }else if(state == 83){ // boundary COP 135-180
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      digitalWrite(lbw,HIGH);
      digitalWrite(lfw,HIGH);
      digitalWrite(lh,HIGH);
      delay(mindel);
//        digitalWrite(lfw,HIGH);
      prevpin1 = lbw;
      prevpin2 = lfw;
      prevpin3 = lh;
      
    }
  }else if(state == 84){ // boundary COP 180-225
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      
//        digitalWrite(rfa,HIGH);
      digitalWrite(lba,HIGH);
      digitalWrite(lfa,HIGH);
      digitalWrite(lh,HIGH);
      delay(mindel);
      prevpin1 = lfa;
      prevpin2 = lba;
      prevpin3 = lh;
       
    }
  }else if(state == 85){ // boundary COP 225-270
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;
     
      digitalWrite(lba,HIGH);
      digitalWrite(rfa,HIGH);
      digitalWrite(lh,HIGH);
      delay(mindel);
      prevpin1 = lba;
      prevpin2 = rfa;
      prevpin3 = lh;
      
    }
  }else if(state == 86){ // boundary COP 270-315
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      
      digitalWrite(rba,HIGH);
      digitalWrite(lfa,HIGH);
      digitalWrite(rh,HIGH);
      delay(mindel);
      prevpin1 = rba;
      prevpin2 = lfa;
      prevpin3 = rh;
      
    }
  }else if(state == 87){ // boundary COP 315-360
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      digitalWrite(prevpin3,LOW);
      delay(mindel);
      prevState = state;

      digitalWrite(rfa,HIGH);
      digitalWrite(rba,HIGH);
      digitalWrite(rh,HIGH);
      delay(mindel);
//        digitalWrite(lfw,HIGH);
      prevpin1 = rfa;
      prevpin2 = rba;
      prevpin3 = rh;
      
    }
  }else { // error state
    digitalWrite(prevpin1,LOW);
    digitalWrite(prevpin2,LOW);
    digitalWrite(prevpin3,LOW);
    delay(mindel);
    
    digitalWrite(13,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    delay(500);
  }
}
