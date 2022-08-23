void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);

  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  
}

int ang = 0;
void loop() {
  // put your main code here, to run repeatedly:
  int del = 15; // fastest is 75ms

  if (ang < 90){
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    delay(del);
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    delay(del);
  }else{
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
  }

  if (ang > 90 and ang < 180){
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    delay(del);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    delay(del);
  }else{
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  }

  if (ang > 180 and ang < 270){
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    delay(del);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    delay(del);
  }else{
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  }

  if (ang > 270 and ang < 360){
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    delay(del);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    delay(del);
  }else{
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
  }
  
  ang ++;
  if (ang == 360) ang = 0;
  
}
