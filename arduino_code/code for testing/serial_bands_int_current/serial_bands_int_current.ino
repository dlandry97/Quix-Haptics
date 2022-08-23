
int state = -1;
int prevState = 0;
int del = 100;
int prevpin = 0;
int window = 90;
int loWindow = 80;

int rh = 2;     // right hand
int rfw = 3;    // right front wrist
int rfa = 5;    // right front arm
int rba = 6;    // right back arm
int rbw = 4;    // right back wrist

bool leftSide = false; // left side true right side false 

int lh = 8;     // left hand
int lfw = 9;    // left front wrist
int lfa = 11;   // left front arm 
int lba = 12;   // left back arm
int lbw = 10;   // left back wrist

void setup(){
  Serial.begin(9600);
//  inputString.reserve(200);
//  Serial.setTimeout(100);
  
//  pinMode(1,OUTPUT);
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

void loop(){

  if (Serial.available()) {
    byte incomingByte = Serial.read();
    if (incomingByte != -1){
      state = incomingByte;
    }
    if (incomingByte == 0){
      digitalWrite(9,LOW);
    } 
  }

  if(state == 1){ // standby
    if (state != prevState){
      digitalWrite(prevpin,LOW);
      delay(75);
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
  }else if(state == 10){ // 
    if (state != prevState){
      digitalWrite(prevpin,LOW);
      delay(75);
      prevState = state;
      
      prevpin = rh;
      digitalWrite(rh,HIGH);
      delay(75);
    }
    
  }else if(state == 11){ // 
    if (state != prevState){
      digitalWrite(prevpin,LOW);
      delay(75);
      prevState = state;

      prevpin = rfw;
      digitalWrite(rfw,HIGH);
      delay(75);
    }
    
  }else if(state == 12){ // 
    if (state != prevState){
      digitalWrite(prevpin,LOW);
      delay(75);
      prevState = state;
   
      prevpin = rfa;
      digitalWrite(rfa,HIGH);
      delay(75);
    }
    
  }else if(state == 13){ // 
    if (state != prevState){
      digitalWrite(prevpin,LOW);
      delay(75);
      prevState = state;

      prevpin = rba;
      digitalWrite(rba,HIGH);
      delay(75);

    }
    
  }else if(state == 14){ // 
    if (state != prevState){
      digitalWrite(prevpin,LOW);
      delay(75);
      prevState = state;

      prevpin = rbw;
      digitalWrite(rbw,HIGH);
      delay(75);

    }
    
  }else if(state == 20){ // 
    if (state != prevState){
      digitalWrite(prevpin,LOW);
      delay(75);
      prevState = state;
      
      prevpin = lh;
      digitalWrite(lh,HIGH);
      delay(75);

    }
    
  }else if(state == 21){ // 
    if (state != prevState){
      digitalWrite(prevpin,LOW);
      delay(75);
      prevState = state;

      prevpin = lfw;
      digitalWrite(lfw,HIGH);
      delay(75);

    }
    
  }else if(state == 22){ // 
    if (state != prevState){
      digitalWrite(prevpin,LOW);
      delay(75);
      prevState = state;
   
      prevpin = lfa;
      digitalWrite(lfa,HIGH);
      delay(75);
    }
    
  }else if(state == 23){ // 
    if (state != prevState){
      digitalWrite(prevpin,LOW);
      delay(75);
      prevState = state;

      prevpin = lba;
      digitalWrite(lba,HIGH);
      delay(75);
      
    }
    
  }else if(state == 24){ // 
    if (state != prevState){
      digitalWrite(prevpin,LOW);
      delay(75);
      prevState = state;


      prevpin = lbw;
      digitalWrite(lbw,HIGH);
      delay(75);

      
    }
    
  }else if(state == 15){ // 
    if (state != prevState){
      
      digitalWrite(prevpin,LOW);
      delay(75);
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
//      digitalWrite(rfw,HIGH);
      delay(200);
      digitalWrite(rbw,LOW);
//      digitalWrite(rfw,LOW);
      

//      leftSide = true;
    }
    
  }else if(state == 25){ // 
    if (state != prevState){
      digitalWrite(prevpin,LOW);
      delay(75);
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
//      digitalWrite(lfw,HIGH);
      delay(200);
      digitalWrite(lbw,LOW);
//      digitalWrite(lfw,LOW);
      

//      leftSide = false;
      
    }
    
  }else if(state == 16){ // 
    if (state != prevState){
      digitalWrite(prevpin,LOW);
      delay(75);
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
//      digitalWrite(rfw,HIGH);
      delay(200);
      digitalWrite(rbw,LOW);
//      digitalWrite(rfw,LOW);
      

//      leftSide = true;   
    }
    
  }else if(state == 26){ // 
    if (state != prevState){
      digitalWrite(prevpin,LOW);
      delay(75);
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
//      digitalWrite(lfw,HIGH);
      delay(200);
      digitalWrite(lbw,LOW);
//      digitalWrite(lfw,LOW);
      

//      leftSide = false;
      
    }
    
  }else { // 
    digitalWrite(13,HIGH);
    delay(500);
    digitalWrite(13,LOW);
//    digitalWrite(2,HIGH);
    delay(500);
//    digitalWrite(2,LOW);
//    digitalWrite(1,LOW);
    
//    digitalWrite(2,HIGH);
//    digitalWrite(3,HIGH);
//    digitalWrite(4,HIGH);
//    digitalWrite(5,HIGH);
//    digitalWrite(6,HIGH);
//    digitalWrite(7,HIGH);
//    digitalWrite(8,HIGH);
//    digitalWrite(9,HIGH);
//    digitalWrite(10,HIGH);
//    digitalWrite(11,HIGH);
//    digitalWrite(12,HIGH);
//    delay(1000);
//    digitalWrite(2,LOW);
//    digitalWrite(3,LOW);
//    digitalWrite(4,LOW);
//    digitalWrite(5,LOW);
//    digitalWrite(6,LOW);
//    digitalWrite(7,LOW);
//    digitalWrite(8,LOW);
//    digitalWrite(9,LOW);
//    digitalWrite(10,LOW);
//    digitalWrite(11,LOW);
//    digitalWrite(12,LOW);
//    delay(1000);
    
  }
//  digitalWrite(1,LOW);
//
//  
//  if(state == 2){
//    if (state != prevState){
//      digitalWrite(prevState,LOW);
//      delay(75);
//      prevState = state;
//      
//    
//      digitalWrite(2,HIGH);
//      delay(del);
//      digitalWrite(2,LOW);
//      delay(del);
//      digitalWrite(2,HIGH);
//      delay(del);
//      digitalWrite(2,LOW);
//      delay(del);
//      digitalWrite(2,HIGH);
//      delay(del);
//      digitalWrite(2,LOW);
//      delay(del);
//      digitalWrite(2,HIGH);
//      delay(del);
//      digitalWrite(2,LOW);
//      delay(del);
//    }
//  } else if(state == 7 or state == 8){
//    if (state != prevState){
//      digitalWrite(prevState,LOW);
//      delay(75);
//      prevState = state;
//    }
////    for (int pwm = 127; pwm <=225 ; pwm=pwm+3){
////      analogWrite(state+3,pwm);
////    }
////    for (int pulse = 100; pulse >= 10 ; pulse=pulse-6){
////      digitalWrite(state,HIGH);
////      delay(pulse);
////      digitalWrite(state,LOW);
////      delay(pulse);
////    }
////    digitalWrite(state,HIGH);
////    delay(del);

//    for (int pulse = 100; pulse >= 10 ; pulse=pulse-6){
//      digitalWrite(7,LOW);
//      digitalWrite(8,HIGH);
//      delay(pulse);
//      digitalWrite(7,HIGH);
//      digitalWrite(8,LOW);
//      delay(pulse);
//    }
//    digitalWrite(7,HIGH);
//    digitalWrite(8,HIGH);
//    delay(del);
//    digitalWrite(7,LOW);
//    digitalWrite(8,LOW);
        
//  } else if(state > 0){
//
//    
//    digitalWrite(state,HIGH);
//    delay(75);
//    if (state != prevState){
//      digitalWrite(prevState,LOW);
//      delay(75);
//      prevState = state;
//    }
//    
//  }
}
