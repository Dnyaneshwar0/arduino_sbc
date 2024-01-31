#include <Wire.h>
#include <LiquidCrystal_SR.h>

int tsec=5000;
LiquidCrystal_SR lcd(17,16,21);
void setup() 
{
  lcd.begin(16,2);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(27, OUTPUT);
}

void loop() 
{
  lcd.setCursor(0,0);
  lcd.printf("Time remaining: ");
  int temp=tsec;
  int hr=temp/3600;
  temp%=3600;
  int min=temp/60;
  temp%=60;
  int sec=temp;
  lcd.setCursor(0,1);
  lcd.printf("%d:%d:%d",hr,min,sec);
  if(tsec==0)
  {
    lcd.clear();
    lcd.printf("Timer Expired.");
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(14, HIGH);
    digitalWrite(27, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(14, LOW);
    digitalWrite(27, LOW);
    delay(500);
  }
  else
  {
    tsec--;
    delay(1000);
  }
  if(tsec<4975 && tsec>21)
  {
    tsec=20;
  }
  lcd.clear();
}
