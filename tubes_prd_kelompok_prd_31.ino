// C++ code
//
#include <LiquidCrystal.h>
LiquidCrystal lcd( 7, 6, 5, 4, 3, 2);
const int buzz = 10;
float cm = 0;
int photoPin = A0;
int rota = A1;
int led1 = 11;
int led2 = 12;
int led3 = 13;
int led4 = 10;

void setup()
{ 
  pinMode(rota, INPUT);
  pinMode(8, INPUT);
  pinMode(A0, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(buzz, OUTPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop()
{
  //PotentiometerLock
  int rotaMea = analogRead(A1);
  
  if (rotaMea == 206)
  {
    digitalWrite(led1, HIGH);
  }
  if (rotaMea == 1000)
  {
    digitalWrite(led2, HIGH);
  }
  if (rotaMea == 552)
  {
    digitalWrite(led3, HIGH);
  }
  
  //Ultrasonic
  cm = 0.01723 * readUltrasonicDistance(8);
  lcd.setCursor(0,0);
  lcd.print("Cm: ");
  lcd.print(cm);
  delay(1000);
  
  if (cm >= 100.0 && cm <= 110.0)
  {
    lcd.setCursor(0,1);
    lcd.print("Access Granted");
  }
  
  //Photoresistor
  int lightRead = analogRead(A0);
  Serial.println(lightRead);
  if (lightRead == 793)
  {
    tone(buzz, 300, 400);
    delay(5000);
  }
}
long readUltrasonicDistance(int Pin)
{
  pinMode(Pin, OUTPUT);
  digitalWrite(Pin, LOW);
  delayMicroseconds(1);
  
  digitalWrite(Pin, HIGH);
  delayMicroseconds(1);
  digitalWrite(Pin,LOW);
  pinMode(Pin,INPUT);
  
  return pulseIn(Pin,HIGH);
}