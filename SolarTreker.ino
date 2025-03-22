#include <Servo.h>  // библиотека сервопривода
Servo myservo;  // создаём обьект сервопривода myservo
//--------переменные--------
int razh;  // переменная разницы
int val;  // переменная угла поворота

int a,b;  // переменные фоторезисторов A и B

float k = 0.02; //  коэффициент фильтрации

//--------Функции(основной код)--------
void setup() {
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  myservo.attach(3);  // подключаем на пин 3
  myservo.write(90);  // поворачиваем сервопривот в середину

  Serial.begin(9600);  // подключаем порт для отладки
}

void loop() {
Math();  //функция вычеслений
myservo.write(expRunningAverage(val));  // изменение угла поворота сервопривода 
constrain(val, -180, 180);  // ограничение по углам поворота
delay(10); // задержка от лагов
}

float expRunningAverage(float newVal) {  // функция фильтра
  static float filVal = 0;
  filVal += (newVal - filVal) * k;
  return filVal;
}

void Math(){  // функция вычеслений
a = analogRead(A0);  // подключаем фоторезистор А к пину А0
b = analogRead(A1);  // подключаем фоторезистор В к пину А1
a = map(a,450,3,0,5);  // переводим яркость в нужные значения
b = map(b,450,3,0,5);  // переводим яркость в нужные значения


razh = b - a;  // получение разницы
val += razh;  // изменение значения угла поворота сервопривода
  
  Serial.println(val);  // выводим значения угла в порт для отладки
}

