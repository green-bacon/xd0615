/*
  Ping))) Sensor

  This sketch reads a PING))) ultrasonic
  rangefinder and returns the distance to the
  closest object in range. To do this, it sends a
  pulse to the sensor to initiate a reading, then
  listens for a pulse to return.  The length of
  the returning pulse is proportional to the
  distance of the object from the sensor.
  启动后，装置会向前方发射脉冲，脉冲碰到物体后会反弹，反弹波被传感器接受后
  会有一个时间差，通过对时间差进行计算可以得出物体与传感器的距离
  The circuit:
   * +V connection of the PING))) attached to +5V
   * GND connection attached to ground
   * SIG connection attached to digital pin 7
  http://www.arduino.cc/en/Tutorial/Ping
  This example code is in the public domain.
*/

int inches = 0;

int cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  //初始化，清除触发器
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  //将触发器引脚设置为高状态10微秒，发射超声波
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  //读取回声管脚，并返回声波传播时间（微秒）
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);//初始化

}

void loop()
{
  //测量ping时间（cm）
  cm = 0.01723 * readUltrasonicDistance(7, 7);
  //除以2.54换算成英寸
  inches = (cm / 2.54);
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.println("cm");//输出测距结果in xx cm
  delay(100); // 等上100微秒
}