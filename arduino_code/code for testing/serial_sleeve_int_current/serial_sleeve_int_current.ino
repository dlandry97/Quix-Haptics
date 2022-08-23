
int state = -1;
int prevState = 0;
int del = 100;

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
  if(state == 2){
    if (state != prevState){
      digitalWrite(prevState,LOW);
      delay(75);
      prevState = state;
      
    
      digitalWrite(2,HIGH);
      delay(del);
      digitalWrite(2,LOW);
      delay(del);
      digitalWrite(2,HIGH);
      delay(del);
      digitalWrite(2,LOW);
      delay(del);
      digitalWrite(2,HIGH);
      delay(del);
      digitalWrite(2,LOW);
      delay(del);
      digitalWrite(2,HIGH);
      delay(del);
      digitalWrite(2,LOW);
      delay(del);
    }
  } else if(state == 7 or state == 8){
    if (state != prevState){
      digitalWrite(prevState,LOW);
      delay(75);
      prevState = state;
    }
//    for (int pwm = 127; pwm <=225 ; pwm=pwm+3){
//      analogWrite(state+3,pwm);
//    }
//    for (int pulse = 100; pulse >= 10 ; pulse=pulse-6){
//      digitalWrite(state,HIGH);
//      delay(pulse);
//      digitalWrite(state,LOW);
//      delay(pulse);
//    }
//    digitalWrite(state,HIGH);
//    delay(del);

    for (int pulse = 100; pulse >= 10 ; pulse=pulse-6){
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      delay(pulse);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);
      delay(pulse);
    }
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    delay(del);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
        
  } else if(state > 0){

    
    digitalWrite(state,HIGH);
    delay(75);
    if (state != prevState){
      digitalWrite(prevState,LOW);
      delay(75);
      prevState = state;
    }
    
  }
}
