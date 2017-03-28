//int line_overshoot = 60, turn_overshoot = 900;//HIT AND TRIAL......

void turn_right()
{
  sensor_read();
  digitalWrite(m11, HIGH);
  digitalWrite(m12, LOW);
  analogWrite(pwm1, vturn);
  
  digitalWrite(m21, LOW);
  digitalWrite(m22, HIGH);
  analogWrite(pwm2, vturn);
}

void turn_left()
{
  sensor_read();
  digitalWrite(m11, LOW);
  digitalWrite(m12, HIGH);
  analogWrite(pwm1, vturn);
  
  digitalWrite(m21, HIGH);
  digitalWrite(m22, LOW);
  analogWrite(pwm2, vturn);
}

void halt()
{
  digitalWrite(m11, HIGH);
  digitalWrite(m12, HIGH);
  
  digitalWrite(m21, HIGH);
  digitalWrite(m22, HIGH);
  //Serial.println("halt");
}

void turnBack()
{
  t = millis();
  while(millis() < t + line_overshoot)
  {
    line_follow();
  }
  
    t = millis();
    while(millis() < t + turn_overshoot)
    {  turn_right();  }

    sensor_read();    
    while(s1 == 0 && s2==0)
  {
    sensor_read();
    turn_right();
  }
    Serial.println("Turned once");

    
    t = millis();
    while(millis() < t + 150)
    {  turn_right();  }
    
    sensor_read();
    
    while(s1==0)
  {
    sensor_read();
    turn_right();
  }
  Serial.println("Turned twice");
}




void turnRight()
{
  t = millis();
  while(millis()-t < overshoot)
  {
    line_follow();
  }

  while(s1 == 0 && s2==0)
  {
    sensor_read();
    digitalWrite(m11,HIGH);
    digitalWrite(m12,LOW);
    digitalWrite(m21,LOW);
    digitalWrite(m22,HIGH);
  
    analogWrite(pwm1, vturn);
    analogWrite(pwm2, vturn);
  }
  
    digitalWrite(m11,HIGH);
    digitalWrite(m12,HIGH);
    digitalWrite(m21,HIGH);
    digitalWrite(m22,HIGH);
    delay(100);
}



void turnLeft()
{
  t = millis();
  while(millis()-t < overshoot)
  {
    line_follow();
  }

  while(s7 == 0 && s6==0)
  {
    sensor_read();
    digitalWrite(m11,LOW);
    digitalWrite(m12,HIGH);
    digitalWrite(m21,HIGH);
    digitalWrite(m22,LOW);
  
    analogWrite(pwm1, vturn); 
    analogWrite(pwm2, vturn);
  }
    digitalWrite(m11,HIGH);
    digitalWrite(m12,HIGH);
    digitalWrite(m21,HIGH);
    digitalWrite(m22,HIGH);
    delay(100);
}




