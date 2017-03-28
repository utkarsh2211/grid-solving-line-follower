void sensor_read()
{
  digitalWrite(13,HIGH);
  s1= analogRead(A0);
  s2= analogRead(A1);
  s3= analogRead(A2);
  s4= analogRead(A3);
  s5= analogRead(A4);
  s6= analogRead(A5);
  s7= analogRead(A6);

  if(s1 > 250) s1 = 1; else s1 = 0;
  if(s2 > 250) s2 = 1; else s2 = 0;
  if(s3 > 250) s3 = 1; else s3 = 0;
  if(s4 > 250) s4 = 1; else s4 = 0;
  if(s5 > 250) s5 = 1; else s5 = 0;
  if(s6 > 250) s6 = 1; else s6 = 0;
  if(s7 > 250) s7 = 1; else s7 = 0;
 
  digitalWrite(13,LOW);
  
  Serial.println("Start");
  Serial.println(s1);
  Serial.println(s2);
  Serial.println(s3);
  Serial.println(s4);
  Serial.println(s5);
  Serial.println(s6);
  Serial.println(s7);
}

void calc_pwm()
{
  preErr = err;

  wsum = (-6)*s7 + (-4)*s6 + (-2)*s5 + 2*s3 + 4*s2 + 6*s1;
  sum = s1+s2+s3+s4+s5+s6+s7;
  err = wsum/sum;
  if(sum == 0) err = 0;
  derr = err - preErr;
  sum_err += err;
}

void motor_drive()
{
  corr = kp*err + kd*derr + ki*sum_err;
  v1 = v + corr; 
  v2 = v - corr; 
  
  constrain(v1,0,255);
  constrain(v2,0,255);
  
  digitalWrite(m11,HIGH);
  digitalWrite(m12,LOW);
  digitalWrite(m21,HIGH);
  digitalWrite(m22,LOW);
  
  analogWrite(pwm1, v1);
  analogWrite(pwm2, v2);
}

void line_follow()
{
  sensor_read();
  calc_pwm();
  motor_drive();
}

