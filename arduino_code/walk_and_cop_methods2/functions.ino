void buzz(int motor1, int motor2, int motor3, int motor4){
  digitalWrite(prevpin1,LOW);
  digitalWrite(prevpin2,LOW);
  digitalWrite(prevpin3,LOW);
  digitalWrite(prevpin4,LOW);
  delay(mindel);
  prevState = state;
  
  digitalWrite(motor1,HIGH);
  digitalWrite(motor2,HIGH);
  digitalWrite(motor3,HIGH);
  digitalWrite(motor4,HIGH);
  delay(mindel);
  prevpin1 = motor1;
  prevpin2 = motor2;
  prevpin3 = motor3;
  prevpin4 = motor4;
}

void swingPulse(int arm1,int arm2, int wrist1, int wrist2, int hand){
  
  digitalWrite(prevpin1,LOW);
  digitalWrite(prevpin2,LOW);
  digitalWrite(prevpin3,LOW);
  digitalWrite(prevpin4,LOW);
  delay(mindel);
  prevState = state;
  
  for (int pulse = 100; pulse >= 10 ; pulse=pulse-7){
    digitalWrite(arm1,LOW);
    digitalWrite(arm2,HIGH);
    delay(pulse);
    digitalWrite(arm1,HIGH);
    digitalWrite(arm2,LOW);
    delay(pulse);
    if (pulse < window and pulse > loWindow){
      digitalWrite(hand,HIGH);
      delay(pulse);
      digitalWrite(hand,LOW);
    }
    pulse = pulse - 8;
  }

  digitalWrite(hand,LOW);
  
  digitalWrite(arm1,LOW);
  digitalWrite(arm2,LOW);

  digitalWrite(wrist1,HIGH);
  digitalWrite(wrist2,HIGH);
  prevpin1 = wrist1;
  prevpin2 = wrist2;
  delay(200);
  digitalWrite(wrist1,LOW);
  digitalWrite(wrist2,LOW);
  
}
