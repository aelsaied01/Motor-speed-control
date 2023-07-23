#define trigPin 12
#define echoPin 11
#define dcm 9
long duration, distance;


void setup() 
{
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(dcm, OUTPUT);
}

void loop() 
{
digitalWrite(trigPin,0);
delayMicroseconds(2);
digitalWrite(trigPin,1);
delayMicroseconds(10);
digitalWrite(trigPin,0);
duration = pulseIn(echoPin,1);
distance = (duration/2) * 0.0343;


  if (distance <= 200) 
  {
    analogWrite(dcm, map(distance, 0, 200, 255, 0));
  } else {
    analogWrite(dcm, 0);
  }
}
 