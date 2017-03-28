#include<Servo.h>

//===================================For Gripping mechanism============================================

// motor that actuate left hand is servo_lt 
// motor that actuate right hand is servo_rt
// motor that actuate vertical motion is servo_vm

Servo servo_lt; 
Servo servo_rt;

int lt_servo=4;
int rt_servo=5;
int vm21 = 30;
int vm22 = 32;
int t_vert_down=1000;
int t_vert=1000;

void set_pinmode()
{
  servo_lt.attach(lt_servo);
  servo_rt.attach(rt_servo);
}


/*void halt()
{
  digitalWrite(vm21,HIGH);
  digitalWrite(vm22,HIGH);
}*/

void gripper_open()
{
 servo_lt.write(20);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
 servo_rt.write(130);
}

void gripper_close()
{
  servo_lt.write(110);
  servo_rt.write(60);
}


void gripper_up()
{
  t=millis();
  
  while(millis()<t+t_vert)
  {
    digitalWrite(vm21,LOW);
    digitalWrite(vm22,HIGH);
  }
  halt();
}

void gripper_down()
{
  t=millis();
  while(millis()<t+t_vert_down)
  {
    digitalWrite(vm21,HIGH);
    digitalWrite(vm22,LOW);
  }
  halt();
}



