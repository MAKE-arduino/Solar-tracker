#include <Servo.h>
Servo myservo;
int razh;
int a,b;
float k = 0.03;
void setup() {
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  myservo.attach(3);  // подключаем на пин 3
  myservo.write(50);

  Serial.begin(9600);
}

void loop() {
Math();
myservo.write(expRunningAverage(razh));
delay(20);
}

float expRunningAverage(float newVal) {
  static float filVal = 0;
  filVal += (newVal - filVal) * k;
  return filVal;
}

void Math(){
a = analogRead(A0);
b = analogRead(A1);
a = map(a,450,3,0,360);
b = map(b,450,3,0,360);


razh = b - a;
Serial.println(razh);
}