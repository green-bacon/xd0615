int pinInterrupt=2;
int tick = 0; //计数值
int state=0;
int income=0;
//中断服务程序
void myfunc()
{
  income=-1;
  state=~state;
  digitalWrite(13,state);}
 
void setup()
{
  Serial.begin(9600); //初始化串口
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(13,OUTPUT);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  
  attachInterrupt( digitalPinToInterrupt(pinInterrupt), myfunc, CHANGE);
}
 
void loop()
{
    digitalWrite(3,income&0x1);
    digitalWrite(4,(income>>1)&0x1);
    digitalWrite(5,(income>>2)&0x1);
    digitalWrite(6,(income>>3)&0x1);
    delay(1000);
    income=income+1;
  if(income==10) income=0;
}