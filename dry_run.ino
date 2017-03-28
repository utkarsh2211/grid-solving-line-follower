

//////////////////////   Maze related ////////////////////////

int maze[9][5];      //Since there were 9 rows and 5 columns in grid

int node_type;       // 1 for cross-section(passable, 0 for node(not passable) and 5 for block
boolean flag_node;   // Determines whether node is detected or node
int x = 2;
int y = -1;
int vx,vy;           //x,y are current coord of bot and vx,vy are current direction.
int sum1=0,sum2=0;


void follow_row()
{
  line_follow();
    if(node_check())
    {
      x += vx;
      y += vy;
     
      maze[y][x] = node_type;
      //t=millis();
      //while(millis()<t+400)
      //{
      //  line_follow();
      //}
    }
}

void follow_column()
{
  line_follow();
    if(node_check())
    {
      x += vx;
      y += vy;
      maze[y][x] = node_type;
      //t = millis();
      //while(millis() < t + 400)
      //{
      //  line_follow();
      //}
    }
}

/*void block()
{
  if(distance<lim)
  {
    block_x = x;
    block_y = y;
    turnBack();
  }
}*/

void dry_run()
{
  maze[0][0]=0;
  maze[1][0]=0;
  maze[2][0]=0;
  maze[3][0]=0;
  maze[4][0]=0;

  while(!node_check())
  {
    line_follow();
  }
   
  if((x == 2) && (y == -1))
   {
    while(s7==0)
    turn_left();
    y = 0;
    vx = -1;
    vy = 0;
   }
  while((x==2) && (y==0))
  {
    follow_row();
  }

  if((x == 1)&&(y==0)&&(vx == -1))
  {
    turnBack();
    vx = 1;
  }
    
  ///////////////////////////////////////// run till x=4, y=0//////////////////////////////////////
  while(x<4)
  {
     follow_row(); 
     if(x==2&&y==0)
     {
       Serial.println("Printing Maze");
       for(int r=0; r<=8; r++)
        {
         for(int c=0; c<=4; c++)
           {
            Serial.print(maze[r][c]);
            Serial.print(" ,"); 
           }
            Serial.println(); 
          }  
     }
     
  }
  while(s7 == 0)
  turn_left();
  
  ///////////////////////////////////////////Running along x = 4 till x=4, y=1/////////////////////////////////////////
  vx=0; vy=1;
  while(y<1)
  {
    follow_column();
  }
  while(s7 == 0)
  turn_left();

  ////////////////////////////////////////moving along y=1//////////////////////////
  vx=-1;
  vy=0;
  
  while(x>1)
  {
    follow_row();
    if(x==2&&y==1)
     {
       Serial.println("Printing Maze");
       for(int r=0; r<=8; r++)
        {
         for(int c=0; c<=4; c++)
           {
            Serial.print(maze[r][c]);
            Serial.print(" ,"); 
           }
            Serial.println(); 
          }
     }
  }
  while(s1 == 0)
  turn_right();
  
  ///////////////////////////////////////////Running along x = 1 till x=1, y=2/////////////////////////////////////////
  vx=0; vy=1;
  while(y<2)
  {
    follow_column();
  }
  while(s1 == 0)
  turn_right();
  
  ////////////////////////////////////////////Moving along y = 2///////////////////////////////////
  vx=1; vy=0;
  
  while(x<4)
  {
   follow_row();
   if(x==4&& y==2)
      maze[y][x]=6;
  }
  while(s7 == 0)
  turn_left();
   ///////////////////////////////////////////Running along x =4  till x=4, y=3/////////////////////////////////////////
  vx=0; vy=1;
  while(y<3)
  {
    follow_column();
  }
  while(s7 == 0)
  turn_left();
    
  /////////////////////////////////////////////////////////// moving along y=3 ////////////////////////////////////////////////////////////////
  vx = -1;
  vy = 0;
  while(x>1)
  {
   follow_row();
   if(x==2)
   {
     Serial.println("Printing Maze");
      for(int r=0; r<=3; r++)
       {
          for(int c=0; c<=4; c++)
          {
            Serial.print(maze[r][c]);
            Serial.print(" ,"); 
          }
          Serial.println(); 
       }
   }
  }
  while(s1 == 0)
  turn_right();

 

  ///////////////////////////////////////////Running along x = 1 till x=1, y=2/////////////////////////////////////////
  vx=0; vy=1;
  while(y<4)
  {
    follow_column();
  }
  while(s1 == 0 )
  turn_right();
  
 ///////////////////////////////////////////Running along y = 4/////////////////////////////////////////
  vx=1; vy=0;
  while(x<4)
  {
    follow_row();
    if(y==4&&x==2)
     maze[y][x]=5;
  }
while(s7 == 0)
  turn_left();
 ///////////////////////////////////////////Running along x =4  till x=4, y=5/////////////////////////////////////////
  vx=0; vy=1;
  while(y<5)
  {
    follow_column();
  }
  while(s7 == 0)
  turn_left();
///////////////////////////////////////////Running along y = 5////////////////////////////////////////

  vx=-1; vy=0;
  while(x>0)
  {
    follow_row();
    if(x == 0&& y == 5)
    {
      maze[y][x]= 7;
    }
  }
while(s1 == 0)
  turn_right();
  ///////////////////////////////////////////Running along x = 0 till x=0, y=5/////////////////////////////////////////
  vx=0; vy=1;
  while(y<6)
  {
    follow_column();
  }
  while(s1 == 0)
  turn_right();
    
  ////////////////////////////////////////////Moving along y = 6///////////////////////////////////
  vx=1; vy=0;
  
  while(x<4)
  {
    follow_row();
  }
while(s7 == 0)
  turn_left();
    ///////////////////////////////////////////Running along x = 4 till x=4, y=7/////////////////////////////////////////
  vx=0; vy=1;
  while(y<7)
  {
    follow_column();
  }
  while(s7 == 0)
  turn_left();
  
  ////////////////////////////////////////moving along y=7//////////////////////////
  vx = -1;
  vy = 0;

  while(x>0)
  {
    follow_row();
    if(y==7 && x==3)
       maze[y][x]=8;
  }
  while(s1 == 0)
  turn_right();
  ///////////////////////////////////////////Running along x = 0 till x=0, y=8/////////////////////////////////////////
  vx=0; vy=1;
  while(y<8)
  {
    follow_column();
  }
  while(s1 == 0)
  turn_right();
     
  /////////////////////////move alomg y=8/////////////////////////////
  vx=1; vy=0;
  
  while(x<4)
  {
    follow_row();
    if(x==4 && y==8)
      maze[y][x]=9;
  }

  
  Serial.println("Printing Maze");
  for(int r=0; r<=8; r++)
  {
    for(int c=0; c<=4; c++)
    {
     Serial.print(maze[r][c]);
     Serial.print(" ,"); 
    }
   Serial.println(); 
  }

  
  if((x==4)&&(y==8))
  {
   halt();
   digitalWrite(buzz,HIGH);
   delay(5000);
   digitalWrite(buzz,LOW);
  }
 
}




  
