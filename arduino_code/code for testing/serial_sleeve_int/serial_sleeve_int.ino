int pin2 = 2;
int pin3 = 3;
int pin4 = 4;
int pin5 = 5;
int pin6 = 6;
int pin7 = 7;
int pin8 = 8;
int pin9 = 9;


String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete
int state = -1;
int prevState = 0;
int del = 500; // fastest is 75ms
int longer = 75;
//char inChar = 'b';
void setup(){
  Serial.begin(9600);
//  inputString.reserve(200);
  Serial.setTimeout(100);
  

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

  if (Serial.available()) {
//    digitalWrite(pin2,HIGH);
    // get the new byte:
    byte incomingByte = Serial.read();
    if (incomingByte != -1){
      state = incomingByte;
//      prevState = state;
//    }else {
//      state = -1;
    }
    if (incomingByte == 0){
      
//      delay(1000);
      digitalWrite(9,LOW);
//      prevState = state;
//    }else {
//      state = -1;
    }
//  }else{
//    delay(1000);
//    digitalWrite(9,LOW);
////    
  }
  if (state > 0){
    digitalWrite(state,HIGH);
    delay(75);
    
    if (state != prevState){
      
      digitalWrite(prevState,LOW);
      delay(75);
      prevState = state;
    }
    
  }else{
//    delay(1000);
//    digitalWrite(9,LOW);
  }
//  digitalWrite(state,HIGH);
//  delay(75);
//  digitalWrite(prevState,LOW);
//  delay(75);
  
//  switch (state) {
//  case "initialSwing":
//    digitalWrite(pin8,HIGH);
//    delay(75);
//    break;
//  case "midSwing":
//    digitalWrite(pin6,HIGH);
//    delay(75);
//    break;
//  case "terminalSwing":
//void serialEvent() {
//  while (Serial.available()) {
//    // get the new byte:
//    char inChar = (char)Serial.read();
//    // add it to the inputString:
//    inputString = inChar;
//    // if the incoming character is a newline, set a flag so the main loop can
//    // do something about it:
//    if (inChar == '\n') {
//      stringComplete = true;
//    }
//  }
//}
//    digitalWrite(pin4,HIGH);
//    delay(75);
//    break;
//  case "heelStrike":
//    digitalWrite(pin2,HIGH);
//    delay(75);
//    break;
//  case "loadingResponse":
//    digitalWrite(pin3,HIGH);
//    delay(75);
//    break;
//  case "midStance":
//    digitalWrite(pin5,HIGH);
//    delay(75);
//    break;
//  case "terminalStance":
//    digitalWrite(pin7,HIGH);
//    delay(75);
//    break;
//  case "preSwing":
//    digitalWrite(pin9,HIGH);
//    delay(75);
//    break;
//  default:
//    digitalWrite(prevState,LOW);
//    break;
//  }
  
//  delay(1000);
}
