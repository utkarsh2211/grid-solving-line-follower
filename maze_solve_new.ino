
//=================================Creating the stack======================================

int stack[50];
int top=-1;                                                                

void push(int d)
{
  top++;
  stack[top] = d;                                                             
                                                                              
}

int pop()
{
  top--;
  return stack[top+1];
}
//===============================stack1=========================================================
int stack1[45];
int top1=-1;                                                                

void push1(int d)
{
  top1++;
  stack1[top1] = d;                                                             
                                                                              
}

int pop1()
{
  top1--;
  return stack1[top1+1];
}

//=========================================stack2================================================
int stack2[45];
int top2=-1;                                                                

void push2(int d)
{
  top2++;
  stack2[top2] = d;                                                             
                                                                              
}

int pop2()
{
  top2--;
  return stack2[top2+1];
}


//======================================stack3===================================================
int stack3[45];
int top3=-1;                                                                

void push3(int d)
{
  top3++;
  stack3[top3] = d;                                                             
                                                                              
}

int pop3()
{
  top3--;
  return stack3[top3+1];
}


//=========================================================================================

int line_overshoot = 60, turn_overshoot = 900;
//int node_type;       // 1 for cross-section(passable, 0 for node(not passable) and 5 for block
//boolean flag_node;   // Determines whether node is detected or node
int minm,r,c,i;

/*int maze[9][5]={
  {0,0,1,1,0},
  {0,1,1,1,1},
  {0,0,1,0,6},
  {0,1,5,1,1},
  {0,1,1,0,1},
  {7,1,0,1,1},
  {1,1,1,0,1},
  {1,0,1,8,1},
  {1,1,1,1,9},
  };*/

int sol[9][5];
int sol1[9][5];
int sol2[9][5];
int sol3[9][5];
int l1;
int l2;
int l3;
int dest, dir, curDir;
int curX,curY,destX,destY;
int target[5];

void ini_sol()
 {
  for(int i=0;i<9;i++)
  {
    for(int j=0;j<5;j++)
    {
      sol[i][j]=0;
    }
  }
 }

void ini_sol1()
 {
  for(int i=0;i<9;i++)
  {
    for(int j=0;j<5;j++)
    {
      sol1[i][j]=0;
    }
  }
 }


void ini_sol2()
 {
  for(int i=0;i<9;i++)
  {
    for(int j=0;j<5;j++)
    {
      sol2[i][j]=0;
    }
  }
 }


void ini_sol3()
 {
  for(int i=0;i<9;i++)
  {
    for(int j=0;j<5;j++)
    {
      sol3[i][j]=0;
    }
  }
 }

 

 

void printsol()
 {
  for(int i=8;i>-1;i--)
  {
    for(int j=0;j<5;j++)
    {
      Serial.print(sol[i][j] + " ");
    }
    Serial.println();
  }
 }

void printsol1()
 {
  for(int i=8;i>-1;i--)
  {
    for(int j=0;j<5;j++)
    {
      Serial.print(sol1[i][j] + " ");
    }
    Serial.println();
  }
 }
 void printsol2()
 {
  for(int i=8;i>-1;i--)
  {
    for(int j=0;j<5;j++)
    {
      Serial.print(sol2[i][j]+ " ");
    }
    Serial.println();
  }
 }
 void printsol3()
 {
  for(int i=8;i>-1;i--)
  {
    for(int j=0;j<5;j++)
    {
      Serial.print(sol3[i][j] + " ");
    }
    Serial.println();
  }
 }

bool isvalid(int x,int y)
{ 
  if(x<0||x>4)
    return false;
  if(y<0||y>8)
    return false;
  if(maze[y][x] == 0)
    return false;
  if(sol[y][x] == 1)
    return false;
            
  return true;
}

bool isOptimizable(int x, int y, int p)
{
  int a=1,b=1,c=1,d=1;
  if(x-1 < 0) d=0;
  if(x+1 > 4) c=0;
  if(y-1 < 0) b=0;
  if(y+1 > 8) a=0;
   if(p == 1) {
  if(a*sol1[y+1][x] + b*sol1[y-1][x] + c*sol1[y][x+1] + d*sol1[y][x-1] > 1) {
      return true;
      }
   }
   
   if(p == 2) {
  if(a*sol2[y+1][x] + b*sol2[y-1][x] + c*sol2[y][x+1] + d*sol2[y][x-1] > 1) {
      return true;
      }
   }
   
   if(p == 3) {
  if(a*sol3[y+1][x] + b*sol3[y-1][x] + c*sol3[y][x+1] + d*sol3[y][x-1] > 1) {
      return true;
      }
   }
      return false;
}

bool findpath1(int x, int y, int d)
{
  if(!isvalid(x,y))                                                                          
    { return false; }
    
    if(isOptimizable(x,y,1)) {             // doubt
      return false;
      }
    
    sol1[y][x]=1; push1(10*y + x);
    l1++;
    if(maze[y][x]==dest)
    { curX = x; curY = y; return true; }
    
    if(d!=3) {  if (findpath1(x+1,y,1)) return true;}               // d=3 negative x direction
    if(d!=4) {  if (findpath1(x,y+1,2)) return true;}               // d=4 negative y direction
    if(d!=1) {  if (findpath1(x-1,y,3)) return true;}               // d=1 positive x direction
    if(d!=2) {  if (findpath1(x,y-1,4)) return true;}               // d=2 positive y direction
     sol1[y][x]=0; pop1();
     l1--;
     return false;
 }

bool findpath2(int x, int y, int d)
{
  if(!isvalid(x,y))                                                                          
    { return false; }
    
    if(isOptimizable(x,y,2)) {             // doubt
      return false;
      }
    
    sol2[y][x]=1; push2(10*y + x);
    l2++;
    if(maze[y][x]==dest)
    { curX = x; curY = y; return true; }
    
    if(d!=1) {  if (findpath2(x-1,y,3)) return true;}               // d=1 positive x direction
    if(d!=4) {  if (findpath2(x,y+1,2)) return true;}               // d=4 negative y direction
    if(d!=3) {  if (findpath2(x+1,y,1)) return true;}               // d=3 negative x direction
    if(d!=2) {  if (findpath2(x,y-1,4)) return true;}               // d=2 positive y direction
     sol2[y][x]=0; pop2();
     l2--;
     return false;
 }

bool findpath3(int x, int y, int d)
{
  if(!isvalid(x,y))                                                                          
    { return false; }
    
    if(isOptimizable(x,y,3)) {             // doubt
      return false;
      }
    
    sol3[y][x]=1; push3(10*y + x);
    l3++;
    if(maze[y][x]==dest)
    { curX = x; curY = y; return true; }
    
    if(d!=4) {  if (findpath3(x,y+1,2)) return true;}               // d=4 negative y direction  
    if(d!=3) {  if (findpath3(x+1,y,1)) return true;}               // d=3 negative x direction
    if(d!=1) {  if (findpath3(x-1,y,3)) return true;}               // d=1 positive x direction
    if(d!=2) {  if (findpath3(x,y-1,4)) return true;}               // d=2 positive y direction
     sol3[y][x]=0; pop3();
     l3--;
     return false;
 }


 
 void printmaze()
 {
  for(int i=8;i>-1;i--)
  {
    for(int j=0;j<5;j++)
    {
      Serial.print(maze[i][j] + " ");
    }
    Serial.println();
  }
 }

//void givePath()
//{
//  for(int i = 0; i < 50; i++)
//  {
//    cout<< stack[i]%10; cout << ","; cout << stack[i]/10; cout << "  ";
//  }
//}
 
void solvemaze(int xi, int yi, int end_pos) 
{
  ini_sol();
  ini_sol1();
  ini_sol2();
  ini_sol3();
  l1 = 0;
  l2 = 0;
  l3 = 0;
  top1 = -1; top2 = -1; top3 = -1;
  dest = end_pos;
  findpath1(xi, yi, 0);
  findpath2(xi, yi, 0);
  findpath3(xi, yi, 0);
 
  minm = l1;
  if(l2<=minm)
      minm=l2;
  else if(l3<=minm)
      minm = l3;
      
  if(minm == l1 )
  {
    for(r=0;r<=8;r++)
      {for(c=0;c<=4;c++)
           { sol[r][c]=sol1[r][c];}
      }   
    for(i=0;i<top1;i++)
       { push(stack1[i]);} 
   }
   
  else if(minm == l2 )
  {
    for(r=0;r<=8;r++)
       {for(c=0;c<=4;c++)
           {sol[r][c]=sol2[r][c];}
       }
    for(i=0;i<top2;i++)
        {push(stack2[i]);}         
  }
  
  else if(minm == l3 )
  {
    for(r=0;r<=8;r++)
       {for(c=0;c<=4;c++)
           {sol[r][c]=sol3[r][c];}
       }
    for(i=0;i<top3;i++)
        {push(stack3[i]);}              
  }  
  printsol();
}


//Assuming
//First block is kept at Node = 5
//Transfer zone is Node = 6 (Ye toh fixed point h, save kr lena bas maze me)
//Jedi block is Node = 7    (Ye bhi fixed h na, 0,6 h sayad
//Jedi zone is Node = 8
//Pit is node = 9
//I am assuming wahi ruk jaega woh, Node 8 pe

void  getFinalPath()
{
  printmaze();
        
        //Starting at point 2,0 and moving towards Clone block
        solvemaze(2,0,5);
        target[0] = 10*curY + curX;
          
        //Now moving towards Node 6;
        solvemaze(curX,curY,6);
        target[1] = 10*curY + curX;
        //now moving towards pit which is node 9

        solvemaze(curX,curY,9);
        target[2] = 10*curY + curX;
        //Now sail towards Node 7 to pick up the Jedi block
        
        solvemaze(curX,curY,7);
        target[3] = 10*curY + curX;
        
        solvemaze(curX,curY,8);
        target[4] = 10*curY + curX;
        push(target[4]);
 
       //Now all the coord dat the bot has to visit has been stored in the stack and the main checkpoints are saved in the array target... All we have to do is go on transversing...
}
//====================================================================================================================================================================================
int getDir(int xi, int yi, int xf, int yf)
{
  if(xf - xi == 1) return 1;
  if(xi - xf == 1) return 3;
  if(yf - yi == 1) return 2;
  if(yi - yf == 1) return 4;
}

void make_turn(int i, int f)
{
  
  if(i == 2 && f == 1) 
  {
    t = millis();
    while(millis() < t + 150)
    {  turn_right();  }
    
    sensor_read();
    
    while(s1==0)
    {
      sensor_read();
      turn_right();
    }
  }
  
  if(i == 3 && f == 2) 
  {
    t = millis();
    while(millis() < t + 150)
    {  turn_right();  }
    
    sensor_read();
    
    while(s1==0)
    {
      sensor_read();
      turn_right();
    }
  }
  
  if(i == 4 && f == 3) 
  {
    t = millis();
    while(millis() < t + 150)
    {  turn_right();  }
    
    sensor_read();
    
    while(s1==0)
    {
      sensor_read();
      turn_right();
    }
  }
  
  if(i == 1 && f == 4) 
  {
    t = millis();
    while(millis() < t + 150)
    {  turn_right();  }
    
    sensor_read();
    
    while(s1==0)
    {
      sensor_read();
      turn_right();
    }
  }
  
  if(i == 1 && f == 2) 
  {
    t = millis();
    while(millis() < t + 150)
    {  turn_left();  }
    
    sensor_read();
    
    while(s7==0)
    {
      sensor_read();
      turn_left();
    }
  }
  
  if(i == 2 && f == 3) 
  {
    t = millis();
    while(millis() < t + 150)
    {  turn_left();  }
    
    sensor_read();
    
    while(s7==0)
    {
      sensor_read();
      turn_left();
    }
  }
  
  if(i == 3 && f == 4) 
  {
    t = millis();
    while(millis() < t + 150)
    {  turn_left();  }
    
    sensor_read();
    
    while(s7==0)
    {
      sensor_read();
      turn_left();
    }
  }
  
  if(i == 4 && f == 1) 
  {
    t = millis();
    while(millis() < t + 150)
    {  turn_left();  }
    
    sensor_read();
    
    while(s7==0)
    {
      sensor_read();
      turn_left();
    }
  }
  
  if( f - i == 2 || i - f == 2) turnBack();
}
//============================================================================================================================================

void main_run()
{
  getFinalPath(); //Well you can put this at the end of dry run for faster main run as this takes some time to be executed!!
  
  //we are at autonomous starting zone, from there we have to move towards coord 2,0
  while(!node_check())
  {
    line_follow();
  }
  
  
  int steps = 1; //because the first element in stack is always 2,0
  int a,b;
  
  curX = 2; curY = 0; curDir = 2;
  a = target[0]%10; b = target[0]/10;
  while(1)
  {
    destX = stack[steps]%10; destY = stack[steps]/10;
    dir = getDir(curX, curY, destX, destY);
    make_turn(curDir,dir); curDir = dir;
    
    if(destX == a && destY == b)
    {
      break;
    }
    
    while(!node_check())
    {
      line_follow();
    }
    t = millis();
    while(millis() < t + line_overshoot)
    {
      line_follow();
    }
    
    curX = destX; curY = destY; steps++;
  }
    while(millis() < t + 220)  // mind the distance till which gripper grips the block comfortably
    {
      line_follow();
    }
   
    halt();
    delay(2000);
    // !!!!! PUT THE COMMAND FOR GRIPPER HERE !!!!!!
    gripper_open();
    gripper_down();
    delay(300);
    gripper_close();
    delay(300);
    gripper_up();
    delay(500);
    
    while(!node_check())
    {
      line_follow();
    }
    
    //halt();
    //delay(2000);// stop for 2 sec at blocks node
    //t = millis();
    //while(millis() < t + line_overshoot)
    //{
    //line_follow();
    //gripper_close();
    //}

    steps++;
    
    //=====================================Next phase - Going to the transfer zone============================
    
    curX = a; curY = b;  //Note that the curdir was already saved!
    a = target[1]%10; b = target[1]/10;
    while(1)
    { gripper_close();
      destX = stack[steps]%10; destY = stack[steps]/10;
      dir = getDir(curX, curY, destX, destY);
      make_turn(curDir, dir); curDir = dir;
    
      if(destX == a && destY == b)
      {
       
        break;
      }
    
      while(!node_check())
      {
        line_follow();
        gripper_close();
      }

      t = millis();
      while(millis() < t + line_overshoot)
      {
        line_follow();
        gripper_close();
      }
    
      curX = destX; curY = destY; steps++;
    }

    
    while(!node_check())
      {
        line_follow();
      }
      
   // while(millis() < t + 150)  // dekh lena kitna agee jana hai!
   // {
   //   line_follow();
   // }
   
   
    make_turn(curDir,1);
          halt();
      
   
    // !!!!!!! PUT THE COMMAND TO LOWER THE BLOCK !!!!!!!!
    
    gripper_down();
    delay(500);
    gripper_open();
    delay(500);
    gripper_up();
    gripper_close();

    curDir=1;
   // make_turn(curDir,3);
      
    //while(!node_check()) { line_follow(); }
    //t = millis();
    //while(millis() < t + line_overshoot) { line_follow(); }
    //halt();
    //digitalWrite(buzz,HIGH);
    //delay(3000);
    //digitalWrite(buzz,LOW);
    steps++;

   //===============================================Going towards pit======================================================

    curX = a; curY = b;  //Note that the curdir was already saved!
    a = target[2]%10; b = target[2]/10;
    //curDir=3;
    
    while(1)
    {
      destX = stack[steps]%10; destY = stack[steps]/10;
      dir = getDir(curX, curY, destX, destY);
      make_turn(curDir, dir); curDir = dir;
    
      if(destX == a && destY == b)
      { 
        break;
      }
    
      while(!node_check())
      {
        line_follow();
      }

      t = millis();
      while(millis() < t + line_overshoot)
      {
        line_follow();
      }
    
      curX = destX; curY = destY; steps++;
    }

        Serial.println("Executing Halt");
        t=millis();
        while(millis()<t+60000)
        {
          halt();
        }
        
            
    while(!node_check())
      {
        line_follow();
      }

      
      
    //while(millis() < t + 150)  // dekh lena kitna agee jana hai!
    //{
    //  line_follow();
    //}
    //while(!node_check()) { line_follow(); }
    //t = millis();
    //while(millis() < t + line_overshoot) { line_follow(); }
    steps++;
    
    
    //=====================================Next Phase - To get the jedi block=====================================
    curX = a; curY = b;
    a = target[3]%10; b = target[3]/10;
  
    
    while(1)
    {
      destX = stack[steps]%10; destY = stack[steps]/10;
      dir = getDir(curX, curY, destX, destY);
      make_turn(curDir, dir); curDir = dir;
    
      if(destX == a && destY == b)
      {
        break;
      }
    
      while(!node_check())
      {
        line_follow();
      }
      t = millis();
      while(millis() < t + line_overshoot)
      {
        line_follow();
      }
    
      curX = destX; curY = destY; steps++;
    }
       Serial.println("Executing Halt");
  
        halt();
        delay(2000); 
    //while(millis() < t + 150)  // Again mind the gap!!!
    //{
    //  line_follow();
    //}
    
    
    // !!!!! PUT THE COMMAND FOR GRIPPER HERE !!!!!!
    Serial.println("Executing Gripper commands");
    gripper_open();
    gripper_down();
    delay(500);
    gripper_close();
    gripper_up();
    
    while(!node_check()) { line_follow(); }
    //t = millis();
    //while(millis() < t + line_overshoot) { line_follow(); }
    
    //halt();
    //delay(2000);
    //digitalWrite(buzz,HIGH);
    //delay(2000);
    //digitalWrite(buzz,LOW);
    steps++;
    
    //================================Final Phase - Put the JEdi in the assigned pit================================================
    curX = a; curY = b;
    a = target[4]%10; b = target[4]/10;
    while(1)
    {
      destX = stack[steps]%10; destY = stack[steps]/10;
      dir = getDir(curX, curY, destX, destY);
      make_turn(curDir, dir); curDir = dir;
    
      if(destX == a && destY == b) break;
    
      while(!node_check())
      {
        line_follow();
      }
      t = millis();
      while(millis() < t + line_overshoot)
      {
        line_follow();
      }
    
      curX = destX; curY = destY; steps++;
    }
    t=millis();
    while(millis()<t+2000)
        halt();
    //while(millis() < t + 150)  // U know it... Mind the GAP!!!
    //{
    //  line_follow();
    //}
    // !!!!!!! PUT THE COMMAND TO LOWER THE BLOCK !!!!!!!!
    Serial.println("Executing gripper commands");
    gripper_down();
    gripper_open();
    gripper_up();
    
    //========================== THE END OF AUTOBOT'S JOURNEY ==============================
    
}

