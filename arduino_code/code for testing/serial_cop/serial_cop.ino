
int state = 2000;
int prevState = 0;
int del = 100;
int prevpin1 = 0;
int prevpin2 = 0;
int window = 90;
int loWindow = 80;
bool power = false;

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

int led = 13;

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
      digitalWrite(led,HIGH);
      delay(75);
      digitalWrite(led,LOW);
      
    }
    if (incomingByte == 0){
      digitalWrite(led,LOW);
    } 
  }

//  if (state > 1000){
//    state = state - 1000;
//    power = true;
//  }else{
//    power = false;
//  }

  if(state < 45){ // standby
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      delay(75);
      state = prevState;

      
      if (power == true){
        digitalWrite(rfa,HIGH);
        prevpin1 = rfa;
        prevpin2 = 0;
      }else{
        digitalWrite(rfw,HIGH);
        prevpin1 = rfw;
        prevpin2 = 0;
      }
        
    }

  
  }else if(state < 90){ // standby
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      delay(75);
      state = prevState;

      if (power == true){
        digitalWrite(rfa,HIGH);
        digitalWrite(lfw,HIGH);
        prevpin1 = rfa;
        prevpin2 = lfw;
      }else{
        digitalWrite(rfw,HIGH);
        digitalWrite(lfw,HIGH);
        prevpin1 = rfw;
        prevpin2 = lfw;
      }   
    }
  }else if(state < 135){ // standby
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      delay(75);
      state = prevState;

      if (power == true){
        digitalWrite(lfa,HIGH);
        digitalWrite(rfw,HIGH);
        prevpin1 = lfa;
        prevpin2 = rfw;
      }else{
        digitalWrite(rfw,HIGH);
        digitalWrite(lfw,HIGH);
        prevpin1 = rfw;
        prevpin2 = lfw;
      }   
    }
  }else if(state < 180){ // standby
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      delay(75);
      state = prevState;

      if (power == true){
        digitalWrite(lfa,HIGH);
//        digitalWrite(lfw,HIGH);
        prevpin1 = lfa;
        prevpin2 = 0;
      }else{
//        digitalWrite(rfw,HIGH);
        digitalWrite(lfw,HIGH);
        prevpin1 = 0;
        prevpin2 = lfw;
      }   
    }
  }else if(state < 225){ // standby
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      delay(75);
      state = prevState;

      if (power == true){
//        digitalWrite(rfa,HIGH);
        digitalWrite(lba,HIGH);
        prevpin1 = 0;
        prevpin2 = lba;
      }else{
//        digitalWrite(rfw,HIGH);
        digitalWrite(lbw,HIGH);
        prevpin1 = 0;
        prevpin2 = lbw;
      }   
    }
  }else if(state < 270){ // standby
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      delay(75);
      state = prevState;

      if (power == true){
        digitalWrite(lba,HIGH);
        digitalWrite(rbw,HIGH);
        prevpin1 = lba;
        prevpin2 = rbw;
      }else{
        digitalWrite(rbw,HIGH);
        digitalWrite(lbw,HIGH);
        prevpin1 = rbw;
        prevpin2 = lbw;
      }   
    }
  }else if(state < 315){ // standby
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      delay(75);
      state = prevState;

      if (power == true){
        digitalWrite(rba,HIGH);
        digitalWrite(lbw,HIGH);
        prevpin1 = rba;
        prevpin2 = lbw;
      }else{
        digitalWrite(rbw,HIGH);
        digitalWrite(lbw,HIGH);
        prevpin1 = rbw;
        prevpin2 = lbw;
      }   
    }
  }else if(state < 360){ // standby
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      delay(75);
      state = prevState;

      if (power == true){
        digitalWrite(rfa,HIGH);
//        digitalWrite(lfw,HIGH);
        prevpin1 = rfa;
        prevpin2 = 0;
      }else{
        digitalWrite(rfw,HIGH);
//        digitalWrite(lfw,HIGH);
        prevpin1 = rfw;
        prevpin2 = 0;
      }   
    }
  }if(state < 1045){ // standby
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      delay(75);
      state = prevState;
     
      digitalWrite(rfa,HIGH);
      prevpin1 = rfa;
      prevpin2 = 0;
      
        
    }

  
  }else if(state < 1090){ // standby
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      delay(75);
      state = prevState;

     
      digitalWrite(rfa,HIGH);
      digitalWrite(lfw,HIGH);
      prevpin1 = rfa;
      prevpin2 = lfw;
       
    }
  }else if(state < 1135){ // standby
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      delay(75);
      state = prevState;

      
      digitalWrite(lfa,HIGH);
      digitalWrite(rfw,HIGH);
      prevpin1 = lfa;
      prevpin2 = rfw;
      
    }
  }else if(state < 1180){ // standby
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      delay(75);
      state = prevState;

      digitalWrite(lfa,HIGH);
//        digitalWrite(lfw,HIGH);
      prevpin1 = lfa;
      prevpin2 = 0;
      
    }
  }else if(state < 1225){ // standby
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      delay(75);
      state = prevState;

      
//        digitalWrite(rfa,HIGH);
      digitalWrite(lba,HIGH);
      prevpin1 = 0;
      prevpin2 = lba;
       
    }
  }else if(state < 1270){ // standby
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      delay(75);
      state = prevState;

     
      digitalWrite(lba,HIGH);
      digitalWrite(rbw,HIGH);
      prevpin1 = lba;
      prevpin2 = rbw;
      
    }
  }else if(state < 1315){ // standby
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      delay(75);
      state = prevState;

      
      digitalWrite(rba,HIGH);
      digitalWrite(lbw,HIGH);
      prevpin1 = rba;
      prevpin2 = lbw;
      
    }
  }else if(state < 1360){ // standby
    if (state != prevState){
      digitalWrite(prevpin1,LOW);
      digitalWrite(prevpin2,LOW);
      delay(75);
      state = prevState;

      digitalWrite(rfa,HIGH);
//        digitalWrite(lfw,HIGH);
      prevpin1 = rfa;
      prevpin2 = 0;
      
    }
  }else{
    digitalWrite(prevpin1,LOW);
    digitalWrite(prevpin2,LOW);
    delay(75);
    
    digitalWrite(13,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    delay(500);
  }





//
//
//  
//  if(state == 10){ // 
//    if (state != prevState){
//      digitalWrite(prevpin,LOW);
//      delay(75);
//      prevState = state;
//      
//      prevpin = rh;
//      digitalWrite(rh,HIGH);
//      delay(75);
//    }
//    
//  }else if(state == 11){ // 
//    if (state != prevState){
//      digitalWrite(prevpin,LOW);
//      delay(75);
//      prevState = state;
//
//      prevpin = rfw;
//      digitalWrite(rfw,HIGH);
//      delay(75);
//    }
//    
//  }else if(state == 12){ // 
//    if (state != prevState){
//      digitalWrite(prevpin,LOW);
//      delay(75);
//      prevState = state;
//   
//      prevpin = rfa;
//      digitalWrite(rfa,HIGH);
//      delay(75);
//    }
//    
//  }else if(state == 13){ // 
//    if (state != prevState){
//      digitalWrite(prevpin,LOW);
//      delay(75);
//      prevState = state;
//
//      prevpin = rba;
//      digitalWrite(rba,HIGH);
//      delay(75);
//
//    }
//    
//  }else if(state == 14){ // 
//    if (state != prevState){
//      digitalWrite(prevpin,LOW);
//      delay(75);
//      prevState = state;
//
//      prevpin = rbw;
//      digitalWrite(rbw,HIGH);
//      delay(75);
//
//    }
//    
//  }else if(state == 20){ // 
//    if (state != prevState){
//      digitalWrite(prevpin,LOW);
//      delay(75);
//      prevState = state;
//      
//      prevpin = lh;
//      digitalWrite(lh,HIGH);
//      delay(75);
//
//    }
//    
//  }else if(state == 21){ // 
//    if (state != prevState){
//      digitalWrite(prevpin,LOW);
//      delay(75);
//      prevState = state;
//
//      prevpin = lfw;
//      digitalWrite(lfw,HIGH);
//      delay(75);
//
//    }
//    
//  }else if(state == 22){ // 
//    if (state != prevState){
//      digitalWrite(prevpin,LOW);
//      delay(75);
//      prevState = state;
//   
//      prevpin = lfa;
//      digitalWrite(lfa,HIGH);
//      delay(75);
//    }
//    
//  }else if(state == 23){ // 
//    if (state != prevState){
//      digitalWrite(prevpin,LOW);
//      delay(75);
//      prevState = state;
//
//      prevpin = lba;
//      digitalWrite(lba,HIGH);
//      delay(75);
//      
//    }
//    
//  }else if(state == 24){ // 
//    if (state != prevState){
//      digitalWrite(prevpin,LOW);
//      delay(75);
//      prevState = state;
//
//
//      prevpin = lbw;
//      digitalWrite(lbw,HIGH);
//      delay(75);
//
//      
//    }
//    
//  }else if(state == 15){ // 
//    if (state != prevState){
//      
//      digitalWrite(prevpin,LOW);
//      delay(75);
//      prevState = state;
//      
//      for (int pulse = 100; pulse >= 10 ; pulse=pulse-7){
//        digitalWrite(rfa,LOW);
//        digitalWrite(rba,HIGH);
//        delay(pulse);
//        digitalWrite(rfa,HIGH);
//        digitalWrite(rba,LOW);
//        delay(pulse);
//        if (pulse < window and pulse > loWindow){
//          digitalWrite(lh,HIGH);
//          delay(pulse);
//          digitalWrite(lh,LOW);
//        }
//      }
//
//      digitalWrite(lh,LOW);
//      
//      digitalWrite(rfa,LOW);
//      digitalWrite(rba,LOW);
//
//      digitalWrite(rbw,HIGH);
////      digitalWrite(rfw,HIGH);
//      delay(200);
//      digitalWrite(rbw,LOW);
////      digitalWrite(rfw,LOW);
//      
//
////      leftSide = true;
//    }
//    
//  }else if(state == 25){ // 
//    if (state != prevState){
//      digitalWrite(prevpin,LOW);
//      delay(75);
//      prevState = state;
//
//      
//
//      for (int pulse = 100; pulse >= 10 ; pulse=pulse-7){
//        digitalWrite(lfa,LOW);
//        digitalWrite(lba,HIGH);
//        delay(pulse);
//        digitalWrite(lfa,HIGH);
//        digitalWrite(lba,LOW);
//        delay(pulse);
//        if (pulse < window and pulse > loWindow){
//          digitalWrite(rh,HIGH);
//          delay(pulse);
//          digitalWrite(rh,LOW);
//        }
//      }
//      
//      digitalWrite(rh,LOW);
//      
//      digitalWrite(lfa,LOW);
//      digitalWrite(lba,LOW);
//
//      digitalWrite(lbw,HIGH);
////      digitalWrite(lfw,HIGH);
//      delay(200);
//      digitalWrite(lbw,LOW);
////      digitalWrite(lfw,LOW);
//      
//
////      leftSide = false;
//      
//    }
//    
//  }else if(state == 16){ // 
//    if (state != prevState){
//      digitalWrite(prevpin,LOW);
//      delay(75);
//      prevState = state;
//      
//      for (int pulse = 100; pulse >= 10 ; pulse=pulse-5){
//        digitalWrite(rfa,LOW);
//        digitalWrite(rba,HIGH);
//        delay(pulse);
//        digitalWrite(rfa,HIGH);
//        digitalWrite(rba,LOW);
//        delay(pulse);
//        if (pulse < window and pulse > loWindow){
//          digitalWrite(lh,HIGH);
//          delay(pulse);
//          digitalWrite(lh,LOW);
//        }
//      }
//      
//
//      digitalWrite(lh,LOW);
//      digitalWrite(rfa,LOW);
//      digitalWrite(rba,LOW);
//
//      digitalWrite(rbw,HIGH);
////      digitalWrite(rfw,HIGH);
//      delay(200);
//      digitalWrite(rbw,LOW);
////      digitalWrite(rfw,LOW);
//      
//
////      leftSide = true;   
//    }
//    
//  }else if(state == 26){ // 
//    if (state != prevState){
//      digitalWrite(prevpin,LOW);
//      delay(75);
//      prevState = state;
//
//      
//
//      for (int pulse = 100; pulse >= 10 ; pulse=pulse-5){
//        digitalWrite(lfa,LOW);
//        digitalWrite(lba,HIGH);
//        delay(pulse);
//        digitalWrite(lfa,HIGH);
//        digitalWrite(lba,LOW);
//        delay(pulse);
//        if (pulse < window and pulse > loWindow){
//          digitalWrite(rh,HIGH);
//          delay(pulse);
//          digitalWrite(rh,LOW);
//        }
//      }
//      
//      digitalWrite(rh,LOW);
//      
//      digitalWrite(lfa,LOW);
//      digitalWrite(lba,LOW);
//
//      digitalWrite(lbw,HIGH);
////      digitalWrite(lfw,HIGH);
//      delay(200);
//      digitalWrite(lbw,LOW);
////      digitalWrite(lfw,LOW);
//      
//
//    }
//    
//  }else { // 
//    digitalWrite(13,HIGH);
//    delay(500);
//    digitalWrite(13,LOW);
////    digitalWrite(2,HIGH);
//    delay(500);

}
