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
String state = "";
int del = 500; // fastest is 75ms
int longer = 75;
//char inChar = 'b';
void setup(){
  Serial.begin(9600);
  inputString.reserve(200);
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

//  if (Serial.available()) {
//    digitalWrite(pin2,HIGH);
//    // get the new byte:
//    inChar = (char)Serial.read();
//    
//   
//  }else{
//    digitalWrite(pin2,LOW);
//  }
//
//  if (stringComplete) {
//    Serial.println(inputString);
//    state = inputString;
//    // clear the string:
//    inputString = "";
//    stringComplete = false;
//  }

//  state = inChar;
  state = Serial.readString();

  if (state == "abc"){
    digitalWrite(pin8,HIGH);
    
  } else {
    digitalWrite(pin8,LOW);
  }
  
  if (state == "initialSwing"){
    digitalWrite(pin8,HIGH);
    delay(100);
    
  } else {
    digitalWrite(pin8,LOW);
  }

  if (state == "midSwing"){
    digitalWrite(pin6,HIGH);
    
  } else {
    digitalWrite(pin6,LOW);
  }

  if (state == "terminalSwing"){
    digitalWrite(pin4,HIGH);
    
  } else {
    digitalWrite(pin4,LOW);
  }

  if (state == "heelStrike"){
    digitalWrite(pin2,HIGH);
    
  } else {
    digitalWrite(pin2,LOW);
  }

  if (state == "loadingResponse"){
    digitalWrite(pin3,HIGH);
    
  } else {
    digitalWrite(pin3,LOW);
  }

  if (state == "midStance"){
    digitalWrite(pin5,HIGH);
    
  } else {
    digitalWrite(pin5,LOW);
  }

  if (state == "terminalStance"){
    digitalWrite(pin7,HIGH);
    
  } else {
    digitalWrite(pin7,LOW);
  }

  if (state == "preSwing"){
    digitalWrite(pin9,HIGH);
    
  } else {
    digitalWrite(pin9,LOW);
  }
  
//  delay(1000);
}
//
//void serialEvent() {
//  while (Serial.available()) {
//    // get the new byte:
//    digitalWrite(pin2,HIGH);
//    
//    char inChar = (char)Serial.read();
//    // add it to the inputString:
//    inputString = inChar;
//    // if the incoming character is a newline, set a flag so the main loop can
//    // do something about it:
//    if (inChar == '\n') {
//      stringComplete = true;
//    }
//  }
////  delay(100);
//}
