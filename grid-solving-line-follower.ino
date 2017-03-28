const int m11 = 22; // for left motor
const int m12 = 24;
const int m21 = 26; // for right motor
const int m22 = 28;
const int pwm2 = 10;  // for v2 where v2 is right motor
const int pwm1 = 9;  // for v1 where v1 is left motor
const int buzz = 12;
int s1;
int s2;
int s3;
int s4;
int s5;
int s6;
int s7;
int kp=15; 
int kd=10; 
int ki=0; 
int final=0;
int prev_v1 = 0;
int prev_v2 = 0;
int derr = 0;
int sum_err=0;
int err= 0;
int preErr=0;
double corr;
int v = 135;
int vturn = 125 ; // velocity of tyres when bot makes a turn
int v1; //left motor 
int v2; // right motor
double sum=0, wsum=0;
unsigned long t;
int overshoot= 420; // time upto which bot overtravels at a node
int rswitch = 40;

void setup() {
  Serial.begin(38400);
  pinMode(buzz,OUTPUT);
  pinMode(m11,OUTPUT);
  pinMode(m12,OUTPUT);
  pinMode(m21,OUTPUT);
  pinMode(m22,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(pwm1,OUTPUT); 
  digitalWrite(buzz,LOW);
  pinMode(rswitch,INPUT);
}

void loop() 
{
  set_pinmode();
  gripper_close();
    //line_follow();
  sensor_read();  // read values from ir sensor
  if(digitalRead(rswitch)==HIGH)
    {
      dry_run();
      while(digitalRead(rswitch)==HIGH);
           halt();
    }
  else
    main_run();

  
}

















 
