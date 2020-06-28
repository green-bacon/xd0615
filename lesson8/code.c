/*
  Ping))) Sensor

  This sketch reads a PING))) ultrasonic
  rangefinder and returns the distance to the
  closest object in range. To do this, it sends a
  pulse to the sensor to initiate a reading, then
  listens for a pulse to return.  The length of
  the returning pulse is proportional to the
  distance of the object from the sensor.
  ������װ�û���ǰ���������壬�������������ᷴ���������������������ܺ�
  ����һ��ʱ��ͨ����ʱ�����м�����Եó������봫�����ľ���
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
  pinMode(triggerPin, OUTPUT);  //��ʼ�������������
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  //����������������Ϊ��״̬10΢�룬���䳬����
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  //��ȡ�����ܽţ���������������ʱ�䣨΢�룩
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);//��ʼ��

}

void loop()
{
  //����pingʱ�䣨cm��
  cm = 0.01723 * readUltrasonicDistance(7, 7);
  //����2.54�����Ӣ��
  inches = (cm / 2.54);
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.println("cm");//��������in xx cm
  delay(100); // ����100΢��
}