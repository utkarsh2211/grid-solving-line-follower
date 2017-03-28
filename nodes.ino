//node_type = 1 for white node
//node_type = 0 for black node
//node_type = 8 for Jedi zone
//node_type = 5 for first block
//node_type = 6 for transfer zone
//node_type = 7 for jedi block
//node_type= 9 for pit

int clone_found = false;

boolean node_check()
{
 sensor_read();
 
 if((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==1)&&(s6==1)&&(s7==1))
 {  
    
  
    t=millis();
    while(millis()<t+overshoot)
    {
      line_follow();
    }
    
    if((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==1)&&(s6==1)&&(s7==1))
    {
      
      flag_node = true;
      node_type = 8;
      Serial.println("Node detected" );
      Serial.println("Node type : Jedi Zone" );
  
      t=millis();
      while(millis()<t+300)
      {
        line_follow();
      }
     
    }
    else
    {
     
      flag_node = true;
    node_type = 1 ;    //White node
    Serial.println("Node detected" );
    Serial.println("Node type : White (Passable)" );    
    }
 }
   
 

else if((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0))
{
  t=millis();
  /*while(millis()<t+300)
      line_follow();
      
      halt();
      delay(1000);
  if((s1==0)&&(s4==1)&&(s7==0))
  { */
      while(millis()<t+205)
      line_follow();
      //halt();
      //delay(2000);
      /*if((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0))
      {digitalWrite(buzz, HIGH);
      delay(150);
      digitalWrite(buzz, LOW);}*/
      if((s2==1)&&(s6==1)&&(s4==0||s3==0||s5==0))
        {
           if(!clone_found)
              node_type = 5;   // node
           else
              node_type = 7; 
           clone_found = true;      
           flag_node = true;
           t=millis();
           while(millis()<t+overshoot)
            {
              line_follow();
            }
           Serial.println("Node detected" );
           Serial.println("Node type : Clone Block" );
        }
    
      //}
    }

  else if((s1==1)&&(s7==1)&&(s4==0))
 {
   node_type = 0;   //Black node
   flag_node = true;
    t=millis();
    
    while(millis()<t+overshoot)
    {
      line_follow();
    }
   Serial.println("Node detected" );
   Serial.println("Node type : Black (Non-Passable)" );
 }


 else
 {
   flag_node= false;
   Serial.println("Node not detected" ); 
 }
     
 return flag_node;
}

